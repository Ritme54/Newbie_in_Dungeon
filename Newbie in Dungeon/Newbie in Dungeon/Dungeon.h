#pragma once
#include <vector>       // std::vector 사용
#include <memory>       // std::unique_ptr 사용
#include <functional>   // std::function 사용
#include <random>       // std::mt19937, std::uniform_int_distribution 사용

class Player;
class Monster;

#include "Tile.h"
#include "EmptyTile.h" 
#include "RestTile.h"
#include "MonsterTile.h"

extern std::mt19937 rng;

class Dungeon
{
private:
    int currentFloor;       // 현재 플레이어가 있는 층 (1부터 시작)
    int totalFloors;        // 던전의 총 층수
    int tilesPerFloor;      // 각 층의 총 칸 수 (예: 100칸)
    int currentTileIndex;   // 현재 층에서 플레이어가 있는 칸의 인덱스 (0부터 시작)

    // 현재 층의 칸 배치를 저장하는 벡터 (다형성을 위해 Tile* 포인터를 unique_ptr로 관리)
    std::vector<std::unique_ptr<Tile>> floorLayout;

    // 각 층별 몬스터 생성 람다 함수 풀
    // Dungeon 클래스가 몬스터 풀을 직접 관리합니다.
    std::vector<std::vector<std::function<std::unique_ptr<Monster>()>>> monsterPools;

    // --- private 헬퍼 함수 ---
    // 각 층의 타일 레이아웃을 생성하는 함수
    // 이 함수는 생성자나 advanceToNextFloor()에서 호출됩니다.
    void generateFloorLayout(int floorNum);

public:
    Dungeon(int totalFloors, int tilesPerFloor,
        const std::vector<std::vector<std::function<std::unique_ptr<Monster>()>>>& pools);
    ~Dungeon() = default;

#pragma region 플레이어 이동 함수
    // --- 플레이어 이동 및 칸 이벤트 관련 함수 ---
// 플레이어를 다음 칸으로 이동시키는 함수
    void movePlayer();

    // 현재 플레이어가 있는 칸의 이벤트를 실행하는 함수
    void enterCurrentTile(Player& player);

    // --- 던전 진행 상태 확인 함수 ---
    // 현재 층을 완료했는지 확인하는 함수
    bool isFloorCompleted() const;

    // 다음 층으로 진행하는 함수 (성공하면 true, 던전 전체 클리어 시 false 반환)
    bool advanceToNextFloor();

    // 던전 전체를 클리어했는지 확인하는 함수
    bool isDungeonCompleted() const;

    // --- 몬스터 생성 관련 함수 ---
    // 현재 층에 맞는 랜덤 몬스터를 생성하여 반환하는 함수
    // 이 함수는 MonsterTile::onEnter()에서 호출될 것입니다.
    std::unique_ptr<Monster> getRandomMonsterForCurrentFloor();

    // --- Getter 함수들 (정보 조회용) ---
    int getCurrentFloor() const { return currentFloor; }
    int getCurrentTileIndex() const { return currentTileIndex; }
    int getTilesPerFloor() const { return tilesPerFloor; }
    // 현재 칸의 설명을 반환하는 함수 (디버깅/표시용)
    std::string getCurrentTileDescription() const;
#pragma endregion

};

