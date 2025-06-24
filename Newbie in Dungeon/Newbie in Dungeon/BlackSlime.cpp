#include "BlackSlime.h"
#include <iostream>

using namespace std;

BlackSlime::BlackSlime() : BossMonster("블랙 슬라임",10,10,10,10)//이후 수정
{
	std::cout << "블랙 슬라임이 당신을 눈치체고 다가옵니다." << std::endl;
}

void BlackSlime::activateSpecialPhase()
{
}

std::string BlackSlime::getDefeatMessage() const
{
	return  "당신의 마지막 일격에 블랙 슬라임이 산산조각났다!";
}
