// BleedAbility.h
#pragma once
#include "PlayerSpecialAbility.h"

class BleedAbility : public PlayerSpecialAbility {
public:
    BleedAbility();
    void use(Player& user, Monster& target) override;
    int calculateEffectValue(int playerLevel) const override; // �� �Լ��� ���ط� ���
    int calculateDuration(int playerLevel) const; // ���� ���� �� ���
};
