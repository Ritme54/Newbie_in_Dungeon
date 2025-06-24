#include "Dungeon.h"

#include <iostream>  // std::cout, std::endl 사용
#include <algorithm> // std::shuffle (타일 랜덤 배치 시 사용 가능)
#include <random>    // std::uniform_int_distribution (타일 랜덤 배치 시 사용)
#include "Player.h"
#include "BossTile.h"
#include "RestTile.h"
#include "MonsterTile.h"
#include "EmptyTile.h"

using namespace std;


// --- private 헬퍼 함수 ---
// 각 층의 타일 레이아웃을 생성하는 함수
// 이 함수는 생성자나 advanceToNextFloor()에서 호출됩니다.
void Dungeon::generateFloorLayout(int floorNum)
{
	floorLayout.clear(); // 이전 층의 레이아웃 비우기
	floorLayout.reserve(tilesPerFloor); // 미리 메모리 할당 (선택 사항)

	const auto& currentFloorNormalMonsterGenerators = normalMonsterPools[floorNum - 1];
	const auto& currentFloorBossMonsterGenerators = bossMonsterPools[floorNum - 1];
	for (int i = 0; i < tilesPerFloor; i++)
	{
		if (i == tilesPerFloor - 2)
		{
			floorLayout.push_back(make_unique<RestTile>());//마지막-2칸은 반드시 휴식
		}
		else if (i == tilesPerFloor - 1)
		{
			floorLayout.push_back(std::make_unique<BossTile>(currentFloorBossMonsterGenerators, *this));
		}
		else
		{
			uniform_int_distribution<int> dist(0, 1); // 0:빈칸, 1:몬스터 
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
	std::cout << "던전 " << floorNum << "층의 레이아웃이 생성되었습니다." << std::endl;
}

Dungeon::Dungeon(int totalFloors, int tilesPerFloor, const std::vector<std::vector<std::function<std::unique_ptr<Monster>()>>>& normalPools, const std::vector<std::vector<std::function<std::unique_ptr<Monster>()>>>& bossPools)
	: currentFloor(1),
	totalFloors(totalFloors),
	tilesPerFloor(tilesPerFloor),
	currentTileIndex(0),
	normalMonsterPools(normalPools), // <-- normalPools로 초기화
	bossMonsterPools(bossPools),     // <-- bossPools로 초기화
	bossDefeatedInCurrentFloor(false) // <-- bossDefeatedInCurrentFloor 초기화
{

	generateFloorLayout(currentFloor);
	std::cout << "던전 생성 :  총" << totalFloors << "층 " << tilesPerFloor << "칸" << std::endl; // 

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
	return currentTileIndex >= tilesPerFloor - 1 && bossDefeatedInCurrentFloor;
}

bool Dungeon::advanceToNextFloor()
{
	if (currentFloor < totalFloors) {
		currentFloor++;       // 층 증가
		currentTileIndex = 0; // 칸 인덱스 초기화
		bossDefeatedInCurrentFloor = false; //

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
	const auto& currentFloorNormalMonsterGenerators = normalMonsterPools[currentFloor - 1];;
	if (currentFloorNormalMonsterGenerators.empty()) 
	{

		std::cout << "경고: 현재 층(" << currentFloor << "층)의 일반 몬스터 풀이 비어있습니다." << std::endl;


		return nullptr;
	}
	// 일반 몬스터 풀에서 랜덤 인덱스 선택
	std::uniform_int_distribution<int> dist(0, static_cast<int>(currentFloorNormalMonsterGenerators.size() - 1));
	int randomIndex = dist(rng); // 전역 rng 사용

	// 선택된 람다 함수를 호출하여 몬스터 생성
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
// 현재 칸의 설명을 반환하는 함수 (디버깅/표시용)
std::string Dungeon::getCurrentTileDescription() const {
	if (currentTileIndex >= 0 && currentTileIndex < floorLayout.size()) {
		return floorLayout[currentTileIndex]->getDescription();
	}
	return "알 수 없는 칸";
}