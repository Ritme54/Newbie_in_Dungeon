
#pragma once
#include "Monster.h" // Monster Ŭ������ ��ӹ����Ƿ� ����
#include <string>


class BossMonster : public Monster {
public:
    // ������: Monster �����ڸ� ȣ���Ͽ� �⺻ �Ӽ� �ʱ�ȭ
    // ���� ���ʹ� �̸�, ü��, ���ݷ� ���� �Ϲ� ���ͺ��� �ξ� ���� ���Դϴ�.
    BossMonster(std::string name, int hp, int attack, int defense, int expGiven);

    // ���� ���͸��� Ư���� �ൿ�̳� ������ �����ϴ� ���� �Լ�
    // ��: Ư�� ü�� ���Ϸ� �������� ������ ��ȯ
    virtual void activateSpecialPhase() = 0; // ���� ���� �Լ��� ����� BossMonster�� �߻� Ŭ����

    // Monster Ŭ������ ���� �Լ��� �������Ͽ� ���� ���͸��� Ư���� �ο��� ���� �ֽ��ϴ�.
    // ��: ���� ���ʹ� �Ϲ� ���ͺ��� �� ������ ���� �޽����� ���
    void Attack(Player& targetPlayer) override;

    // �Ҹ��� (Monster �Ҹ��ڰ� virtual�̹Ƿ� override ����)
    virtual ~BossMonster() = default;
};