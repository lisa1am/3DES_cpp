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

template<int size>
class SequenceD : private Sequence{

private :
	Sequence seqd;

public:
	SequenceD();

}

SequenceD::SequenceD(){
	seq = Sequence(size);
}


int main(){

}