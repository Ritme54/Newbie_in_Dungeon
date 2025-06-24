// BossMonster.cpp
#include "BossMonster.h"
#include <iostream>
#include "Player.h"

BossMonster::BossMonster(std::string name, int hp, int attack, int defense, int expGiven)
    : Monster(name, hp, attack, defense, expGiven) {
    std::cout << "������ ���� " << GetName() << "(��)�� �����Ǿ����ϴ�." << std::endl;
}

void BossMonster::Attack(Player& targetPlayer) {
    if (!IsAlive()) return;

    std::cout << GetName() << "(��)�� ������ ������ �õ��մϴ�!" << std::endl;

    int damage = GetAttack() - targetPlayer.GetDefense();
    if (damage < 0) damage = 0;

    targetPlayer.TakeDamage(damage);
}


