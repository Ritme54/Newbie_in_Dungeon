#include "Kig_Rat.h"
#include <iostream>

using namespace std;

Kig_Rat::Kig_Rat() : BossMonster("대왕 쥐", 80, 25, 15, 100) // 수치 수정할 것
{
	std::cout << "대왕 쥐가 나타났습니다!" << std::endl;
}


void Kig_Rat::activateSpecialPhase()
{
}

std::string Kig_Rat::getDefeatMessage() const
{
    return "당신의 마지막 일격에 대왕 쥐가 저 멀리 날아갔다!";
}
