// BossMonster.cpp
#include "BossMonster.h"
#include <iostream>
#include "Player.h" // Attack �Լ����� Player�� ����ϹǷ�

// BossMonster ������: ��� Ŭ���� Monster�� �����ڸ� ȣ��
BossMonster::BossMonster(std::string name, int hp, int attack, int defense, int expGiven)
    : Monster(name, hp, attack, defense, expGiven) {
    // BossMonster ������ �ʱ�ȭ ���� (�ʿ��ϴٸ�)
}

// Attack �Լ� ������ (����: ���� ���ʹ� �� �������� �޽���)
void BossMonster::Attack(Player& targetPlayer) {
    // Monster::Attack(targetPlayer); // ��� Ŭ������ Attack ������ �״�� ����ϰ� �ʹٸ�
    if (!IsAlive()) return;

    std::cout << GetName() << "(��)�� ������ ������ �õ��մϴ�!" << std::endl;

    int damage = GetAttack() - targetPlayer.GetDefense();
    if (damage < 0) damage = 0;

    targetPlayer.TakeDamage(damage);
}