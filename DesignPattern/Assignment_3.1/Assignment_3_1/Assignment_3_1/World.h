// World.h
#ifndef __WORLD_H__
#define __WORLD_H__

#include <utility>
#include <vector>
#include <unordered_map>
#include "GlobalData.h"
#include "Character.h"
#include "Player.h"
#include "Enemy.h"

class Tile;

class World
{
private:
	static World* world;
public:

	static World* GetInstance()
	{
		if (world == nullptr)
		{
			world = new World();
		}

		return world;
	}

	static void FreeInstance()
	{
		if (world != nullptr)
		{
			delete world;
			world = nullptr;
		}
	}

	// initialization
	void Init(int width, int height);
	void CreatePlayer(int x = 0, int y = 0);
	void GenerateWorld();

	// update
	void Draw();
	void Update();

    // end
    void EndGame();
    bool IsGameOver() const { return m_gameOver; }
	bool IsPlayerNear(int enemyIndex);

private:
	World();
	~World();


	typedef std::pair<int, TileType> TileProbability;
	static const TileProbability s_tileProbabilities[(int)TileType::k_numTiles];

	int m_width, m_height;

	Enemy* m_pEnemy[3];

	bool m_gameOver;
public:
	Tile** m_ppGrid;
	Player* m_pPlayer;
	
	TileType& GetTileType(int index)
	{ 
		return m_ppGrid[index]->type;
	}
};

#endif