#pragma once
#include <vector>
#include <string>
#include <iostream>
#include "Service functions.h"
#include <windows.h>
#include <map>
#include <iomanip>

//std::string _f_NAMES_[]{ "Olga", "Svetlana", "Oxana", "Irina", "Marina", "Alexandra", "Natalya" };
//std::string _m_NAMES_[]{ "Petr", "Daniil", "Oleg", "Igor", "Nikita", "Artem", "Sergio" };
//std::string _f_SURNAMES_[]{ "Platonova", "Makarova", "Popova", "Ivanova", "Starodubceva", "Yachmeneva", "Kalmykova" };
//std::string _m_SURNAMES_[]{ "Platonov", "Makarov", "Popov", "Ivanov", "Starodubcev", "Yachmenev", "Kalmykov" };
//std::map<int, int> _FLAT_NUMBERS_MAP_;
static std::string _f_NAMES_[]{ "Olga", "Svetlana", "Oxana", "Irina", "Marina", "Alexandra", "Natalya" };
static std::string _m_NAMES_[]{ "Petr", "Daniil", "Oleg", "Igor", "Nikita", "Artem", "Sergio" };
static std::string _f_SURNAMES_[]{ "Platonova", "Makarova", "Popova", "Ivanova", "Starodubceva", "Yachmeneva", "Kalmykova" };
static std::string _m_SURNAMES_[]{ "Platonov", "Makarov", "Popov", "Ivanov", "Starodubcev", "Yachmenev", "Kalmykov" };
//так придумал учитывать номер квартиры в привязке к номеру дома
// 1) без static не работает
// 2) как еще можно учесть номера квартир?
static std::map<int, int> _FLAT_NUMBERS_MAP_;
//std::map<int, int> _FLAT_NUMBERS_MAP_;

struct Flat_credentional
{
	int selected_house_index;
	int floor_number_index;
	int _flatObj_index;
	int selected_flat_number;
};

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
	inHabbitant(char random_flag);
	inHabbitant(inHabbitant* inHabbitant_obj);	
	void ShowInfo();	
};

class Flat
{
	int _flat_number;
	int inHabbitant_size = 5;
	// по заданию было про динамические массивы, но я заменил векторами, и так возни хватило
	//inHabbitant* inHabbitant_list_da = new inHabbitant[inHabbitant_size];
	std::vector<inHabbitant*> inHabbitant_list_vct;
public:
	Flat(int max_inHabbitans, int NewHouseNumber);
	int GetFlatNumber()	{	return _flat_number;	}
	int GetinHabbitansAmount()	{ return inHabbitant_list_vct.size(); }
	void ShowInfo();
	void AddNewinHabbitant(inHabbitant* tmp_ptr)	{inHabbitant_list_vct.push_back(tmp_ptr);}
	void DeleteinHabbitant(int selected_inHabbitant_index);
	inHabbitant* GetinHabbitantObj(int inHabbitant_index)	{ return inHabbitant_list_vct[inHabbitant_index]; }
	~Flat();
};

class Floor
{
	int _floor_number;
	std::vector<Flat*> _flats_list_vct;
public:
	Floor(int max_flats, int max_inHabbitans, int NextFloorNumer, int NewHouseNumber);
	int GetFloorNumber()	{ return _floor_number; }
	Flat*& GetFlatObj(int index)	{ return _flats_list_vct[index]; }
	int GetFlatAmount()	{ return _flats_list_vct.size(); }
	void ShowInfo();
	~Floor();
};

class House
{
	int _house_number;
	Floor* _floors_list_da;
	std::vector<Floor*> _floors_list_vct;
public:
	House(int max_floors, int max_flats, int max_inHabbitans, int NewHouseNumber);
	int GetHouseNumber()	{ return _house_number; }
	int GetFloorsTotal()	{ return _floors_list_vct.size(); }
	void ShowInfo();
	Floor* GetFloorObj(int floor_number)	{ return _floors_list_vct[floor_number]; }
	~House();
};

class Street
{
	std::string _street_name;
	std::vector<House*> House_list_vct;
	//static std::vector<House*> House_list_vct;
public:
	Street(std::string name) : _street_name(name) {}
	void RandomFill(int max_house, int max_floors, int max_flats, int max_inHabbitans);	
	void ShowInfo();
	static void ShowMethods();
	Flat_credentional LocationSpecify();
	void UserChoiceHandle();
	void CopyinHabbitant(Flat_credentional Flat_credentional_tmp);
	void AddNewinHabbitant(Flat_credentional Flat_credentional_tmp);
	void DeleteinHabbitant(Flat_credentional Flat_credentional_tmp);
	~Street();
};


