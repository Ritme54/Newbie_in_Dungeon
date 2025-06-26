// BleedAbility.cpp
#include "BleedAbility.h"
#include "Player.h" // Player::GetLevel() 사용
#include "Monster.h" // Monster::ApplyBleed() 사용
#include <iostream>

BleedAbility::BleedAbility()
    : PlayerSpecialAbility("출혈", "적에게 턴당 지속 피해를 입힙니다.", 4) {
} // 이름, 설명, 쿨다운

void BleedAbility::use(Player& user, Monster& target) {
    if (isOnCooldown()) {
        std::cout << getName() << "은(는) 아직 쿨다운 중입니다! (" << getCurrentCooldown() << "턴 남음)" << std::endl;
        return;
    }

    std::cout << user.GetName() << "(이)가 " << getName() << "(을)를 사용합니다! " << target.GetName() << "(이)가 출혈 상태에 빠졌습니다!" << std::endl;

    int bleedDamage = calculateEffectValue(user.GetLevel()); // 플레이어 레벨에 따라 턴당 피해량 계산
    int bleedDuration = calculateDuration(user.GetLevel()); // 플레이어 레벨에 따라 지속 턴 계산
    target.ApplyBleed(bleedDamage, bleedDuration); // 몬스터에게 출혈 상태 적용 (Monster 클래스에 ApplyBleed 함수 필요)

    currentCooldown = cooldown; // 쿨다운 적용
}

// 플레이어 레벨에 따라 출혈 턴당 피해량 계산 (예시: 기본 5 + 레벨당 2)
int BleedAbility::calculateEffectValue(int playerLevel) const {
    return 5 + (playerLevel * 2); // 레벨 1: 7, 레벨 5: 15 (예시)
}

// 플레이어 레벨에 따라 출혈 지속 턴 계산 (예시: 기본 2 + 레벨 3당 1턴, 최대 4턴)
int BleedAbility::calculateDuration(int playerLevel) const {
    return std::min(2 + (playerLevel / 3), 4); // 레벨 1-2: 2턴, 레벨 3-5: 3턴, 레벨 6+: 4턴 (예시)
}
