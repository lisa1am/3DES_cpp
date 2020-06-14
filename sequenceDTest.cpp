using namespace std;
#include"sequenceD.h"

//g++ sequenceD.cpp
//g++ *.o sequenceDTest.cpp -o testSequenceD
// ./testSequenceD

int main(){

	SequenceD<64> seqd = SequenceD<64>();
	seqd.afficher();
	cout << "operator << " << seqd << endl;


	SequenceD<64> seq = SequenceD<64>();
	seq.afficher();
	cout << "oparetor >> (introduisez 8 caractères )" << endl;
	cin >> seq;
	seq.afficher();
	cout << endl;

	cout << "\noperator () : " << seqd(3) << endl;
	
	cout << "before decalage : " << endl;
	seqd.afficher();
	seqd.decalage(2);
	cout <<"\nafter decalage 2 : "<< endl;
	seqd.afficher();
	cout << endl;

	cout << "left " << endl;
	seqd.left().afficher();
	cout << "\nright " << endl;
	seqd.right().afficher();
	cout << endl;


}
