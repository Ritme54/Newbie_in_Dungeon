#include "Dungeon.h"
#include <iostream>  // std::cout, std::endl 사용
#include <algorithm> // std::shuffle (타일 랜덤 배치 시 사용 가능)
#include <random>    // std::uniform_int_distribution (타일 랜덤 배치 시 사용)
#include "Player.h"

using namespace std;

Dungeon::Dungeon(int totalFloors, int tilesPerFloor, const std::vector<std::vector<std::function<std::unique_ptr<Monster>()>>>& pools)
	: currentFloor(1),
	totalFloors(totalFloors),
	tilesPerFloor(tilesPerFloor),
	currentTileIndex(0),
	monsterPools(pools)
{
	generateFloorLayout(currentFloor);
	cout << "던전 생성 :  총" << totalFloors << "층" << tilesPerFloor << "칸" << endl;
}

void Dungeon::generateFloorLayout(int floorNum)
{
	floorLayout.clear(); // 이전 층의 레이아웃 비우기
	floorLayout.reserve(tilesPerFloor); // 미리 메모리 할당 (선택 사항)
	
	const auto& currentFloorMonsterGenerators = monsterPools[floorNum - 1];
	for (int i = 0; i < tilesPerFloor; i++)
	{
		if (i==tilesPerFloor-2)
		{
			floorLayout.push_back(make_unique<RestTile>());//마지막-2칸은 반드시 휴식
		}
		else if (i==tilesPerFloor-1)
		{
			floorLayout.push_back(make_unique<BossTile>());
		}
		else
		{
			uniform_int_distribution<int> dist(0, 1); // 0:빈칸, 1:몬스터 
				if (dist(rng) == 0)
				{
					floorLayout.push_back(make_unique<EmteyTile>());
				}
				else
				{
					floorLayout.push_back(make_unique<MonsterTile>(currentFloorMonsterGenerators));
				}

		}
	}
	std::cout << "던전 " << floorNum << "층의 레이아웃이 생성되었습니다." << std::endl;
}



void Dungeon::movePlayer()
{
	if (currentTileIndex<tilesPerFloor-1)
	{
		currentTileIndex++;
	}
	else
	{
		// 이미 마지막 칸에 도달했거나 층이 완료된 경우
	  // 이 함수는 isFloorCompleted() 체크 후에 호출되는 것이 일반적입니다.
	}
}

void Dungeon::enterCurrentTile(Player& player)
{
	if (currentTileIndex>=0 && currentTileIndex< floorLayout.size())
	{
		floorLayout[currentTileIndex]->onEnter(player);//다형적 흐름.
	}
	else
	{
		std::cout << "경고: 유효하지 않은 칸 인덱스입니다." << std::endl;
	}
}

bool Dungeon::isFloorCompleted() const
{
	return currentTileIndex >= tilesPerFloor - 1;
}

bool Dungeon::advanceToNextFloor()
{
	if (currentFloor < totalFloors) {
		currentFloor++;       // 층 증가
		currentTileIndex = 0; // 칸 인덱스 초기화
		generateFloorLayout(currentFloor); // 다음 층 레이아웃 생성
		std::cout << "다음 층으로 이동합니다: " << currentFloor << "층." << std::endl;
		return true; // 다음 층으로 진행 성공
	}
	else {
		// 모든 층을 클리어한 경우
		return false; // 던전 전체 클리어
	}
}

bool Dungeon::isDungeonCompleted() const
{
	return currentFloor > totalFloors;
}

std::unique_ptr<Monster> Dungeon::getRandomMonsterForCurrentFloor()
{
	const auto& currentFloorMonsterGenerators = monsterPools[currentFloor - 1];
	if (currentFloorMonsterGenerators.empty()) 
	{

		std::cout << "경고: 현재 층(" << currentFloor << "층)의 몬스터 풀이 비어있습니다." << std::endl;


		return nullptr;
	}
	// 몬스터 풀에서 랜덤 인덱스 선택
	std::uniform_int_distribution<int> dist(0, static_cast<int>(currentFloorMonsterGenerators.size() - 1));
	int randomIndex = dist(rng); // 전역 rng 사용

	// 선택된 람다 함수를 호출하여 몬스터 생성
	return currentFloorMonsterGenerators[randomIndex]();


}
// 현재 칸의 설명을 반환하는 함수 (디버깅/표시용)
std::string Dungeon::getCurrentTileDescription() const {
	if (currentTileIndex >= 0 && currentTileIndex < floorLayout.size()) {
		return floorLayout[currentTileIndex]->getDescription();
	}
	return "알 수 없는 칸";
}