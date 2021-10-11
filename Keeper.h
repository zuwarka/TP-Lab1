#pragma once
#include "Character.h"

using namespace std;

class Keeper
{
private:
	int m_size = 0;
	Character** m_data;

public:
	Keeper();
	Keeper(int size);
	~Keeper();

	Character*& operator[] (int index);

	int get_size();
	void erase(); //������� ������ �� �������
	void insert(Character* n_data, int index); //���������� � ������ ����� ��������
	void remove(int index);
	void save(); //��������� � ����
	void file_write(); //������ �� �����
};