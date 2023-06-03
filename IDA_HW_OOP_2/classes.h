#pragma once
#include <vector>
#include <string>
#include <iostream>
#include "Service functions.h"
#include <windows.h>
#include <map>

//std::string _f_NAMES_[]{ "Olga", "Svetlana", "Oxana", "Irina", "Marina", "Alexandra", "Natalya" };
//std::string _m_NAMES_[]{ "Petr", "Daniil", "Oleg", "Igor", "Nikita", "Artem", "Sergio" };
//std::string _f_SURNAMES_[]{ "Platonova", "Makarova", "Popova", "Ivanova", "Starodubceva", "Yachmeneva", "Kalmykova" };
//std::string _m_SURNAMES_[]{ "Platonov", "Makarov", "Popov", "Ivanov", "Starodubcev", "Yachmenev", "Kalmykov" };
//std::map<int, int> _FLAT_NUMBERS_MAP_;
static std::string _f_NAMES_[]{ "Olga", "Svetlana", "Oxana", "Irina", "Marina", "Alexandra", "Natalya" };
static std::string _m_NAMES_[]{ "Petr", "Daniil", "Oleg", "Igor", "Nikita", "Artem", "Sergio" };
static std::string _f_SURNAMES_[]{ "Platonova", "Makarova", "Popova", "Ivanova", "Starodubceva", "Yachmeneva", "Kalmykova" };
static std::string _m_SURNAMES_[]{ "Platonov", "Makarov", "Popov", "Ivanov", "Starodubcev", "Yachmenev", "Kalmykov" };
static std::map<int, int> _FLAT_NUMBERS_MAP_;

class Main_menu
{
	std::vector<std::string> _menu_elements;

public:
	void AddElement(std::string menu_element)	{	_menu_elements.push_back(menu_element);	}
	void Show_menu();
	int User_Choice_Handle();	
	void User_Choice_Handle(int key_code);
};

class inHabbitant
{
	std::string _FIO;
	int _birth_year;
	//enum sex {male=1, female=2};
	//sex sex_1;
	char _sex = 1; //1 male 2 female
public:
	//inHabbitant (std::string FIO, int birth_year, sex { male, female })
	inHabbitant(std::string FIO, int birth_year, char sex);
	inHabbitant();
	inHabbitant(char random_flag)
	{
		_sex = Get_Random(1, 3);
		if (_sex == 1)
		{
			_FIO = _m_NAMES_[Get_Random(0, _m_NAMES_->size())] + _m_SURNAMES_[Get_Random(0, _m_SURNAMES_->size())];
		}
		else
		{
			_FIO = _f_NAMES_[Get_Random(0, _f_NAMES_->size())] + _f_SURNAMES_[Get_Random(0, _f_SURNAMES_->size())];
		}
		_birth_year = Get_Random(1900, 2023);
	}
};

class Flat
{
	int _flat_number;
	int inHabbitant_size = 5;
	//inHabbitant* inHabbitant_list_da = new inHabbitant[inHabbitant_size];
	std::vector<inHabbitant*> inHabbitant_list_vct;
public:
	Flat(int max_inHabbitans, int NewHouseNumber)
	{
		int inHabbitans_amount = Get_Random(max_inHabbitans / 2, max_inHabbitans + 1);
		for (int i = 0; i < inHabbitans_amount; i++)
		{
			inHabbitant* tmp_ptr = new inHabbitant(1);
			inHabbitant_list_vct.push_back(tmp_ptr);
		}
		_flat_number = ++_FLAT_NUMBERS_MAP_[NewHouseNumber]; //учитываем номера квартир в привязке к дому
	}
	int GetFlatNumber()
	{
		return _flat_number;
	}
};

class Floor
{
	int _floor_number;
	std::vector<Flat*> _flats_list_vct;
public:
	Floor(int max_flats, int max_inHabbitans, int NextFloorNumer, int NewHouseNumber)
	{
		for (int i = 0; i < max_flats; i++)
		{
			Flat* tmp_ptr = new Flat(max_inHabbitans, NewHouseNumber);
			_flats_list_vct.push_back(tmp_ptr); 
		}
		//_floor_number = House::GetNewFloorNumber();
		_floor_number = NextFloorNumer;
	}
	int GetFloorNumber()
	{
		return _floor_number;
	}
	Flat*& GetFlatObj(int index)
	{
		return _flats_list_vct[index];
	}
	int GetFlatAmount()
	{
		return _flats_list_vct.size();
	}

};

class House
{
	int _house_number;
	Floor* _floors_list_da;
	std::vector<Floor*> _floors_list_vct;
public:
	House(int max_floors, int max_flats, int max_inHabbitans, int NewHouseNumber)
	{
		int floors_amount = Get_Random(max_floors / 2, max_floors + 1);
		for (int i = 0; i < floors_amount; i++)
		{
			Floor* tmp_ptr = new Floor(max_flats, max_inHabbitans, _floors_list_vct.size()+1, NewHouseNumber);
			_floors_list_vct.push_back(tmp_ptr);
		}
		//_house_number = Street::GetNewHouseNumber(); //????
		_house_number = NewHouseNumber;

	}
	//static int GetNewFloorNumber()
	//{
	//	return _floors_list_vct.size(); //???
	//}
	int GetHouseNumber()
	{
		return _house_number;
	}
	int GetFloorsTotal()
	{
		return _floors_list_vct.size();;
	}
	void ShowInfo()
	{
		std::cout << "Detailed information " <<
			"House number " << _house_number << "\n\n";
		for (int i = _floors_list_vct.size()-1; i >= 0; i--)
		{
			std::cout << "floor  " << _floors_list_vct[i]->GetFloorNumber() <<"\tflats: ";
			
			_floors_list_vct[i]->GetFlatAmount();
			for (int ii = _floors_list_vct[i]->GetFlatAmount() - 1; ii >= 0; ii--)
			{
				std::cout << _floors_list_vct[i]->GetFlatObj(ii)->GetFlatNumber() << " | ";
			}
			std::cout << "\b\b \n";
			//_flats_list_vct.size() - квартир на этаже
			
		
				//for (int ii=0;i< _floors_list_vct.)
		}

	}
};

class Street
{
	std::string _street_name;
	std::vector<House*> House_list_vct;
	//static std::vector<House*> House_list_vct;
public:
	Street(std::string name) : _street_name(name) {}
	void RandomFill(int max_house, int max_floors, int max_flats, int max_inHabbitans)
	{
		int house_amount = Get_Random(max_house / 2, max_house + 1);
		for (int i = 0; i < house_amount; i++)
		{
			int NewHouseNumber = House_list_vct.size();
			House* tmp_ptr = new House(max_floors, max_flats, max_inHabbitans, ++NewHouseNumber);
			House_list_vct.push_back(tmp_ptr);
		}
	}
	void AddinHabbitant()
	{
		//заселяем жильца в конкретный дом, этаж, квартиру 
	}
	//int GetNewHouseNumber()
	//static int GetNewHouseNumber()
	//{
	//	return House_list_vct.size();
	//}
	void ShowInfo()
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
	static void ShowMethods()
	{
		std::cout << "\nAvailable methods:\n";
		std::cout << "\n1) Show Street info\n" <<
			"2) Show House info [House number]\n" <<
			"3) Show Flat info [Flatr number]\n\n";
	}
	void UserChoiceHandle()
	{
		switch (Get_Int_Positive())
		{
		case 1: ShowInfo(); break;
		case 2: 
			std::cout << "\nEnter a house number: ";
			House_list_vct[Get_Int_Positive()-1]->ShowInfo();
		}
	}
};