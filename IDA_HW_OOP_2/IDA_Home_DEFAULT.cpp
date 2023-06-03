#include <iostream>
#include <string>
#include <windows.h>
#include <time.h>
#include <algorithm>
#include <conio.h>
//#include <array>
//My own headers
#include "Service functions.h"
#include "classes.h"



// Homework OOP_2 ----------------------------------------------------	

//Task 1 BigHouse
void Task_1()
{
	Street Lenina("Lenina");
	int max_house = 11, max_floors = 31, max_flats = 5, max_inHabbitans = 5;
	//Lenina.RandomFill(10, 30, 5, 5); // max_house, max_floors, max_flats
	Lenina.RandomFill(max_house, max_floors, max_flats, max_inHabbitans);
	
	do
	{
		system("cls");

		std::cout << "\nHouse class demonstration\n\n" << 
			"New dataset generated with following parametrs : \n";
		std::cout << "max_house" << max_house;
		std::cout << "\tmax_floors" << max_floors;
		std::cout << "\tmax_flats" << max_flats;
		std::cout << "\tmax_inHabbitans" << max_inHabbitans << "\n\n";

		Street::ShowMethods();
		Lenina.UserChoiceHandle();
		//Lenina.ShowInfo();


	} while (_getch() != 27);
}
//Task 2
void Task_2(){}
//Task 3
void Task_3() {}


// MAIN ------- MAIN ------- MAIN ------- MAIN ------- MAIN --------
int main()
{
	//setlocale(LC_CTYPE, "Russian");
	//system("mode con cols=110 lines=40"); 

	Main_menu MainMenu;	
	MainMenu.AddElement("OOP Home Work 2: Classes. Continue");	// Homework name
	MainMenu.AddElement("House with flats");		// Menu element 1
	MainMenu.AddElement("Reservour");				// Menu element 2
	//MainMenu.AddElement("XXX");

	do 
	{		
		MainMenu.Show_menu();
		if (!MainMenu.User_Choice_Handle())	break;
	} while (true);
	return 0;
}

