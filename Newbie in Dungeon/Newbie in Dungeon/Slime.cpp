#include "Slime.h"
#include <iostream>
#include "Monster.h"
#include "Player.h" // Player 클래스 포함


Slime::Slime() : Monster("녹색 슬라임", 20, 7, 3, 10)
{
	std::cout << "녹색 슬라임이 나타났다." << std::endl;
}

std::string Slime::getDefeatMessage() const
{
	return GetName() + "(이)가 젤리처럼 녹아내리며 쓰러졌습니다!";
}

// 강공격 구현
void Slime::StrongAttack(Player& targetPlayer) 
{ // override 키워드 추가
    // 슬라임 고유의 강공격 메시지
    std::cout << GetName() << " (이)가 몸을 크게 부풀려 강력한 돌진 공격을 합니다!" << std::endl;

    // 슬라임 고유의 강공격 수치 (예: 기본 공격력의 2배)
    int damage = static_cast<int>(GetAttack() * 2.0) - targetPlayer.GetDefense();
    if (damage < 0) damage = 0;
    targetPlayer.TakeDamage(damage);
}

// 방어 구현
void Slime::Defend() 
{ // override 키워드 추가
    // 슬라임 고유의 방어 메시지
    std::cout << GetName() << " 의 액체때문에 재대로 공격이 들어가지 않았다..." << std::endl;

    // Monster::Defend()의 공통 로직 호출
    // isDefending = true; // Monster::Defend()에서 처리되므로 여기서는 직접 설정하지 않습니다.
    Monster::Defend(); // Monster의 Defend 함수를 명시적으로 호출
}
std::string Slime::GetActionPredictionMessage() const  {
    switch (nextAction) { // nextAction은 Monster의 protected 멤버이므로 접근 가능
    case MonsterAction::ATTACK:
        return GetName() + " (이)가 끈적한 몸을 흔들며 다가옵니다!";
    case MonsterAction::DEFEND:
        return GetName() + " (이)가 몸을 웅크리고 끈적한 액체를 분비합니다!";
    case MonsterAction::STRONG_ATTACK:
        return GetName() + " (이)가 몸을 크게 부풀립니다!";
    case MonsterAction::NONE:
        return GetName() + " (이)가 멍하니 있습니다.";
    default:
        return Monster::GetActionPredictionMessage(); // 기본 Monster 클래스의 메시지 사용 (혹시 모를 경우)
    }
}


