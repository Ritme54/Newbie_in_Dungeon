#include "Monster.h"





void Monster::DisplayStatus() const
{
	{
		std::cout << "--- " << name << "의 상태 ---" << std::endl;
		std::cout << "체력: " << hp << "/" << maxHp << std::endl;
		std::cout << "공격력: " << attack << std::endl;
		std::cout << "방어력: " << defense << std::endl;
		std::cout << "-------------------------" << std::endl;
	}
}

Monster::~Monster()
{
	if (hp=0)
	{
		cout << "--- 을 쓰려트렸습니다." << endl;
		cout << "전투에서 승리했습니다." << endl;
	}
}
