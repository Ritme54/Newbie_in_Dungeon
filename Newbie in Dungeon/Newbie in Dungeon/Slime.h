#pragma once
#include <string>

#include "Monster.h"
class Slime : public Monster
{
public:
	Slime();
    // Monster Ŭ������ ���� �Լ����� ������ (override)
    std::string getDefeatMessage() const override;
    void StrongAttack(Player& targetPlayer) override; // ������
    void Defend() override;                           // ���
   // void PerformTurnAction(Player& targetPlayer) override; // ������ �� �ൿ (���� ����: ���ͺ� Ȯ�� ���� ��)
    std::string GetActionPredictionMessage() const override; //
};

