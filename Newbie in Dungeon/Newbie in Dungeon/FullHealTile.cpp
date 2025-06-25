#include "FullHealTile.h"
#include <iostream>
#include "Player.h"

void FullHealTile::onEnter(Player& player)
{
    std::cout << "��ں��� �����̴�." << std::endl;
    std::cout << "��ں��� �ǿ� �� ������ ����." << std::endl;

    std::cout << "��Ű! ������ ������ ã�Ҵ�!" << std::endl;
    std::cout << "����ϰ� �޽��� ���� �� �־���." << std::endl;
    // TODO: �÷��̾� ü�� ȸ�� ����
   // ����: �÷��̾� �ִ� ü�� ���� ȸ��
   // Player Ŭ������ Heal(int amount) �Լ��� �ִٰ� ����
    int healAmount = player.GetMaxHP(); // ����: �ִ� ü�� ȸ��
    player.Heal(healAmount); // Player::Heal() �Լ� ȣ��
    player.DisplayStatus();
    std::cout << player.GetName() << "�� ü���� ���� ȸ���Ǿ����ϴ�." << std::endl;
    std::cout << player.GetName() << "�� �������� �� �� �ٽ� �����ϱ� �����ߴ�." << std::endl;
    // ȸ�� �� �÷��̾� ���¸� �ٽ� ǥ���� ���� �ֽ��ϴ�.
}

std::string FullHealTile::getDescription() const
{
	return std::string("�ְ��� �޽� ĭ");
}
