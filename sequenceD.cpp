#include<iostream>
#include<deque>
#include<stdlib.h>
#include<stdio.h>
#include<time.h>
#include<list>
#include<algorithm>
#include<vector>
#include"sequence.cpp"
using namespace std;

template<int size=4>
class SequenceD : private Sequence{

private :
	Sequence R;
	Sequence L;

public:
	SequenceD();

	SequenceD(Sequence s1, Sequence s2);

	int& operator[](int i);

	const int operator()(const int i);

	int size();

	void decalage(int d);

	SequenceD & operator*(SequenceD<size> seq);

	Sequence& left();

	Sequence& right();

};

template <int size>
SequenceD<size>::SequenceD(){
	R = Sequence(size/2);
	L = Sequence(size/2);
}

template <int size>
SequenceD<size>::SequenceD(Sequence s1, Sequence s2){
	L = s1;
	R = s2;
}

template<int size>
int& SequenceD<size>::operator[](int i) {
	if(i>0 && i<size){
		if(i<size/2){
			return L[i];
		}else{
			return R[i-(size/2)];
		}
	}else{
		cout << "Problème d'index !";
		exit(1);
	}
}

template<int size>
const int SequenceD<size>::operator()(const int i){
	if(i>0 && i<size){
		if(i<size/2){
			return L[i];
		}else{
			return R[i-(size/2)];
		}
	}else{
		cout << "Problème d'index !";
		exit(1);
	}
}

template<int size>
int SequenceD<size>::size(){
	return size;
}

template<int size>
void SequenceD<size>::decalage(int d){
	L.decalage(d);
	R.decalage(d);
}

template<int size>
SequenceD<size>& SequenceD<size>::operator*(SequenceD<size> seq){
	if(seq.size()!=size){
		return SequenceD<0>();
	}else{
		return SequenceD<seq.size>(seq.left()*L, seq.right()*R);
	}
}


//revoir s'il faut vraiment renvoyer la ref ou non
template<int size>
Sequence& SequenceD<size>::left(){
	return L;
}

template<int size>
Sequence& SequenceD<size>::right(){
	return R;
}




int main(){

}