#pragma once
//BASE
//������� ����� ��������, � ������� ���������� ������ ��� (��� ����� ������� ��� ������� ���� �����������)
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