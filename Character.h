#pragma once
//BASE
//Ѕазовый класс ѕерсонаж, в котором ообъ€влено только им€ (это общий элменет дл€ будущих трех наследников)
#include <iostream>
#include <string>

using namespace std;

class Character
{
protected:
	string name = 0;

public:
	Character();
	~Character();
	Character(const Character& Character_copy);

	string get_name();
	string set_name(string& name_ch);
};