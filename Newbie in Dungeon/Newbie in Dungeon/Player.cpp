#include "Player.h"
#include <string>
#include <iostream>


using namespace std;

Player::Player(string initialName, int instialHp, int instialAttack, int instialDefense):
	name(initialName),
	hp(instialHp),
	maxHp(instialHp),
	attack(instialAttack),
	defense(instialDefense),
	level(1),
	exp(0),
	requiredExp(100)
{
	cout << "ĳ���Ͱ� �����Ǿ����ϴ�." << endl;
}

void Player::Attack(Monster& targetEnemy)
{

}

void Player::TakeDamage(int damageAmount)
{
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

Player::~Player()
{

	if (int hp=0)
	{
cout << "ĳ���Ͱ� ġ��ҷ� �Ƿ������ϴ�." << endl;
	}
	

}

