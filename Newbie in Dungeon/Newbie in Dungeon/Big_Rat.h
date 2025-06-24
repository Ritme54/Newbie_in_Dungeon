#pragma once
#include "Monster.h"
class Big_Rat : public Monster
{

public:
	Big_Rat();
	std::string getDefeatMessage() const override;
	
};

