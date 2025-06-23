#include "MonsterTile.h"
#include <iostream>

using namespace std;

extern mt19937 rng;

MonsterTile::MonsterTile(const std::vector<std::function<std::unique_ptr<Monster>()>>& generators)
{
	cout << "�ӽ� �ʱ�ȭ �޼���" << endl;
}

void MonsterTile::onEnter(Player& player)
{
	cout << "---(��)�� �����߽��ϴ�." << endl;


	if (monsterGenerators.empty()) {
		std::cout << "������ �� ĭ���� ���Ͱ� �����ϴ�. (���� Ǯ�� �������)" << std::endl;
		return;
	}

	uniform_int_distribution<int> dist(0, static_cast<int>(monsterGenerators.size() - 1));
	int randomIndex = dist(rng); // ���� rng ���

	unique_ptr<Monster> monster = monsterGenerators[randomIndex]();
	if (monster)
	{ startcombat(player, *monster);//���� ���� �Լ� ȣ��
	} 
	else {
	 std::cout << "���� ������ �����߽��ϴ�." << std::endl;
	}
}

std::string MonsterTile::getDescription() const
{
	return std::string("���� ĭ");
}
