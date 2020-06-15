#include "sequenceD.h"

class desInv
{
public:
	desInv(const SequenceD<64>&);
	SequenceD<64> operator()(SequenceD<64> SequenceD) const;
private:
	SequenceD<64> key_;
};