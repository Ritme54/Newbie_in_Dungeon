// PlayerSpecialAbility.cpp
#include "PlayerSpecialAbility.h"

PlayerSpecialAbility::PlayerSpecialAbility(std::string name, std::string description, int cooldown)
    : name(name), description(description), cooldown(cooldown), currentCooldown(0) {
}

void PlayerSpecialAbility::decreaseCooldown() {
    if (currentCooldown > 0) {
        currentCooldown--;
    }
}
