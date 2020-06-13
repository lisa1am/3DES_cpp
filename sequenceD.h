#ifndef DES_SEQUENCED_H
#define DES_SEQUENCED_H

#include<iostream>
#include <sstream>
#include"sequence.h"
#include <bitset>
#include <cstdlib>
#include <cstring>
using namespace std;

template<int S=4>
class SequenceD : private Sequence{

private :
	Sequence R;
	Sequence L;

public:
	SequenceD();

	SequenceD(Sequence s1, Sequence s2);

	int& operator[](int i);

	const int operator()(const int i);

	void decalage(int d);

	SequenceD& operator*(SequenceD<S> seq);

	Sequence& left();

	Sequence& right();

	template<int Sz>
	friend ostream& operator<<(ostream& os, SequenceD<64> sedq);

	template<int Sz>
	friend istream& operator>>(istream& is, SequenceD<64>& seqd);

	void afficher();

};

template <int S>
SequenceD<S>::SequenceD(){
	R = Sequence(S/2);
	L = Sequence(S/2);
}


template <int S>
SequenceD<S>::SequenceD(Sequence s1, Sequence s2){
	L = s1;
	R = s2;
}

template<int S>
int& SequenceD<S>::operator[](int i) {
	if(i>=0 && i<S){
		if(i<S/2){
			return L[i];
		}else{
			return R[i-(S/2)];
		}
	}else{
		cout << "Problème d'index !";
		exit(1);
	}
}

template<int S>
const int SequenceD<S>::operator()(const int i){
	if(i>=0 && i<S){
		if(i<S/2){
			return L[i];
		}else{
			return R[i-(S/2)];
		}
	}else{
		cout << "Problème d'index !";
		exit(1);
	}
}


template<int S>
void SequenceD<S>::decalage(int d){
	L.decalage(d);
	R.decalage(d);
}

template<int S>
SequenceD<S>& SequenceD<S>::operator*(SequenceD<S> seq){
	L=L*seq.left();
	R=R*seq.right();
	return *this;
}


//revoir s'il faut vraiment renvoyer la ref ou non
template<int S>
Sequence& SequenceD<S>::left(){
	return L;
}

template<int S>
Sequence& SequenceD<S>::right(){
	return R;
}

template<int S>
ostream& operator<<(ostream& os, SequenceD<S> seqd){
	string result ="";
	if(S!=64){
		return os;
	}else{
		bitset<8> byte;
		for(int i=0; i<4; i++){
			Sequence seq8 = seqd.left().sous_sequence(i*8, i*8+7);
			for (int j = 7; j > -1; j--){
				byte[j] = seq8(7-j);
			}
			char c = (char)byte.to_ulong();
			result+= c;
			
		}
		for(int i=0; i<4; i++){
			Sequence seq8 = seqd.right().sous_sequence(i*8, i*8+7);
			for (int j = 7; j > -1; j--){
				byte[j] = seq8(7-j);
			}
			char c = (char)byte.to_ulong();
			result+= c;
			
		}
	}
	os << result << endl;
	return os;
}



// TODO : tout est good mais l'affectation ne marche pas correctement 
template<int S>
istream& operator>>(istream& is, SequenceD<S>& seqd){
	if(S!=64){
		return is;
	}else{

		for(int i=0; i<8; i++){
			char read;
			is >> read;

			bitset<8> binary = bitset<8>(read);
			cout <<  binary << endl;
			string str = binary.to_string().c_str();
			int j=0;
			for(char element : str){
				//affectation
				seqd[i+j]=element-'0';
				j++;
			}
		}
	}
	return is;
}


template<int S>
void SequenceD<S>::afficher(){
	left().afficher();
	right().afficher();
	cout << "\n";
}


template<int S>
ostream& write(ostream& os, SequenceD<S> seqd){
	if(S!=64){
		return os;
	}else{
		for(int i=0; i<64; i++){
			os << seqd(i);
			if((i+1)%8==0){
				os << "-";
			}
		}
	}
	os << endl;
	return os;
}

template<int S>
istream& read(istream& is, SequenceD<S>& seqd){
	char bit;
	if(S!=64){
		return is;
	}else{
		for(int i=0; i<64; i++){
			is >> bit;
			seqd[i]=bit-'0';
		}
	}
	return is;
}


#endif
