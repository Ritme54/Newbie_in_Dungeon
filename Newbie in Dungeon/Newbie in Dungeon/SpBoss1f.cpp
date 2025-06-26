#include "SpBoss1f.h"
#include "Player.h"
#include "Monster.h"
#include <iostream>

SpBoss1f::SpBoss1f()
    : BossSpecialAbility("������ ����", "�ڽ��� ���� ���߽��� �÷��̾�� ���� ���ظ� �����ϴ�.", 4) {
}

void SpBoss1f::use(Monster& user, Player& target) { // <-- user�� Monster, target�� Player
    if (isOnCooldown()) {
        std::cout << getName() << "��(��) ���� ��ٿ� ���Դϴ�! (" << getCurrentCooldown() << "�� ����)" << std::endl;
        return;
    }
    std::cout << user.GetName() << "(��)�� ���� ��Ǯ���� ������ ������ �غ��մϴ�!" << std::endl;
    int damage = getFixedEffectValue(); // <-- ���� ȿ�� �� ���
    target.TakeDamage(damage); // �÷��̾�� ����
    currentCooldown = cooldown;
}

int SpBoss1f::getFixedEffectValue() const {
    return 15; // �׻� 50�� ���ظ� �ݴϴ�.
}