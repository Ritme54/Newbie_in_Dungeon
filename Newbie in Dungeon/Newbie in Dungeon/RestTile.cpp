#include "RestTile.h"
#include <iostream>
#include "Player.h"



void RestTile::onEnter(Player& player)
{
	std::cout << "��ں��� �����̴�." << std::endl;
	std::cout << "��ں��� �ǿ� �� ������ ����." << std::endl;

    std::cout << "�ֺ��� �μ��� ���� ���ط� ���� �ǿ���." << std::endl;
    std::cout << "�״� ���� ��ں��� �ƴ�����, �׷��� �޽��� ���� �� �־���." << std::endl;
    // TODO: �÷��̾� ü�� ȸ�� ����
   // ����: �÷��̾� �ִ� ü���� ���ݸ�ŭ ȸ��
   // Player Ŭ������ Heal(int amount) �Լ��� �ִٰ� ����
    int healAmount = player.GetMaxHP() / 2; // ����: �ִ� ü���� ���� ȸ��
    player.Heal(healAmount); // Player::Heal() �Լ� ȣ��
    std::cout << player.GetName() << "�� ü���� ���� ȸ���Ǿ����ϴ�." << std::endl;
    std::cout << player.GetName() << "�� �������� �� �� �ٽ� �����ϱ� �����ߴ�." << std::endl;
    // ȸ�� �� �÷��̾� ���¸� �ٽ� ǥ���� ���� �ֽ��ϴ�.
    player.DisplayStatus();
}

std::string RestTile::getDescription() const
{
	return std::string("�޽� ĭ");
}
