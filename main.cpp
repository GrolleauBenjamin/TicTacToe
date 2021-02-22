#include <iostream>

using namespace std;

#define SIDE 3
#define NB_COUP 9
#define COUP_J1 'O'
#define COUP_J2 'X'

void play();
void print_consigne();
void print_plateau(char plateau[][SIDE]);
void initialise_plateau(char plateau[][SIDE]);
bool winner(char plateau[][SIDE]);
bool add_point(char plateau[][SIDE], string whose_play);

int main()
{
	play();
	return 0;
}

/// <summary>
/// Fonction qui lance tout le programme
/// </summary>
void play()
{
	char plateau[SIDE][SIDE];
	string whose_play{ "P1" };
	int nb_coup{ 0 };

	initialise_plateau(plateau);
	print_consigne();

	while (!winner(plateau) || nb_coup == 9)
	{
		while (!add_point(plateau, whose_play))
		{
			add_point(plateau, whose_play);
		}
		print_plateau(plateau);

		if (whose_play == "P1")
			whose_play = "P2";
		else
			whose_play = "P1";

		nb_coup++;

		if (nb_coup == 9)
		{
			cout << "Bien jouer, personne n'a gagne " << endl;
			return;
		}
	}
	return;
}

/// <summary>
/// Affiche les règles du jeu
/// </summary>
void print_consigne()
{
	cout <<  "  --> TIC TAC TOE GAME" << endl;
	cout << "\t " << 1 << " | " << 2 << " | " << 3 << endl;
	cout << "\t" << "----------" << endl;
	cout << "\t " << 4 << " | " << 5 << " | " << 6 << endl;
	cout << "\t" << "----------" << endl;
	cout << "\t " << 7 << " | " << 8 << " | " << 9 << endl;

	cout << "\nChose a number to put your signe" << endl;
	cout << "\t--> Signe du joueur 1 : X" << endl;
	cout << "\t--> Signe du joueur 1 : O" << endl;
}

/// <summary>
///  Affiche le plateau 
/// </summary>
/// <param name="plateau"> plateau a afficher </param>
void print_plateau(char plateau[][SIDE])
{
	cout << "\t " << plateau[0][0] << " | " << plateau[0][1] << " | " << plateau[0][2] << endl;
	cout << "\t" << "----------" << endl;
	cout << "\t " << plateau[1][0] << " | " << plateau[1][1] << " | " << plateau[1][2] << endl;
	cout << "\t" << "----------" << endl;
	cout << "\t " << plateau[2][0] << " | " << plateau[2][1] << " | " << plateau[2][2] << endl;

	return;
}

/// <summary>
/// ajoute des valeurs null dans chaque valeur du tableau
/// </summary>
/// <param name="plateau"> ajoute ' ' pour chaque variable du plateau </param>
void initialise_plateau(char plateau[][SIDE])
{
	for (int i = 0; i < SIDE; ++i)
	{
		for (int j = 0; j < SIDE; ++j)
		{
			plateau[i][j] = ' ';
		}
	}
	return;
}

/// <summary>
/// Cherche si il y  aun gagnant en parcourant le plateau
/// </summary>
/// <param name="plateau"> plateau de jeu a parcourir </param>
/// <returns> True or false</returns>
bool winner(char plateau[][SIDE])
{
	// diagonal haut gauche bas droite
	if (plateau[0][0] == plateau[1][1] &&
		plateau[1][1] == plateau[2][2] &&
		plateau[0][0] != ' ')
	{
		if (plateau[0][0] == 'X')
			cout << "Good job, Player 1 won" << endl;
		if (plateau[0][0] == 'O')
			cout << "Good job, Player 2 won" << endl;
		return true;
	}

	// diagonal haut droite bas gauche
	if (plateau[0][2] == plateau[1][1] &&
		plateau[1][1] == plateau[2][0] &&
		plateau[0][2] != ' ')
	{
		if (plateau[0][0] == 'X')
			cout << "Good job, Player 1 won" << endl;
		if (plateau[0][0] == 'O')
			cout << "Good job, Player 2 won" << endl;
		return true;
	}

	// vérification horizontal
	for (int i = 0; i < SIDE; ++i)
	{
		if (plateau[i][0] == plateau[i][1] &&
			plateau[i][1] == plateau[i][2] &&
			plateau[i][0] != ' ')
		{
			if (plateau[i][0] == 'X')
				cout << "Good job, Player 1 won" << endl;
			if (plateau[i][0] == 'O')
				cout << "Good job, Player 2 won" << endl;
			return true;
		}
	}

	// verification vertical
	for (int i = 0; i < SIDE; ++i)
	{
		if (plateau[0][i] == plateau[1][i] &&
			plateau[1][i] == plateau[2][i] &&
			plateau[0][i] != ' ')
		{
			if (plateau[0][i] == 'X')
				cout << "Good job, Player 1 won" << endl;
			if (plateau[0][i] == 'O')
				cout << "Good job, Player 2 won" << endl;
			return true;
		}
	}

	return false;
}

/// <summary>
/// ajoute "O" ou "X" sur la plateau en fonction de qui joue et de la position choisi
/// </summary>
/// <param name="plateau"> plateau de jeu </param>
/// <param name=""> joueur en train de jouer</param>
bool add_point(char plateau[][SIDE], string whose_play)
{
	char point;
	if (whose_play == "P1")
		point = COUP_J1;
	if (whose_play == "P2")
		point = COUP_J2;

	int pos;
	cout << "Dans quelle case voulez vous poser votre " << point << " ? : ";
	cin >> pos;

	if (pos == 1)
		if (plateau[0][0] == ' ')
		{
			plateau[0][0] = point;
			return true;
		}

	if (pos == 2)
		if (plateau[0][1] == ' ')
		{
			plateau[0][1] = point;
			return true;
		}

	if (pos == 3)
		if (plateau[0][2] == ' ')
		{
			plateau[0][2] = point;
			return true;
		}

	if (pos == 4)
		if (plateau[1][0] == ' ')
		{
			plateau[1][0] = point;
			return true;
		}

	if (pos == 5)
		if (plateau[1][1] == ' ')
		{
			plateau[1][1] = point;
			return true;
		}

	if (pos == 6)
		if (plateau[1][2] == ' ')
		{
			plateau[1][2] = point;
			return true;
		}

	if (pos == 7)
		if (plateau[2][0] == ' ')
		{
			plateau[2][0] = point;
			return true;
		}

	if (pos == 8)
		if (plateau[2][1] == ' ')
		{
			plateau[2][1] = point;
			return true;
		}

	if (pos == 9)
		if (plateau[2][2] == ' ')
		{
			plateau[2][2] = point;
			return true;
		}

	return true;
}