#pragma once
#include "Monster.h"
class Goblin : public Monster
{
public:
	Goblin();

	std::string getDefeatMessage() const override;
	void StrongAttack(Player& targetPlayer) override; // 강공격
	void Defend() override;                           // 방어
	// void PerformTurnAction(Player& targetPlayer) override; // 몬스터의 턴 행동 (선택 사항: 몬스터별 확률 조절 시)
	std::string GetActionPredictionMessage() const override; //
};

