#include "Slime.h"
#include <iostream>
#include "Monster.h"
#include "Player.h" // Player Ŭ���� ����


Slime::Slime() : Monster("��� ������", 20, 7, 3, 10)
{
	std::cout << "��� �������� ��Ÿ����." << std::endl;
}

std::string Slime::getDefeatMessage() const
{
	return GetName() + "(��)�� ����ó�� ��Ƴ����� ���������ϴ�!";
}

// ������ ����
void Slime::StrongAttack(Player& targetPlayer) 
{ // override Ű���� �߰�
    // ������ ������ ������ �޽���
    std::cout << GetName() << " (��)�� ���� ũ�� ��Ǯ�� ������ ���� ������ �մϴ�!" << std::endl;

    // ������ ������ ������ ��ġ (��: �⺻ ���ݷ��� 2��)
    int damage = static_cast<int>(GetAttack() * 2.0) - targetPlayer.GetDefense();
    if (damage < 0) damage = 0;
    targetPlayer.TakeDamage(damage);
}

// ��� ����
void Slime::Defend() 
{ // override Ű���� �߰�
    // ������ ������ ��� �޽���
    std::cout << GetName() << " �� ��ü������ ���� ������ ���� �ʾҴ�..." << std::endl;

    // Monster::Defend()�� ���� ���� ȣ��
    // isDefending = true; // Monster::Defend()���� ó���ǹǷ� ���⼭�� ���� �������� �ʽ��ϴ�.
    Monster::Defend(); // Monster�� Defend �Լ��� ��������� ȣ��
}
std::string Slime::GetActionPredictionMessage() const  {
    switch (nextAction) { // nextAction�� Monster�� protected ����̹Ƿ� ���� ����
    case MonsterAction::ATTACK:
        return GetName() + " (��)�� ������ ���� ���� �ٰ��ɴϴ�!";
    case MonsterAction::DEFEND:
        return GetName() + " (��)�� ���� ��ũ���� ������ ��ü�� �к��մϴ�!";
    case MonsterAction::STRONG_ATTACK:
        return GetName() + " (��)�� ���� ũ�� ��Ǯ���ϴ�!";
    case MonsterAction::NONE:
        return GetName() + " (��)�� ���ϴ� �ֽ��ϴ�.";
    default:
        return Monster::GetActionPredictionMessage(); // �⺻ Monster Ŭ������ �޽��� ��� (Ȥ�� �� ���)
    }
}


