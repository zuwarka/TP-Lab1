#pragma once
//BASE abstract
//������� ����� ��������, � ������� ���������� ������ ��� (��� ����� ������� ��� ������� ���� �����������)
#include <iostream>
#include <string>

using namespace std;

class Character
{
protected:
	string name;
	int level = 0;

public:
	Character() {};
	Character(string name_ch) : name(name_ch) {};
	virtual ~Character() {};

	string get_name() { return name; };
	string set_name(string& name_ch) { name = name_ch; };
	int get_level() { return level; };
	int set_level(int& level_ch) { level = level_ch; };

	virtual void show() = 0; //����� ������������� ��� ������� ����������
	virtual void del() = 0; //�������� �� ������� �������
	virtual void insert() = 0; //���������� �������� �� �������
	virtual void rewrite() = 0; //���������� ������ (�������� + �������)
};