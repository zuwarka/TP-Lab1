#pragma warning( disable : 6386 )
#pragma warning( disable : 26451 )
#include <iostream>
#include <fstream>
#include <string>
#include <cassert>
#include "Keeper.h"

using namespace std;

Keeper::Keeper() : m_size(0), m_data(nullptr) {}
Keeper::Keeper(int size) : m_data(nullptr) { this->m_size = size; }
Keeper::~Keeper() { delete[] m_data; }

Character*& Keeper::operator[] (int index)
{
	assert(index >= 0 && index <= m_size);
	return m_data[index];
}

int Keeper::get_size() { return m_size; }

void Keeper::erase()
{
	delete[] m_data;
	m_data = nullptr;
	m_size = 0;
}

void Keeper::insert(Character* n_data, int index)
{
	assert(index >= 0 && index <= m_size); //Проверка корректности передаваемого индекса
	Character** data = new Character*[m_size+1]; //Создаем новый массив на один элемент больше старого массива

	for (int before = 0; before < index; ++before) //Копируем все элементы аж до index
	{
		data[before] = m_data[before];
	}

	data[index] = n_data; //Вставляем наш новый элемент в наш новый массив

	for (int after = index; after < m_size; ++after) //Копируем все значения после вставляемого элемента
	{
		data[after + 1] = m_data[after];
	}

	delete[] m_data;
	m_data = data;
	++m_size;
}

void Keeper::remove(int index)
{
	assert(index >= 0 && index <= m_size); //Проверка корректности передаваемого индекса
	if (m_size == 1) //Если это последний элемент массива, то делаем массив пустым и выполняем return
	{
		erase();
		return;
	}
	Character** data = new Character * [m_size + 1];

	for (int before = 0; before < index; ++before) //Копируем все элементы аж до index
	{
		data[before] = m_data[before];
	}
	for (int after = index+1; after < m_size; ++after) //Копируем все значения после вставляемого элемента
	{
		data[after - 1] = m_data[after];
	}

	delete[] m_data;
	m_data = data;
	--m_size;
}

void Keeper::save()
{
	ofstream outfile;
	string initfile = "data.txt";
	outfile.open(initfile);
	if (!outfile)
	{
		throw "Error opening!";
		exit(1);
	}


}