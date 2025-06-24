#include "Dungeon.h"

#include <iostream>  // std::cout, std::endl ���
#include <algorithm> // std::shuffle (Ÿ�� ���� ��ġ �� ��� ����)
#include <random>    // std::uniform_int_distribution (Ÿ�� ���� ��ġ �� ���)
#include "Player.h"
#include "BossTile.h"
#include "RestTile.h"
#include "MonsterTile.h"
#include "EmptyTile.h"

using namespace std;


// --- private ���� �Լ� ---
// �� ���� Ÿ�� ���̾ƿ��� �����ϴ� �Լ�
// �� �Լ��� �����ڳ� advanceToNextFloor()���� ȣ��˴ϴ�.
void Dungeon::generateFloorLayout(int floorNum)
{
	floorLayout.clear(); // ���� ���� ���̾ƿ� ����
	floorLayout.reserve(tilesPerFloor); // �̸� �޸� �Ҵ� (���� ����)

	const auto& currentFloorNormalMonsterGenerators = normalMonsterPools[floorNum - 1];
	const auto& currentFloorBossMonsterGenerators = bossMonsterPools[floorNum - 1];
	for (int i = 0; i < tilesPerFloor; i++)
	{
		if (i == tilesPerFloor - 2)
		{
			floorLayout.push_back(make_unique<RestTile>());//������-2ĭ�� �ݵ�� �޽�
		}
		else if (i == tilesPerFloor - 1)
		{
			floorLayout.push_back(std::make_unique<BossTile>(currentFloorBossMonsterGenerators, *this));
		}
		else
		{
			uniform_int_distribution<int> dist(0, 1); // 0:��ĭ, 1:���� 
			if (dist(rng) == 0)
			{
				floorLayout.push_back(std::make_unique<EmptyTile>());
			}

			else
			{
				floorLayout.push_back(make_unique<MonsterTile>(currentFloorNormalMonsterGenerators));
			}

		}
	}
	std::cout << "���� " << floorNum << "���� ���̾ƿ��� �����Ǿ����ϴ�." << std::endl;
}

Dungeon::Dungeon(int totalFloors, int tilesPerFloor, const std::vector<std::vector<std::function<std::unique_ptr<Monster>()>>>& normalPools, const std::vector<std::vector<std::function<std::unique_ptr<Monster>()>>>& bossPools)
	: currentFloor(1),
	totalFloors(totalFloors),
	tilesPerFloor(tilesPerFloor),
	currentTileIndex(0),
	normalMonsterPools(normalPools), // <-- normalPools�� �ʱ�ȭ
	bossMonsterPools(bossPools),     // <-- bossPools�� �ʱ�ȭ
	bossDefeatedInCurrentFloor(false) // <-- bossDefeatedInCurrentFloor �ʱ�ȭ
{

	generateFloorLayout(currentFloor);
	std::cout << "���� ���� :  ��" << totalFloors << "�� " << tilesPerFloor << "ĭ" << std::endl; // 

}







void Dungeon::movePlayer()
{
	if (currentTileIndex<tilesPerFloor-1)
	{
		currentTileIndex++;
	}
	else
	{
		// �̹� ������ ĭ�� �����߰ų� ���� �Ϸ�� ���
	  // �� �Լ��� isFloorCompleted() üũ �Ŀ� ȣ��Ǵ� ���� �Ϲ����Դϴ�.
	}
}

void Dungeon::enterCurrentTile(Player& player)
{
	if (currentTileIndex>=0 && currentTileIndex< floorLayout.size())
	{
		floorLayout[currentTileIndex]->onEnter(player);//������ �帧.
	}
	else
	{
		std::cout << "���: ��ȿ���� ���� ĭ �ε����Դϴ�." << std::endl;
	}
}

bool Dungeon::isFloorCompleted() const
{
	return currentTileIndex >= tilesPerFloor - 1 && bossDefeatedInCurrentFloor;
}

bool Dungeon::advanceToNextFloor()
{
	if (currentFloor < totalFloors) {
		currentFloor++;       // �� ����
		currentTileIndex = 0; // ĭ �ε��� �ʱ�ȭ
		bossDefeatedInCurrentFloor = false; //

		generateFloorLayout(currentFloor); // ���� �� ���̾ƿ� ����
		std::cout << "���� ������ �̵��մϴ�: " << currentFloor << "��." << std::endl;
		return true; // ���� ������ ���� ����
	}
	else {
		// ��� ���� Ŭ������ ���
		return false; // ���� ��ü Ŭ����
	}
}

bool Dungeon::isDungeonCompleted() const
{
	return currentFloor > totalFloors;
}

std::unique_ptr<Monster> Dungeon::getRandomMonsterForCurrentFloor()
{
	const auto& currentFloorNormalMonsterGenerators = normalMonsterPools[currentFloor - 1];;
	if (currentFloorNormalMonsterGenerators.empty()) 
	{

		std::cout << "���: ���� ��(" << currentFloor << "��)�� �Ϲ� ���� Ǯ�� ����ֽ��ϴ�." << std::endl;


		return nullptr;
	}
	// �Ϲ� ���� Ǯ���� ���� �ε��� ����
	std::uniform_int_distribution<int> dist(0, static_cast<int>(currentFloorNormalMonsterGenerators.size() - 1));
	int randomIndex = dist(rng); // ���� rng ���

	// ���õ� ���� �Լ��� ȣ���Ͽ� ���� ����
	return currentFloorNormalMonsterGenerators[randomIndex]();


}
void Dungeon::setBossDefeated(bool defeated)
{
	bossDefeatedInCurrentFloor = defeated;
}
bool Dungeon::isBossDefeatedInCurrentFloor() const
{
	return bossDefeatedInCurrentFloor; // 
}
// ���� ĭ�� ������ ��ȯ�ϴ� �Լ� (�����/ǥ�ÿ�)
std::string Dungeon::getCurrentTileDescription() const {
	if (currentTileIndex >= 0 && currentTileIndex < floorLayout.size()) {
		return floorLayout[currentTileIndex]->getDescription();
	}
	return "�� �� ���� ĭ";
}