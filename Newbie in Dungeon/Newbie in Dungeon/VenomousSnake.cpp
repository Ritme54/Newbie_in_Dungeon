#include "VenomousSnake.h"
#include <iostream>

using namespace std;

VenomousSnake::VenomousSnake() : BossMonster("독사", 80, 25, 15, 100) // 수치 수정할 것
{
	std::cout << "독사가 나타났습니다!" << std::endl;
}


void VenomousSnake::activateSpecialPhase()
{
}

std::string VenomousSnake::getDefeatMessage() const
{
    return "당신의 마지막 일격에 독사가 반으로 잘려나갔다!";
}
