// PlayerSpecialAbility.h
#pragma once
#include <string>

class Player;  // PlayerSpecialAbility를 사용하는 Player
class Monster; // PlayerSpecialAbility의 대상이 되는 Monster

class PlayerSpecialAbility {
protected:
    std::string name;
    std::string description;
    int cooldown;        // 총 쿨다운 턴 수
    int currentCooldown; // 현재 남은 쿨다운 턴 수

public:
    PlayerSpecialAbility(std::string name, std::string description, int cooldown);

    // 플레이어가 몬스터에게 사용하는 능력
    virtual void use(Player& user, Monster& target) = 0;

    // 플레이어 레벨에 따라 효과 값을 계산하는 함수
    virtual int calculateEffectValue(int playerLevel) const = 0;

    void decreaseCooldown();
    bool isOnCooldown() const { return currentCooldown > 0; }

    std::string getName() const { return name; }
    std::string getDescription() const { return description; }
    int getCooldown() const { return cooldown; }
    int getCurrentCooldown() const { return currentCooldown; }

    virtual ~PlayerSpecialAbility() = default;
};
