using namespace std;
#include"sequence.h"

//g++ -c sequence.cpp
//g++ *.o sequenceTest.cpp -o testSequence
// ./testSequence


int main(){
	srand(time(0));
	Sequence s1 = Sequence();

	Sequence s2 = Sequence(6);
	s1.afficher();
	s2.afficher();

	Sequence s3 = Sequence();
	list<Sequence> lst;
	lst.push_front(s1);
	lst.push_front(s2);
	lst.push_front(s3);

	Sequence s4 = Sequence(lst);
	s1.afficher();
	s2.afficher();
	s3.afficher();
	s4.afficher();


	cout << "\noperator () : " << s4(2) << endl;
	s4[2]=0;
	cout << "after operator [] -> s4[2]=0 : " << s4(2) << endl;
	s4.afficher();
	cout << "\nTaille = " << s4.size() << endl;
	s1=10;
	s1.afficher();
	cout << "\nAfter operator * : \n";

	Sequence result = s1*s2;
	result.afficher();

	cout << "before decalage : ";
	s2.afficher();
	s2.decalage(2);
	cout <<"\nafter decalage 2 : ";
	s2.afficher();
	cout << endl;

	vector<int> vec ={2,0,0,3,0};
	Sequence s = s1.permutation(vec);
	cout << "Permutation : ";
	s.afficher();

	s=s1.sous_sequence(1,2);
	cout << "\nSous-sequence : ";
	s.afficher();
	cout << endl;

}
