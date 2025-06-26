// BleedAbility.h
#pragma once
#include "SpecialAbility.h"

class BleedAbility : public SpecialAbility {
public:
    BleedAbility();
    void use(Player& user, Monster& target) override;
    int calculateEffectValue(int playerLevel) const override; // �� �Լ��� ���ط� ���
    int calculateDuration(int playerLevel) const; // ���� ���� �� ���
};
