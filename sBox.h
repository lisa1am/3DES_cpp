
#ifndef DES_SBOX_H
#define DES_SBOX_H
#include "sequenceD.h"


class sBox {

private:
	int** matrice_;
public:
	sBox(int matrice[][]);
	~sBox();
	sBox(const sBox& sbox);
	sBox& operator=(sBox& sbox);
	Sequence operator()(Sequence seq);
};

#endif