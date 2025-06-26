// ArmorPierceAttackAbility.h
#pragma once
#include "SpecialAbility.h"

class ArmorPierceAttackAbility : public SpecialAbility {
public:
    ArmorPierceAttackAbility();
    void use(Player& user, Monster& target) override;
    int calculateEffectValue(int playerLevel) const override;
};
