#ifndef DES_KEYGEN_H
#define DES_KEYGEN_H

using namespace std;
#include"sequenceD.h"
#include<vector>


class KeyGen{
	private :
		SequenceD<56> seqd_56;
		int appel;
		//pré-définir le nombre de bits à faire tourner à chaque génération de clé
		vector<int> bits_rotate = {1,1,2,2,2,2,2,2,1,2,2,2,2,2,2,1};
		// pré-définir le vecteur de permutation du constructeur ( de 64 à 56 bits )
		vector<int> pc1 = { 57,49,41,33,25,17,9,
								   1,58,50,42,34,26,18,
								   10,2,59,51,43,35,27,
								   19,11,3,60,52,44,36,
								   63,55,47,39,31,23,15,
								   7,62,54,46,38,30,22,
								   14,6,61,53,45,37,29,
								   21,13,5,28,20,12,4 };
		//pré-définir le vecteur de permutation de next ( de 56 à 48 bits )
		vector<int> pc2 = { 14,17,11,24,1,5,
									3,28,15,6,21,10,
									23,19,12,4,26,8,
									16,7,27,20,13,2,
									41,52,31,37,47,55,
									30,40,51,45,33,48,
									44,49,39,56,34,53,
									46,42,50,36,29,32 };

	public:
		KeyGen(const SequenceD<64>& seqd);
		KeyGen() {};
		SequenceD<48> next();

    

};

#endif
