#include "Monster.h"
#include <iostream>
#include <string>
#include "Player.h"

 
Monster::Monster(string initialName, int initialHp, int initialAttack, int initialDefense, int initialExpGiven)
	: name(initialName),       // �̸� �ʱ�ȭ
	hp(initialHp),           // ���� ü�� �ʱ�ȭ
	maxHp(initialHp),        // �ִ� ü�� �ʱ�ȭ (���� �ʱ� ü�°� ���� ����)
	attack(initialAttack),   // ���ݷ� �ʱ�ȭ
	defense(initialDefense), // ���� �ʱ�ȭ
	expGiven(initialExpGiven) // ���� ����ġ �ʱ�ȭ
{

}


#pragma region �ൿ ����
void Monster::Attack(Player& targetPlayer)
{
}
void Monster::DisplayStatus() const
{
	{
		std::cout << "--- " << name << "�� ���� ---" << std::endl;
		std::cout << "ü��: " << hp << "/" << maxHp << std::endl;
		std::cout << "���ݷ�: " << attack << std::endl;
		std::cout << "����: " << defense << std::endl;
		std::cout << "-------------------------" << std::endl;
	}
}
#pragma endregion

#pragma region ���� ��ȯ

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
		std::cout << "--- �� ����Ʈ�Ƚ��ϴ�." << std::endl;

		std::cout << "�������� �¸��߽��ϴ�." << std::endl;
	}
}
