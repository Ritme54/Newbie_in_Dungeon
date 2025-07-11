
#pragma once
#include "Monster.h" // Monster 클래스를 상속받으므로 포함
#include <string>
#include <memory> // std::unique_ptr 사용
#include "BossSpecialAbility.h" // BossSpecialAbility 클래스 포함



class BossMonster : public Monster {
private:
    std::unique_ptr<BossSpecialAbility> bossSpecialAbility; // 보스 몬스터의 고유 특수능력
public:
    // 생성자: Monster 생성자를 호출하여 기본 속성 초기화
    // 보스 몬스터는 이름, 체력, 공격력 등이 일반 몬스터보다 훨씬 높을 것입니다.
    BossMonster(std::string name, int hp, int attack, int defense, int expGiven);

    // 보스 몬스터만의 특별한 행동이나 패턴을 정의하는 가상 함수
    // 예: 특정 체력 이하로 내려가면 페이즈 전환
    virtual void activateSpecialPhase() = 0; // 순수 가상 함수로 만들면 BossMonster도 추상 클래스

    // Monster 클래스의 가상 함수를 재정의하여 보스 몬스터만의 특성을 부여할 수도 있습니다.
    // 예: 보스 몬스터는 일반 몬스터보다 더 복잡한 공격 메시지를 출력
    void Attack(Player& targetPlayer) override;

    // Monster의 PerformTurnAction 함수 재정의 (보스 몬스터의 턴 행동)
    void PerformTurnAction(Player& targetPlayer) override;

    // 보스 몬스터의 특수능력을 설정하는 함수
    void setBossSpecialAbility(std::unique_ptr<BossSpecialAbility> ability);


    // 소멸자 (Monster 소멸자가 virtual이므로 override 가능)
    virtual ~BossMonster() = default;
};