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
	if (!IsAlive()) return;
	std::cout << GetName() << "(이)가" << targetPlayer.GetName() << "(을)를 공격합니다." << std::endl;
	int damage = attack - targetPlayer.GetDefense();
	if (damage < 0) damage = 0;
	targetPlayer.TakeDamage(damage);
}

void Monster::TakeDamage(int damageAmount)
{
	if (!IsAlive()) return;
	hp -= damageAmount;
	std::cout << GetName() << "(은)는" << damageAmount << "의 피해를 입었습니다." << std::endl;
	
	if (hp <= 0)
	{
		hp = 0;
		std::cout << "체력: " << hp << "/" << maxHp << std::endl;
		std::cout << name << "(을)를 쓰러졌습니다..." << std::endl;
	}
	else
	{
	std::cout << "체력: " << hp << "/" << maxHp << std::endl;
	}
	
}
void Monster::DisplayStatus() const
{
	
		std::cout << "--- " << name << "의 상태 ---" << std::endl;
		std::cout << "체력: " << hp << "/" << maxHp << std::endl;
		std::cout << "공격력: " << attack << std::endl;
		std::cout << "방어력: " << defense << std::endl;
		std::cout << "-------------------------" << std::endl;
	
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
bool Monster::IsAlive() const
{
	return hp > 0;
}



#pragma endregion



