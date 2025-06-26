// BossSpecialAbility.cpp
#include "BossSpecialAbility.h"

BossSpecialAbility::BossSpecialAbility(std::string name, std::string description, int cooldown)
    : name(name), description(description), cooldown(cooldown), currentCooldown(0) {
}

void BossSpecialAbility::decreaseCooldown() {
    if (currentCooldown > 0) {
        currentCooldown--;
    }
}
