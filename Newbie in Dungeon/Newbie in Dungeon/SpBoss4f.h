#pragma once
#include "BossSpecialAbility.h"
class SpBoss4f :
    public BossSpecialAbility
{
public:
	SpBoss4f();
	void use(Monster& user, Player& target) override;
	int getFixedEffectValue() const override { return 0; } // ������ ������ ���� ȿ�� �� ��ȯ

};

