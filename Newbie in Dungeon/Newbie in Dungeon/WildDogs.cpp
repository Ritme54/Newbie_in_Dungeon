#include "WildDogs.h"
#include <iostream>
#include "Monster.h"
#include "Player.h"


using namespace std;

WildDogs::WildDogs() : Monster("�鰳", 50, 15, 8, 30)//��ġ �����Ұ�
{
	std::cout << "�鰳�� Ƣ��Դ�!" << std::endl;
}

std::string WildDogs::getDefeatMessage() const
{
	return GetName() + "�鰳�� ����� ������ ���������ϴ�!";
}

// ������ ����
void WildDogs::StrongAttack(Player& targetPlayer)
{ // override Ű���� �߰�
    // �鰳 ������ ������ �޽���
    std::cout << GetName() << " (��)�� ���� �ε�ġ�鼭 ������!" << std::endl;

    // �鰳 ������ ������ ��ġ (��: �⺻ ���ݷ��� 2��)
    int damage = static_cast<int>(GetAttack() * 2.0) - targetPlayer.GetDefense();
    if (damage < 0) damage = 0;
    targetPlayer.TakeDamage(damage);
}

// ��� ����
void WildDogs::Defend()
{ // override Ű���� �߰�
    // �鰳 ������ ��� �޽���
    std::cout << GetName() << "���� ���ϰ� ���ȴ�..." << std::endl;

    // Monster::Defend()�� ���� ���� ȣ��
    // isDefending = true; // Monster::Defend()���� ó���ǹǷ� ���⼭�� ���� �������� �ʽ��ϴ�.
    Monster::Defend(); // Monster�� Defend �Լ��� ��������� ȣ��
}

std::string WildDogs::GetActionPredictionMessage() const {
    switch (nextAction) { // nextAction�� Monster�� protected ����̹Ƿ� ���� ����
    case MonsterAction::ATTACK:
        return GetName() + " (��)�� �ֺ��� �����Ÿ��ϴ�!";
    case MonsterAction::DEFEND:
        return GetName() + " (��)�� ���� ���߸� ����մϴ�!";
    case MonsterAction::STRONG_ATTACK:
        return GetName() + " (��)�� �����ϸ� �޷���ϴ�!";
    case MonsterAction::NONE:
        return GetName() + " (��)�� ���ϴ� �ֽ��ϴ�.";
    default:
        return Monster::GetActionPredictionMessage(); // �⺻ Monster Ŭ������ �޽��� ��� (Ȥ�� �� ���)
    }
}