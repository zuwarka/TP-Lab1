#pragma once

#include <string>
#include "Character.h"
using namespace std;

class Hero : public Character
{
private:
	string weapon = 0;
	float health = 0;
	float armor = 0;

public:
	Hero();
	~Hero();
	Hero(const Hero& Hero_copy);
	Hero(string name);

	string get_weapon();
	string set_weapon(string& weapon_ch);
	float get_health() const;
	float set_health(float& health_ch);
	float get_armor() const;
	float set_armor(float& armor_ch);

	virtual void show(); //будет переопределен для каждого наследника
	virtual void del(); //удаление по индексу массива
	virtual void insert(); //добавление элемента по индексу
	virtual void rewrite(); //перезапись данных (удаление + вставка)
};