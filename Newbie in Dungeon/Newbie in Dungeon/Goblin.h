#pragma once
#include "Monster.h"
class Goblin : public Monster
{
public:
	Goblin();

	std::string getDefeatMessage() const override;
	void StrongAttack(Player& targetPlayer) override; // ������
	void Defend() override;                           // ���
	// void PerformTurnAction(Player& targetPlayer) override; // ������ �� �ൿ (���� ����: ���ͺ� Ȯ�� ���� ��)
	std::string GetActionPredictionMessage() const override; //
};

