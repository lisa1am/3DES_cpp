using namespace std;
#include"permutation.h"
#include<vector>


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
	}
