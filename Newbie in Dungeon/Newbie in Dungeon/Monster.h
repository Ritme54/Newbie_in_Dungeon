#pragma once
#include <string>

class Player;





class Monster
{
private:
    std::string name;
     int hp;//���� ü��
    int maxHp; // ���� �ִ� ü��
    int attack;// ���ݷ�
    int defense;//����
    int expGiven;//����ϴ� ����ġ


public:
    Monster(std::string initialName, int initialHp, int initialAttack, int initialDefense, int initialExpGiven);
    void Attack(Player& targetPlayer); // �÷��̾ ����
    void TakeDamage(int damageAmount); //�÷��̾� �������� ���Ͱ� �޴� ������.
    void DisplayStatus() const;//ȭ�鿡 ������ ���� ����â ���� �󸶳� ǥ�õ����� ����

    int GetHP() const; // ���� ü���� ��ȯ
    int GetMaxHP() const; // �ִ� ü���� ��ȯ
    int GetAttack() const; // ���ݷ��� ��ȯ
    int GetDefense() const; // ������ ��ȯ
    int GetEXPValue() const; // �����߷��� �� �ִ� ����ġ ���� ��ȯ
    std::string GetName() const; // ���� �̸��� ��ȯ

    bool IsAlive() const;//���� ����ִ��� Ȯ��

   virtual ~Monster();



};

