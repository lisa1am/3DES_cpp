#include "sBox.h"

sBox::sBox(int matrice[][]) {
	this->matrice_ = new int* [4];

	// Genère un tableau d'int pour chaque pointeur de tableau de pointeur
	for (int i = 0; i < 4; i++)
	{
		this->matrice_[i] = new int[16];

		// Copie de la valeur de la matrice en param
		for (int j = 0; j < 16; j++)
		{
			int val = matrice[i][j];
			this->matrice_[i][j] = val;
		}
	}
}

sBox::~sBox() {
	delete matrice_;
}

sBox::sBox(const sBox& sbox) {
	this->matrice_ = sbox.matrice_;
}

sBox& sBox::operator=(sBox& sbox) = default;

sequence sBox::operator()(Sequence seq)
{
	//verifier que la taille de la seq en entrée est bien de 6bits
	Sequence row_sequence = sequence(2);
	// attribution à la sequence intermédiaire du premier et du dernier bit
	row_sequence[0] = seq(0);
	row_sequence[1] = seq(5);
	int row = 0;
	int row_size = row_sequence.size();

	for (int i = 0; i < row_size; i++) {
	    // de 0 à 3 pour la ligne
		row += row_sequence(i) * pow(2, row_size - i - 1);
	}

	//attribution de la sequence intermédiaire avec les 4 bits du milieu
	Sequence col_sequence = sequence(seq.sous_sequence(1, 4));
	int col_size = col_sequence.size();
	int col = 0;
	for (int i = 0; i < col_size; i++) {
		col += col_sequence(i) * pow(2, col_size - i - 1);
	}

    //Récupération de la valeur dans la matrice
	int res = matrice_[row][col];
	int cpt = 0, temp_res = matrice_[row][col];
	do
	{
		temp_res /= 2;
		cpt++;
	} while (temp_res != 0);
	Sequence return_seq = sequence();
	return_seq = res;
	return return_seq;
}