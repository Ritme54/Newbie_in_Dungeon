#include "RestTile.h"
#include <iostream>
#include "Player.h"



void RestTile::onEnter(Player& player)
{
	std::cout << "��ں��� �����̴�." << std::endl;
	std::cout << "��ں��� �ǿ� �� ������ ����." << std::endl;
    // TODO: �÷��̾� ü�� ȸ�� ����
   // ����: �÷��̾� �ִ� ü���� ���ݸ�ŭ ȸ��
   // Player Ŭ������ Heal(int amount) �Լ��� �ִٰ� ����
   // player.Heal(player.GetMaxHP() / 2);
    std::cout << player.GetName() << "�� ü���� ȸ���Ǿ����ϴ�." << std::endl;
    // ȸ�� �� �÷��̾� ���¸� �ٽ� ǥ���� ���� �ֽ��ϴ�.
    // player.DisplayStatus();
}

std::string RestTile::getDescription() const
{
	return std::string("�޽� ĭ");
}
