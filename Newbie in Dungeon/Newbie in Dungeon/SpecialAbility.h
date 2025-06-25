// SpecialAbility.h
#pragma once
#include <string>

// Player와 Monster 클래스에 대한 전방 선언
// SpecialAbility는 이 클래스들의 객체를 직접 생성하지 않고, 포인터/참조로만 사용하므로 전방 선언으로 충분합니다.
class Player;
class Monster;

class SpecialAbility {
protected:
    std::string name;
    std::string description;
    int cooldown;        // 총 쿨다운 턴 수
    int currentCooldown; // 현재 남은 쿨다운 턴 수

public:
    SpecialAbility(std::string name, std::string description, int cooldown);

    // 특수능력 사용 시 호출될 순수 가상 함수
    // 플레이어 레벨에 따라 효과가 달라지므로 Player 객체를 인자로 받습니다.
    virtual void use(Player& user, Monster& target) = 0;

    // 플레이어 레벨에 따라 특수능력의 효과 값을 계산하는 순수 가상 함수
    virtual int calculateEffectValue(int playerLevel) const = 0;

    // 쿨다운 감소
    void decreaseCooldown();
    // 쿨다운 중인지 확인
    bool isOnCooldown() const { return currentCooldown > 0; }

    // Getter 함수들
    std::string getName() const { return name; }
    std::string getDescription() const { return description; }
    int getCooldown() const { return cooldown; }
    int getCurrentCooldown() const { return currentCooldown; }

    // 소멸자는 반드시 virtual
    virtual ~SpecialAbility() = default;
};
