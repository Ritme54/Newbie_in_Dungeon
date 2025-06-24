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
	std::cout << "ĳ���Ͱ� �����Ǿ����ϴ�." << std::endl;
}

#pragma region ���� ����


void Player::Attack(Monster& targetEnemy)
{
	if (!IsAlive()) return;
	std::cout << name << "(��)��" << targetEnemy.GetName() << "(��)�� �����մϴ�." << std::endl;
	int damage = attack - targetEnemy.GetDefense();
	if (damage < 0) damage = 0;
	targetEnemy.TakeDamage(damage);
}



void Player::TakeDamage(int damageAmount)
{
	if (!IsAlive()) return;

	hp -= damageAmount;
	std::cout << name << "(��)��" << damageAmount << "�� ���ظ� �Ծ����ϴ�." << std::endl;
	if (hp<=0)
	{

		hp = 0;
	std::cout << "ü��: " << hp << "/" << maxHp << std::endl;
		std::cout << name << "(��)�� ���������ϴ�..." << std::endl;
	}
	else
	{
		std::cout << "ü��: " << hp << "/" << maxHp << std::endl;
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
		std::cout << "--- " << name << "�� ���� ---" << std::endl;
		std::cout << "����: " << level << std::endl;
		std::cout << "ü��: " << hp << "/" << maxHp << std::endl;
		std::cout << "���ݷ�: " << attack << std::endl;
		std::cout << "����: " << defense << std::endl;
		std::cout << "����ġ: " << exp << "/" << requiredExp << std::endl;
		std::cout << "-------------------------" << std::endl;
	}

}

bool Player::IsAlive() const
{
	return hp > 0;
	return true;
}
#pragma region ���� ��ȯ

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





