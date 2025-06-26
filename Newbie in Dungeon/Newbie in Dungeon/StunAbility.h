// StunAbility.h
#pragma once
#include "PlayerSpecialAbility.h"

class StunAbility : public PlayerSpecialAbility {
public:
    StunAbility();
    // SpecialAbility의 use 함수 재정의
    void use(Player& user, Monster& target) override;
    // SpecialAbility의 calculateEffectValue 함수 재정의
    int calculateEffectValue(int playerLevel) const override;
};
