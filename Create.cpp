/** @file  */

#include "Create.h"

#include <iostream>
#include <fstream>

/**
Metoda kt�ra wczytuje graf z pliku wskazanego przez u�ytkownika
@param DATA Wska�nik na referencje do obiektu typu Data w kt�rym przechowywane s� wszystkie inne obiekty na kt�rych operuje program
@return Zwraca informacj� o poprawno�ci wykonania metody i wyst�pieniu ewentualnego b��du
*/
bool Create::LoadGraph(Data*& DATA)
{
	std::ifstream FILE;

	FILE.open(DATA->P->paths[0].c_str(), std::ios::in);

	if (FILE.fail())
	{
		std::cout << C("B��d otwarcia pliku z grafem!") << std::endl;
		return false;
	}
	else
	{

		while (!FILE.eof())
		{
			Graph* t_graph = new Graph;
			Borderer* t_borderer = nullptr;

			char sign = '\0';
			unsigned long int top = 0;
			unsigned long int number = 0;
			double metrics = 0;

			bool flag = true;

			FILE >> top >> sign;
			if (sign != ':')
			{
				if (sign != ' ' && sign != '\n' && sign != '\0')
				{
					std::cout << C("B��dny format danych w pliku z grafem!") << std::endl;
					return false;
				}
			}
			else
			{
				t_graph->top = new Primal;
				t_graph->top->number = top;

				while (flag == true)
				{
					FILE >> number >> metrics >> sign;

					if (sign != ';')
					{
						if (sign != ' ' && sign != '\n' && sign != '\0')
						{
							std::cout << C("B��dny format danych w pliku z grafem!") << std::endl;
							return false;
						}
					}
					else
					{
						t_borderer = new Borderer;

						t_borderer->number = number;
						t_borderer->metrics = metrics;

						Borderer::AddBordererByNumber(t_graph->BTops, t_borderer);

						t_borderer = nullptr;
					}

					if (FILE.peek() == '\n' || FILE.eof())
					{
						flag = false;
					}

				}
				Graph::AddGraphByTop(DATA->G, t_graph);
				t_graph = nullptr;
			}
		}
	}

	FILE.close();

	return true;
}

/**
Metoda kt�ra tworzy graf na podstawie informacji od u�ytkownika
@param DATA Wska�nik na referencje do obiektu typu Data w kt�rym przechowywane s� wszystkie inne obiekty na kt�rych operuje program
@return Zwraca informacj� o poprawno�ci wykonania metody i wyst�pieniu ewentualnego b��du
*/
bool Create::CreateGraph(Data*& DATA)
{
	bool TopD = true;
	bool BordererD = true;

	Graph* t_graph = nullptr;
	Borderer* t_borderer = nullptr;
	std::string answer;

	std::cout << C("Kreator tworzenia graf�w!") << std::endl;
	while (TopD == true)
	{
		t_graph = new Graph;

		std::cout << C("Podaj numer wierzcho�ka: ");
		t_graph->top = new Primal;
		std::cin >> t_graph->top->number;
		while (BordererD == true)
		{
			t_borderer = new Borderer;
			std::cout << C("Podaj numer s�siada: ");
			std::cin >> t_borderer->number;
			std::cout << C("Podaj metryk� mi�dzy wierzcho�kiem a s�siadem: ");
			std::cin >> t_borderer->metrics;

			system("cls");

			Borderer::AddBordererByNumber(t_graph->BTops, t_borderer);

			std::cout << C("Czy chcesz poda� kolejnego s�siada? Je�li tak wpisz 'Tak', a je�li nie 'Nie': ");
			std::cin >> answer;
			if (answer == "Tak")
			{
				BordererD = true;
			}
			else if (answer == "Nie")
			{
				BordererD = false;
			}
			else
			{
				std::cout << C("B��dna odpowied�!") << std::endl;
				return false;
			}

			system("cls");
		}

		BordererD = true;

		Graph::AddGraphByTop(DATA->G, t_graph);

		std::cout << C("Czy chcesz poda� kolejny wierzcho�ek? Je�li tak wpisz 'Tak', a je�li nie 'Nie': ");
		std::cin >> answer;
		if (answer == "Tak")
		{
			TopD = true;
		}
		else if (answer == "Nie")
		{
			TopD = false;
		}
		else
		{
			std::cout << C("B��dna odpowied�!") << std::endl;
			return false;
		}

		system("cls");
	}

	std::cout << C("Graf zosta� uko�czony!") << std::endl;

	return true;
}

/**
Metoda kt�ra wczytuje dane z pliku wskazanego przez u�ytkownika
@param DATA Wska�nik na referencje do obiektu typu Data w kt�rym przechowywane s� wszystkie inne obiekty na kt�rych operuje program
@return Zwraca informacj� o poprawno�ci wykonania metody i wyst�pieniu ewentualnego b��du
*/
bool Create::LoadData(Data*& DATA)
{
	std::ifstream FILE;

	FILE.open(DATA->P->paths[1].c_str(), std::ios::in);

	if (FILE.fail())
	{
		std::cout << C("B��d otwarcia pliku z danymi!") << std::endl;
		return false;
	}
	else
	{

		while (!FILE.eof())
		{
			DataTops* t_D = new DataTops;
			Primal* t_Dtops = nullptr;

			char sign = '\0';
			unsigned long int top = 0;
			unsigned long int number = 0;

			bool flag = true;

			FILE >> top >> sign;
			if (sign != ':')
			{
				if (sign != ' ' && sign != '\n' && sign != '\0')
				{
					std::cout << C("B��dny format danych w pliku z danymi!") << std::endl;
					return false;
				}
			}
			else
			{
				t_D->top = new Primal;
				t_D->top->number = top;

				while (flag == true)
				{
					FILE >> number >> sign;

					if (sign != ';')
					{
						if (sign != ' ' && sign != '\n' && sign != '\0')
						{
							std::cout << C("B��dny format danych w pliku z danymi!") << std::endl;
							return false;
						}
					}
					else
					{
						t_Dtops = new Primal;

						t_Dtops->number = number;

						Primal::AddPrimalByNumber(t_D->Dtops, t_Dtops);
						t_Dtops = nullptr;
					}

					if (FILE.peek() == '\n' || FILE.eof())
					{
						flag = false;
					}

				}

				DataTops::AddDataTopsByTop(DATA->D, t_D); //przeci�� operator przypisania
				t_D = nullptr;
			}
		}
	}

	FILE.close();

	return true;
}

/**
Metoda kt�ra tworzy dane na podstawie informacji od u�ytkownika
@param DATA Wska�nik na referencje do obiektu typu Data w kt�rym przechowywane s� wszystkie inne obiekty na kt�rych operuje program
@return Zwraca informacj� o poprawno�ci wykonania metody i wyst�pieniu ewentualnego b��du
*/
bool Create::CreateData(Data*& DATA)
{
	bool TopD = true;
	bool DestinationD = true;

	DataTops* t_data = nullptr;
	Primal* t_dtops = nullptr;
	std::string answer;

	std::cout << C("Kreator tworzenia danych!") << std::endl;
	while (TopD == true)
	{
		t_data = new DataTops;

		std::cout << C("Podaj numer wierzcho�ka dla kt�rego chcesz wyzanczy� metryki: ");
		t_data->top = new Primal;
		std::cin >> t_data->top->number;
		while (DestinationD == true)
		{
			t_dtops = new Primal;
			std::cout << C("Podaj numer wierzcho�ka do kt�rego chcesz wyznaczy� metryk�: ");
			std::cin >> t_dtops->number;


			system("cls");

			Borderer::AddPrimalByNumber(t_data->Dtops, t_dtops);

			std::cout << C("Czy chcesz poda� kolejn� destynacje? Je�li tak wpisz 'Tak', a je�li nie 'Nie': ");
			std::cin >> answer;
			if (answer == "Tak")
			{
				DestinationD = true;
			}
			else if (answer == "Nie")
			{
				DestinationD = false;
			}
			else
			{
				std::cout << C("B��dna odpowied�!") << std::endl;
				return false;
			}

			system("cls");
		}

		DestinationD = true;

		DataTops::AddDataTopsByTop(DATA->D, t_data);

		std::cout << C("Czy chcesz poda� kolejny wierzcho�ek? Je�li tak wpisz 'Tak', a je�li nie 'Nie': ");
		std::cin >> answer;
		if (answer == "Tak")
		{
			TopD = true;
		}
		else if (answer == "Nie")
		{
			TopD = false;
		}
		else
		{
			std::cout << C("B��dna odpowied�!") << std::endl;
			return false;
		}

		std::cout << C("Dane zosta�y pomy�lnie zaimplementowane!") << std::endl;

		system("cls");
	}

	return true;
}