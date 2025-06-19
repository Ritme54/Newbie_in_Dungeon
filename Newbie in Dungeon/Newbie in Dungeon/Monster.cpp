#include "Monster.h"
#include <iostream>
#include <string>
#include "Player.h"

 
Monster::Monster(string initialName, int initialHp, int initialAttack, int initialDefense, int initialExpGiven)
	: name(initialName),       // 이름 초기화
	hp(initialHp),           // 현재 체력 초기화
	maxHp(initialHp),        // 최대 체력 초기화 (보통 초기 체력과 같게 시작)
	attack(initialAttack),   // 공격력 초기화
	defense(initialDefense), // 방어력 초기화
	expGiven(initialExpGiven) // 제공 경험치 초기화
{

}


#pragma region 행동 로직
void Monster::Attack(Player& targetPlayer)
{
}
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
#pragma endregion

#pragma region 상태 반환

int Monster::GetHP() const
{
	return hp;
}

int Monster::GetMaxHP() const
{
	return maxHp;
}

int Monster::GetAttack() const
{
	return attack;
}

int Monster::GetDefense() const
{
	return defense;
}

int Monster::GetEXPValue() const
{
	return expGiven;
}

std::string Monster::GetName() const
{
	return name;
}

#pragma endregion




Monster::~Monster()
{
	if (int hp=0)
	{
		std::cout << "--- 을 쓰려트렸습니다." << std::endl;

		std::cout << "전투에서 승리했습니다." << std::endl;
	}
}
