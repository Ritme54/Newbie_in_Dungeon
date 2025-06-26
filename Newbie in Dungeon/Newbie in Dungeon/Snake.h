#pragma once
#include "Monster.h"
class Snake : public Monster
{

public:
	Snake();
	std::string getDefeatMessage() const override;
	void StrongAttack(Player& targetPlayer) override; // ������
	void Defend() override;                           // ���
	// void PerformTurnAction(Player& targetPlayer) override; // ������ �� �ൿ (���� ����: ���ͺ� Ȯ�� ���� ��)
	std::string GetActionPredictionMessage() const override; //
};

