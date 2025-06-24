#pragma once
#include <vector>       // std::vector ���
#include <memory>       // std::unique_ptr ���
#include <functional>   // std::function ���
#include <random>       // std::mt19937, std::uniform_int_distribution ���

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
    int currentFloor;       // ���� �÷��̾ �ִ� �� (1���� ����)
    int totalFloors;        // ������ �� ����
    int tilesPerFloor;      // �� ���� �� ĭ �� (��: 100ĭ)
    int currentTileIndex;   // ���� ������ �÷��̾ �ִ� ĭ�� �ε��� (0���� ����)

    // ���� ���� ĭ ��ġ�� �����ϴ� ���� (�������� ���� Tile* �����͸� unique_ptr�� ����)
    std::vector<std::unique_ptr<Tile>> floorLayout;

    // �� ���� ���� ���� ���� �Լ� Ǯ
    // Dungeon Ŭ������ ���� Ǯ�� ���� �����մϴ�.
    std::vector<std::vector<std::function<std::unique_ptr<Monster>()>>> monsterPools;

    // --- private ���� �Լ� ---
    // �� ���� Ÿ�� ���̾ƿ��� �����ϴ� �Լ�
    // �� �Լ��� �����ڳ� advanceToNextFloor()���� ȣ��˴ϴ�.
    void generateFloorLayout(int floorNum);

public:
    Dungeon(int totalFloors, int tilesPerFloor,
        const std::vector<std::vector<std::function<std::unique_ptr<Monster>()>>>& pools);
    ~Dungeon() = default;

#pragma region �÷��̾� �̵� �Լ�
    // --- �÷��̾� �̵� �� ĭ �̺�Ʈ ���� �Լ� ---
// �÷��̾ ���� ĭ���� �̵���Ű�� �Լ�
    void movePlayer();

    // ���� �÷��̾ �ִ� ĭ�� �̺�Ʈ�� �����ϴ� �Լ�
    void enterCurrentTile(Player& player);

    // --- ���� ���� ���� Ȯ�� �Լ� ---
    // ���� ���� �Ϸ��ߴ��� Ȯ���ϴ� �Լ�
    bool isFloorCompleted() const;

    // ���� ������ �����ϴ� �Լ� (�����ϸ� true, ���� ��ü Ŭ���� �� false ��ȯ)
    bool advanceToNextFloor();

    // ���� ��ü�� Ŭ�����ߴ��� Ȯ���ϴ� �Լ�
    bool isDungeonCompleted() const;

    // --- ���� ���� ���� �Լ� ---
    // ���� ���� �´� ���� ���͸� �����Ͽ� ��ȯ�ϴ� �Լ�
    // �� �Լ��� MonsterTile::onEnter()���� ȣ��� ���Դϴ�.
    std::unique_ptr<Monster> getRandomMonsterForCurrentFloor();

    // --- Getter �Լ��� (���� ��ȸ��) ---
    int getCurrentFloor() const { return currentFloor; }
    int getCurrentTileIndex() const { return currentTileIndex; }
    int getTilesPerFloor() const { return tilesPerFloor; }
    // ���� ĭ�� ������ ��ȯ�ϴ� �Լ� (�����/ǥ�ÿ�)
    std::string getCurrentTileDescription() const;
#pragma endregion

};

