#pragma once
#include "BossSpecialAbility.h"
class SpBoss2f :
    public BossSpecialAbility
{

private:
	const int minNumAttacks;   // �ּ� ���� Ƚ��
	const int maxNumAttacks;   // �ִ� ���� Ƚ��
	const int damagePerAttack; // 1ȸ ���ݴ� ���ط�
public:
	SpBoss2f();
	void use(Monster& user, Player& target) override;
	int getFixedEffectValue() const override { return 0; } // ������ ������ ���� ȿ�� �� ��ȯ

};

