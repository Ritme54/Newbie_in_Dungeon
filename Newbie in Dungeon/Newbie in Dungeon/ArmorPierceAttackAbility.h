// ArmorPierceAttackAbility.h
#pragma once
#include "PlayerSpecialAbility.h"

class ArmorPierceAttackAbility : public PlayerSpecialAbility {
public:
    ArmorPierceAttackAbility();
    void use(Player& user, Monster& target) override;
    int calculateEffectValue(int playerLevel) const override;
};
