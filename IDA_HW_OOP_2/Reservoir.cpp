#include "Reservoir.h"

Reservoir::Reservoir(char just_non_default_flag)
{
	std::cout << "\nAdding new reservoir\n";
	std::cout << "\nName -> ";
	getline(std::cin, _name);
	std::cout << "\nDepth average, meters -> ";
	_parametrs.depth = Get_Dbl_Positive();
	std::cout << "\nLength, meters -> ";
	_parametrs.length = Get_Dbl_Positive();
	std::cout << "\nWidth, meters -> ";
	_parametrs.width = Get_Dbl_Positive();
	Set_type();
}

Reservoir::Reservoir(Reservoir copy_obj, int index)
{
	_name = copy_obj._name;
	_parametrs = copy_obj._parametrs;
	_index = index;
}

void Reservoir::Reservoir_fabric(int Current_Reservoirs_amount, Reservoir Reservoirs_dataset[], Reservoir_fabric_parametrs fabric_parametrs)
{
	Reservoir_parametrs random_parametrs;
	for (int i = 0; i < Current_Reservoirs_amount; i++)
	{
		//Reservoirs_dataset[i]._parametrs.type_code = Get_Random(1, 6);
		random_parametrs.type_code = Get_Random(1, 6);

		switch (random_parametrs.type_code)
		{
		case 1:
			random_parametrs.depth = Get_Random(1e3, fabric_parametrs.max_depth);
			random_parametrs.length = Get_Random(1e6, fabric_parametrs.max_length);
			random_parametrs.width = Get_Random(1e6, fabric_parametrs.max_width);
			break;
		case 2:
			random_parametrs.depth = Get_Random(1e2, fabric_parametrs.max_depth / 1e1);
			random_parametrs.length = Get_Random(1e5, fabric_parametrs.max_length / 1e1);
			random_parametrs.width = Get_Random(1e5, fabric_parametrs.max_width / 1e1);
			break;
		case 3:
			random_parametrs.depth = Get_Random(1e1, fabric_parametrs.max_depth / 1e2);
			random_parametrs.length = Get_Random(1e2, fabric_parametrs.max_length / 1e3);
			random_parametrs.width = Get_Random(1e2, fabric_parametrs.max_width / 1e3);
			break;
		case 4:
			random_parametrs.depth = Get_Random(1e0, fabric_parametrs.max_depth / 1e3);
			random_parametrs.length = Get_Random(1e0, fabric_parametrs.max_length / 1e5);
			random_parametrs.width = Get_Random(1e0, fabric_parametrs.max_width / 1e5);
			break;
		case 5:
			random_parametrs.depth = Get_Random(1e-1, fabric_parametrs.max_depth / 5e3);
			random_parametrs.length = Get_Random(1e-1, fabric_parametrs.max_length / 1e7);
			random_parametrs.width = Get_Random(1e-1, fabric_parametrs.max_width / 1e7);
			break;
		}


		/*		random_parametrs.depth = Get_Random(0.1, fabric_parametrs.max_depth);
				random_parametrs.length = Get_Random(0.1, fabric_parametrs.max_length);
				random_parametrs.width = Get_Random(0.1, fabric_parametrs.max_width);*/


		Reservoirs_dataset[i].Set_parameters(random_parametrs);
		//Reservoirs_dataset[i].Set_type();
		//Reservoirs_dataset[i].Set_reservoirs_list_ptr(Reservoirs_dataset);
		Reservoirs_dataset[i].Set_index(i);
		Reservoirs_dataset[i]._name = Reservoirs_dataset[i].Get_type() + std::to_string(Get_Random(0, 100));
	}
}

void Reservoir::ShowMethods()
{
	std::cout << "\nAvailable methods:\n";
	std::cout << "\n1) Show reservoirs info";
	std::cout << "\n2) Add new reservoir";
	std::cout << "\n3) Delete reservoir";
	std::cout << "\n4) Make a copy of reservoir";
	std::cout << "\n5) Save reservoirs dataset to text file";
	std::cout << "\n6) Save reservoirs dataset to binary file";
	std::cout << "\nChoose a method: ";
	//std::cout << "\n";
}

void Reservoir::Set_parameters(Reservoir_parametrs random_parametrs)
{
	_parametrs.depth = random_parametrs.depth;
	_parametrs.length = random_parametrs.length;
	_parametrs.width = random_parametrs.width;
	_parametrs.type_code = random_parametrs.type_code;
}

bool Reservoir::Is_type_equal(Reservoir obj_to_compare)
{
	if (_parametrs.type_code == obj_to_compare._parametrs.type_code) return true;
	return false;
}

double Reservoir::Area_compare(Reservoir obj_to_compare) // возвращает коэф отношения площадей
{
	if (Is_type_equal(obj_to_compare)) return (Get_Surface_area() / obj_to_compare.Get_Surface_area());
	return -1;
}

void Reservoir::Copy_reservoir(int& Current_Reservoirs_amount, Reservoir*& Reservoirs_dataset)
{
	ShowInfoSummary(Current_Reservoirs_amount, Reservoirs_dataset);
	std::cout << "\n" << "Choose number of reservoir to copy -> ";
	int index_to_copy = Get_Int_Positive() - 1;
	Current_Reservoirs_amount++;
	Reservoir* new_Reservoirs_dataset = new Reservoir[Current_Reservoirs_amount];
	for (int i = 0; i < Current_Reservoirs_amount - 1; i++)
	{
		new_Reservoirs_dataset[i] = Reservoirs_dataset[i];
	}
	new_Reservoirs_dataset[Current_Reservoirs_amount - 1] = *(new Reservoir(Reservoirs_dataset[index_to_copy], Current_Reservoirs_amount - 1));
	delete[] Reservoirs_dataset;
	Reservoirs_dataset = new_Reservoirs_dataset;
	ShowInfoSummary(Current_Reservoirs_amount, Reservoirs_dataset);
	std::cout << "\nCopy OK";
}

void Reservoir::ShowInfoSummary(int Current_Reservoirs_amount, Reservoir Reservoirs_dataset[])
{
	for (int i = 0; i < Current_Reservoirs_amount; i++)
	{
		std::cout << "\nReservoir " << i + 1;
		Reservoirs_dataset[i].ShowInfo_obj();
	}
}

void Reservoir::Delete_reservoir(int& Current_Reservoirs_amount, Reservoir*& Reservoirs_dataset)
{
	ShowInfoSummary(Current_Reservoirs_amount, Reservoirs_dataset);
	std::cout << "\n" << "Choose number of reservoir to delete -> ";
	int index_to_delete = Get_Int_Positive() - 1;
	Current_Reservoirs_amount--;
	Reservoir* new_Reservoirs_dataset = new Reservoir[Current_Reservoirs_amount];
	for (int i = 0; i < Current_Reservoirs_amount; i++)
	{
		//if (i == index_to_delete) continue;
		if (i >= index_to_delete)
		{
			new_Reservoirs_dataset[i] = Reservoirs_dataset[i + 1];
			new_Reservoirs_dataset[i]._index--;
			continue;
		}
		new_Reservoirs_dataset[i] = Reservoirs_dataset[i];
	}
	delete[] Reservoirs_dataset;
	Reservoirs_dataset = new_Reservoirs_dataset;
	std::cout << "\nDeleting OK";
}

void Reservoir::Add_reservoir(int& Current_Reservoirs_amount, Reservoir*& Reservoirs_dataset)
{
	Current_Reservoirs_amount++;
	Reservoir* new_Reservoirs_dataset = new Reservoir[Current_Reservoirs_amount];
	for (int i = 0; i < Current_Reservoirs_amount - 1; i++)
	{
		new_Reservoirs_dataset[i] = Reservoirs_dataset[i];
	}
	// запись странная, но вроде так - разыменовываем, чтобы поместить именно объект Reservoir в последнюю ячейку массива
	new_Reservoirs_dataset[Current_Reservoirs_amount - 1] = *(new Reservoir('x')); //передача параметра чтобы вызвать конструктор не по умолчанию
	delete[] Reservoirs_dataset;
	Reservoirs_dataset = new_Reservoirs_dataset;
	ShowInfoSummary(Current_Reservoirs_amount, Reservoirs_dataset);
	std::cout << "\nAdding OK";
}
