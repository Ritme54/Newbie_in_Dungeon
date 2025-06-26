
#pragma once
#include "Monster.h" // Monster Ŭ������ ��ӹ����Ƿ� ����
#include <string>
#include <memory> // std::unique_ptr ���
#include "BossSpecialAbility.h" // BossSpecialAbility Ŭ���� ����



class BossMonster : public Monster {
private:
    std::unique_ptr<BossSpecialAbility> bossSpecialAbility; // ���� ������ ���� Ư���ɷ�
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

    // Monster�� PerformTurnAction �Լ� ������ (���� ������ �� �ൿ)
    void PerformTurnAction(Player& targetPlayer) override;

    // ���� ������ Ư���ɷ��� �����ϴ� �Լ�
    void setBossSpecialAbility(std::unique_ptr<BossSpecialAbility> ability);


    // �Ҹ��� (Monster �Ҹ��ڰ� virtual�̹Ƿ� override ����)
    virtual ~BossMonster() = default;
};