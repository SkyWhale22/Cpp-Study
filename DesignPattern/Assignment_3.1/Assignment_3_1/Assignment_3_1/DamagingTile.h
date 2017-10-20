#pragma once
#include "GlobalData.h"
#include "Character.h"

class DamagingTile
{
protected:

public :
	typedef std::pair<int, int> DamageRange;
	virtual ~DamagingTile() { };

	virtual void GiveDamage(Character* pPlayer, DamageRange range)
	{
		int damage = (rand() % (range.second - range.first)) + range.first;
		pPlayer->Damage(damage);
	}
};
