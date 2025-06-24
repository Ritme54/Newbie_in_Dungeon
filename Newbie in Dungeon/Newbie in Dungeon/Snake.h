#pragma once
#include "Monster.h"
class Snake : public Monster
{

public:
	Snake();
	std::string getDefeatMessage() const override;
};

