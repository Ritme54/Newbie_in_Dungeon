#include "GoblinWarrior.h"
#include <iostream>

using namespace std;

GoblinWarrior::GoblinWarrior() : BossMonster("고블린 전사", 80, 15, 8, 40) // 수치 수정할 것
{
	std::cout << "고블린 전사가 나타났습니다!" << std::endl;

}

void GoblinWarrior::activateSpecialPhase()
{
}

std::string GoblinWarrior::getDefeatMessage() const
{
    return "당신의 마지막 일격에 고블린 전사가 가슴을 부여잡으며 쓰러졌다!";std::string();
}
