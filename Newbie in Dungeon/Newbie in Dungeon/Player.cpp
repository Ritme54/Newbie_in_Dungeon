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
	cout << "캐릭터가 생성되었습니다." << endl;
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
		std::cout << "--- " << name << "의 상태 ---" << std::endl;
		std::cout << "레벨: " << level << std::endl;
		std::cout << "체력: " << hp << "/" << maxHp << std::endl;
		std::cout << "공격력: " << attack << std::endl;
		std::cout << "방어력: " << defense << std::endl;
		std::cout << "경험치: " << exp << "/" << requiredExp << std::endl;
		std::cout << "-------------------------" << std::endl;
	}

}

Player::~Player()
{

	if (int hp=0)
	{
cout << "캐릭터가 치료소로 실려갔습니다." << endl;
	}
	

}

