#pragma once
#include "BossSpecialAbility.h"
class SpBoss3f :
    public BossSpecialAbility
{
public:
	SpBoss3f();
	void use(Monster& user, Player& target) override;
	int getFixedEffectValue() const override { return 0; } // ������ ������ ���� ȿ�� �� ��ȯ

};

