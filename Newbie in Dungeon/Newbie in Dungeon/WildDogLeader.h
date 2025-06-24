#pragma once
#include "BossMonster.h"
class WildDogLeader : public BossMonster
{
public:
	WildDogLeader();
	void activateSpecialPhase() override;
	std::string getDefeatMessage() const override;
};

