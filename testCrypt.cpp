using namespace std;
#include <iostream>
#include "crypt.h"
#include "decrypt.h"
#include "sequenceD.h"
#include "sequence.h"
int main(){
    auto key1 = SequenceD<64>();
    auto key2 = SequenceD<64>();
   	cout << "Entrez les 2 clés :" << endl;
   	cin >> key1;
   	cin >> key2;
   	cout << "clé : " << key1 << endl;
    cout << "clé : " << key2 << endl;
   	auto encryption = crypt(key1, key2);
   	auto decryption = decrypt(key1, key2);

   //crypt
    cout << "===== DEBUT CRYPT =====" << endl;
   	encryption("./fichier/file.txt", "./fichier/encrypted_text.txt");
   	cout << "===== FIN CRYPT =====" << endl << endl;

   // decrypt
    cout << "===== DEBUT DECRYPT =====" << endl;
    decryption("./fichier/encrypted_text.txt", "./fichier/decrypted_text.txt");
    cout << "===== FIN DECRYPT =====";
}