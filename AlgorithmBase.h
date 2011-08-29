/*
 * AlgorithmBase.h
 *
 *  Created on: 2011/08/22
 *      Author: なつき
 */

#ifndef ALGORITHMBASE_H_
#define ALGORITHMBASE_H_

class Problem;
class Answer;

class AlgorithmBase
{
public:
	AlgorithmBase();
	virtual ~AlgorithmBase();
	virtual void Solve(Problem &problem, Answer &answer);
};

#endif /* ALGORITHMBASE_H_ */
