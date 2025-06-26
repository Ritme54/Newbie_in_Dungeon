// BossMonster.cpp (수정)
#include "BossMonster.h"
#include <iostream>
#include <random> // 랜덤 행동 선택용
#include "Player.h" // Player::TakeDamage() 등
#include "SpecialAbility.h" // SpecialAbility 클래스 정의 포함

extern std::mt19937 rng; // 전역 rng 사용

BossMonster::BossMonster(std::string name, int hp, int attack, int defense, int expGiven)
    : Monster(name, hp, attack, defense, expGiven),
    bossSpecialAbility(nullptr) // 특수능력 초기화
{
    std::cout << "강력한 보스 " << GetName() << "(이)가 생성되었습니다." << std::endl;
}

// 보스 몬스터의 특수능력을 설정하는 함수
void BossMonster::setBossSpecialAbility(std::unique_ptr<SpecialAbility> ability) {
    bossSpecialAbility = std::move(ability);
}

// PerformTurnAction 함수 재정의 (보스 몬스터의 턴 행동)
void BossMonster::PerformTurnAction(Player& targetPlayer) {
    ResetTurnState(); // 턴 시작 시 상태 초기화

    if (IsStunned()) { // 기절 상태면 행동 스킵
        std::cout << GetName() << " (이)가 기절하여 아무것도 할 수 없습니다!" << std::endl;
        return;
    }
    TakeBleedDamage(); // 출혈 피해 적용

    if (!IsAlive()) return; // 출혈로 죽었으면 행동 스킵

    // 보스 몬스터의 행동 선택 (예시: 일반 공격 50%, 방어 20%, 강공격 10%, 특수능력 20%)
    // 특수능력이 쿨다운 중이면 다른 행동을 선택하도록 로직 추가
    std::uniform_int_distribution<int> dist(1, 100);
    int actionChoice = dist(rng);

    if (bossSpecialAbility && bossSpecialAbility->isOnCooldown()) {
        // 특수능력이 쿨다운 중이면, 특수능력 선택 확률을 다른 행동으로 분배
        // 예시: 특수능력 확률(20%)을 일반 공격(10%)과 방어(10%)에 분배
        if (actionChoice <= 60) { // 1-60 (60%)
            Attack(targetPlayer);
        }
        else if (actionChoice <= 80) { // 61-80 (20%)
            Defend();
        }
        else { // 81-100 (20%)
            StrongAttack(targetPlayer);
        }
    }
    else {
        // 특수능력 사용 가능
        if (actionChoice <= 50) { // 1-50 (50%)
            Attack(targetPlayer);
        }
        else if (actionChoice <= 70) { // 51-70 (20%)
            Defend();
        }
        else if (actionChoice <= 80) { // 71-80 (10%)
            StrongAttack(targetPlayer);
        }
        else { // 81-100 (20%)
            bossSpecialAbility->use(*this, targetPlayer); // 보스 몬스터가 자신을 user로, 플레이어를 target으로 사용
        }
    }
    // 쿨다운 감소는 SpecialAbility::decreaseCooldown()에서 처리
    if (bossSpecialAbility) {
        bossSpecialAbility->decreaseCooldown(); // 턴 종료 시 쿨다운 감소
    }
}
