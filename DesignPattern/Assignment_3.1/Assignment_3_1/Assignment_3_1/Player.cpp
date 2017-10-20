// Player.cpp
#include "Player.h"
#include "GlobalData.h"
#include <iostream>
#include <conio.h>
#include "World.h"

using std::cout;

Player::Player(int x, int y)
    : m_gold(0)
    , m_moveCount(0)
{
	m_x = x;
	m_y = y;
	m_hitPoints = k_maxHitPoints;
}

void Player::Draw()
{
    if (!IsDead())
	    cout << "@";
    else
        cout << "~";
}

void Player::DrawUi() const
{
    cout << "HP: " << m_hitPoints << "  Detector: " << m_detectorCount << "  Gold: " << m_gold << "  Move Count: " << m_moveCount << "  Score: " << CalculateScore() << "\n\n";
}

bool Player::Update()
{
    if (IsDead())
        return false;

    char input = _getch();

    switch (input)
    {
        case 'q':
            return false;  // quitting

        case 'w':
            Move(0, -1);
            break;

        case 'a':
            Move(-1, 0);
            break;

        case 's':
            Move(0, 1);
            break;

        case 'd':
            Move(1, 0);
            break;
		case 'e':
			ActivateDetactor();
			break;
        default:
            cout << "Invalid input";
            break;
    }

    return true;
}

void Player::Move(int deltaX, int deltaY)
{
	Character::Move(deltaX, deltaY);
    ++m_moveCount;
}


void Player::AddGold(int amount)
{
    m_gold += amount;
}

int Player::CalculateScore() const
{
    int score = k_baseScore + (m_hitPoints * k_hitPointsWeight) + (m_gold * k_goldWeight) - (m_moveCount * k_moveCountWeight);
    return score;
}


void Player::ActivateDetactor()
{
	if (m_detectorCount > 0)
	{
		for (int y = -1; y < 2; ++y)
		{
			for (int x = -1; x < 2; ++x)
			{
				if((x==0 && y==0) || (m_x == 0 && (m_y >= 0 && m_y <= 19) && x == -1) || (m_x == 19 && (m_y >= 0 && m_y <= 19) && x == 1) || (m_y == 0 && (m_x >= 0 && m_x <= 19) && y == -1) || (m_y == 19 && (m_x >= 0 && m_x <= 19) && y == 1))
				{
					continue;
				}

				int index = ((m_y + y) * k_worldHeight) + (m_x + x);
				if (World::GetInstance()->GetTileType(index) == TileType::k_mimic)
				{
					Tile* pCurrentTile = World::GetInstance()->m_ppGrid[index];
					MimicTile* pMimicToReveal = dynamic_cast<MimicTile*>(pCurrentTile);
					pMimicToReveal->GetDetacted();
				}
			}
		}
		--m_detectorCount;
		++m_moveCount;
	}
}