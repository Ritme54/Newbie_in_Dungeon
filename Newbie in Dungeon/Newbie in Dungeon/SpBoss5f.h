#pragma once
#include "BossSpecialAbility.h"
class SpBoss5f :
    public BossSpecialAbility
{
public:
	SpBoss5f();
	void use(Monster& user, Player& target) override;
	int getFixedEffectValue() const override { return 0; } // ������ ������ ���� ȿ�� �� ��ȯ

};

