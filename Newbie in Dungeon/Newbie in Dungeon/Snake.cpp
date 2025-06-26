#include "Snake.h"
#include <iostream>
#include "Monster.h"
#include "Player.h"

using namespace std;

Snake::Snake() : Monster("구렁이", 35,15,6,25)//수치 수정할것
{
	std::cout << "구렁이가 바위틈에서 튀어나왔다!" << std::endl;
}

std::string Snake::getDefeatMessage() const 
{
	return GetName() + "구렁이가 쓰러졌습니다!";
}
// 강공격 구현
void Snake::StrongAttack(Player& targetPlayer)
{ // override 키워드 추가
    // 구렁이 고유의 강공격 메시지
    std::cout << GetName() << " (이)가 꼬리로 강하게 후려쳤다!" << std::endl;

    // 구렁이 고유의 강공격 수치 (예: 기본 공격력의 2배)
    int damage = static_cast<int>(GetAttack() * 2.0) - targetPlayer.GetDefense();
    if (damage < 0) damage = 0;
    targetPlayer.TakeDamage(damage);
}

// 방어 구현
void Snake::Defend()
{ // override 키워드 추가
    // 구렁이 고유의 방어 메시지
    std::cout << GetName() << " 에게 타격이 제대로 들어가지 않았다... " << std::endl;

    // Monster::Defend()의 공통 로직 호출
    // isDefending = true; // Monster::Defend()에서 처리되므로 여기서는 직접 설정하지 않습니다.
    Monster::Defend(); // Monster의 Defend 함수를 명시적으로 호출
}

std::string Snake::GetActionPredictionMessage() const  {
    switch (nextAction) { // nextAction은 Monster의 protected 멤버이므로 접근 가능
    case MonsterAction::ATTACK:
        return GetName() + " (이)가 바닥을 기며 다가옵니다!";
    case MonsterAction::DEFEND:
        return GetName() + " (이)가 똬리를 틀며 방어 자세를 취합니다!";
    case MonsterAction::STRONG_ATTACK:
        return GetName() + " (이)가 날렵하게 접근해옵니다!";
    case MonsterAction::NONE:
        return GetName() + " (이)가 멍하니 있습니다.";
    default:
        return Monster::GetActionPredictionMessage(); // 기본 Monster 클래스의 메시지 사용 (혹시 모를 경우)
    }
}