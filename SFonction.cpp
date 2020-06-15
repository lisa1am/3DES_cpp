#include"SFonction.h"

SFonction::SFonction(int*** boxes){
	s_boxes=new int**[8];
	for(int i=0; i<8; i++){
		s_boxes[i]= new int*[4];
		for(int j=0; j<4; j++){
			s_boxes[i][j]=new int[16];
			for(int k=0; k<16; k++){
				s_boxes[i][j][k]=boxes[i][j][k];
			}
		}
	}

}


SFonction::SFonction(const SFonction& s_fonc){
	s_boxes = s_fonc.s_boxes;
}

SFonction::~SFonction(){
	if(s_boxes!=NULL){
		delete[] s_boxes;
	} 
	return;
}


SFonction& SFonction::operator=(const SFonction& s_fonc)= default;


Sequence SFonction::operator()(Sequence seq){
	list<Sequence> liste;
	for(int i=0; i<8; ++i){
		sBox sbox = sBox(s_boxes[i]);
		Sequence sous_seq = seq.sous_sequence(i*6, i*6+5);
		liste.push_back(sbox(sous_seq));
	}
	return Sequence(liste);
}
