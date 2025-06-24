// BossMonster.cpp
#include "BossMonster.h"
#include <iostream>
#include "Player.h" // Attack 함수에서 Player를 사용하므로

// BossMonster 생성자: 기반 클래스 Monster의 생성자를 호출
BossMonster::BossMonster(std::string name, int hp, int attack, int defense, int expGiven)
    : Monster(name, hp, attack, defense, expGiven) {
    // BossMonster 고유의 초기화 로직 (필요하다면)
}

// Attack 함수 재정의 (예시: 보스 몬스터는 더 위협적인 메시지)
void BossMonster::Attack(Player& targetPlayer) {
    // Monster::Attack(targetPlayer); // 기반 클래스의 Attack 로직을 그대로 사용하고 싶다면
    if (!IsAlive()) return;

    std::cout << GetName() << "(이)가 강력한 공격을 시도합니다!" << std::endl;

    int damage = GetAttack() - targetPlayer.GetDefense();
    if (damage < 0) damage = 0;

    targetPlayer.TakeDamage(damage);
}