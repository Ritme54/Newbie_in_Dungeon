#include "Big_Rat.h"
#include <iostream>
#include "Monster.h"
#include "Player.h" // Player 클래스 포함


using namespace std;

Big_Rat::Big_Rat() : Monster("큰 쥐", 30, 9, 4, 15)
{
	std::cout << "큰 쥐가 튀어나왔다!" << std::endl;
}

std::string Big_Rat::getDefeatMessage() const // <-- const 키워드 확인
{
	return GetName() + " 큰 쥐가 비명을 지르며 쓰러졌다!"; // 오타 수정: 쓰러젔다 -> 쓰러졌다
}

// 강공격 구현
void Big_Rat::StrongAttack(Player& targetPlayer)
{ // override 키워드 추가
    // 큰 쥐 고유의 강공격 메시지
    std::cout << GetName() << " (이)가 날카로운 이빨로 물어뜯었다!" << std::endl;

    // 큰 쥐 고유의 강공격 수치 (예: 기본 공격력의 2배)
    int damage = static_cast<int>(GetAttack() * 2.0) - targetPlayer.GetDefense();
    if (damage < 0) damage = 0;
    targetPlayer.TakeDamage(damage);
}

// 방어 구현
void Big_Rat::Defend()
{ // override 키워드 추가
    // 큰 쥐 고유의 방어 메시지
    std::cout << GetName() << " (이)가 저자세로 공격을 받아냈다." << std::endl;

    // Monster::Defend()의 공통 로직 호출
    // isDefending = true; // Monster::Defend()에서 처리되므로 여기서는 직접 설정하지 않습니다.
    Monster::Defend(); // Monster의 Defend 함수를 명시적으로 호출
}
std::string Big_Rat::GetActionPredictionMessage() const {
    switch (nextAction) { // nextAction은 Monster의 protected 멤버이므로 접근 가능
    case MonsterAction::ATTACK:
        return GetName() + " (이)가 끈적한 몸을 흔들며 다가옵니다!";
    case MonsterAction::DEFEND:
        return GetName() + " (이)가 몸을 웅크리고 끈적한 액체를 분비합니다!";
    case MonsterAction::STRONG_ATTACK:
        return GetName() + "  (이)가 날카로운 이빨을 들이밀며 뛰어오른다!";
    case MonsterAction::NONE:
        return GetName() + " (이)가 멍하니 있습니다.";
    default:
        return Monster::GetActionPredictionMessage(); // 기본 Monster 클래스의 메시지 사용 (혹시 모를 경우)
    }
}