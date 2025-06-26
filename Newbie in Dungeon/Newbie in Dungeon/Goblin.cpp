#include "Goblin.h"
#include <iostream>
#include "Monster.h"
#include "Player.h" // Player Ŭ���� ����



using namespace std;


Goblin::Goblin() : Monster("���",10,10,10,10)//���� ����
{
	std::cout << "����� ����Ÿ��� ��Ÿ����!" << std::endl;

}

std::string Goblin::getDefeatMessage() const 
{
	return GetName() + "(��)�� �����̸� ��ġ�� ����� ������ ���������ϴ�!";
}

// ������ ����
void Goblin::StrongAttack(Player& targetPlayer)
{ // override Ű���� �߰�
    // ��� ������ ������ �޽���
    std::cout << GetName() << "���� ���ϰ� �¾Ҵ�. " << std::endl;

    // ��� ������ ������ ��ġ (��: �⺻ ���ݷ��� 2��)
    int damage = static_cast<int>(GetAttack() * 2.0) - targetPlayer.GetDefense();
    if (damage < 0) damage = 0;
    targetPlayer.TakeDamage(damage);
}

// ��� ����
void Goblin::Defend() 
{ // override Ű���� �߰�
    // ��� ������ ��� �޽���
    std::cout << GetName() << " (��)�� �ݴ� �ȷ� ���Ҵ�." << std::endl;

    // Monster::Defend()�� ���� ���� ȣ��
    // isDefending = true; // Monster::Defend()���� ó���ǹǷ� ���⼭�� ���� �������� �ʽ��ϴ�.
    Monster::Defend(); // Monster�� Defend �Լ��� ��������� ȣ��
}


std::string Goblin::GetActionPredictionMessage() const {
    switch (nextAction) { // nextAction�� Monster�� protected ����̹Ƿ� ���� ����
    case MonsterAction::ATTACK:
        return GetName() + " (��)�� ������ϴ�!";
    case MonsterAction::DEFEND:
        return GetName() + "(��)�� ����ϰ� �ִ�.";
    case MonsterAction::STRONG_ATTACK:
        return GetName() + " (��)�� �����̸� �ϴ÷� ġ�ѵ�� �޷��´�!";
    case MonsterAction::NONE:
        return GetName() + " (��)�� ���ϴ� �ֽ��ϴ�.";
    default:
        return Monster::GetActionPredictionMessage(); // �⺻ Monster Ŭ������ �޽��� ��� (Ȥ�� �� ���)
    }
}