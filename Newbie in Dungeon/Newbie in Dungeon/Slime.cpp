#include "Slime.h"
#include <iostream>
#include "Monster.h"

using namespace std;

Slime::Slime() : Monster("녹색 슬라임", 20, 7, 3, 10)
{
	std::cout << "녹색 슬라임이 나타났다." << std::endl;
}

std::string Slime::getDefeatMessage() const
{
	return GetName() + "(이)가 젤리처럼 녹아내리며 쓰러졌습니다!";
}



