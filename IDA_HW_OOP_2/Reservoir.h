#pragma once

#include <string>
#include <iostream>
#include <fstream>
#include "Service functions.h"


struct Reservoir_parametrs
{
	//measerment unit - meters
	double depth;
	double width;
	double length;
	//enum form_type { square, round, complicity };
	char type_code; // 1 ocean 2 sea 3 lake 4 pool 5 small
};

struct Reservoir_fabric_parametrs
{
	//measerment unit - meters
	int max_reservoirs_amount;
	double max_depth;
	double max_width;
	double max_length;	
	//enum form_type { square, round, complicity };
	//char form_type_code;
};

class Reservoir
{
	std::string _name;
	int _index;
	Reservoir_parametrs _parametrs;
	//Reservoir* _reservoirs_list_ptr = nullptr;
	//void Set_reservoirs_list_ptr(Reservoir Reservoirs_dataset[])
	/*{
		_reservoirs_list_ptr = Reservoirs_dataset;
	}*/
public:
	Reservoir() {}
	explicit Reservoir(char just_non_default_flag);	
	explicit Reservoir(Reservoir copy_obj, int index);
	void Set_type();
	static void Reservoir_fabric(int Current_Reservoirs_amount,
		Reservoir Reservoirs_dataset[],
		Reservoir_fabric_parametrs fabric_parametrs);
	void Set_index(int index)	{ _index = index; }
	static void ShowMethods();
	void Set_parameters(Reservoir_parametrs random_parametrs);
	double Get_Volume_approx() { return (Get_Surface_area() * _parametrs.depth); }
	double Get_Surface_area() { return (_parametrs.length * _parametrs.width); }
	bool Is_type_equal(Reservoir obj_to_compare);
	double Area_compare(Reservoir obj_to_compare);
	static void Copy_reservoir(int& Current_Reservoirs_amount, Reservoir*& Reservoirs_dataset);
	static void ShowInfoSummary(int Current_Reservoirs_amount, Reservoir Reservoirs_dataset[]);
	void const ShowInfo_obj();
	std::string Get_type();
	static void UserChoiceHandle(int& Current_Reservoirs_amount, Reservoir*& Reservoirs_dataset);
	static void Save_to_file(int Current_Reservoirs_amount,
		Reservoir* Reservoirs_dataset,
		std::string operation_type);
	static std::string Summary_Info_to_string(int Current_Reservoirs_amount, Reservoir Reservoirs_dataset[]);
	std::string Obj_Info_to_string();
	static void Delete_reservoir(int& Current_Reservoirs_amount, Reservoir*& Reservoirs_dataset);
	static void Add_reservoir(int& Current_Reservoirs_amount, Reservoir*& Reservoirs_dataset);
	static void Memory_clean(Reservoir*& Reservoirs_dataset)	{ delete[] Reservoirs_dataset; }
	//~Reservoir() 
	//{
	////очищать память вроде имеет смысл по выходу из Task_2
	//	delete this; // не знаю работает так или нет?
	//	// не работает
	//	std::cout << "\nDestructor " << _name << " was called";
	//}


};

