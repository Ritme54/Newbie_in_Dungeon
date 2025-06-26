#include "Snake.h"
#include <iostream>
#include "Monster.h"
#include "Player.h"

using namespace std;

Snake::Snake() : Monster("������", 35,15,6,25)//��ġ �����Ұ�
{
	std::cout << "�����̰� ����ƴ���� Ƣ��Դ�!" << std::endl;
}

std::string Snake::getDefeatMessage() const 
{
	return GetName() + "�����̰� ���������ϴ�!";
}
// ������ ����
void Snake::StrongAttack(Player& targetPlayer)
{ // override Ű���� �߰�
    // ������ ������ ������ �޽���
    std::cout << GetName() << " (��)�� ������ ���ϰ� �ķ��ƴ�!" << std::endl;

    // ������ ������ ������ ��ġ (��: �⺻ ���ݷ��� 2��)
    int damage = static_cast<int>(GetAttack() * 2.0) - targetPlayer.GetDefense();
    if (damage < 0) damage = 0;
    targetPlayer.TakeDamage(damage);
}

// ��� ����
void Snake::Defend()
{ // override Ű���� �߰�
    // ������ ������ ��� �޽���
    std::cout << GetName() << " ���� Ÿ���� ����� ���� �ʾҴ�... " << std::endl;

    // Monster::Defend()�� ���� ���� ȣ��
    // isDefending = true; // Monster::Defend()���� ó���ǹǷ� ���⼭�� ���� �������� �ʽ��ϴ�.
    Monster::Defend(); // Monster�� Defend �Լ��� ��������� ȣ��
}

std::string Snake::GetActionPredictionMessage() const  {
    switch (nextAction) { // nextAction�� Monster�� protected ����̹Ƿ� ���� ����
    case MonsterAction::ATTACK:
        return GetName() + " (��)�� �ٴ��� ��� �ٰ��ɴϴ�!";
    case MonsterAction::DEFEND:
        return GetName() + " (��)�� �̸��� Ʋ�� ��� �ڼ��� ���մϴ�!";
    case MonsterAction::STRONG_ATTACK:
        return GetName() + " (��)�� �����ϰ� �����ؿɴϴ�!";
    case MonsterAction::NONE:
        return GetName() + " (��)�� ���ϴ� �ֽ��ϴ�.";
    default:
        return Monster::GetActionPredictionMessage(); // �⺻ Monster Ŭ������ �޽��� ��� (Ȥ�� �� ���)
    }
}