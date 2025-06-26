#include "SpBoss1f.h"
#include "Player.h"
#include "Monster.h"
#include <iostream>

SpBoss1f::SpBoss1f()
    : BossSpecialAbility("슬라임 폭발", "자신의 몸을 폭발시켜 플레이어에게 광역 피해를 입힙니다.", 4) {
}

void SpBoss1f::use(Monster& user, Player& target) { // <-- user는 Monster, target은 Player
    if (isOnCooldown()) {
        std::cout << getName() << "은(는) 아직 쿨다운 중입니다! (" << getCurrentCooldown() << "턴 남음)" << std::endl;
        return;
    }
    std::cout << user.GetName() << "(이)가 몸을 부풀리며 슬라임 폭발을 준비합니다!" << std::endl;
    int damage = getFixedEffectValue(); // <-- 고정 효과 값 사용
    target.TakeDamage(damage); // 플레이어에게 피해
    currentCooldown = cooldown;
}

int SpBoss1f::getFixedEffectValue() const {
    return 15; // 항상 50의 피해를 줍니다.
}