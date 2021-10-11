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
	void erase(); //стереть данные из массива
	void insert(Character* n_data, int index); //добавление в массив перед индексом
	void remove(int index);
	void save(); //сохранить в файл
	void file_write(); //чтение из файла
};