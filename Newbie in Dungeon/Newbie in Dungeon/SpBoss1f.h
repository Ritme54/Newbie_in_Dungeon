#pragma once
#include "BossSpecialAbility.h"
class SpBoss1f : public BossSpecialAbility
{
public:
	SpBoss1f();
	void use(Monster& user, Player& target) override;
	int getFixedEffectValue() const override { return 0; } // ������ ������ ���� ȿ�� �� ��ȯ


};

