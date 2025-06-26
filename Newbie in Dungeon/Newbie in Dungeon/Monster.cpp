// Monster.cpp (����)

#include "Monster.h"
#include <iostream> // std::cout, std::endl ���
#include <string>   // std::string ���
#include "Player.h" // Attack, TakeDamage �Լ����� Player�� ����ϹǷ� ����
#include <random>   // std::uniform_int_distribution ��� (PerformTurnAction���� ���� ���ÿ�)

// ���� rng ���� (main.cpp�� ���ǵǾ� �ִٰ� ����)
extern std::mt19937 rng;

// Monster ������ ����
Monster::Monster(std::string initialName, int initialHp, int initialAttack, int initialDefense, int initialExpGiven)
	: name(initialName),
	hp(initialHp),
	maxHp(initialHp),
	attack(initialAttack),
	defense(initialDefense),
	expGiven(initialExpGiven),
	// ---���� ���� ���� ��� ���� �ʱ�ȭ ---
	isDefending(false),          // ���� ��� ���� �ʱ�ȭ
	isStunned(false),            // ���� ���� �ʱ�ȭ
	stunDuration(0),             // ���� �� �ʱ�ȭ
	bleedTurns(0),               // ���� �� �ʱ�ȭ
	bleedDamagePerTurn(0),        // ���� ���ط� �ʱ�ȭ
	nextAction(MonsterAction::NONE) // ���� �ൿ �ʱ�ȭ
{
	// ������ ��ü (�ʿ��ϴٸ� �߰� �ʱ�ȭ)
}

#pragma region �ൿ ����

// ������ �⺻ ����
void Monster::Attack(Player& targetPlayer)
{
	if (!IsAlive()) return;
	std::cout << GetName() << " (��)�� " << targetPlayer.GetName() << " (��)�� �����մϴ�." << std::endl; // ������ ����
	int damage = attack - targetPlayer.GetDefense();
	if (damage < 0) damage = 0;
	targetPlayer.TakeDamage(damage);
}

// ���Ͱ� ���ظ� �޴� �Լ� (��� ȿ�� ����)
void Monster::TakeDamage(int damageAmount)
{
	if (!IsAlive()) return;

	int actualDamage = damageAmount;
	if (isDefending) {
		actualDamage = damageAmount / 2; // ��� �� ���� ���� (����)
		std::cout << GetName() << " (��)�� ����Ͽ� ���ظ� " << actualDamage << "�� �ٿ����ϴ�!" << std::endl; // ������ ����
	}

	hp -= actualDamage;
	std::cout << GetName() << " (��)�� " << actualDamage << "�� ���ظ� �Ծ����ϴ�." << std::endl; // ������ ����

	if (hp <= 0)
	{
		hp = 0;
		std::cout << "ü��: " << hp << "/" << maxHp << std::endl;
		std::cout << GetName() << " (��)�� ���������ϴ�..." << std::endl; // GetName() ���, ������ ����
	}
	else
	{
		std::cout << "ü��: " << hp << "/" << maxHp << std::endl;
	}
}

// ���� ���� ǥ��
void Monster::DisplayStatus() const
{
	std::cout << "--- " << GetName() << "�� ���� ---" << std::endl; // GetName() ���
	std::cout << "ü��: " << hp << "/" << maxHp << std::endl;
	std::cout << "���ݷ�: " << attack << std::endl;
	std::cout << "����: " << defense << std::endl;
	// ���� �̻� ���� �߰�
	if (isStunned) {
		std::cout << "����: ���� (" << stunDuration << "�� ����)" << std::endl;
	}
	if (bleedTurns > 0) {
		std::cout << "����: ���� (�ϴ� " << bleedDamagePerTurn << " ����, " << bleedTurns << "�� ����)" << std::endl;
	}
	std::cout << "-------------------------" << std::endl; // �ߺ��� �� ����
}

// ������ �Ͽ� ȣ��� �⺻ �ൿ (����, ���, �������� Ȯ�������� ����)
void Monster::PerformTurnAction(Player& targetPlayer) {
	ResetTurnState(); // �� ���� �� ���� �ʱ�ȭ (��ٿ�, ���� �̻� �� ����)

	if (IsStunned()) { // ���� ���¸� �ൿ ��ŵ
		std::cout << GetName() << " (��)�� �����Ͽ� �ƹ��͵� �� �� �����ϴ�!" << std::endl; // ������ ����
		return;
	}
	TakeBleedDamage(); // ���� ���� ����

	if (!IsAlive()) return; // ������ �׾����� �ൿ ��ŵ

	// ������ �ൿ ���� (����: �Ϲ� ���� 60%, ��� 20%, ������ 20%)
	std::uniform_int_distribution<int> dist(1, 100); // 1���� 100������ ����
	int actionChoice = dist(rng);

	if (actionChoice <= 60) { // 1-60 (60%)
		Attack(targetPlayer); // �Ϲ� ����
	}
	else if (actionChoice <= 80) { // 61-80 (20%)
		Defend(); // ���
	}
	else { // 81-100 (20%)
		StrongAttack(targetPlayer); // ������
	}
}

// ������ ��� �ൿ (���� virtual)
void Monster::Defend() {
	std::cout << GetName() << " (��)�� ��� �ڼ��� ���մϴ�!" << std::endl; // ������ ����
	isDefending = true;
}

// ������ ������ (virtual)
void Monster::StrongAttack(Player& targetPlayer) {
	std::cout << GetName() << " (��)�� ������ �ϰ��� �غ��մϴ�!" << std::endl;
	int damage = static_cast<int>(attack * 1.8) - targetPlayer.GetDefense(); // �Ϲ� ���ݷ��� 1.8�� (����)
	if (damage < 0) damage = 0;
	targetPlayer.TakeDamage(damage);
}

// --- ���� �̻� ���� �Լ� ---
void Monster::ApplyStun(int duration) {
	isStunned = true;
	stunDuration = duration;
	std::cout << GetName() << " (��)�� " << duration << "�� ���� �����߽��ϴ�!" << std::endl; // ������ ����
}

void Monster::ApplyBleed(int damage, int duration) {
	bleedDamagePerTurn = damage;
	bleedTurns = duration;
	std::cout << GetName() << " (��)�� " << duration << "�� ���� �� �� " << damage << "�� ���� ���ظ� �޽��ϴ�!" << std::endl; // ������ ����
}

// --- �� ���� �� ���� �ʱ�ȭ �� ȿ�� ���� �Լ� ---
void Monster::ResetTurnState() {
	isDefending = false; // ��� ���� ����

	// ���� �� ����
	if (isStunned && stunDuration > 0) {
		stunDuration--;
		if (stunDuration == 0) {
			isStunned = false;
			std::cout << GetName() << " (��)�� �������� ������ϴ�!" << std::endl; // ������ ����
		}
	}

	// ���� �� ����
	if (bleedTurns > 0) {
		bleedTurns--;
		if (bleedTurns == 0) {
			bleedDamagePerTurn = 0; // ���� ���ط� �ʱ�ȭ
			std::cout << GetName() << " (�� ������ ������ϴ�!" << std::endl; // ������ ����
		}
	}
}

// ���� ���� ����
void Monster::TakeBleedDamage() {
	if (bleedTurns > 0 && bleedDamagePerTurn > 0) {
		std::cout << GetName() << " (��)�� ������ " << bleedDamagePerTurn << "�� ���ظ� �Ծ����ϴ�!" << std::endl; // ������ ����
		TakeDamage(bleedDamagePerTurn); // TakeDamage �Լ� ����
	}
}

#pragma region �ൿ ���� ��¹�
// --- ���� �ൿ ���� �ý��� ���� �Լ� ���� ---
// ���� �Ͽ� ������ �ൿ�� ���� (�⺻ ������ �ϰ� Ȯ��)
void Monster::DecideNextAction(Player& targetPlayer) {
	std::uniform_int_distribution<int> dist(1, 100); // 1���� 100������ ����
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

// ������ �ൿ�� ���� ���� �޽��� ��ȯ
std::string Monster::GetActionPredictionMessage() const {
	switch (nextAction) {
	case MonsterAction::ATTACK:
		return GetName() + " (��)�� ����� ������ϴ�!";
	case MonsterAction::DEFEND:
		return GetName() + " (��)�� ���� ��ũ���ϴ�!";
	case MonsterAction::STRONG_ATTACK:
		return GetName() + " (��)�� ������ ����� �����ϴ�!";
	case MonsterAction::SPECIAL_ABILITY: // ���� ���Ϳ��� �����ǵ� ��
		return GetName() + " (��)�� �� �� ���� ���� �߻��մϴ�!";
	case MonsterAction::NONE:
		return GetName() + " (��)�� �ƹ��͵� ���� �ʽ��ϴ�.";
	default:
		return GetName() + " (��)�� ȥ�������� ���Դϴ�.";
	}
}

// ������ �ൿ�� ����
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
		// �� �κ��� BossMonster���� �������Ͽ� Ư���ɷ��� ����ϵ��� �� ���Դϴ�.
		// Monster �⺻ Ŭ���������� �� �ൿ�� ���� �������� �ʽ��ϴ�.
		std::cout << GetName() << " (��)�� Ư���ɷ��� ����Ϸ� ������ �����߽��ϴ�. (�⺻ ���ʹ� Ư���ɷ� ����)" << std::endl;
		break;
	case MonsterAction::NONE:
		std::cout << GetName() << " (��)�� �ƹ��͵� ���� �ʽ��ϴ�." << std::endl;
		break;
	}
	nextAction = MonsterAction::NONE; // �ൿ ���� �� �ʱ�ȭ
}

#pragma endregion







// --- ���� ��ȸ �Լ� ---
bool Monster::IsStunned() const {
	return isStunned;
}

#pragma endregion

#pragma region ���� ��ȯ (Getter �Լ���)

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

// �Ҹ��ڴ� default�� ���������Ƿ�, Ư���� �ڿ� ���� ������ ���ٸ� .cpp ���Ͽ� ������ �ʿ� �����ϴ�.
// Monster::~Monster() = default;
