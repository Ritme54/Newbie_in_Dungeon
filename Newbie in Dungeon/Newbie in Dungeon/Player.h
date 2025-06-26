#pragma once
#include <string>
#include <memory> 
class Monster;
class SpecialAbility;

class Player//ĳ���� ���� Ŭ����
{
private:
    std::string name;//ĳ���� �̸�
    int hp;//ĳ���� ü��
    int maxHp;//ĳ���� �ִ� ä��-���� �������� ���� �����ϰ� ����
    int attack;// ���ݷ�
    int defense;//����
    int level;//�� ����
    int exp;//ȹ���� ����ġ
    int requiredExp;//�ִ� ����ġ. �ִ�ġ�� �Ѿ�� �������ϸ� �����ϰ� ������

    int bandageCount;    // ���� �����ִ� ġ�� �ش� ��
    // int maxBandages;     // <-- �� �� ���� (�ִ�ġ ���� ����)
    const int bandageHealAmt; // ġ�� �ش� ��� �� ȸ���� (������)

    // --- 3��: ���� ���� ��� ���� ---
    int potionCount;     // ���� �����ִ� ���� ��
    // int maxPotions;      // <-- �� �� ���� (�ִ�ġ ���� ����)
    const int potionHealAmt; // ���� ��� �� ȸ���� (������)

    // --- ���ο� ���� �ൿ ���� ��� ���� ---
    bool isDefending; // ��� ���� ����
    int strongAttackCooldown; // ������ ��ٿ�

    std::unique_ptr<SpecialAbility> selectedSpecialAbility;


public:
    Player(std::string initialName, int initialHp, int initialAttack, int initialDefense);

    void Attack(Monster& targetEnemy); // Enemy Ŭ������ �ִٰ� ���� ���� ��ü�� ����ǵ��� �ؾ���. �⺻������ �÷��̾� ���ݷ�-���� ������ �ǵ��� �ؾ���.
    void TakeDamage(int damageAmount); //�ݴ�� ���� ���ݷ�-�÷��̾� ������ �Ǿ���.(��� ȿ�� ���� ����)
    void GainExperience(int expAmount);//���Ͱ� ��������� ȹ���ϴ� ����ġ
    void DisplayStatus();//ȭ�鿡 ������ �÷��̾� ����â ���� �󸶳� ǥ�õ����� ����
    void Heal(int amount); // ȸ��
    void LevelUp(); // ������ �� ������ ȸ�� ���� ���� ���� ����
  
    // --- ���ο� ���� �ൿ �Լ� ---
    void StrongAttack(Monster& targetEnemy); // ������
    void Defend(); // ���

    void setSpecialAbility(std::unique_ptr<SpecialAbility> ability); // Ư���ɷ� ����
    void useSpecialAbility(Monster& targetEnemy); // ������ Ư���ɷ� ���

    // --- �� ���� �� ���� �ʱ�ȭ �Լ� (GameManager���� ȣ��) ---
    void ResetTurnState(); // �� ���� �� ��� ���� ����, ��ٿ� ���� ��


    // --- 6��: ġ�� �ش� ���� �Լ� ---
    bool useBandage(); // ġ�� �ش� ���
    int getBandageCount() const; // ���� �ش� ���� ��ȸ
    void setBandages(int count); // GameManager���� �ش븦 ������ �� ���
    void addBandages(int count); // <-- �� �� �߰�: �ش� ���� �߰�

    // --- 3��: ���� ���� �Լ� ---
    bool usePotion(); // ���� ���
    int getPotionCount() const; // ���� ���� ���� ��ȸ
    void addPotions(int count); // <-- �� �� �߰�: ���� ���� �߰�

    bool IsAlive() const; //��������

    int GetHP() const; // ���� ü���� ��ȯ
    int GetMaxHP() const; // �ִ� ü���� ��ȯ
    int GetAttack() const; // ���ݷ��� ��ȯ
    int GetDefense() const; // ������ ��ȯ
    std::string GetName() const; // �÷��̾� �̸��� ��ȯ
  int GetLevel() const; //���� �Լ�
    ~Player();



   
  
       
};

