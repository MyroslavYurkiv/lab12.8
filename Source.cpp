#include <iostream>
#include <Windows.h>
#include <time.h>
#include <fstream>
#include <string>

using namespace std;

typedef int inform;
struct Spusok
{
	Spusok* link1,
		* link2;
	inform inf;
};

int Start(ifstream& file_load, Spusok*& first, Spusok*& last);
void Print(Spusok*& first, Spusok*& T, const int N);
void Process(Spusok*& top1, Spusok* T, Spusok* G, const int N);

int main(void)
{
	srand((unsigned)time(NULL));
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	Spusok* first = NULL;
	Spusok* last = NULL;

	char fname[51];
	cout << "¬вед≥ть назву файлу дл€ зчитуванн€ чисел: "; cin >> fname; cout << endl;

	int kilkist;
	inform value;

	ifstream file_load;
	file_load.open(fname);
	kilkist = Start(file_load, first, last);
	file_load.close();

	cout << "—формований список за допомогою зчитуванн€ з текстового файлу: " << endl << endl;
	Spusok* T = first;
	Print(first, T, kilkist);

	cout << "—формований стек 'п≥сл€ перетворенн€': " << endl << endl;
	T = first;
	Spusok* G = first;
	Process(first, T, G, kilkist);

	T = first;
	Print(first, T, kilkist);

	return 0;
}

int Start(ifstream& file_load, Spusok*& first, Spusok*& last)
{
	inform i;
	int kilkist = 0;

	while (!file_load.eof())
	{
		file_load >> i;
		Spusok* tmp = new Spusok;
		tmp->inf = i;
		tmp->link1 = NULL;
		tmp->link2 = NULL;
		if (first == NULL)
			first = tmp;
		else
		{
			last->link1 = tmp;
			tmp->link2 = last;
		}
		last = tmp;
		kilkist++;
	}
	return kilkist;
}

void Print(Spusok*& first, Spusok*& T, const int N)
{
	inform i;
	int index = 0;

	while (index < N)
	{
		i = T->inf;
		cout << i << "   ";
		T = T->link1;
		index++;
	}
	cout << endl << endl;
}

void Process(Spusok*& top1, Spusok* T, Spusok* G, const int N)
{
	inform x, y;
	int zmina, zmina_l = 1;      
	inform min_x;

	for (int i = 0; i < N; i++)
	{
		x = G->inf;               
		min_x = x;                
		zmina = 0;                
		while (zmina < zmina_l)
		{
			T = T->link1;         
			zmina++;              
		}

		while (T != NULL)
		{
			x = T->inf;           
			if (min_x > x)
				min_x = x;        
			T = T->link1;         
		}

		T = top1;                 
		x = G->inf;               

		zmina = 0;                
		while (zmina < zmina_l)
		{
			T = T->link1;         
			zmina++;              
		}

		while (T != NULL)
		{
			y = T->inf;           
			if (y == min_x)
			{
				G->inf = min_x;   
				T->inf = x;       

				break;
			}
			T = T->link1;         
		}

		zmina_l++;                

		T = top1;                 
		G = G->link1;             
	}
}
