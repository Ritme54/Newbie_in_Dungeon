#include "Player.h"
#include <string>
#include <iostream>
#include "Monster.h"

using namespace std;

Player::Player(string initialName, int initialHp, int initialAttack, int initialDefense):
	name(initialName),
	hp(initialHp),
	maxHp(initialHp),
	attack(initialAttack),
	defense(initialDefense),
	level(1),
	exp(0),
	requiredExp(100)
{
	std::cout << "캐릭터가 생성되었습니다." << std::endl;
}

#pragma region 전투 로직


void Player::Attack(Monster& targetEnemy)
{
	if (!IsAlive()) return;
	std::cout << name << "(이)가" << targetEnemy.GetName() << "(을)를 공격합니다." << std::endl;
	int damage = attack - targetEnemy.GetDefense();
	if (damage < 0) damage = 0;
	targetEnemy.TakeDamage(damage);
}



void Player::TakeDamage(int damageAmount)
{
	if (!IsAlive()) return;

	hp -= damageAmount;
	std::cout << name << "(은)는" << damageAmount << "의 피해를 입었습니다." << std::endl;
	if (hp<=0)
	{

		hp = 0;
	std::cout << "체력: " << hp << "/" << maxHp << std::endl;
		std::cout << name << "(이)가 쓰러졌습니다..." << std::endl;
	}
	else
	{
		std::cout << "체력: " << hp << "/" << maxHp << std::endl;
	}

}



void Player::GainExperience(int expAmount)
{
}

void Player::LevelUp()
{
}



void Player::DisplayStatus()
{
	{
		std::cout << "--- " << name << "의 상태 ---" << std::endl;
		std::cout << "레벨: " << level << std::endl;
		std::cout << "체력: " << hp << "/" << maxHp << std::endl;
		std::cout << "공격력: " << attack << std::endl;
		std::cout << "방어력: " << defense << std::endl;
		std::cout << "경험치: " << exp << "/" << requiredExp << std::endl;
		std::cout << "-------------------------" << std::endl;
	}

}

bool Player::IsAlive() const
{
	return hp > 0;
	return true;
}
#pragma region 상태 반환

int Player::GetHP() const
{
	return hp;
}

int Player::GetMaxHP() const
{
	return maxHp;
}

int Player::GetAttack() const
{
	return attack;
}

int Player::GetDefense() const
{
	return defense;
}

std::string Player::GetName() const
{
	return name;
}



#pragma endregion




Player::~Player()
{
}

#pragma endregion





