// BleedAbility.cpp
#include "BleedAbility.h"
#include "Player.h" // Player::GetLevel() ���
#include "Monster.h" // Monster::ApplyBleed() ���
#include <iostream>

BleedAbility::BleedAbility()
    : PlayerSpecialAbility("����", "������ �ϴ� ���� ���ظ� �����ϴ�.", 4) {
} // �̸�, ����, ��ٿ�

void BleedAbility::use(Player& user, Monster& target) {
    if (isOnCooldown()) {
        std::cout << getName() << "��(��) ���� ��ٿ� ���Դϴ�! (" << getCurrentCooldown() << "�� ����)" << std::endl;
        return;
    }

    std::cout << user.GetName() << "(��)�� " << getName() << "(��)�� ����մϴ�! " << target.GetName() << "(��)�� ���� ���¿� �������ϴ�!" << std::endl;

    int bleedDamage = calculateEffectValue(user.GetLevel()); // �÷��̾� ������ ���� �ϴ� ���ط� ���
    int bleedDuration = calculateDuration(user.GetLevel()); // �÷��̾� ������ ���� ���� �� ���
    target.ApplyBleed(bleedDamage, bleedDuration); // ���Ϳ��� ���� ���� ���� (Monster Ŭ������ ApplyBleed �Լ� �ʿ�)

    currentCooldown = cooldown; // ��ٿ� ����
}

// �÷��̾� ������ ���� ���� �ϴ� ���ط� ��� (����: �⺻ 5 + ������ 2)
int BleedAbility::calculateEffectValue(int playerLevel) const {
    return 5 + (playerLevel * 2); // ���� 1: 7, ���� 5: 15 (����)
}

// �÷��̾� ������ ���� ���� ���� �� ��� (����: �⺻ 2 + ���� 3�� 1��, �ִ� 4��)
int BleedAbility::calculateDuration(int playerLevel) const {
    return std::min(2 + (playerLevel / 3), 4); // ���� 1-2: 2��, ���� 3-5: 3��, ���� 6+: 4�� (����)
}
