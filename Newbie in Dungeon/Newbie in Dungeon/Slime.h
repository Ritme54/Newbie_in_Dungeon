#pragma once
#include <string>

#include "Monster.h"
class Slime : public Monster
{
public:
	Slime();

	std::string getDefeatMessage() const override;
};

