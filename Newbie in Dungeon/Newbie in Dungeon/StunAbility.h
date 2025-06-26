// StunAbility.h
#pragma once
#include "PlayerSpecialAbility.h"

class StunAbility : public PlayerSpecialAbility {
public:
    StunAbility();
    // SpecialAbility�� use �Լ� ������
    void use(Player& user, Monster& target) override;
    // SpecialAbility�� calculateEffectValue �Լ� ������
    int calculateEffectValue(int playerLevel) const override;
};
