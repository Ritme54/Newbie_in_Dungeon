// PlayerSpecialAbility.h
#pragma once
#include <string>

class Player;  // PlayerSpecialAbility�� ����ϴ� Player
class Monster; // PlayerSpecialAbility�� ����� �Ǵ� Monster

class PlayerSpecialAbility {
protected:
    std::string name;
    std::string description;
    int cooldown;        // �� ��ٿ� �� ��
    int currentCooldown; // ���� ���� ��ٿ� �� ��

public:
    PlayerSpecialAbility(std::string name, std::string description, int cooldown);

    // �÷��̾ ���Ϳ��� ����ϴ� �ɷ�
    virtual void use(Player& user, Monster& target) = 0;

    // �÷��̾� ������ ���� ȿ�� ���� ����ϴ� �Լ�
    virtual int calculateEffectValue(int playerLevel) const = 0;

    void decreaseCooldown();
    bool isOnCooldown() const { return currentCooldown > 0; }

    std::string getName() const { return name; }
    std::string getDescription() const { return description; }
    int getCooldown() const { return cooldown; }
    int getCurrentCooldown() const { return currentCooldown; }

    virtual ~PlayerSpecialAbility() = default;
};
