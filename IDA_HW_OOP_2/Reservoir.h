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
	/*Reservoir(Reservoir* Reservoirs_dataset, Reservoir_fabric_parametrs fabric_parametrs)
	{
		_parametrs.depth = Get_Random(fabric_parametrs.max_depth /10, fabric_parametrs.max_depth);
		_parametrs.length = Get_Random(fabric_parametrs.max_length / 10, fabric_parametrs.max_length);
		_parametrs.width = Get_Random(fabric_parametrs.max_width / 10, fabric_parametrs.max_width);
		_parametrs.type_code = Get_Random(1, 5);
		
		Reservoirs_dataset[] = this;
	}*/
	explicit Reservoir(Reservoir copy_obj, int index);
	void Set_type()
	{
		double Surface_area = Get_Surface_area();
		if (Surface_area > 1e12)
			_parametrs.type_code =  1;
		else if (Surface_area > 1e10)
			_parametrs.type_code = 2;
		else if (Surface_area > 1e4)
			_parametrs.type_code = 3;
		else if (Surface_area > 1e2)
			_parametrs.type_code = 4;
		else 
			_parametrs.type_code = 5;	
	}
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
	void const ShowInfo_obj()
	{
		std::cout << "\n" << "name:          " << _name;
		std::cout << "\n" << "type:          " << Get_type();
		std::cout << "\n" << "depth:         " << _parametrs.depth << " meters";
		std::cout << "\n" << "surface area:  " << Get_Surface_area() << " sqr meters";
		std::cout << "\n" << "approx volume: " << Get_Volume_approx() << " cubic meters";
		std::cout << "\n";
	}
	std::string Get_type()
	{
		switch (_parametrs.type_code)
		{
		case 1: return "ocean";
		case 2: return "sea";
		case 3: return "lake";
		case 4: return "pool";
		case 5: return "small reservoir";
		}
		return "unknown";
	}
	static void UserChoiceHandle(int& Current_Reservoirs_amount, Reservoir*& Reservoirs_dataset)
	{
		int selected_method = Get_Int_Positive();
		switch (selected_method)
		{
		case 1:	Reservoir::ShowInfoSummary(Current_Reservoirs_amount, Reservoirs_dataset);  break;
		case 3: Reservoir::Delete_reservoir(Current_Reservoirs_amount, Reservoirs_dataset); break;
		case 2: Reservoir::Add_reservoir(Current_Reservoirs_amount, Reservoirs_dataset); break;
		case 4: Reservoir::Copy_reservoir(Current_Reservoirs_amount, Reservoirs_dataset); break;
		case 5: Reservoir::Save_to_file(Current_Reservoirs_amount, Reservoirs_dataset, ".txt"); break;
		case 6: Reservoir::Save_to_file(Current_Reservoirs_amount, Reservoirs_dataset, ".bin"); break;


		}
	}
	static void Save_to_file(int Current_Reservoirs_amount, Reservoir* Reservoirs_dataset, std::string operation_type)
	{
		std::string file_name;
		std::cout << "\nEnter a file name ->";
		getline(std::cin, file_name);
		if (file_name == "") file_name = "Reservoir_dataset";
		file_name += operation_type;
		std::ofstream file_stream_obj;
		if (operation_type == ".txt")			
			file_stream_obj.open(file_name);		
		else if (operation_type == ".bin")		
			file_stream_obj.open(file_name, std::ios::binary);		

		if (file_stream_obj.is_open())
		{
			file_stream_obj << Summary_Info_to_string(Current_Reservoirs_amount, Reservoirs_dataset);
		}
		file_stream_obj.close();
		std::cout << "\nData saved to " << file_name << " - OK\n";
	}
	static std::string Summary_Info_to_string(int Current_Reservoirs_amount, Reservoir Reservoirs_dataset[])
	{
		std::string tmp_str;
		for (int i = 0; i < Current_Reservoirs_amount; i++)
		{
			tmp_str += "\nReservoir " + std::to_string(i + 1) + Reservoirs_dataset[i].Obj_Info_to_string();
		}
		return tmp_str;
	}
	std::string Obj_Info_to_string()
	{
		std::string tmp_str;
		//tmp_str = "\n" + "name:          " + _name
		tmp_str = "\nname:          " + _name
		+ "\n" + "type:          " + Get_type()
		+ "\n" + "depth:         " + std::to_string(_parametrs.depth)
		+ "\n" + "surface area:  " + std::to_string(Get_Surface_area()) + " sqr m"
		+ "\n" + "approx volume: " + std::to_string(Get_Volume_approx()) + " cubic m" + "\n";
		return tmp_str;
	}	
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

