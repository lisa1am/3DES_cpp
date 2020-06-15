#include"f.h"
#include"permutation.h"

f::f(const SequenceD<64>& seqd){

	keygen = KeyGen(seqd);
	s_fonc = SFonction(construct_sboxes());
}

Sequence f::operator()(Sequence& seq){
	//expasion-permutation

	Permutation<32,48> exp_permutation;
	SequenceD<32> seqd_32 = SequenceD<32>(seq.sous_sequence(0, (seq.size()/2)-1),seq.sous_sequence(seq.size()/2, seq.size()-1));
	SequenceD<48> seqd_48 = exp_permutation(seqd_32, e_p);
	SequenceD<48> key = keygen.next();

	//XOR
	SequenceD<48> xor_seqd_48 = seqd_48*key;
	list<Sequence> xor_list({xor_seqd_48.left(), xor_seqd_48.right()});

	Sequence xor_seq = Sequence(xor_list);

	//s_fonction
	list<Sequence> liste;
	liste.push_back(s_fonc(xor_seq));
	Sequence substitution = Sequence(liste);

   
    //permutation
    return substitution.permutation(p);
}


//private : internal use only 
int*** f::construct_sboxes(){
	auto* sbox = new int** [8];

	for(int i=0; i<8; i++){
		sbox[i]= new int* [4];
		for(int j=0; j<4; j++){
			sbox[i][j] = new int[16];
			for(int k=0; k<16; k++){
				sbox[i][j][k] = sboxes[i][j][k];
			}
		}
	} 
	return sbox;
}
