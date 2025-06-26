#pragma once
#include "BossMonster.h"


class BlackSlime : public BossMonster
{
public:
	BlackSlime();
	void activateSpecialPhase() override;
	std::string getDefeatMessage() const override;
};

