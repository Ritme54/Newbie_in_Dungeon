// StunAbility.h
#pragma once
#include "SpecialAbility.h"

class StunAbility : public SpecialAbility {
public:
    StunAbility();
    // SpecialAbility�� use �Լ� ������
    void use(Player& user, Monster& target) override;
    // SpecialAbility�� calculateEffectValue �Լ� ������
    int calculateEffectValue(int playerLevel) const override;
};
