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
	std::cout << "\nNew inHabbitant credentials:\n\nEnter FIO: ";
	getline(std::cin, _FIO);
	std::cout << "Enter birth_year: ";
	_birth_year = Get_Int_Positive();
	std::cout << "Enter sex: Male[1] or Female[2]?";
	_sex = Get_Int_Positive();
	//Street.AddinHabbitant();
}
inHabbitant::inHabbitant(char random_flag)
{
	_sex = Get_Random(1, 3);
	if (_sex == 1)
	{
		_FIO = _m_NAMES_[Get_Random(0, _m_NAMES_->size() - 1)] + " " + _m_SURNAMES_[Get_Random(0, _m_SURNAMES_->size() - 1)];
	}
	else
	{
		_FIO = _f_NAMES_[Get_Random(0, _f_NAMES_->size() - 1)] + " " + _f_SURNAMES_[Get_Random(0, _f_SURNAMES_->size() - 1)];
	}
	_birth_year = Get_Random(1950, 2023);
}
inHabbitant::inHabbitant(inHabbitant* inHabbitant_obj)
{
	_FIO = inHabbitant_obj->_FIO;
	_birth_year = inHabbitant_obj->_birth_year;
	_sex = inHabbitant_obj->_sex;
}
void inHabbitant::ShowInfo()
{
	std::cout << "\nFIO:        " << _FIO;
	std::cout << "\nBirth Year: " << _birth_year;
	if (_sex == 1)
		std::cout << "\nsex:        male";
	else
		std::cout << "\nsex:        female";
	std::cout << "\n\n";
}

//::::::::::::::::::Flat::Flat::Flat::::::::::::::::::
Flat::Flat(int max_inHabbitans, int NewHouseNumber)
{
	int inHabbitans_amount = Get_Random(max_inHabbitans / 2, max_inHabbitans + 1);
	for (int i = 0; i < inHabbitans_amount; i++)
	{
		inHabbitant* tmp_ptr = new inHabbitant(1);
		inHabbitant_list_vct.push_back(tmp_ptr);
	}
	_flat_number = ++_FLAT_NUMBERS_MAP_[NewHouseNumber]; //учитываем номера квартир в привязке к дому
}
void Flat::ShowInfo()
{
	std::cout << "\nFlat number " << _flat_number << " detailed inHabbitans info:\n";
	for (int i = 0; i < inHabbitant_list_vct.size(); i++)
	{
		std::cout << "[" << i + 1 << "]";
		inHabbitant_list_vct[i]->ShowInfo();
	}
}
void Flat::DeleteinHabbitant(int selected_inHabbitant_index)
{
	delete inHabbitant_list_vct[selected_inHabbitant_index];
	inHabbitant_list_vct.erase(inHabbitant_list_vct.begin() + selected_inHabbitant_index);
}
Flat::~Flat()
{
	for (int i = 0; i < inHabbitant_list_vct.size(); i++)
	{
		delete inHabbitant_list_vct[i];
	}
}

//::::::::::::::::::Floor::Floor::Floor::::::::::::::::::
Floor::Floor(int max_flats, int max_inHabbitans, int NextFloorNumer, int NewHouseNumber)
{
	for (int i = 0; i < max_flats; i++)
	{
		Flat* tmp_ptr = new Flat(max_inHabbitans, NewHouseNumber);
		_flats_list_vct.push_back(tmp_ptr);
	}
	//_floor_number = House::GetNewFloorNumber();
	_floor_number = NextFloorNumer;
}
void Floor::ShowInfo()
{
	std::cout << "Floor number " << _floor_number << " detailed info:\n\n";
	for (int i = 0; i < _flats_list_vct.size(); i++)
	{
		std::cout << "Flat N" << _flats_list_vct[i]->GetFlatNumber() <<
			"\t inHabbitans total: " << _flats_list_vct[i]->GetinHabbitansAmount() << "\n";
	}
}
Floor::~Floor()
{
	for (int i = 0; i < _flats_list_vct.size(); i++)
	{
		delete _flats_list_vct[i];
	}
}

//::::::::::::::::::House::House::House::::::::::::::::::
House::House(int max_floors, int max_flats, int max_inHabbitans, int NewHouseNumber)
{
	int floors_amount = Get_Random(max_floors / 2, max_floors + 1);
	for (int i = 0; i < floors_amount; i++)
	{
		Floor* tmp_ptr = new Floor(max_flats, max_inHabbitans, _floors_list_vct.size() + 1, NewHouseNumber);
		_floors_list_vct.push_back(tmp_ptr);
	}
	_house_number = NewHouseNumber;

}
void House::ShowInfo()
{
	std::cout << "Detailed information " <<
		"House number " << _house_number << "\n\n";
	for (int i = _floors_list_vct.size() - 1; i >= 0; i--)
	{
		std::cout << "floor" << std::setw(4) << _floors_list_vct[i]->GetFloorNumber() << "\tflats: ";

		_floors_list_vct[i]->GetFlatAmount();
		for (int ii = _floors_list_vct[i]->GetFlatAmount() - 1; ii >= 0; ii--)
		{
			std::cout << std::setw(3) << _floors_list_vct[i]->GetFlatObj(ii)->GetFlatNumber() << " | ";
		}
		std::cout << "\b\b \n";
		//_flats_list_vct.size() - квартир на этаже


			//for (int ii=0;i< _floors_list_vct.)
	}

}
House::~House()
{
	for (int i = 0; i < _floors_list_vct.size(); i++)
	{
		delete _floors_list_vct[i];
	}
}

//::::::::::::::::::Street::Street::Street::::::::::::::::::
void Street::RandomFill(int max_house, int max_floors, int max_flats, int max_inHabbitans)
{
	int house_amount = Get_Random(max_house / 2, max_house + 1);
	for (int i = 0; i < house_amount; i++)
	{
		int NewHouseNumber = House_list_vct.size() + 1;
		_FLAT_NUMBERS_MAP_[NewHouseNumber] = 0; //сбрасываю значения номеров квартир по ключу дома. Требуется для корректных повторных вызовов, поскольку map глобальный
		House* tmp_ptr = new House(max_floors, max_flats, max_inHabbitans, NewHouseNumber);
		House_list_vct.push_back(tmp_ptr);
	}
}
void Street::ShowInfo()
{
	std::cout << "\nStreet " << _street_name << " information:\n";
	std::cout << "\nNumbers of houses: " << House_list_vct.size();
	std::cout << "\n\nHouses information:\n";
	for (int i = 0; i < House_list_vct.size(); i++)
	{
		std::cout << _street_name << ", " << House_list_vct[i]->GetHouseNumber();
		std::cout << "\tfloors: " << House_list_vct[i]->GetFloorsTotal();

		int flats_total = _FLAT_NUMBERS_MAP_[House_list_vct[i]->GetHouseNumber()];
		std::cout << "\tflats total: " << flats_total;
		std::cout << "\n";
	}
	//<< House_list_vct.size();

}
void Street::ShowMethods()
{
	std::cout << "\nAvailable methods:\n";
	std::cout << "\n1) Show Street info ->" <<
		" Show House info [House number] ->" <<
		" Show Flat info [Flat number]";
	std::cout << "\n2) Add new inHabbitant";
	std::cout << "\n3) Delete inHabbitant";
	std::cout << "\n4) Copy inHabbitant";
	std::cout << "\nChoose a method: ";
	//std::cout << "\n";

}
Flat_credentional Street::LocationSpecify()
{
	int selected_house, floor_number, selected_flat_number, flatObj_index, flat_total_on_floor;

	//selected_method = Get_Int_Positive();
	ShowInfo();
	std::cout << "\nEnter a house number: ";
	selected_house = Get_Int_Positive();
	int selected_house_index = selected_house - 1; //траснсформируем номер в индекс
	House_list_vct[selected_house_index]->ShowInfo();

	std::cout << "\nEnter a floor number: ";
	floor_number = Get_Int_Positive();
	int floor_number_index = floor_number - 1; //траснсформируем номер в индекс
	House_list_vct[selected_house_index]->GetFloorObj(floor_number_index)->ShowInfo();

	std::cout << "\nEnter a flat number: ";
	selected_flat_number = Get_Int_Positive();
	flat_total_on_floor = House_list_vct[selected_house_index]->GetFloorObj(floor_number_index)->GetFlatAmount();

	for (int i = 0; i < flat_total_on_floor; i++)
	{
		if (selected_flat_number == House_list_vct[selected_house_index]->GetFloorObj(floor_number_index)->GetFlatObj(i)->GetFlatNumber())
			flatObj_index = i;
	}
	House_list_vct[selected_house_index]->GetFloorObj(floor_number_index)->GetFlatObj(flatObj_index)->ShowInfo();

	return { selected_house_index,  floor_number_index , flatObj_index, selected_flat_number };

}
void Street::UserChoiceHandle()
{
	//int selected_house_index, floor_number_index, flatObj_index, selected_flat_number;
	int selected_method = Get_Int_Positive();
	Flat_credentional Flat_credentional_tmp = LocationSpecify();

	//ShowInfo();
	//std::cout << "\nEnter a house number: ";
	//selected_house = Get_Int_Positive();
	//selected_house--; //траснсформируем номер в индекс
	//House_list_vct[selected_house]->ShowInfo();
	//
	//std::cout << "\nEnter a floor number: ";
	//floor_number = Get_Int_Positive();
	//floor_number--; //траснсформируем номер в индекс
	//House_list_vct[selected_house]->GetFloorObj(floor_number)->ShowInfo();
	//std::cout << "\nEnter a flat number: ";
	//selected_flat_number = Get_Int_Positive();
	//flat_total_on_floor = House_list_vct[selected_house]->GetFloorObj(floor_number)->GetFlatAmount();
	//for (int i = 0; i < flat_total_on_floor; i++)
	//{
	//	if (selected_flat_number == House_list_vct[selected_house]->GetFloorObj(floor_number)->GetFlatObj(i)->GetFlatNumber())
	//		flatObj_index = i;
	//}
	//House_list_vct[selected_house]->GetFloorObj(floor_number)->GetFlatObj(flatObj_index)->ShowInfo();

	switch (selected_method)
	{
	case 1:	break;
	case 2: AddNewinHabbitant(Flat_credentional_tmp); break;
	case 3: DeleteinHabbitant(Flat_credentional_tmp); break;
	case 4: CopyinHabbitant(Flat_credentional_tmp); break;
	}
}
void Street::CopyinHabbitant(Flat_credentional Flat_credentional_tmp)
{
	std::cout << "\nEnter number of inHabbitant to copy: ";
	int selected_inHabbitant = Get_Int_Positive();
	int selected_inHabbitant_index = selected_inHabbitant - 1;
	inHabbitant* obj_to_copy = House_list_vct[Flat_credentional_tmp.selected_house_index]
		->GetFloorObj(Flat_credentional_tmp.floor_number_index)
		->GetFlatObj(Flat_credentional_tmp._flatObj_index)
		->GetinHabbitantObj(selected_inHabbitant_index);
	 
	inHabbitant* created_from_copy_obj = new inHabbitant(obj_to_copy);

	std::cout << "\nSpecify where to copy selected inHabbitant:\n";
	Flat_credentional Flat_credentional_copy = LocationSpecify();
	House_list_vct[Flat_credentional_copy.selected_house_index]
		->GetFloorObj(Flat_credentional_copy.floor_number_index)
		->GetFlatObj(Flat_credentional_copy._flatObj_index)->AddNewinHabbitant(created_from_copy_obj);
	std::cout << "\ninHabbitant successfully copied\n";
	std::cout << "\nNew flat " << Flat_credentional_copy.selected_flat_number << " information:\n";
	House_list_vct[Flat_credentional_copy.selected_house_index]
		->GetFloorObj(Flat_credentional_copy.floor_number_index)
		->GetFlatObj(Flat_credentional_copy._flatObj_index)
		->ShowInfo();
}
void Street::AddNewinHabbitant(Flat_credentional Flat_credentional_tmp)
{
	std::cout << "\nAdding new inHabbitant at house number " << Flat_credentional_tmp.selected_house_index + 1 <<
		" at floor " << Flat_credentional_tmp.floor_number_index + 1 <<
		" in flat " << Flat_credentional_tmp.selected_flat_number;

	inHabbitant* tmp_ptr = new inHabbitant();
	House_list_vct[Flat_credentional_tmp.selected_house_index]
		->GetFloorObj(Flat_credentional_tmp.floor_number_index)
		->GetFlatObj(Flat_credentional_tmp._flatObj_index)->AddNewinHabbitant(tmp_ptr);

	/*	ShowInfo();
		std::cout << "\nAdd new inHabbitant in house number ";
		int selected_house = Get_Int_Positive();

		std::cout << "\nAdd new inHabbitant in house number " << selected_house << " at floor ";
		int selected_house = Get_Int_Positive();
		std::cout << "\nAdd new inHabbitant in house number";
		int selected_house = Get_Int_Positive()*/;

}
void Street::DeleteinHabbitant(Flat_credentional Flat_credentional_tmp)
{
	std::cout << "\nEnter number of inHabbitant to delete: ";
	int selected_inHabbitant = Get_Int_Positive();
	int selected_inHabbitant_index = selected_inHabbitant - 1;
	House_list_vct[Flat_credentional_tmp.selected_house_index]
		->GetFloorObj(Flat_credentional_tmp.floor_number_index)
		->GetFlatObj(Flat_credentional_tmp._flatObj_index)
		->DeleteinHabbitant(selected_inHabbitant_index);
}
Street::~Street()
{
	for (int i = 0; i < House_list_vct.size(); i++)
	{
		delete House_list_vct[i];
	}
}
