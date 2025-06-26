// BossSpecialAbility.h
#pragma once
#include <string>

class Monster; // BossSpecialAbility를 사용하는 Monster (보스)
class Player;  // BossSpecialAbility의 대상이 되는 Player

class BossSpecialAbility {
protected:
    std::string name;
    std::string description;
    int cooldown;        // 총 쿨다운 턴 수
    int currentCooldown; // 현재 남은 쿨다운 턴 수

public:
    BossSpecialAbility(std::string name, std::string description, int cooldown);

    // 몬스터(보스)가 플레이어에게 사용하는 능력
    virtual void use(Monster& user, Player& target) = 0;

    // 레벨과 무관한 고정 효과 값을 반환하는 함수
    virtual int getFixedEffectValue() const = 0;

    void decreaseCooldown();
    bool isOnCooldown() const { return currentCooldown > 0; }

    std::string getName() const { return name; }
    std::string getDescription() const { return description; }
    int getCooldown() const { return cooldown; }
    int getCurrentCooldown() const { return currentCooldown; }

    virtual ~BossSpecialAbility() = default;
};
