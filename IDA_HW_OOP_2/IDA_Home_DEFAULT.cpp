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
#include "Reservoir.h"




// Homework OOP_2 ----------------------------------------------------	

//Task 1 BigHouse
void Task_1()
{
	Street Lenina("Lenina");
	int max_house = 10, max_floors = 30, max_flats = 5, max_inHabbitans = 5;
	Lenina.RandomFill(max_house, max_floors, max_flats, max_inHabbitans);	
		do
	{
		system("cls");

		std::cout << "\nHouse class demonstration\n\n" << 
			"New dataset generated with following parametrs : \n";
		std::cout << "max_house = " << max_house;
		std::cout << "\tmax_floors = " << max_floors;
		std::cout << "\tmax_flats = " << max_flats;
		std::cout << "\tmax_inHabbitans = " << max_inHabbitans << "\n\n";

		Street::ShowMethods();
		Lenina.UserChoiceHandle();

		std::cout << "\nEsc - exit | any key to continue";
	} while (_getch() != 27);
}

//Task 2 Reservoir
void Task_2()
{
	//Reservoir_fabric_parametrs: max_reservoirs_amount, double max_depth, double max_width, double max_length
	//measerment unit - meters
	Reservoir_fabric_parametrs fabric_parametrs{ 1e1, 5e3, 1e7, 1e7 };

	int Current_Reservoirs_amount = Get_Random(fabric_parametrs.max_reservoirs_amount / 2, fabric_parametrs.max_reservoirs_amount);
	Reservoir* Reservoirs_dataset = new Reservoir[Current_Reservoirs_amount];
	Reservoir::Reservoir_fabric(Current_Reservoirs_amount, Reservoirs_dataset, fabric_parametrs);

	do
	{
		system("cls");

		std::cout << "\nReservoir class demonstration\n\n" <<
			"New dataset generated with following parametrs : \n";
		std::cout << "max_reservoirs_amount = " << fabric_parametrs.max_reservoirs_amount;
		std::cout << "\tmax_depth = " << fabric_parametrs.max_depth;
		std::cout << "\tmax_length = " << fabric_parametrs.max_length;
		std::cout << "\tmax_width = " << fabric_parametrs.max_width << "\n\n";

		Reservoir::ShowMethods();
		//так и не придумал как можно при внешнем хранении объектов получить к ним доступ не передавая параметров и не прописывая static хранилища
		Reservoir::UserChoiceHandle(Current_Reservoirs_amount, Reservoirs_dataset);

		std::cout << "\nEsc - exit | any key to continue";
	} while (_getch() != 27);
	// через деструктор не смог реализовать очистку памяти, только вот так
	Reservoir::Memory_clean(Reservoirs_dataset);
}
//Task 3
void Task_3() {}


// MAIN ------- MAIN ------- MAIN ------- MAIN ------- MAIN --------
int main()
{
	//setlocale(LC_CTYPE, "Russian");
	//system("mode con cols=100 lines=40"); 
	srand(time(NULL));

	Main_menu MainMenu;	
	MainMenu.AddElement("OOP Home Work 2: Classes. Continue");	// Homework name
	MainMenu.AddElement("House with flats");		// Menu element 1
	MainMenu.AddElement("Reservoir");				// Menu element 2
	//MainMenu.AddElement("XXX");

	do 
	{		
		MainMenu.Show_menu();
		if (!MainMenu.User_Choice_Handle())	break;
	} while (true);
	return 0;
}

