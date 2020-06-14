using namespace std;
#include"keyGen.h"
#include"permutation.h"




KeyGen::KeyGen(const SequenceD<64>& seqd){
	appel=0;
	Permutation<64,56> permutation;
	seqd_56=permutation(seqd, pc1);
}

SequenceD<48> KeyGen::next(){
	seqd_56.decalage(bits_rotate[appel++]);
	Permutation<56,48> permutation;
	return permutation(seqd_56, pc2);
}




