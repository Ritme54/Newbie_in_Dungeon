// Monster.h (수정)
#pragma once
#include <string>

class Player;

enum class MonsterAction {
    NONE,             // 아무것도 하지 않음 (초기값 또는 특정 상황)
    ATTACK,           // 일반 공격
    DEFEND,           // 방어
    STRONG_ATTACK,    // 강공격
    SPECIAL_ABILITY   // 특수능력 (보스 몬스터용)
};


class Monster
{
private:
    std::string name;
    int hp;          // 몬스터 체력
    int maxHp;       // 몬스터 최대 체력
    int attack;      // 공격력
    int defense;     // 방어력
    int expGiven;    // 드랍하는 경험치

    // --- 새로운 전투 상태 관련 멤버 변수 ---
    bool isDefending;          // 몬스터 방어 상태 여부
    bool isStunned;            // 몬스터가 현재 기절 상태인지 여부
    int stunDuration;          // 기절 상태의 남은 턴 수
    int bleedTurns;            // 출혈 상태의 남은 턴 수
    int bleedDamagePerTurn;    // 출혈 상태일 때 매 턴 받을 피해량



public:
    Monster(std::string initialName, int initialHp, int initialAttack, int initialDefense, int initialExpGiven);
    virtual void Attack(Player& targetPlayer); // 플레이어를 공격
    void TakeDamage(int damageAmount); //플레이어 공격으로 몬스터가 받는 데미지.
    void DisplayStatus() const;//화면에 생성될 몬스터 상태창 언제 얼마나 표시될지는 미정

    // --- 새로운 몬스터 행동 함수 ---
   // 몬스터의 턴에 호출될 함수. 파생 클래스에서 재정의하여 행동을 다양화합니다.
    virtual void PerformTurnAction(Player& targetPlayer); // <-- 이 함수는 이제 행동 결정과 상태 초기화만 담당
    virtual void Defend(); // <-- 이 줄 수정: virtual 키워드 추가
    virtual void StrongAttack(Player& targetPlayer); // 몬스터의 강공격

    // --- 몬스터 행동 예고 시스템 관련 함수 ---
    virtual void DecideNextAction(Player& targetPlayer); // 다음 턴에 수행할 행동을 결정
    virtual std::string GetActionPredictionMessage() const; // 결정된 행동에 대한 예고 메시지 반환
    virtual void ExecuteDecidedAction(Player& targetPlayer); // 결정된 행동을 실행

    // --- 상태 이상 적용 함수 ---
    void ApplyStun(int duration); // 기절 상태 적용
    void ApplyBleed(int damage, int duration); // 출혈 상태 적용

    MonsterAction nextAction; // 다음 턴에 수행할 행동

    // --- 상태 조회 함수 ---
    bool IsStunned() const; // 몬스터가 현재 기절 상태인지 확인


    // --- 턴 시작 시 상태 초기화 및 효과 적용 함수 ---
    void ResetTurnState(); // 턴 시작 시 방어 상태 해제, 기절/출혈 턴 감소
    void TakeBleedDamage(); // 출혈 피해 적용 (몬스터 턴 시작 시 호출)

    int GetHP() const; // 현재 체력을 반환
    int GetMaxHP() const; // 최대 체력을 반환
    int GetAttack() const; // 공격력을 반환
    int GetDefense() const; // 방어력을 반환
    int GetEXPValue() const; // 쓰러뜨렸을 때 주는 경험치 값을 반환
    std::string GetName() const; // 몬스터 이름을 반환

    bool IsAlive() const;//현재 살아있는지 확인
    virtual std::string getDefeatMessage() const = 0; // 몬스터가 쓰러졌을 때의 메시지 (순수 가상)
    virtual ~Monster() = default; // 소멸자 (가상)
};
