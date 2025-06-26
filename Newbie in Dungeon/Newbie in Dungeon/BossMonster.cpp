// BossMonster.cpp (����)
#include "BossMonster.h"
#include <iostream>
#include <random> // ���� �ൿ ���ÿ�
#include "Player.h" // Player::TakeDamage() ��
#include "SpecialAbility.h" // SpecialAbility Ŭ���� ���� ����

extern std::mt19937 rng; // ���� rng ���

BossMonster::BossMonster(std::string name, int hp, int attack, int defense, int expGiven)
    : Monster(name, hp, attack, defense, expGiven),
    bossSpecialAbility(nullptr) // Ư���ɷ� �ʱ�ȭ
{
    std::cout << "������ ���� " << GetName() << "(��)�� �����Ǿ����ϴ�." << std::endl;
}

// ���� ������ Ư���ɷ��� �����ϴ� �Լ�
void BossMonster::setBossSpecialAbility(std::unique_ptr<SpecialAbility> ability) {
    bossSpecialAbility = std::move(ability);
}

// PerformTurnAction �Լ� ������ (���� ������ �� �ൿ)
void BossMonster::PerformTurnAction(Player& targetPlayer) {
    ResetTurnState(); // �� ���� �� ���� �ʱ�ȭ

    if (IsStunned()) { // ���� ���¸� �ൿ ��ŵ
        std::cout << GetName() << " (��)�� �����Ͽ� �ƹ��͵� �� �� �����ϴ�!" << std::endl;
        return;
    }
    TakeBleedDamage(); // ���� ���� ����

    if (!IsAlive()) return; // ������ �׾����� �ൿ ��ŵ

    // ���� ������ �ൿ ���� (����: �Ϲ� ���� 50%, ��� 20%, ������ 10%, Ư���ɷ� 20%)
    // Ư���ɷ��� ��ٿ� ���̸� �ٸ� �ൿ�� �����ϵ��� ���� �߰�
    std::uniform_int_distribution<int> dist(1, 100);
    int actionChoice = dist(rng);

    if (bossSpecialAbility && bossSpecialAbility->isOnCooldown()) {
        // Ư���ɷ��� ��ٿ� ���̸�, Ư���ɷ� ���� Ȯ���� �ٸ� �ൿ���� �й�
        // ����: Ư���ɷ� Ȯ��(20%)�� �Ϲ� ����(10%)�� ���(10%)�� �й�
        if (actionChoice <= 60) { // 1-60 (60%)
            Attack(targetPlayer);
        }
        else if (actionChoice <= 80) { // 61-80 (20%)
            Defend();
        }
        else { // 81-100 (20%)
            StrongAttack(targetPlayer);
        }
    }
    else {
        // Ư���ɷ� ��� ����
        if (actionChoice <= 50) { // 1-50 (50%)
            Attack(targetPlayer);
        }
        else if (actionChoice <= 70) { // 51-70 (20%)
            Defend();
        }
        else if (actionChoice <= 80) { // 71-80 (10%)
            StrongAttack(targetPlayer);
        }
        else { // 81-100 (20%)
            bossSpecialAbility->use(*this, targetPlayer); // ���� ���Ͱ� �ڽ��� user��, �÷��̾ target���� ���
        }
    }
    // ��ٿ� ���Ҵ� SpecialAbility::decreaseCooldown()���� ó��
    if (bossSpecialAbility) {
        bossSpecialAbility->decreaseCooldown(); // �� ���� �� ��ٿ� ����
    }
}
