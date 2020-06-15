using namespace std;
#include"f.h"

//g++ -c f.cpp
//g++ *.o f.cpp -o testF
// ./testF

int main(){
	SequenceD<64> seqd = SequenceD<64>();
	//contructing f
	f f_ = f(seqd);

	//input sequence - sous-sequence of 64 sequence D
	SequenceD<64> seqd_input = SequenceD<64>();
	cout << "Sequence 64 bits : " << endl;
	seqd_input.afficher();
	cout << " done" << endl;
	//cout << endl << "SequenceD right side 32 bits : " << endl;
	//seqd_input.right().afficher();
	Sequence seq = Sequence(32);
	//seq.afficher();
	cout << endl;
	Sequence seq_out = f_(seq);


}