#include "Player.h"
#include "Macros.h"
#include "Input.h"
#include "Map.h"
#include <conio.h>

Player::Player()
{
	m_HP = 5;
	m_position.Set(24, 15);
	m_state.ChangeDirection(TankStateMachine::Direction::kUp);
	ReadSprite();
}

Player::~Player()
{
}

void Player::PrintTank()
{
	ReadSprite();
}

void Player::Move(int x, int y)
{
	m_position.Set(m_position.GetX() + x, m_position.GetY() + y);
}

void Player::Action()
{
}

bool Player::Update()
{
	char input = m_pInput->GetInput();

	switch (input)
	{
	case 's':	// Down
		m_state.ChangeDirection(TankStateMachine::Direction::kDown);

		if (Map::GetInstance()->CheckEndOfMap(input, m_position.GetY()) == false)
			Move(0, 1);
		break;

	case 'a':	// Left
		m_state.ChangeDirection(TankStateMachine::Direction::kLeft);

		if (Map::GetInstance()->CheckEndOfMap(input, m_position.GetX()) == false)
			Move(-1, 0);
		break;

	case 'd':	// Right
		m_state.ChangeDirection(TankStateMachine::Direction::kRight);

		if (Map::GetInstance()->CheckEndOfMap(input, m_position.GetX()) == false)
			Move(1, 0);
		break;

	case 'w':	// Up
		m_state.ChangeDirection(TankStateMachine::Direction::kUp);

		if (Map::GetInstance()->CheckEndOfMap(input, m_position.GetY()) == false)
			Move(0, -1);
		break;
	}

	PrintTank();

	if (input == 'q')
		return false;
	else
		return true;
}

void Player::ReadSprite()
{
	m_state.GetState()->ReadSprite("PlayerTank");
}

bool Player::CheckMovable()
{
	return false;
}

/*
void Player::ReadXML(Direction dir)
{

	// Loading a file...
	XMLDocument doc;
	//doc.LoadFile("TankStatus.xml");
	doc.LoadFile("SpriteData.xml");
	// Find the root
	XMLElement* pSprite = doc.RootElement();
	XMLElement* pType = pSprite->FirstChildElement("Tank");
	XMLElement* pTank = pTank->FirstChildElement("PlayerTank");
	XMLElement* pDir = pPlayer->FirstChildElement();
	//ReadElementValue(pRoot, "myInt", value, Int);

	switch (dir)
	{
	case Tank::Direction::kUp:
		pDir = pPlayer->FirstChildElement("Up");
		break;
	case Tank::Direction::kDown:
		pDir = pPlayer->FirstChildElement("Down");
		break;
	case Tank::Direction::kRight:
		pDir = pPlayer->FirstChildElement("Right");
		break;
	case Tank::Direction::kLeft:
		pDir = pPlayer->FirstChildElement("Left");
		break;
	}

	m_Sprite = pDir->GetText();

	for (int i = 0; i < 9; ++i)
	{
		cout << m_Sprite[i];

		if (i == 2 || i == 5)
			cout << endl;
	}
	cout << endl;


	//m_pInput = new Input;

	if (pRoot = nullptr)
	{
		cout << "Couldn't open SpriteData." << endl;
	}
	else
	{
		XMLElement* pTank = pRoot->FirstChildElement("Tile");
		if (pTank = nullptr)
		{
			cout << "Couldn't open Tile." << endl;
		}
		else
		{
			XMLElement* pPlayer = pTank->FirstChildElement("BrickWall");
			//		XMLElement* pDir = pPlayer->FirstChildElement("Up");

			if (pPlayer = nullptr)
			{
				cout << "Couldn't open Tile." << endl;
			}
			else
			{
				m_Sprite = pPlayer->GetText();
				cout << m_Sprite;
			}
		}
	}
	while (pDir != nullptr)
	{
		std::string elementName = pDir->Name();


		if (elementName == "Up")
		{
			m_Sprite = pDir->GetText();
		}
		else if (elementName == "Down")
		{
			m_connectedRoomIds[Direction::East] = id;
		}
		else if (elementName == "Right")
		{
			m_connectedRoomIds[Direction::West] = id;
		}
		else if (elementName == "Left")
		{
			m_connectedRoomIds[Direction::South] = id;
		}

		pConnection = pConnection->NextSiblingElement();
		
	}
}*/
