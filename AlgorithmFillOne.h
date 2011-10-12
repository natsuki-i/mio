/*!
 * \file AlgorithmFillOne.h
 * \date 2011/08/25
 * \author らきせぶん
 */

#ifndef ALGORITHMFILLONE_H_
#define ALGORITHMFILLONE_H_

#include "AlgorithmBase.h"

class AlgorithmFillOne: public AlgorithmBase
{
public:
	AlgorithmFillOne();
	virtual ~AlgorithmFillOne();
	virtual void Solve(Problem &problem, Answer &answer);
};

#endif /* ALGORITHMFILLONE_H_ */
