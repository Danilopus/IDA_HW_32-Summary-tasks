#include <iostream>
#include <string>
#include <windows.h>
#include <time.h>

// Service functions prototypes ------------------------------------
int Get_Int_SA();			// String-analysis вариант фильтра INTEGER
int Get_Int_Positive();		// String-Analysis вариант проверки ввода INTEGER_POSITIVE		
template <typename ANY> void Array_Console_Out(ANY arr[], int Size);

// Homework 32 ----------------------------------------------------	

// Structures definition
struct arr
{
	int* pointer = nullptr;
	int length = 0;
} arr_object{};
struct route
{
	int number;
	char type;
	std::string begin;
	std::string end;
	double charge;
} r66{ 66,'A', "Avangard", "Compressorny", 52 };

//Task 1
template <typename ANY> void Swap_even_and_odd_in_array(ANY arr[], int Size)
{
	ANY* _pointer_arr = arr;
	for (int i = 0; i < Size / 2; i++)
		std::swap(*(_pointer_arr + i * 2), *(_pointer_arr + 1 + i * 2));
}

//void init(arr& arr_object)
void init()
{
	if (arr_object.pointer != nullptr) { std::cout << "\n\nArray is already initialised"; return; }
	std::cout << "\nEnter aray capacity: ";
	arr_object.length = Get_Int_Positive();
	int* array_of_float = new int[arr_object.length] {};
	arr_object.pointer = array_of_float;
	std::cout << "\nArray ["<< arr_object.length << "] of " << typeid(array_of_float[0]).name() << " is initialised";
	//typeid(array_of_float[0]).name();
}
//Task 2

//void show(const arr& arr_object)
void show()
{
	//arr_object.length--;
	if (arr_object.pointer == nullptr) { std::cout << "\n\nArray is not initialised"; return; }
	std::cout << "\n" << "Array:\n";
	Array_Console_Out(arr_object.pointer, arr_object.length); // Была заготовочка ))
}

//Task 3
//void app(arr& arr_object)
void app()
{
	if (arr_object.pointer == nullptr) { std::cout << "\n\nArray is not initialised"; return; }
	arr_object.length++;
	int* new_array_of_float = new int[arr_object.length];
	for (int i = 0; i < arr_object.length-1; i++)
	{
		new_array_of_float[i] = arr_object.pointer[i];
	}
	std::cout << "\nEnter a value " << typeid(arr_object.pointer[0]).name() << " to add in array: ";
	new_array_of_float[arr_object.length - 1] = Get_Int_SA();
	delete[] arr_object.pointer;
	arr_object.pointer = new_array_of_float;
	std::cout << "\nElement added";
}

//Task 4
void el(int index)
{
	if (arr_object.pointer == nullptr) { std::cout << "\n\nArray is not initialised"; return; }
	std::cout << "Array[" << index << "] -> " << arr_object.pointer[index];
}
void el_demo()
{
	if (arr_object.pointer == nullptr) { std::cout << "\n\nArray is not initialised"; return; }
	std::cout << "\nEnter an index: ";
	int index = Get_Int_Positive();
	if (index >= arr_object.length) { std::cout << "\n\nIndex is out of range [0.." << arr_object.length-1<<"]"; return; }
	el(index);
}

//Task 5
void clear()
{
	if (arr_object.pointer == nullptr) { std::cout << "\n\nArray is not initialised"; return; }
	delete[] arr_object.pointer;
	arr_object.pointer = nullptr;
	arr_object.length = 0;
}

//Task 6 
void string_change(std::string& Original_string, char ch1, char ch2)
{
	if (Original_string=="") { std::cout << "\n\nString is empty"; return; }
	int pos=0;
	char ch2_arr[2]{ ch2, '\0'};
	while ((pos = Original_string.find(ch1)) != std::string::npos) {
		Original_string.replace(pos, 1, ch2_arr);
	}
}
void string_change_demo()
{
	std::string User_input;
	std::cout << "\nEnter a string:\n";
	getline(std::cin, User_input);
	std::cout << "\nEnter a char to find a replace:\n";
	char ch1, ch2;	
	std::cin >> ch1;
	std::cout << "\nEnter a char to replace with:\n";	
	std::cin >> ch2;	
	string_change(User_input, ch1, ch2);
	std::cout << "Changed string:\n" << User_input;
}

//Task 7
void route_show()
{
	std::cout << "route.number " << r66.number << "\n";
	std::cout << "route.type   " << r66.type << "\n";
	std::cout << "route.begin  " << r66.begin << "\n";
	std::cout << "route.end    " << r66.end << "\n";
	std::cout << "route.charge " << r66.charge << " roubles"<< "\n";
}
double route_charge(int persons)
{
	return persons * r66.charge;
}
//Task 8
void route_charge_demo()
{
	std::cout << "\nHow many person: ";
	int Persons = Get_Int_Positive();
	std::cout << "Charge for " << Persons << " persons is " << route_charge(Persons) << " roubles" << "\n";
}

// MAIN ------- MAIN ------- MAIN ------- MAIN ------- MAIN --------
int main()
{
	setlocale(LC_CTYPE, "Russian");
	system("mode con cols=110 lines=40"); 
	std::string Name_of_Work = { "Home Work 32: Summary" };
	std::string Menu_Element_1 = { "Initialasation of array" };
	std::string Menu_Element_2 = { "Show array" };
	std::string Menu_Element_3 = { "Add an element to array" };
	std::string Menu_Element_4 = { "Show element []" };
	std::string Menu_Element_5 = { "Clear memory []" };
	std::string Menu_Element_6 = { "String char replace" };
	std::string Menu_Element_7 = { "Show route info" };
	std::string Menu_Element_8 = { "Calcute route charge" };
	
	do {		
		system("cls");
		std::cout << "\n\t***\t" << Name_of_Work << "\t***\n\n\t\n\nChoose an option: \n";
		std::cout << "\n 1. " << Menu_Element_1;
		std::cout << "\n 2. " << Menu_Element_2;
		std::cout << "\n 3. " << Menu_Element_3;
		std::cout << "\n 4. " << Menu_Element_4;
		std::cout << "\n 5. " << Menu_Element_5;
		std::cout << "\n\n 6. " << Menu_Element_6;
		std::cout << "\n\n 7. " << Menu_Element_7;
		std::cout << "\n 8. " << Menu_Element_8;

		std::cout << "\n\n 0. Exit\n";
		int choice = 0;
		std::cout << "\nYour choice: ";
		choice = Get_Int_Positive();		
		std::cout << "\n";
		// Обработка выбора пользователя
		if (choice == 0) { std::cout << "\nGood By"; for (int j = 0; j < 50; j++) { Sleep(50 - j); std::cout << "y"; } std::cout << "e!"; Sleep(850);  return 0; }
		else if (choice == 1) init();
		else if (choice == 2) show();
		else if (choice == 3) app();
		else if (choice == 4) el_demo();
		else if (choice == 5) clear(); 
		else if (choice == 6) string_change_demo();
		else if (choice == 7) route_show();
		else if (choice == 8) route_charge_demo();
					
		else { std::cout << "\nSuch choice does not exist yet\n"; Sleep(1000); }
		std::cout << "\n\n";
		system("pause");
		} while (true);
		
	//system("pause");
	return 0;
}

// Service functions -----------------------------------------
int Get_Int_SA() {
	std::string a;
	std::cin.sync(); 
	std::cin.clear(); 
	getline(std::cin, a);
	if (a != "")
	{

		if ((a.find_first_not_of("-0123456789") == -1))
		{
			for (int i = 1; i < a.size(); i++) // определяем есть ли минусы кроме первого символа
			{
				if (a[i] == '-') 
				{
					std::cout << "Input Error: Minus misstanding. [INTEGER] expected.\n";
					return Get_Int_SA();
				}
			}
			try
			{
				return stoi(a);
			}
			catch (std::out_of_range)
			{
				std::cout << "Input Error: Data type overflow. [INTEGER] expected.\n";
				return Get_Int_SA();
			}


		}
		else
		{
			std::cout << "Input Error: Incorrect symbol. [INTEGER] expected.\n";
			return Get_Int_SA();
		}
	}
	else
	{
		std::cout << "Input Error: NULL input. [INTEGER] expected.\n";
		return Get_Int_SA();
	}
}
int Get_Int_Positive()
{
	std::string a;
	std::cin.sync();
	std::cin.clear();
	getline(std::cin, a);
	if (a != "") 
	{

		if ((a.find_first_not_of("0123456789") == -1))
		{
			try{
				return stoi(a);
			}
			catch (std::out_of_range){
				std::cout << "Input Error: overflow. Positive [INTEGER] expected.\n";
			}
		}
		else
		{
			std::cout << "Input Error: Positive [INTEGER] expected.\n";
			return Get_Int_Positive();
		}		
	}
	else
		std::cout << "Input Error: NULL input. Positive [INTEGER] expected.\n";
	return Get_Int_Positive();
}
//*
//int Get_Int_PG()
//{
//	int a;
//	while (!(std::cin >> a) || (std::cin.peek() != '\n'))
//	{
//		std::cin.clear();
//		while (std::cin.get() != '\n');
//		std::cout << "Input error! [INTEGER] expected. Repeat please...\n";
//	}
//	return a;
//}
//double Get_Dbl_SA(){
//	std::string a;
//	std::cin.sync();
//	getline(std::cin, a);
//	if (a == "") { std::cout << "\nInput Error : NULL input\n"; return Get_Dbl_SA(); }
//	if ((a.find_first_not_of("-.0123456789") == -1))
//	{
//		for (int i = 1; i < a.size(); i++) // Проверяем отсутсвие лишних минусов
//		{
//			if (a[i] == '-')
//			{
//				std::cout << "\nInput Error: Minus misstanding. [DOUBLE] expected.\n";
//				return Get_Dbl_SA();
//			}
//
//		}
//		bool Dot_Flag = 0;
//		for (int i = 0; i < a.size(); i++) // проверяем отсутсвие лишних точек
//		{
//			if (a[i] == '.')
//			{
//				if (Dot_Flag == 1)
//				{
//					std::cout << "\nInput Error: Dot misstandig. [DOUBLE] expected.\n";
//					return Get_Dbl_SA();
//				}
//				Dot_Flag = 1;
//			}
//
//		}		 	
//				try{
//					return stod(a);
//				}
//				catch (std::out_of_range) {
//					std::cout << "Input Error: overflow. [DOUBLE] expected.\n";
//					return Get_Dbl_SA();					
//				}						
//	}
//	else {		
//		std::cout << "Incorrect symbols: [DOUBLE] expected.\nUse dot instead of coma. Example 50.64\n";
//		return Get_Dbl_SA();
//	}
//}
//double Get_Dbl_Positive(){
//	std::string a, dot = ".";
//	std::cin.sync();
//	std::cin.clear();
//	getline(std::cin, a);
//	if (a != "")
//	{
//		if ((a.find_first_not_of(".0123456789") == -1))
//		{
//			bool One_Dot_already = false;
//			for (int i = 0; i < a.size(); i++)
//			{				
//				if (a[i] == dot[0] && One_Dot_already == true) //проверяем количество разделителей
//				{
//					std::cout << "Input Error: Dot misstandig. Positive [DOUBLE] expected.\n";
//					return Get_Dbl_Positive();
//				}
//				if (a[i] == dot[0])	One_Dot_already = true;
//			}
//			try
//			{				
//				return stod(a);
//			}
//			catch (std::out_of_range)
//			{
//				std::cout << "Input Error: Data type overflow. Positive [DOUBLE] expected.\n";
//				return Get_Dbl_Positive();
//			}
//		}
//		else
//		{
//			//std::cout << "Incorrect symbols: positive REAL expected.\nUse coma instead of dot. Example 50,64\n"; // да точно говорю вот даже сообщение такое было, а теперь наоборот wtf*2?!
//			std::cout << "Incorrect symbols: Positive [DOUBLE] expected.\nUse dot instead of coma. Example 50.64\n";
//			return Get_Dbl_Positive();
//		}
//	}
//	else
//	{
//		std::cout << "Input Error: NULL input. Positive [DOUBLE] expected.\n";
//		return Get_Dbl_Positive();
//	}
//	return Get_Dbl_Positive();
//}
//double Get_Dbl_PG()
//{
//	double a;
//	while (!(std::cin >> a) || (std::cin.peek() != '\n'))
//	{
//		std::cin.clear();
//		while (std::cin.get() != '\n');
//		std::cout << "Input error! [DOUBLE] expected. Repeat please...\n";
//	}
//	return a;
//}
//int Get_Random(int Range_min=-999, int Range_max=999)
//{
//	if (Range_min > Range_max) 
//	{ 
//		std::cout << "\nError: Range_min > Range_max. New range: [Range_max..Range_min]\n";
//		std::swap(Range_min, Range_max);
//	}
//	//return (Range_min + rand() % (Range_max - Range_min + 1));
//	double K_random = double((rand() % RAND_MAX)) / RAND_MAX;
//	int random = Range_min + ((Range_max - Range_min) * K_random);
//	//return Range_min + (Range_max - Range_min) * (rand() % RAND_MAX) / RAND_MAX;
//	return random;
//}
//double Get_Random(double Range_min=-9999.0, double Range_max=9999.0)
//{
//	if (Range_min > Range_max)
//	{
//		std::cout << "\nError: Range_min > Range_max. New range: [Range_max..Range_min]\n";
//		std::swap(Range_min, Range_max);
//	}
//	return 	Range_min + (Range_max - Range_min) * double(rand() % RAND_MAX) / RAND_MAX;	
//}
template <typename ANY> void Array_Console_Out(ANY arr[], int Size)
{
	std::cout << "\n[";
	for (int i = 0; i < Size; i++)
		std::cout << arr[i] << ", ";
	std::cout << "\b\b]\n";
}
//template <typename ANY> void Fill_Array_with_Random(ANY arr[], int Size, ANY Range_min, ANY Range_max)
//{
//	for (int i = 0; i < Size; i++)
//	{
//		arr[i] = Get_Random(Range_min, Range_max);		
//	}
//}
//*/