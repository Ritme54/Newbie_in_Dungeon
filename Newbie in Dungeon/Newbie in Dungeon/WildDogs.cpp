#include "WildDogs.h"
#include <iostream>
#include "Monster.h"

using namespace std;

WildDogs::WildDogs() : Monster("들개", 50, 15, 8, 30)//수치 수정할것
{
	std::cout << "들개가 튀어나왔다!" << std::endl;
}

std::string WildDogs::getDefeatMessage() const
{
	return GetName() + "들개가 비명을 지르며 쓰러졌습니다!";
}

