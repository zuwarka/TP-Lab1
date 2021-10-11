#pragma once

#include <string>
#include "Character.h"
using namespace std;

class Monster : public Character
{
private:
	string description = 0;

public:
	Monster();
	~Monster();
	Monster(const Monster& Monster_copy);
	Monster(string name);

	string get_description();
	string set_descriprion(string& description_ch);

	virtual void show(); //будет переопределен для каждого наследника
	virtual void del(); //удаление по индексу массива
	virtual void insert(); //добавление элемента по индексу
	virtual void rewrite(); //перезапись данных (удаление + вставка)
};