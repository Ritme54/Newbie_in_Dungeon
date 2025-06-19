#pragma once
#include <string>
#include <iostream>
#include "Monster.h"

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
    Player(string initialName, int instialHp, int instialAttack, int instialDefense);

    void Attack(Monster& targetEnemy); // Enemy Ŭ������ �ִٰ� ���� ���� ��ü�� ����ǵ��� �ؾ���. �⺻������ �÷��̾� ���ݷ�-���� ������ �ǵ��� �ؾ���.
    void TakeDamage(int damageAmount); //�ݴ�� ���� ���ݷ�-�÷��̾� ������ �Ǿ���.
    void GainExperience(int expAmount);//���Ͱ� ��������� ȹ���ϴ� ����ġ
    void LevelUp();//�ִ�ġ�� �Ѿ�� �������ϸ� �����ϰ� ������
    void DisplayStatus();//ȭ�鿡 ������ �÷��̾� ����â ���� �󸶳� ǥ�õ����� ����

    ~Player();



   
  
       
};

