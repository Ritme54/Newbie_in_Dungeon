// ArmorPierceAttackAbility.cpp
#include "ArmorPierceAttackAbility.h"
#include "Player.h" // Player::GetLevel(), Player::GetAttack() 사용
#include "Monster.h" // Monster::TakeDamage() 사용
#include <iostream>

ArmorPierceAttackAbility::ArmorPierceAttackAbility()
    : SpecialAbility("방어무시 강공격", "적의 방어를 무시하고 강력한 피해를 입힙니다.", 3) {
} // 이름, 설명, 쿨다운

void ArmorPierceAttackAbility::use(Player& user, Monster& target) {
    if (isOnCooldown()) {
        std::cout << getName() << "은(는) 아직 쿨다운 중입니다! (" << getCurrentCooldown() << "턴 남음)" << std::endl;
        return;
    }

    std::cout << user.GetName() << "(이)가 " << getName() << "(을)를 사용합니다! " << target.GetName() << "(의 방어가 무시되었습니다!" << std::endl;

    int baseDamage = calculateEffectValue(user.GetLevel()); // 플레이어 레벨에 따라 기본 피해량 계산
    target.TakeDamage(baseDamage); // 몬스터에게 피해 적용 (방어력 계산 없이)

    currentCooldown = cooldown; // 쿨다운 적용
}

// 플레이어 레벨에 따라 방어무시 공격 피해량 계산 (예시: 기본 30 + 레벨당 5)
int ArmorPierceAttackAbility::calculateEffectValue(int playerLevel) const {
    return 30 + (playerLevel * 5); // 레벨 1: 35, 레벨 5: 55 (예시)
}
