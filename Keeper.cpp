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
	assert(index >= 0 && index <= m_size); //�������� ������������ ������������� �������
	Character** data = new Character*[m_size+1]; //������� ����� ������ �� ���� ������� ������ ������� �������

	for (int before = 0; before < index; ++before) //�������� ��� �������� �� �� index
	{
		data[before] = m_data[before];
	}

	data[index] = n_data; //��������� ��� ����� ������� � ��� ����� ������

	for (int after = index; after < m_size; ++after) //�������� ��� �������� ����� ������������ ��������
	{
		data[after + 1] = m_data[after];
	}

	delete[] m_data;
	m_data = data;
	++m_size;
}

void Keeper::remove(int index)
{
	assert(index >= 0 && index <= m_size); //�������� ������������ ������������� �������
	if (m_size == 1) //���� ��� ��������� ������� �������, �� ������ ������ ������ � ��������� return
	{
		erase();
		return;
	}
	Character** data = new Character * [m_size + 1];

	for (int before = 0; before < index; ++before) //�������� ��� �������� �� �� index
	{
		data[before] = m_data[before];
	}
	for (int after = index+1; after < m_size; ++after) //�������� ��� �������� ����� ������������ ��������
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