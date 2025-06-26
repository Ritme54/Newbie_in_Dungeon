// Monster.h (����)
#pragma once
#include <string>

class Player;

enum class MonsterAction {
    NONE,             // �ƹ��͵� ���� ���� (�ʱⰪ �Ǵ� Ư�� ��Ȳ)
    ATTACK,           // �Ϲ� ����
    DEFEND,           // ���
    STRONG_ATTACK,    // ������
    SPECIAL_ABILITY   // Ư���ɷ� (���� ���Ϳ�)
};


class Monster
{
private:
    std::string name;
    int hp;          // ���� ü��
    int maxHp;       // ���� �ִ� ü��
    int attack;      // ���ݷ�
    int defense;     // ����
    int expGiven;    // ����ϴ� ����ġ

    // --- ���ο� ���� ���� ���� ��� ���� ---
    bool isDefending;          // ���� ��� ���� ����
    bool isStunned;            // ���Ͱ� ���� ���� �������� ����
    int stunDuration;          // ���� ������ ���� �� ��
    int bleedTurns;            // ���� ������ ���� �� ��
    int bleedDamagePerTurn;    // ���� ������ �� �� �� ���� ���ط�



public:
    Monster(std::string initialName, int initialHp, int initialAttack, int initialDefense, int initialExpGiven);
    virtual void Attack(Player& targetPlayer); // �÷��̾ ����
    void TakeDamage(int damageAmount); //�÷��̾� �������� ���Ͱ� �޴� ������.
    void DisplayStatus() const;//ȭ�鿡 ������ ���� ����â ���� �󸶳� ǥ�õ����� ����

    // --- ���ο� ���� �ൿ �Լ� ---
   // ������ �Ͽ� ȣ��� �Լ�. �Ļ� Ŭ�������� �������Ͽ� �ൿ�� �پ�ȭ�մϴ�.
    virtual void PerformTurnAction(Player& targetPlayer); // <-- �� �Լ��� ���� �ൿ ������ ���� �ʱ�ȭ�� ���
    virtual void Defend(); // <-- �� �� ����: virtual Ű���� �߰�
    virtual void StrongAttack(Player& targetPlayer); // ������ ������

    // --- ���� �ൿ ���� �ý��� ���� �Լ� ---
    virtual void DecideNextAction(Player& targetPlayer); // ���� �Ͽ� ������ �ൿ�� ����
    virtual std::string GetActionPredictionMessage() const; // ������ �ൿ�� ���� ���� �޽��� ��ȯ
    virtual void ExecuteDecidedAction(Player& targetPlayer); // ������ �ൿ�� ����

    // --- ���� �̻� ���� �Լ� ---
    void ApplyStun(int duration); // ���� ���� ����
    void ApplyBleed(int damage, int duration); // ���� ���� ����

    MonsterAction nextAction; // ���� �Ͽ� ������ �ൿ

    // --- ���� ��ȸ �Լ� ---
    bool IsStunned() const; // ���Ͱ� ���� ���� �������� Ȯ��


    // --- �� ���� �� ���� �ʱ�ȭ �� ȿ�� ���� �Լ� ---
    void ResetTurnState(); // �� ���� �� ��� ���� ����, ����/���� �� ����
    void TakeBleedDamage(); // ���� ���� ���� (���� �� ���� �� ȣ��)

    int GetHP() const; // ���� ü���� ��ȯ
    int GetMaxHP() const; // �ִ� ü���� ��ȯ
    int GetAttack() const; // ���ݷ��� ��ȯ
    int GetDefense() const; // ������ ��ȯ
    int GetEXPValue() const; // �����߷��� �� �ִ� ����ġ ���� ��ȯ
    std::string GetName() const; // ���� �̸��� ��ȯ

    bool IsAlive() const;//���� ����ִ��� Ȯ��
    virtual std::string getDefeatMessage() const = 0; // ���Ͱ� �������� ���� �޽��� (���� ����)
    virtual ~Monster() = default; // �Ҹ��� (����)
};
