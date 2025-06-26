#pragma once
#include "BossSpecialAbility.h"
class SpBoss3f :
    public BossSpecialAbility
{
public:
	SpBoss3f();
	void use(Monster& user, Player& target) override;
	int getFixedEffectValue() const override { return 0; } // 레벨과 무관한 고정 효과 값 반환

};

