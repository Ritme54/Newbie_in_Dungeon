#include "Big_Rat.h"
#include <iostream>
#include "Monster.h"
#include "Player.h" // Player Ŭ���� ����


using namespace std;

Big_Rat::Big_Rat() : Monster("ū ��", 30, 9, 4, 15)
{
	std::cout << "ū �㰡 Ƣ��Դ�!" << std::endl;
}

std::string Big_Rat::getDefeatMessage() const // <-- const Ű���� Ȯ��
{
	return GetName() + " ū �㰡 ����� ������ ��������!"; // ��Ÿ ����: �������� -> ��������
}

// ������ ����
void Big_Rat::StrongAttack(Player& targetPlayer)
{ // override Ű���� �߰�
    // ū �� ������ ������ �޽���
    std::cout << GetName() << " (��)�� ��ī�ο� �̻��� ��������!" << std::endl;

    // ū �� ������ ������ ��ġ (��: �⺻ ���ݷ��� 2��)
    int damage = static_cast<int>(GetAttack() * 2.0) - targetPlayer.GetDefense();
    if (damage < 0) damage = 0;
    targetPlayer.TakeDamage(damage);
}

// ��� ����
void Big_Rat::Defend()
{ // override Ű���� �߰�
    // ū �� ������ ��� �޽���
    std::cout << GetName() << " (��)�� ���ڼ��� ������ �޾Ƴ´�." << std::endl;

    // Monster::Defend()�� ���� ���� ȣ��
    // isDefending = true; // Monster::Defend()���� ó���ǹǷ� ���⼭�� ���� �������� �ʽ��ϴ�.
    Monster::Defend(); // Monster�� Defend �Լ��� ��������� ȣ��
}
std::string Big_Rat::GetActionPredictionMessage() const {
    switch (nextAction) { // nextAction�� Monster�� protected ����̹Ƿ� ���� ����
    case MonsterAction::ATTACK:
        return GetName() + " (��)�� ������ ���� ���� �ٰ��ɴϴ�!";
    case MonsterAction::DEFEND:
        return GetName() + " (��)�� ���� ��ũ���� ������ ��ü�� �к��մϴ�!";
    case MonsterAction::STRONG_ATTACK:
        return GetName() + "  (��)�� ��ī�ο� �̻��� ���̹и� �پ������!";
    case MonsterAction::NONE:
        return GetName() + " (��)�� ���ϴ� �ֽ��ϴ�.";
    default:
        return Monster::GetActionPredictionMessage(); // �⺻ Monster Ŭ������ �޽��� ��� (Ȥ�� �� ���)
    }
}