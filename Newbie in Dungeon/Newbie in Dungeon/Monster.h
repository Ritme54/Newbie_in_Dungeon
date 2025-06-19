#pragma once
#include <string>
#include "Player.h"



class Monster
{
private:
    std::string name;//몬스터 이름
    int hp;//몬스터 체력
    int maxHp; // 몬스터 최대 체력
    int attack;// 공격력
    int defense;//방어력
    int expGiven;//드랍하는 경험치

public:
    Monster(string initialName, int instiallHp, int instiallAttack, int instiallDefense, int intialExpGiven);
    void Attack(Player& targetPlayer); // 플레이어를 공격
    void TakeDamage(int damageAmount); //플레이어 공격으로 몬스터가 받는 데미지.
 
    // 상태를 얻는 함수 (Getter) 선언
    int GetHP() const; // 현재 체력을 반환 (const)
    bool IsAlive() const; // 살아있는지 여부를 반환 (const)
    int GetEXPValue() const; // 쓰러뜨렸을 때 주는 경험치 값을 반환 (const)
    std::string GetName() const; // 몬스터 이름을 반환 (const)

    void DisplayStatus() const;//화면에 생성될 몬스터 상태창 언제 얼마나 표시될지는 미정

   virtual~Monster();



};

