// StunAbility.cpp
#include "StunAbility.h"
#include "Player.h" // Player::GetLevel() ���
#include "Monster.h" // Monster::ApplyStun() ���
#include <iostream>

StunAbility::StunAbility()
    : PlayerSpecialAbility("Ȯ�� ����", "���� �������� ���� ���� ��ŵ��ŵ�ϴ�.", 5) {
} // �̸�, ����, ��ٿ�

void StunAbility::use(Player& user, Monster& target) {
    if (isOnCooldown()) {
        std::cout << getName() << "��(��) ���� ��ٿ� ���Դϴ�! (" << getCurrentCooldown() << "�� ����)" << std::endl;
        return;
    }

    std::cout << user.GetName() << "(��)�� " << getName() << "(��)�� ����մϴ�! " << target.GetName() << "(��)�� �����߽��ϴ�!" << std::endl;

    int stunDuration = calculateEffectValue(user.GetLevel()); // �÷��̾� ������ ���� ���� ���� �ð� ���
    target.ApplyStun(stunDuration); // ���Ϳ��� ���� ���� ���� (Monster Ŭ������ ApplyStun �Լ� �ʿ�)

    currentCooldown = cooldown; // ��ٿ� ����
}

// �÷��̾� ������ ���� ���� ���� �ð� ��� (����: ���� 1�� 1��, �ִ� 2��)
int StunAbility::calculateEffectValue(int playerLevel) const {
    return std::min(1 + (playerLevel / 5), 2); // ���� 1-4: 1��, ���� 5-9: 2�� (����)
}
