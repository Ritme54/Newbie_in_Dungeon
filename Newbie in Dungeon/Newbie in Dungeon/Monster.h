#pragma once
#include <string>
#include "Player.h"



class Monster
{
private:
    std::string name;//���� �̸�
    int hp;//���� ü��
    int maxHp; // ���� �ִ� ü��
    int attack;// ���ݷ�
    int defense;//����
    int expGiven;//����ϴ� ����ġ

public:
    Monster(string initialName, int instiallHp, int instiallAttack, int instiallDefense, int intialExpGiven);
    void Attack(Player& targetPlayer); // �÷��̾ ����
    void TakeDamage(int damageAmount); //�÷��̾� �������� ���Ͱ� �޴� ������.
 
    // ���¸� ��� �Լ� (Getter) ����
    int GetHP() const; // ���� ü���� ��ȯ (const)
    bool IsAlive() const; // ����ִ��� ���θ� ��ȯ (const)
    int GetEXPValue() const; // �����߷��� �� �ִ� ����ġ ���� ��ȯ (const)
    std::string GetName() const; // ���� �̸��� ��ȯ (const)

    void DisplayStatus() const;//ȭ�鿡 ������ ���� ����â ���� �󸶳� ǥ�õ����� ����

   virtual~Monster();



};

