#pragma once
#include "BossMonster.h"
class VenomousSnake :
    public BossMonster
{
public:
	VenomousSnake();
	void activateSpecialPhase() override;
	std::string getDefeatMessage() const override;
};

