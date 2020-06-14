using namespace std;
#include"permutation.h"
#include<vector>

//g++ permutation.cpp
//g++ *.o permutationTest.cpp -o testPermutation
// ./testPermutation

int main(){
	vector<int> vec = {3,2,6,1};
	cout << "before permutation with vector = {3,2,6,1} " << endl;
	SequenceD<12> seqd = SequenceD<12>();
	seqd.afficher();
	Permutation<12,4> permutation;
	cout << "after permutation : " << endl;
	permutation(seqd, vec).afficher();
	cout << endl;
}