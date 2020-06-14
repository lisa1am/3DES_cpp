using namespace std;
#include"keyGen.h"

//g++ -c keyGen.cpp
//g++ *.o keyGenTest.cpp -o testKeyGen
// ./testKeyGen


int main(){
	SequenceD<64> seqd = SequenceD<64>();
	cout << "sequence 64 : " << endl;
	seqd.afficher();
	KeyGen keygen(seqd);
	cout << "\nKey generation 16 times : " << endl;
	for(int i=0; i<16; i++){
		cout << "key " << i << " : ";
		keygen.next().afficher();
		cout << endl;
	}

}