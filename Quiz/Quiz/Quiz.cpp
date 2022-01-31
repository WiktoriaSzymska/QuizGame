#include <iostream>
#include <fstream>
#include <string>
#include <time.h>
#include <windows.h>
#include "Header.h"

using namespace std;


int nr_pytania;
int nr;
int iloœæ_linii = 5;
char odp;
char pyt;
int score = 0;
int GameMode = 9;
char Ans = 'x';



class BaseGameMode
{
public:

	int Questions;
	string GameModeName;

};

class EliminationMode : public BaseGameMode
{
public:
	int Life;
};

class TwoPlayerMode : public BaseGameMode
{
public:

	int PlayerPoints;


};


void PrintQuestionA()
{
	iloœæ_linii = 5;
	string s;
	fstream file1("a.txt");


	try {
		if (file1.is_open())
		{
		}
		else
		{
			throw 1;
		}
	}
	catch (int) { std::cout << "Can't open File A \n\n"; exit(0); }



	nr_pytania = rand() % 3; //iloœæ setów pytañ
	nr_pytania = nr_pytania * 5;

	while (getline(file1, s))
	{
		if (nr_pytania >= 0)
		{
			nr_pytania--;
		}
		else
		{
			if (iloœæ_linii > 0)
			{
				iloœæ_linii--;
				std::cout << s << '\n';
			}
		}
	}
	file1.close();


}
void PrintQuestionB()
{
	iloœæ_linii = 5;
	string s;
	fstream file1("b.txt");

	try {
		if (file1.is_open())
		{
		}
		else
		{
			throw 1;
		}
	}
	catch (int) { std::cout << "Can't open File B \n\n"; exit(0); }

	nr_pytania = rand() % 3; //iloœæ setów pytañ
	nr_pytania = nr_pytania * 5;

	while (getline(file1, s))
	{
		if (nr_pytania >= 0)
		{
			nr_pytania--;
		}
		else
		{
			if (iloœæ_linii > 0)
			{
				iloœæ_linii--;
				std::cout << s << '\n';
			}
		}
	}
	file1.close();

}
void PrintQuestionC()
{
	iloœæ_linii = 5;
	string s;
	fstream file1("c.txt");

	try {
		if (file1.is_open())
		{
		}
		else
		{
			throw 1;
		}
	}
	catch (int) { std::cout << "Can't open File C\n\n"; exit(0); }

	nr_pytania = rand() % 3; //iloœæ setów pytañ
	nr_pytania = nr_pytania * 5;

	while (getline(file1, s))
	{
		if (nr_pytania >= 0)
		{
			nr_pytania--;
		}
		else
		{
			if (iloœæ_linii > 0)
			{
				iloœæ_linii--;
				std::cout << s << '\n';
			}
		}
	}
	file1.close();

}
void PrintQuestionD()
{
	iloœæ_linii = 5;
	string s;
	fstream file1("d.txt");

	try {
		if (file1.is_open())
		{
		}
		else
		{
			throw 1;
		}
	}
	catch (int) { std::cout << "Can't open File D\n\n"; exit(1); }

	nr_pytania = rand() % 3; //iloœæ setów pytañ
	nr_pytania = nr_pytania * 5;

	while (getline(file1, s))
	{
		if (nr_pytania >= 0)
		{
			nr_pytania--;
		}
		else
		{
			if (iloœæ_linii > 0)
			{
				iloœæ_linii--;
				std::cout << s << '\n';
			}
		}
	}
	file1.close();

}

char ReturnChar()
{
	std::cin >> Ans;
	while (Ans != 'a' && Ans != 'b' && Ans != 'c' && Ans != 'd')
	{


		cout << "Enter a,b,c or d\n";
		std::cin >> Ans;
		Ans = tolower(Ans);
	}
	return Ans;
}

int main()
{


	BaseGameMode BGame;

	srand(time(NULL)); //Choosing a seed based on time

	PrintQuestionA();
	PrintQuestionB();
	PrintQuestionC();
	PrintQuestionD();

	system("cls");







	while (GameMode != 0 && GameMode != 1 && GameMode != 2)
	{
		std::cout << "Choose your Game Mode \n \nEnter 0 for Normal Mode\nEnter 1 for Elimination Mode \nEnter 2 for Two Player Mode\n";
		std::cin >> GameMode;

		std::system("cls");
	}




	switch (GameMode)
	{
	case 0:
	{
		BGame.GameModeName = "Normal Mode";

		//Normal Mode with 5 Questions
		std::cout << "0";

		for (int i = 0; i < 5; i++)
		{
			cout << "\n                             " << BGame.GameModeName << "\n";

			nr = rand() % 4;
			switch (nr)
			{

			case 0:
			{
				pyt = 'a';

				PrintQuestionA();


			}break;

			case 1:
			{
				pyt = 'b';

				PrintQuestionB();

			}break;
			case 2:
			{
				pyt = 'c';

				PrintQuestionC();
			}break;
			case 3:
			{
				pyt = 'd';

				PrintQuestionD();

			}break;
			}





			odp = ReturnChar();


			if (odp == pyt)
			{
				system("cls");
				score++;
				std::cout << "\n                 Correct Answer\n\n";
			}
			else
			{
				system("cls");
				std::cout << "\n                    Wrong Answer\n\n";
			}
		}
		cout << "\n   End of Game \n Score: " << score;

	}break;
	case 1:
	{
		BGame.GameModeName = "Elimination Mode";
		EliminationMode elim;
		elim.Life = 3;


		while (elim.Life > 0)
		{
			cout << "\n                             " << BGame.GameModeName << "\n";

			nr = rand() % 4;
			switch (nr)
			{

			case 0:
			{
				pyt = 'a';

				PrintQuestionA();


			}break;

			case 1:
			{
				pyt = 'b';

				PrintQuestionB();

			}break;
			case 2:
			{
				pyt = 'c';

				PrintQuestionC();
			}break;
			case 3:
			{
				pyt = 'd';

				PrintQuestionD();

			}break;
			}

			odp = ReturnChar();

			if (odp == pyt)
			{
				system("cls");
				score++;
				std::cout << "\n                    Correct Answer\n\n                    Remaining Life: " << elim.Life << "\n";

			}
			else
			{
				elim.Life--;
				system("cls");
				std::cout << "\n                    Wrong Answer\n\n                    Remaining Life: " << elim.Life << "\n";

			}
		}



	}break;

	case 2:
	{
		BGame.GameModeName = "Two Player Mode";
		TwoPlayerMode Pl1;
		TwoPlayerMode Pl2;
		Pl1.PlayerPoints = 0;
		Pl2.PlayerPoints = 0;

		cout << "\n                             " << BGame.GameModeName << "\n";
		for (int i = 0; i < 5; i++)
		{



			cout << "\nPlayer 1 Turn    Current Score: " << Pl1.PlayerPoints << "\n\n";


			nr = rand() % 4;
			switch (nr)
			{

			case 0:
			{
				pyt = 'a';

				PrintQuestionA();


			}break;

			case 1:
			{
				pyt = 'b';

				PrintQuestionB();

			}break;
			case 2:
			{
				pyt = 'c';

				PrintQuestionC();
			}break;
			case 3:
			{
				pyt = 'd';

				PrintQuestionD();

			}break;
			}

			odp = ReturnChar();

			if (odp == pyt)
			{
				system("cls");
				Pl1.PlayerPoints++;
				cout << "\n                             " << BGame.GameModeName << "\n";
				cout << "Player 1 Answered Correctly\n\n";

			}
			else
			{
				system("cls");
				cout << "\n                             " << BGame.GameModeName << "\n";
				cout << "Player 1 Answered Incorrectly\n\n";
			}


			cout << "\nPlayer 2 Turn    Current Score: " << Pl2.PlayerPoints << "\n\n";


			nr = rand() % 4;
			switch (nr)
			{

			case 0:
			{
				pyt = 'a';

				PrintQuestionA();


			}break;

			case 1:
			{
				pyt = 'b';

				PrintQuestionB();

			}break;
			case 2:
			{
				pyt = 'c';

				PrintQuestionC();
			}break;
			case 3:
			{
				pyt = 'd';

				PrintQuestionD();

			}break;
			}

			odp = ReturnChar();

			if (odp == pyt)
			{
				system("cls");
				Pl2.PlayerPoints++;
				cout << "\n                             " << BGame.GameModeName << "\n";
				cout << "Player 2 Answered Correctly\n\n";
			}
			else
			{
				system("cls");
				cout << "\n                             " << BGame.GameModeName << "\n";
				cout << "Player 2 Answered Incorrectly\n\n";
			}



		}


	}break;
	}

	//std::system("cls");





	return 0;


}



