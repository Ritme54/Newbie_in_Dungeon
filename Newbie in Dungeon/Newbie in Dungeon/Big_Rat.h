#pragma once
#include "Monster.h"
class Big_Rat : public Monster
{

public:
	Big_Rat();
	std::string getDefeatMessage() const override;
	void StrongAttack(Player& targetPlayer) override; // ������
	void Defend() override;                           // ���
	// void PerformTurnAction(Player& targetPlayer) override; // ������ �� �ൿ (���� ����: ���ͺ� Ȯ�� ���� ��)
	std::string GetActionPredictionMessage() const override; //
};

