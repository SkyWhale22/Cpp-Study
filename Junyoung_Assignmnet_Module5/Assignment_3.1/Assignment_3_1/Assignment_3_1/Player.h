// Player.h
#ifndef __PLAYER_H__
#define __PLAYER_H__

#include "Character.h"
#include "MimicTile.h"

class Player : public Character
{
private:
    int m_gold;
	int m_moveCount;
	int m_detectorCount = 3;

public:
	Player(int x, int y);

	int CalculateScore() const;
		
    void Move(int deltaX, int deltaY) override;
	void Draw() override;
    
	bool Update();

    void DrawUi() const;
	bool IsDead() override { return (m_hitPoints <= 0); }

    void AddGold(int amount);
	void ActivateDetactor();
};

#endif
