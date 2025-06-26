// BossSpecialAbility.h
#pragma once
#include <string>

class Monster; // BossSpecialAbility�� ����ϴ� Monster (����)
class Player;  // BossSpecialAbility�� ����� �Ǵ� Player

class BossSpecialAbility {
protected:
    std::string name;
    std::string description;
    int cooldown;        // �� ��ٿ� �� ��
    int currentCooldown; // ���� ���� ��ٿ� �� ��

public:
    BossSpecialAbility(std::string name, std::string description, int cooldown);

    // ����(����)�� �÷��̾�� ����ϴ� �ɷ�
    virtual void use(Monster& user, Player& target) = 0;

    // ������ ������ ���� ȿ�� ���� ��ȯ�ϴ� �Լ�
    virtual int getFixedEffectValue() const = 0;

    void decreaseCooldown();
    bool isOnCooldown() const { return currentCooldown > 0; }

    std::string getName() const { return name; }
    std::string getDescription() const { return description; }
    int getCooldown() const { return cooldown; }
    int getCurrentCooldown() const { return currentCooldown; }

    virtual ~BossSpecialAbility() = default;
};
