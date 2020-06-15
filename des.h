#include "sequenceD.h"

class des
{
public:
	des(const SequenceD<64>& key);
	SequenceD<64> operator()(SequenceD<64> sequenceD) const;

private:
	SequenceD<64> key_;
};