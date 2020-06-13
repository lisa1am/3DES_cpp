#ifndef DES_PERMUTATION_H
#define DES_PERMUTATION_H

using namespace std;
#include"sequenceD.h"
#include<vector>

template<int sizeInput, int sizeOutput>
class Permutation{

	public :
	SequenceD<sizeOutput> operator()(SequenceD<sizeInput>, vector<int>);
};



#endif