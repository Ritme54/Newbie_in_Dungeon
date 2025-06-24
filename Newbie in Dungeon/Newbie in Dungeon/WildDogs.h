#pragma once
#include "Monster.h"
class WildDogs : public Monster
{

public:
	WildDogs();

	std::string getDefeatMessage() const override;
};

