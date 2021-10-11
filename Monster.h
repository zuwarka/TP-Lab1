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

	virtual void show(); //����� ������������� ��� ������� ����������
	virtual void del(); //�������� �� ������� �������
	virtual void insert(); //���������� �������� �� �������
	virtual void rewrite(); //���������� ������ (�������� + �������)
};