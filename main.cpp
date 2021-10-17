//¬ариант 5 -  ласс √ерои хранит данные о положительных геро€х, злоде€х и монстрах. ƒл€
//каждого геро€ определено : им€, тип оружи€, основные навыки(несколько).
//ƒл€ каждого злоде€ определено : им€, тип оружи€, какое злоде€ние совершил,
//где обитает, основные навыки. ƒл€ каждого монстра : наименование, описание
//внешнего вида.

#include <iostream>
#include <cstdlib>
#include <string>
#include <fstream>
#include "Character.h"
#include "Hero.h"
#include "Villain.h"
#include "Monster.h"
#include "Keeper.h"


using namespace std;

int main()
{
	Keeper list;
	Character* characters;
	string redact;
	int c1, c2, c3, exit = 1;
	int flag = 1;

	cout << "The 1(5) laba of TP welcome you!" << endl;
	while (exit == 1)
	{
		cout << "\nWhat do you want to do?" << endl;
		cout << "1 - Show all characters" << endl;
		cout << "2 - Change data of character" << endl;
		cout << "3 - Add new character" << endl;
		cout << "4 - Save all changes to the file" << endl;
		cout << "5 - Load data from the file" << endl;
		cout << "6 - Delete a character" << endl;
		cout << "0 - Exit" << endl;
		cout << "->  ";
		cin >> c1;

		switch (c1)
		{
		case 1: //1 - Show all characters
			system("cls");
			try
			{
				if (list.get_size() == 0)
				{
					throw "There's nothing to show.";
					break;
				}
				for (int i = 0; i < list.get_size(); i++)
				{
					list[i]->show();
				}
			}
			catch (const char* ex) { cout << ex << endl; }
			system("pause");
			break;
		case 2: //2 - Change data of character
			system("cls");
			try
			{
				cout << "What character do you want to change (from 1 to " << list.get_size() << ")?" << endl;
				cin >> c2;

				if (c2 < 1 || c2 > list.get_size())
				{
					throw "Incorrect number!";
					break;
				}

				list[c2-1]->show();
				cout << "What string do you want to change (except Character)?" << endl;
				cout << "->  ";
				cin >> c3;
				cin.ignore(32767, '\n');
				cout << "What do you want to put in this string?" << endl;
				cout << "->  ";
				getline(cin, redact);
				list[c2-1]->redact_str(c3, redact);
				cout << "The string was redacted." << endl;

			}
			catch (const char* ex) { cout << ex << endl; }
			system("pause");
			break;
		case 3: //3 - Add new character
			system("cls");
			cout << "\nWhat character do you want to add?" << endl;
			cout << "1 - Hero" << endl;
			cout << "2 - Villain" << endl;
			cout << "3 - Monster" << endl;
			cout << "0 - Go back" << endl;
			cout << "->  ";
			cin >> c2;

			switch (c2)
			{
			case 1:
				Hero * hero;
				hero = new Hero;
				characters = hero;
				hero->rewrite();
				list.insert(characters);
				cout << "The new character was added." << endl;
				break;
			case 2:
				Villain * villain;
				villain = new Villain;
				characters = villain;
				villain->rewrite();
				list.insert(characters);
				cout << "The new character was added." << endl;
				break;
			case 3:
				Monster * monster;
				monster = new Monster;
				characters = monster;
				monster->rewrite();
				list.insert(characters);
				cout << "The new character was added." << endl;
				break;
			default:
				break;
			}
			system("pause");
			break;
		case 4: //4 - Save all changes to the file
			system("cls");
			try
			{
				if (list.get_size() == 0)
				{
					throw "There's nothing to save.";
					break;
				}
				list.save();
				cout << "The data was saved to the file." << endl;
			}
			catch (const char* ex) { cout << ex << endl; }
			system("pause");
			break;
		case 5: //5 - Save all changes to the file
			system("cls");
			try
			{
				list.load();
				cout << "The data was loaded from file." << endl;
			}
			catch (const char* ex) { cout << ex << endl; }
			break;
		case 6: //6 - Delete a character
			system("cls");
			cout << "What character do you want to change (from 1 to " << list.get_size() << ")?" << endl;
			for (int i = 0; i < list.get_size(); i++)
			{
				list[i]->show();
			}
			cout << "->  ";
			cin >> c2;

			if (c2 < 1 || c2 > list.get_size())
			{
				throw "Incorrect number!";
				break;
			}

			list.remove(c2);
			cout << "The chosen character was deleted." << endl;

			system("pause");
			break;
		default:
			exit = 0;
			break;
		}
	}

	return 0;
}