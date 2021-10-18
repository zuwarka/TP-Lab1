#pragma once
//BASE abstract
//������� ����� ��������, � ������� ���������� ������ ��� (��� ����� ������� ��� ������� ���� �����������)
#include "Library.h"

using namespace std;

class Character
{
public:
	Character() {};
	virtual ~Character() {};

	virtual void show() = 0; //����� ������������� ��� ������� ����������
	virtual void rewrite() = 0; //���������� ������ (�������� + �������)
	virtual void saving() = 0; //��������� ��� ��� ���� ���������
	virtual void redact_str(int num_str, string red_str) = 0; //��������������� ������
};

typedef struct Elem
{
	Character* m_data;
	Elem* next;
} Elem;