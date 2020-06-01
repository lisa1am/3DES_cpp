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

};

template<int size>
SequenceD::SequenceD(){
	seq = Sequence(size);
}


int main(){

}