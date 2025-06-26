// ArmorPierceAttackAbility.cpp
#include "ArmorPierceAttackAbility.h"
#include "Player.h" // Player::GetLevel(), Player::GetAttack() ���
#include "Monster.h" // Monster::TakeDamage() ���
#include <iostream>

ArmorPierceAttackAbility::ArmorPierceAttackAbility()
    : SpecialAbility("���� ������", "���� �� �����ϰ� ������ ���ظ� �����ϴ�.", 3) {
} // �̸�, ����, ��ٿ�

void ArmorPierceAttackAbility::use(Player& user, Monster& target) {
    if (isOnCooldown()) {
        std::cout << getName() << "��(��) ���� ��ٿ� ���Դϴ�! (" << getCurrentCooldown() << "�� ����)" << std::endl;
        return;
    }

    std::cout << user.GetName() << "(��)�� " << getName() << "(��)�� ����մϴ�! " << target.GetName() << "(�� �� ���õǾ����ϴ�!" << std::endl;

    int baseDamage = calculateEffectValue(user.GetLevel()); // �÷��̾� ������ ���� �⺻ ���ط� ���
    target.TakeDamage(baseDamage); // ���Ϳ��� ���� ���� (���� ��� ����)

    currentCooldown = cooldown; // ��ٿ� ����
}

// �÷��̾� ������ ���� ���� ���� ���ط� ��� (����: �⺻ 30 + ������ 5)
int ArmorPierceAttackAbility::calculateEffectValue(int playerLevel) const {
    return 30 + (playerLevel * 5); // ���� 1: 35, ���� 5: 55 (����)
}
