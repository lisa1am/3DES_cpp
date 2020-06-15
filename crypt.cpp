#include "crypt.h"

#include <fstream>
#include <utility>

#include "des.h"
#include "desInv.h"


crypt::crypt(SequenceD<64> k1, SequenceD<64> k2)
{
	this->k1_ = std::move(k1);
	this->k2_ = std::move(k2);
}


/*
 * Entrée : Répertoire du fichier à crypter et chemin du fichier où ecrire le nouveau fichier crypté
 */
void crypt::operator()(const string& file_in, const string& file_out) const
{
	auto cdes = des(k1_);
	auto ddes = desInv(k2_);

	cout << "Fichier d'entrée : " << file_in << endl;
	ifstream read_file(file_in);

	cout << "Fichier de sortie : " << file_out << endl;
	ofstream write_file(file_out);



	//Récupérer la taille du fichier
	read_file.seekg(0, std::ifstream::end);
	int file_size = read_file.tellg();
	cout << "Taille du fichier en entrée : " << read_file.tellg() << endl;
	read_file.seekg(0, std::ifstream::beg);

	for (auto i = 0; i < file_size; i += 8)
	{
		SequenceD<64> seq;
		read_file >> seq;


		//1 étape
		cout << "1 DES : " << endl;
		auto des1_seq = cdes(seq);
		cout << "Resultat : " << des1_seq << endl << endl;

		//2 étape
		cout << "2 DES : " << endl;
		auto des2_seq = ddes(des1_seq);
		cout << "Resultat : " << des2_seq << endl << endl;

		//3 étape
		cout << "3 DES : " << endl;
		auto des3_seq = cdes(des2_seq);
		cout << "Resultat : " << des3_seq << endl << endl;

		//write to file
		write_file << des3_seq;
	}
	read_file.close();
	write_file.close();
}