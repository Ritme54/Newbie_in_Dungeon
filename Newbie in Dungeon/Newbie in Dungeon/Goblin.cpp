#include "Goblin.h"
#include <iostream>
#include "Monster.h"
#include "Player.h" // Player 클래스 포함



using namespace std;


Goblin::Goblin() : Monster("고블린",10,10,10,10)//이후 수정
{
	std::cout << "고블린이 어슬렁거리며 나타났다!" << std::endl;

}

std::string Goblin::getDefeatMessage() const 
{
	return GetName() + "(이)가 몽둥이를 놓치며 비명을 지르고 쓰러졌습니다!";
}

// 강공격 구현
void Goblin::StrongAttack(Player& targetPlayer)
{ // override 키워드 추가
    // 고블린 고유의 강공격 메시지
    std::cout << GetName() << "에게 강하게 맞았다. " << std::endl;

    // 고블린 고유의 강공격 수치 (예: 기본 공격력의 2배)
    int damage = static_cast<int>(GetAttack() * 2.0) - targetPlayer.GetDefense();
    if (damage < 0) damage = 0;
    targetPlayer.TakeDamage(damage);
}

// 방어 구현
void Goblin::Defend() 
{ // override 키워드 추가
    // 고블린 고유의 방어 메시지
    std::cout << GetName() << " (이)가 반대 팔로 막았다." << std::endl;

    // Monster::Defend()의 공통 로직 호출
    // isDefending = true; // Monster::Defend()에서 처리되므로 여기서는 직접 설정하지 않습니다.
    Monster::Defend(); // Monster의 Defend 함수를 명시적으로 호출
}


std::string Goblin::GetActionPredictionMessage() const {
    switch (nextAction) { // nextAction은 Monster의 protected 멤버이므로 접근 가능
    case MonsterAction::ATTACK:
        return GetName() + " (이)가 노려봅니다!";
    case MonsterAction::DEFEND:
        return GetName() + "(이)가 경계하고 있다.";
    case MonsterAction::STRONG_ATTACK:
        return GetName() + " (이)가 몽둥이를 하늘로 치켜들며 달려온다!";
    case MonsterAction::NONE:
        return GetName() + " (이)가 멍하니 있습니다.";
    default:
        return Monster::GetActionPredictionMessage(); // 기본 Monster 클래스의 메시지 사용 (혹시 모를 경우)
    }
}