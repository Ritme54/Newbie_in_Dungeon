#pragma once
#include <string>
#include <memory>       // std::unique_ptr
#include <vector>       // std::vector
#include <functional>   // std::function
#include <random>       // std::mt19937 (전역 rng를 사용한다면 필요 없음)

class Player;
class Monster;
class Dungeon; // Dungeon 클래스도 이제 만들 예정이므로 전방 선언

extern std::mt19937 rng; // main.cpp

class GameManager
{
private:
	std::unique_ptr<Player> player;
	std::unique_ptr<Dungeon> dungeon;

};

