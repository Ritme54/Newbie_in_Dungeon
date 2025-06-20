#pragma once
#include <string>

class Player;





class Monster
{
private:
    std::string name;
     int hp;//몬스터 체력
    int maxHp; // 몬스터 최대 체력
    int attack;// 공격력
    int defense;//방어력
    int expGiven;//드랍하는 경험치


public:
    Monster(std::string initialName, int initialHp, int initialAttack, int initialDefense, int initialExpGiven);
    void Attack(Player& targetPlayer); // 플레이어를 공격
    void TakeDamage(int damageAmount); //플레이어 공격으로 몬스터가 받는 데미지.
    void DisplayStatus() const;//화면에 생성될 몬스터 상태창 언제 얼마나 표시될지는 미정

    int GetHP() const; // 현재 체력을 반환
    int GetMaxHP() const; // 최대 체력을 반환
    int GetAttack() const; // 공격력을 반환
    int GetDefense() const; // 방어력을 반환
    int GetEXPValue() const; // 쓰러뜨렸을 때 주는 경험치 값을 반환
    std::string GetName() const; // 몬스터 이름을 반환

    bool IsAlive() const;//현재 살아있는지 확인

   virtual ~Monster();



};

