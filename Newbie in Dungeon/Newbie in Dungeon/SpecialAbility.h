// SpecialAbility.h
#pragma once
#include <string>

// Player�� Monster Ŭ������ ���� ���� ����
// SpecialAbility�� �� Ŭ�������� ��ü�� ���� �������� �ʰ�, ������/�����θ� ����ϹǷ� ���� �������� ����մϴ�.
class Player;
class Monster;

class SpecialAbility {
protected:
    std::string name;
    std::string description;
    int cooldown;        // �� ��ٿ� �� ��
    int currentCooldown; // ���� ���� ��ٿ� �� ��

public:
    SpecialAbility(std::string name, std::string description, int cooldown);

    // Ư���ɷ� ��� �� ȣ��� ���� ���� �Լ�
    // �÷��̾� ������ ���� ȿ���� �޶����Ƿ� Player ��ü�� ���ڷ� �޽��ϴ�.
    virtual void use(Player& user, Monster& target) = 0;

    // �÷��̾� ������ ���� Ư���ɷ��� ȿ�� ���� ����ϴ� ���� ���� �Լ�
    virtual int calculateEffectValue(int playerLevel) const = 0;

    // ��ٿ� ����
    void decreaseCooldown();
    // ��ٿ� ������ Ȯ��
    bool isOnCooldown() const { return currentCooldown > 0; }

    // Getter �Լ���
    std::string getName() const { return name; }
    std::string getDescription() const { return description; }
    int getCooldown() const { return cooldown; }
    int getCurrentCooldown() const { return currentCooldown; }

    // �Ҹ��ڴ� �ݵ�� virtual
    virtual ~SpecialAbility() = default;
};
