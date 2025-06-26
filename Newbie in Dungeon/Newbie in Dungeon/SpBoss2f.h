#pragma once
#include "BossSpecialAbility.h"
class SpBoss2f :
    public BossSpecialAbility
{

private:
	const int minNumAttacks;   // 최소 공격 횟수
	const int maxNumAttacks;   // 최대 공격 횟수
	const int damagePerAttack; // 1회 공격당 피해량
public:
	SpBoss2f();
	void use(Monster& user, Player& target) override;
	int getFixedEffectValue() const override { return 0; } // 레벨과 무관한 고정 효과 값 반환

};

