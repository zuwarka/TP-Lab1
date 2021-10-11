#pragma once

#include <string>
#include "Character.h"
using namespace std;

class Villain : public Character
{
private:
	string weapon = 0;
	string guilt = 0;
	string place = 0;
	float health = 0;
	float armor = 0;

public:
	Villain();
	~Villain();
	Villain(const Villain& Villain_copy);
	Villain(string name);

	string get_weapon();
	string set_weapon(string& weapon_ch);
	string get_guilt();
	string set_guilt(string& guilt_ch);
	string get_place();
	string set_place(string& place_ch);
	float get_health() const;
	float set_health(float& health_ch);
	float get_armor() const;
	float set_armor(float& armor_ch);

	virtual void show(); //будет переопределен для каждого наследника
	virtual void del(); //удаление по индексу массива
	virtual void insert(); //добавление элемента по индексу
	virtual void rewrite(); //перезапись данных (удаление + вставка)
};