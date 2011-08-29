/*
 * AlgorithmFillOne.h
 *
 *  Created on: 2011/08/25
 *      Author: らきせぶん
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
