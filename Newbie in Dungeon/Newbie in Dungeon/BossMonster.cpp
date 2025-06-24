// BossMonster.cpp
#include "BossMonster.h"
#include <iostream>
#include "Player.h"

BossMonster::BossMonster(std::string name, int hp, int attack, int defense, int expGiven)
    : Monster(name, hp, attack, defense, expGiven) {
    std::cout << "강력한 보스 " << GetName() << "(이)가 생성되었습니다." << std::endl;
}

void BossMonster::Attack(Player& targetPlayer) {
    if (!IsAlive()) return;

    std::cout << GetName() << "(이)가 강력한 공격을 시도합니다!" << std::endl;

    int damage = GetAttack() - targetPlayer.GetDefense();
    if (damage < 0) damage = 0;

    targetPlayer.TakeDamage(damage);
}


