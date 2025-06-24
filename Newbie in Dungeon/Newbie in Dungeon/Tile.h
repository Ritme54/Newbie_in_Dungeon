
#pragma once
#include <string>

class Player;

class Tile
{
public:
// �÷��̾ ĭ�� �������� �� ȣ��� ���� ���� �Լ�
// ��� �Ļ� Ŭ������ �� �Լ��� �ݵ�� �����ؾ� �մϴ�.
// = 0; �� �ٿ� ���� ���� �Լ��� ����� Tile Ŭ������ �߻� Ŭ������ �Ǿ� ��ü ������ �Ұ��������ϴ�.
    virtual void onEnter(Player& player) = 0;

    // ĭ�� ������ ���ڿ��� ��ȯ�ϴ� ���� ���� �Լ� (�����/ǥ�ÿ�)
    // ��� �Ļ� Ŭ������ �� �Լ��� �ݵ�� �����ؾ� �մϴ�.
    virtual std::string getDescription() const = 0;

   // �Ҹ��ڴ� �ݵ�� virtual�� �����ؾ� �մϴ�.
    // �������� ���� Tile* �����ͷ� �Ļ� Ŭ���� ��ü�� delete�� �� �ùٸ� �Ҹ��ڰ� ȣ��ǵ��� �մϴ�.
    // C++11 ���� default �Ҹ��� ��� ����
    virtual ~Tile() = default;
};

