#pragma once
#include "Playable.h"
class NPC :
	public Playable
{
public:
	NPC() {};

	virtual void AddScore() override {}
	virtual int GetScore() override { return m_score; }
	virtual char GetInput() override { return NULL; }
};

