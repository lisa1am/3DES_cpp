#include "sequenceD.h"

class decrypt
{
public:
	decrypt(SequenceD<64> k1, SequenceD<64> k2);
	void operator()(const string& file_in, const string& file_out) const;

private:
	SequenceD<64> k1_;
	SequenceD<64> k2_;
};