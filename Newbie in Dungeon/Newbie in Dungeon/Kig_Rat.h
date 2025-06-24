#pragma once
#include "BossMonster.h"
class Kig_Rat :
    public BossMonster
{
public:
	Kig_Rat();
	void activateSpecialPhase() override;
	std::string getDefeatMessage() const override;
};

