#include "BossTile.h" // �ڽ��� ��� ���� ����
#include <iostream>   // std::cout, std::endl ���
#include <random>     // std::uniform_int_distribution ���
#include "Player.h"   // Player::IsAlive(), Player::GetName() �� ȣ��
#include "Dungeon.h"  // Dungeon::setBossDefeated() ȣ��

extern std::mt19937 rng;

BossTile::BossTile(const std::vector<std::function<std::unique_ptr<Monster>()>>& generators, Dungeon& dungeon) : bossGenerators(generators), dungeonRef(dungeon)
{
	std::cout << "���� �濡 �����߽��ϴ�." << std::endl;
}

void BossTile::onEnter(Player& player)
{
	std::cout << "�� �߾ӿ� ���� ���Դϴ�..." << std::endl;
	if (bossGenerators.empty()) {
		std::cout << "������ ���� ���Ͱ� ��Ÿ���� �ʾҽ��ϴ�. (���� Ǯ�� �������)" << std::endl;
		return;
	}
	std::unique_ptr<Monster> boss = bossGenerators[0]();

	if (boss)
	{
	//������ ���� ����
		startcombat(player, *boss);

	}

}

std::string BossTile::getDescription() const
{
	return std::string();
}
