#ifndef DES_SFONCTION_H
#define DES_SFONCTION_H

#include"sequence.h"
#include"sBox.h"

class SFonction{
	private :
		int *** s_boxes;

	public :
		SFonction(int*** boxes);
		SFonction(){};
		~SFonction();
		SFonction(const SFonction& s_fonc);
		SFonction& operator=(const SFonction& s_fonc);
		Sequence operator()(Sequence seq);
};

#endif