#ifndef DES_SEQUENCE_H
#define DES_SEQUENCE_H

#include<iostream>
#include<deque>
#include<stdlib.h>
#include<stdio.h>
#include<time.h>
#include<list>
#include<algorithm>
#include<vector>
using namespace std;


class Sequence{
	private :
		deque<int> seq;
		int sz;

	public :

		Sequence(int taille=4);

		Sequence(list<Sequence>);

		void afficher();

		int& operator[](int i);

		const int operator()(const int i);

		Sequence& operator=(int i);

		int size();

		void decalage(int i);

		Sequence operator*(Sequence s);

		Sequence permutation(vector<int> vec);

		Sequence sous_sequence(int deb, int fin);
};

#endif 

//g++ -c sequence.cpp
//g++ sequence.o sequenceD.cpp -o test
