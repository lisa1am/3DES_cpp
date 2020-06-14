#ifndef DES_PERMUTATION_H
#define DES_PERMUTATION_H

using namespace std;
#include"sequenceD.h"
#include<vector>


// tout définir dans le header car c'est une classe avec template
template<int sizeInput, int sizeOutput>
class Permutation{

	public :
	SequenceD<sizeOutput> operator()(SequenceD<sizeInput>, vector<int>);
};

//permutation décrite dans le document avec changement de taille pour la sequence en sortie et à travers un vecteur de int
template<int sizeInput, int sizeOutput>
SequenceD<sizeOutput> Permutation<sizeInput, sizeOutput>::operator()(SequenceD<sizeInput> seqd, vector<int> vec){
		SequenceD<sizeOutput> result = SequenceD<sizeOutput>();
		for(int i=0; i<sizeOutput; i++){
			if(vec[i]<sizeInput){
				result[i] = seqd(vec[i]);
			}else{
				result[i] = 0;
			}
			
		}
		return result;
	}



#endif