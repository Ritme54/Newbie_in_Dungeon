#pragma once
#include <string>
#include <iostream>

class Monster;


using namespace std;

class Player//ĳ���� ���� Ŭ����
{
private:
    string name;//ĳ���� �̸�
    int hp;//ĳ���� ü��
    int maxHp;//ĳ���� �ִ� ä��-���� �������� ���� �����ϰ� ����
    int attack;// ���ݷ�
    int defense;//����
    int level;//�� ����
    int exp;//ȹ���� ����ġ
    int requiredExp;//�ִ� ����ġ. �ִ�ġ�� �Ѿ�� �������ϸ� �����ϰ� ������
public:
    Player(string initialName, int initialHp, int initialAttack, int initialDefense);

    void Attack(Monster& targetEnemy); // Enemy Ŭ������ �ִٰ� ���� ���� ��ü�� ����ǵ��� �ؾ���. �⺻������ �÷��̾� ���ݷ�-���� ������ �ǵ��� �ؾ���.
    void TakeDamage(int damageAmount); //�ݴ�� ���� ���ݷ�-�÷��̾� ������ �Ǿ���.
    void GainExperience(int expAmount);//���Ͱ� ��������� ȹ���ϴ� ����ġ
    void LevelUp();//�ִ�ġ�� �Ѿ�� �������ϸ� �����ϰ� ������
    void DisplayStatus();//ȭ�鿡 ������ �÷��̾� ����â ���� �󸶳� ǥ�õ����� ����

    bool IsAlive() const;

    int GetHP() const; // ���� ü���� ��ȯ
    int GetMaxHP() const; // �ִ� ü���� ��ȯ
    int GetAttack() const; // ���ݷ��� ��ȯ
    int GetDefense() const; // ������ ��ȯ
    std::string GetName() const; // ���� �̸��� ��ȯ

    ~Player();



   
  
       
};

