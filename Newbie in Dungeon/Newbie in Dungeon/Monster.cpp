// Monster.cpp (수정)

#include "Monster.h"
#include <iostream> // std::cout, std::endl 사용
#include <string>   // std::string 사용
#include "Player.h" // Attack, TakeDamage 함수에서 Player를 사용하므로 포함
#include <random>   // std::uniform_int_distribution 사용 (PerformTurnAction에서 랜덤 선택용)

// 전역 rng 선언 (main.cpp에 정의되어 있다고 가정)
extern std::mt19937 rng;

// Monster 생성자 정의
Monster::Monster(std::string initialName, int initialHp, int initialAttack, int initialDefense, int initialExpGiven)
	: name(initialName),
	hp(initialHp),
	maxHp(initialHp),
	attack(initialAttack),
	defense(initialDefense),
	expGiven(initialExpGiven),
	// ---전투 상태 관련 멤버 변수 초기화 ---
	isDefending(false),          // 몬스터 방어 상태 초기화
	isStunned(false),            // 기절 상태 초기화
	stunDuration(0),             // 기절 턴 초기화
	bleedTurns(0),               // 출혈 턴 초기화
	bleedDamagePerTurn(0),        // 출혈 피해량 초기화
	nextAction(MonsterAction::NONE) // 다음 행동 초기화
{
	// 생성자 본체 (필요하다면 추가 초기화)
}

#pragma region 행동 로직

// 몬스터의 기본 공격
void Monster::Attack(Player& targetPlayer)
{
	if (!IsAlive()) return;
	std::cout << GetName() << " (이)가 " << targetPlayer.GetName() << " (을)를 공격합니다." << std::endl; // 가독성 개선
	int damage = attack - targetPlayer.GetDefense();
	if (damage < 0) damage = 0;
	targetPlayer.TakeDamage(damage);
}

// 몬스터가 피해를 받는 함수 (방어 효과 적용)
void Monster::TakeDamage(int damageAmount)
{
	if (!IsAlive()) return;

	int actualDamage = damageAmount;
	if (isDefending) {
		actualDamage = damageAmount / 2; // 방어 시 피해 절반 (예시)
		std::cout << GetName() << " (은)는 방어하여 피해를 " << actualDamage << "로 줄였습니다!" << std::endl; // 가독성 개선
	}

	hp -= actualDamage;
	std::cout << GetName() << " (은)는 " << actualDamage << "의 피해를 입었습니다." << std::endl; // 가독성 개선

	if (hp <= 0)
	{
		hp = 0;
		std::cout << "체력: " << hp << "/" << maxHp << std::endl;
		std::cout << GetName() << " (이)가 쓰러졌습니다..." << std::endl; // GetName() 사용, 가독성 개선
	}
	else
	{
		std::cout << "체력: " << hp << "/" << maxHp << std::endl;
	}
}

// 몬스터 상태 표시
void Monster::DisplayStatus() const
{
	std::cout << "--- " << GetName() << "의 상태 ---" << std::endl; // GetName() 사용
	std::cout << "체력: " << hp << "/" << maxHp << std::endl;
	std::cout << "공격력: " << attack << std::endl;
	std::cout << "방어력: " << defense << std::endl;
	// 상태 이상 정보 추가
	if (isStunned) {
		std::cout << "상태: 기절 (" << stunDuration << "턴 남음)" << std::endl;
	}
	if (bleedTurns > 0) {
		std::cout << "상태: 출혈 (턴당 " << bleedDamagePerTurn << " 피해, " << bleedTurns << "턴 남음)" << std::endl;
	}
	std::cout << "-------------------------" << std::endl; // 중복된 줄 제거
}

// 몬스터의 턴에 호출될 기본 행동 (공격, 방어, 강공격을 확률적으로 수행)
void Monster::PerformTurnAction(Player& targetPlayer) {
	ResetTurnState(); // 턴 시작 시 상태 초기화 (쿨다운, 상태 이상 턴 감소)

	if (IsStunned()) { // 기절 상태면 행동 스킵
		std::cout << GetName() << " (이)가 기절하여 아무것도 할 수 없습니다!" << std::endl; // 가독성 개선
		return;
	}
	TakeBleedDamage(); // 출혈 피해 적용

	if (!IsAlive()) return; // 출혈로 죽었으면 행동 스킵

	// 몬스터의 행동 선택 (예시: 일반 공격 60%, 방어 20%, 강공격 20%)
	std::uniform_int_distribution<int> dist(1, 100); // 1부터 100까지의 난수
	int actionChoice = dist(rng);

	if (actionChoice <= 60) { // 1-60 (60%)
		Attack(targetPlayer); // 일반 공격
	}
	else if (actionChoice <= 80) { // 61-80 (20%)
		Defend(); // 방어
	}
	else { // 81-100 (20%)
		StrongAttack(targetPlayer); // 강공격
	}
}

// 몬스터의 방어 행동 (이제 virtual)
void Monster::Defend() {
	std::cout << GetName() << " (이)가 방어 자세를 취합니다!" << std::endl; // 가독성 개선
	isDefending = true;
}

// 몬스터의 강공격 (virtual)
void Monster::StrongAttack(Player& targetPlayer) {
	std::cout << GetName() << " (이)가 강력한 일격을 준비합니다!" << std::endl;
	int damage = static_cast<int>(attack * 1.8) - targetPlayer.GetDefense(); // 일반 공격력의 1.8배 (예시)
	if (damage < 0) damage = 0;
	targetPlayer.TakeDamage(damage);
}

// --- 상태 이상 적용 함수 ---
void Monster::ApplyStun(int duration) {
	isStunned = true;
	stunDuration = duration;
	std::cout << GetName() << " (이)가 " << duration << "턴 동안 기절했습니다!" << std::endl; // 가독성 개선
}

void Monster::ApplyBleed(int damage, int duration) {
	bleedDamagePerTurn = damage;
	bleedTurns = duration;
	std::cout << GetName() << " (이)가 " << duration << "턴 동안 매 턴 " << damage << "의 출혈 피해를 받습니다!" << std::endl; // 가독성 개선
}

// --- 턴 시작 시 상태 초기화 및 효과 적용 함수 ---
void Monster::ResetTurnState() {
	isDefending = false; // 방어 상태 해제

	// 기절 턴 감소
	if (isStunned && stunDuration > 0) {
		stunDuration--;
		if (stunDuration == 0) {
			isStunned = false;
			std::cout << GetName() << " (이)가 기절에서 깨어났습니다!" << std::endl; // 가독성 개선
		}
	}

	// 출혈 턴 감소
	if (bleedTurns > 0) {
		bleedTurns--;
		if (bleedTurns == 0) {
			bleedDamagePerTurn = 0; // 출혈 피해량 초기화
			std::cout << GetName() << " (의 출혈이 멈췄습니다!" << std::endl; // 가독성 개선
		}
	}
}

// 출혈 피해 적용
void Monster::TakeBleedDamage() {
	if (bleedTurns > 0 && bleedDamagePerTurn > 0) {
		std::cout << GetName() << " (이)가 출혈로 " << bleedDamagePerTurn << "의 피해를 입었습니다!" << std::endl; // 가독성 개선
		TakeDamage(bleedDamagePerTurn); // TakeDamage 함수 재사용
	}
}

#pragma region 행동 예고 출력문
// --- 몬스터 행동 예고 시스템 관련 함수 구현 ---
// 다음 턴에 수행할 행동을 결정 (기본 몬스터의 일괄 확률)
void Monster::DecideNextAction(Player& targetPlayer) {
	std::uniform_int_distribution<int> dist(1, 100); // 1부터 100까지의 난수
	int actionChoice = dist(rng);

	if (actionChoice <= 60) { // 1-60 (60%)
		nextAction = MonsterAction::ATTACK;
	}
	else if (actionChoice <= 80) { // 61-80 (20%)
		nextAction = MonsterAction::DEFEND;
	}
	else { // 81-100 (20%)
		nextAction = MonsterAction::STRONG_ATTACK;
	}
}

// 결정된 행동에 대한 예고 메시지 반환
std::string Monster::GetActionPredictionMessage() const {
	switch (nextAction) {
	case MonsterAction::ATTACK:
		return GetName() + " (이)가 당신을 노려봅니다!";
	case MonsterAction::DEFEND:
		return GetName() + " (이)가 몸을 웅크립니다!";
	case MonsterAction::STRONG_ATTACK:
		return GetName() + " (이)가 강력한 기운을 모읍니다!";
	case MonsterAction::SPECIAL_ABILITY: // 보스 몬스터에서 재정의될 것
		return GetName() + " (이)가 알 수 없는 힘을 발산합니다!";
	case MonsterAction::NONE:
		return GetName() + " (이)가 아무것도 하지 않습니다.";
	default:
		return GetName() + " (이)가 혼란스러워 보입니다.";
	}
}

// 결정된 행동을 실행
void Monster::ExecuteDecidedAction(Player& targetPlayer) {
	switch (nextAction) {
	case MonsterAction::ATTACK:
		Attack(targetPlayer);
		break;
	case MonsterAction::DEFEND:
		Defend();
		break;
	case MonsterAction::STRONG_ATTACK:
		StrongAttack(targetPlayer);
		break;
	case MonsterAction::SPECIAL_ABILITY:
		// 이 부분은 BossMonster에서 재정의하여 특수능력을 사용하도록 할 것입니다.
		// Monster 기본 클래스에서는 이 행동을 직접 수행하지 않습니다.
		std::cout << GetName() << " (이)가 특수능력을 사용하려 했으나 실패했습니다. (기본 몬스터는 특수능력 없음)" << std::endl;
		break;
	case MonsterAction::NONE:
		std::cout << GetName() << " (이)가 아무것도 하지 않습니다." << std::endl;
		break;
	}
	nextAction = MonsterAction::NONE; // 행동 실행 후 초기화
}

#pragma endregion







// --- 상태 조회 함수 ---
bool Monster::IsStunned() const {
	return isStunned;
}

#pragma endregion

#pragma region 상태 반환 (Getter 함수들)

int Monster::GetHP() const
{
	return hp;
}

int Monster::GetMaxHP() const
{
	return maxHp;
}

int Monster::GetAttack() const
{
	return attack;
}

int Monster::GetDefense() const
{
	return defense;
}

int Monster::GetEXPValue() const
{
	return expGiven;
}

std::string Monster::GetName() const
{
	return name;
}

bool Monster::IsAlive() const
{
	return hp > 0;
}

// 소멸자는 default로 선언했으므로, 특별한 자원 해제 로직이 없다면 .cpp 파일에 정의할 필요 없습니다.
// Monster::~Monster() = default;
