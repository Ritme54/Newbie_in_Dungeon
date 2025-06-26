// SpBoss2f.cpp (����)
#include "SpBoss2f.h"
#include "Monster.h" // user (����)�� ���� ���
#include "Player.h"  // target (�÷��̾�)���� ���� ����
#include <iostream>  // �޽��� ���
#include <random>    // std::uniform_int_distribution ���

// ���� rng ���� (main.cpp�� ���ǵǾ� �ִٰ� ����)
extern std::mt19937 rng;

SpBoss2f::SpBoss2f()
    : BossSpecialAbility("�㶼�� ����", "�� ���ʸ����� ��ȯ�ؼ� ���� ��� �Ѵ�.", 4), // �̸�, ����, ��ٿ� 4��
    minNumAttacks(3),    // �ּ� ���� Ƚ��
    maxNumAttacks(7),    // �ִ� ���� Ƚ��
    damagePerAttack(10)  // �� 1������ 10�� ����
{
    // ������ ��ü
}

void SpBoss2f::use(Monster& user, Player& target) {
    if (isOnCooldown()) {
        std::cout << getName() << "��(��) ���� ��ٿ� ���Դϴ�! (" << getCurrentCooldown() << "�� ����)" << std::endl;
        return;
    }

    // --- numAttacks�� ���� ������ �������� ���� ---
    std::uniform_int_distribution<int> dist(minNumAttacks, maxNumAttacks);
    int actualNumAttacks = dist(rng); // ���� ���� Ƚ��

    std::cout << user.GetName() << " (��)�� ����Ÿ��� ���ϵ��� �ҷ��ɴϴ�!" << std::endl; // ������ ����
    std::cout << "�� " << actualNumAttacks << "������ " << target.GetName() << " (��)�� ���� ������ �����մϴ�!" << std::endl; // ������ ����

    for (int i = 0; i < actualNumAttacks; ++i) { // ���� ���� Ƚ�� ���
        if (!target.IsAlive()) { // �÷��̾ �߰��� �������� �ߴ�
            std::cout << target.GetName() << " (��)�� �� �̻� ��Ƽ�� ���߽��ϴ�." << std::endl; // ������ ����
            break;
        }
        std::cout << " - �� �� ������ " << target.GetName() << " (��)�� ������ " << damagePerAttack << "�� ���ظ� �������ϴ�." << std::endl; // ������ ����
        target.TakeDamage(damagePerAttack); // �÷��̾�� ���� ����
    }

    currentCooldown = cooldown; // ��ٿ� ����
}

// �� Ư���ɷ��� ���� ȿ�� �� (���⼭�� �� ���ط��� ��հ�)
int SpBoss2f::getFixedEffectValue() const {
    // ��� ���� Ƚ���� �������� �� ���ط� ��ȯ
    return ((minNumAttacks + maxNumAttacks) / 2) * damagePerAttack;
}
