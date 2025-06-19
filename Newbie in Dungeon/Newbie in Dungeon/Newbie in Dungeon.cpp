#include <iostream>
#include <string>
#include "Player.h"
#include "Monster.h"
#include "Slime.h"


using namespace std;


int main()
{
	cout << "당신의 이름을 입력하세요." << endl;
	cout << "'한/영문자만 입력'" << endl;
	string name;
	getline(cin, name);
	
	Player user(name, 100, 10, 5);

	user.DisplayStatus();

	Slime GreenSlime;

	GreenSlime.DisplayStatus();



	return 0;


}

