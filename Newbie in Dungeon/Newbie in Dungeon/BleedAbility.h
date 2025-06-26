// BleedAbility.h
#pragma once
#include "PlayerSpecialAbility.h"

class BleedAbility : public PlayerSpecialAbility {
public:
    BleedAbility();
    void use(Player& user, Monster& target) override;
    int calculateEffectValue(int playerLevel) const override; // 이 함수는 피해량 계산
    int calculateDuration(int playerLevel) const; // 출혈 지속 턴 계산
};
