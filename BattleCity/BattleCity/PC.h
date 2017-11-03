
#include "Playable.h"

class PC :
	public Playable
{
public:
	PC() {};

	virtual void AddScore() override { m_score += 100; }
	virtual int GetScore() override { return m_score; }
	virtual char GetInput() override { return m_input.GetInput(); }
};
