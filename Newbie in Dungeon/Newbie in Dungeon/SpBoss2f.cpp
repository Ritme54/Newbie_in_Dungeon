// SpBoss2f.cpp (수정)
#include "SpBoss2f.h"
#include "Monster.h" // user (몬스터)의 정보 사용
#include "Player.h"  // target (플레이어)에게 피해 입힘
#include <iostream>  // 메시지 출력
#include <random>    // std::uniform_int_distribution 사용

// 전역 rng 선언 (main.cpp에 정의되어 있다고 가정)
extern std::mt19937 rng;

SpBoss2f::SpBoss2f()
    : BossSpecialAbility("쥐떼의 습격", "쥐 수십마리를 소환해서 물어 뜯게 한다.", 4), // 이름, 설명, 쿨다운 4턴
    minNumAttacks(3),    // 최소 공격 횟수
    maxNumAttacks(7),    // 최대 공격 횟수
    damagePerAttack(10)  // 쥐 1마리당 10의 피해
{
    // 생성자 본체
}

void SpBoss2f::use(Monster& user, Player& target) {
    if (isOnCooldown()) {
        std::cout << getName() << "은(는) 아직 쿨다운 중입니다! (" << getCurrentCooldown() << "턴 남음)" << std::endl;
        return;
    }

    // --- numAttacks를 범위 내에서 랜덤으로 결정 ---
    std::uniform_int_distribution<int> dist(minNumAttacks, maxNumAttacks);
    int actualNumAttacks = dist(rng); // 실제 공격 횟수

    std::cout << user.GetName() << " (이)가 찍찍거리며 부하들을 불러옵니다!" << std::endl; // 가독성 개선
    std::cout << "쥐 " << actualNumAttacks << "마리가 " << target.GetName() << " (을)를 덮쳐 물어뜯기 시작합니다!" << std::endl; // 가독성 개선

    for (int i = 0; i < actualNumAttacks; ++i) { // 실제 공격 횟수 사용
        if (!target.IsAlive()) { // 플레이어가 중간에 쓰러지면 중단
            std::cout << target.GetName() << " (이)가 더 이상 버티지 못했습니다." << std::endl; // 가독성 개선
            break;
        }
        std::cout << " - 쥐 한 마리가 " << target.GetName() << " (을)를 물어뜯어 " << damagePerAttack << "의 피해를 입혔습니다." << std::endl; // 가독성 개선
        target.TakeDamage(damagePerAttack); // 플레이어에게 피해 입힘
    }

    currentCooldown = cooldown; // 쿨다운 적용
}

// 이 특수능력의 고정 효과 값 (여기서는 총 피해량의 평균값)
int SpBoss2f::getFixedEffectValue() const {
    // 평균 공격 횟수를 기준으로 총 피해량 반환
    return ((minNumAttacks + maxNumAttacks) / 2) * damagePerAttack;
}
