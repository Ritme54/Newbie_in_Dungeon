#pragma once
#include "Monster.h"
class Goblin : public Monster
{
public:
	Goblin();

	std::string getDefeatMessage() const override;
};

