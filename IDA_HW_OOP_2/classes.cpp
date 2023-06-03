#include "classes.h"

//Main_menu::	
void Task_1();
void Task_2();
void Task_3();
void Main_menu::Show_menu()
{
	{
		system("cls");
		std::cout << "\n\t***\t" << _menu_elements[0] << "\t***\n\n\t\n\nChoose an option: \n";
		//for (int i=1; i< _menu_elements_number; i++)		
		for (int i = 1; i < _menu_elements.size(); i++)
			std::cout << "\n" << i << ". " << _menu_elements[i];
		std::cout << "\n\n 0. Exit\n";
		std::cout << "\nYour choice: ";
	}
}
int Main_menu::User_Choice_Handle()
{
	int choice = 0;
	choice = Get_Int_Positive();
	std::cout << "\n";
	// Обработка выбора пользователя
	if (choice == 0) { std::cout << "\nGood By"; for (int j = 0; j < 50; j++) { Sleep(50 - j); std::cout << "y"; } std::cout << "e!"; Sleep(850);  return 0; }

	else if (choice == 1) Task_1();
	else if (choice == 2) Task_2();
	else if (choice == 3) Task_3();
	//else if (choice == 4) Task_4();

	else { std::cout << "\nSuch choice does not exist yet\n"; Sleep(1000); }
	return 1;
}
void Main_menu::User_Choice_Handle(int key_code)
{
	switch (key_code)
		{
		case 1: break;
			//case:
		}
	
}

//::::::::::::::::::inHabbitant::inHabbitant::inHabbitant::::::::::::::::::
inHabbitant::inHabbitant()
{
	std::cout << "\nNew inHabbitant creating:\n\nEnter FIO: ";
	getline(std::cin, _FIO);
	std::cout << "Enter birth_year: ";
	_birth_year = Get_Int_Positive();
	std::cout << "Enter sex: Male[1] or Female[2]?";
	_sex = Get_Int_Positive();
	//Street.AddinHabbitant();
}
