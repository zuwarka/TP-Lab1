#pragma once
#include "Library.h"

class Menu
{
protected:
	Keeper list;
	Character* characters;
	string redact;
	int exit = 1;
public:
	void main_menu();
	int show_options();
	void show_all_characters();
	void change_data();
	void add_new();
	void save_to_file();
	void load_from_file();
	void delete_character();
	void exit_from_programm();
};