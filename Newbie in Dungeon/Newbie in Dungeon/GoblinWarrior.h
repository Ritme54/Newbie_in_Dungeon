#pragma once
#include "BossMonster.h"
class GoblinWarrior :
    public BossMonster
{
public:
	GoblinWarrior();
	void activateSpecialPhase() override;
	std::string getDefeatMessage() const override;
};

