#include "WildDogLeader.h"
#include <iostream>

using namespace std;


WildDogLeader::WildDogLeader() : BossMonster("우두머리 들개", 100, 20, 12, 50) // 수치 수정할 것
{
	std::cout << "우두머리 들개가 나타났습니다!" << std::endl;


}
void WildDogLeader::activateSpecialPhase()
{
}

std::string WildDogLeader::getDefeatMessage() const
{
	return "당신의 마지막 일격에 우두머리 들개가 비명을 지르며 쓰러졌다!";
}
