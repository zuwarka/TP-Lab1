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

	string get_description();
	string set_descriprion(string& description_ch);