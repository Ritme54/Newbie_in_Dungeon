#include "Goblin.h"
#include <iostream>
#include "Monster.h"

using namespace std;


Goblin::Goblin() : Monster("고블린",10,10,10,10)//이후 수정
{
	std::cout << "고블린이 어슬렁거리며 나타났다!" << std::endl;

}

std::string Goblin::getDefeatMessage() const 
{
	return GetName() + "(이)가 몽둥이를 놓치며 비명을 지르고 쓰러졌습니다!";
}
