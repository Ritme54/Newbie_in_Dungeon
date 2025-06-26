// StunAbility.cpp
#include "StunAbility.h"
#include "Player.h" // Player::GetLevel() 사용
#include "Monster.h" // Monster::ApplyStun() 사용
#include <iostream>

StunAbility::StunAbility()
    : PlayerSpecialAbility("확정 기절", "적을 기절시켜 다음 턴을 스킵시킵니다.", 5) {
} // 이름, 설명, 쿨다운

void StunAbility::use(Player& user, Monster& target) {
    if (isOnCooldown()) {
        std::cout << getName() << "은(는) 아직 쿨다운 중입니다! (" << getCurrentCooldown() << "턴 남음)" << std::endl;
        return;
    }

    std::cout << user.GetName() << "(이)가 " << getName() << "(을)를 사용합니다! " << target.GetName() << "(이)가 기절했습니다!" << std::endl;

    int stunDuration = calculateEffectValue(user.GetLevel()); // 플레이어 레벨에 따라 기절 지속 시간 계산
    target.ApplyStun(stunDuration); // 몬스터에게 기절 상태 적용 (Monster 클래스에 ApplyStun 함수 필요)

    currentCooldown = cooldown; // 쿨다운 적용
}

// 플레이어 레벨에 따라 기절 지속 시간 계산 (예시: 레벨 1당 1턴, 최대 2턴)
int StunAbility::calculateEffectValue(int playerLevel) const {
    return std::min(1 + (playerLevel / 5), 2); // 레벨 1-4: 1턴, 레벨 5-9: 2턴 (예시)
}
