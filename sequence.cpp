#include"sequence.h"

Sequence::Sequence(int taille){
	srand(time(NULL) * clock());
	sz=taille;
	for(int i=0; i<taille; i++){
		seq.push_front(rand()%2);
	}

}

Sequence::Sequence(list<Sequence> lst){
	int i=0;
	Sequence tmp_seq;
	for (list<Sequence>::iterator it_lst=lst.begin(); it_lst != lst.end(); ++it_lst){
		tmp_seq=*it_lst;
		for(deque<int>::iterator it_deq=tmp_seq.seq.begin(); it_deq!=tmp_seq.seq.end(); ++it_deq){
			seq.push_back(*it_deq);
			i++;
		}
	}
	sz=i;
}

void Sequence::afficher(){
	int i=0;
	for(deque<int>::iterator it=seq.begin(); it !=seq.end(); ++it){
		cout << *it;
		i++;
		if(i%8==0){
			cout << "-";
		}
	}
}

int Sequence::size(){
	return sz;
}


//on retourne une références pour nous permettre de modifier la valeur
int & Sequence::operator[](int i){
	if((i>=0) && (i<size())){
		return seq[i];
	}else{
		cout << "Problème d'index ! -- " << i;
		exit(1);
	}
}

// on retourne une copie du int pour ne pas modifier la valeur
const int Sequence::operator()(const int i){
	if((i>=0) && (i<size())){
		return seq[i];
	}else{
		cout << "Problème d'index ! -- " << i;
		exit(1);
	}
}

Sequence & Sequence::operator=(int s){
	for(int i=size()-1; i>=0; i--){
		seq[i]=s%2;
		s=s/2;
	}
	return *this;
}


void Sequence::decalage(int d){
	int temp;
	for(int i=0; i<d; i++){
		temp=seq.front();
		seq.pop_front();
		seq.push_back(temp);
	}
}

// appliquer la regle simple du XOR 
// si pareil = 0
// si différent = 1
Sequence Sequence::operator*(Sequence s){

	if(sz!=s.sz){
		return Sequence(0);
	}else{
		Sequence result(s.size());
		for(int i=0; i<s.size(); i++){
			if(seq[i]!=s[i]){
				result[i]=1;
			}else{
				result[i]=0;
			}
		}
		return result;
	}
}


//replacer les valeur de la sequence selon l'odre donné dans le veteur
Sequence Sequence::permutation(vector<int> vec){
	Sequence s(vec.size());
	for(int i=0; i<(int)vec.size(); i++){
		s[i]=seq[vec[i]];
	}
	return s;
}


Sequence Sequence::sous_sequence(int deb, int fin){
	Sequence s(fin-deb+1);
	for(int i=0; i<=(fin-deb); i++){
		s[i]=seq[deb+i];
	}
	return s;
}




