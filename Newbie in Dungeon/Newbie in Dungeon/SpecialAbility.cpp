// SpecialAbility.cpp
#include "SpecialAbility.h"

SpecialAbility::SpecialAbility(std::string name, std::string description, int cooldown)
    : name(name), description(description), cooldown(cooldown), currentCooldown(0) {
}

void SpecialAbility::decreaseCooldown() {
    if (currentCooldown > 0) {
        currentCooldown--;
    }
}
