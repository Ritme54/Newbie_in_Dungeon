#pragma once
#include <string>
#include <memory>       // std::unique_ptr
#include <vector>       // std::vector
#include <functional>   // std::function
#include <random>       // std::mt19937 (���� rng�� ����Ѵٸ� �ʿ� ����)

class Player;
class Monster;
class Dungeon; // Dungeon Ŭ������ ���� ���� �����̹Ƿ� ���� ����

extern std::mt19937 rng; // main.cpp

class GameManager
{
private:
	std::unique_ptr<Player> player;
	std::unique_ptr<Dungeon> dungeon;

};

