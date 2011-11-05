/*!
 * \file AlgorithmFillOne.cpp
 * \date 2011/08/25
 * \author らきせぶん
 */

#include "prec.h"
#include "Problem.h"
#include "Answer.h"
#include "AlgorithmBase.h"
#include "AlgorithmFillOne.h"

AlgorithmFillOne::AlgorithmFillOne()
{
}

AlgorithmFillOne::~AlgorithmFillOne()
{
}

/*!
 * \param [in, out] problem 問題
 * \param [out] answer 回答
 */
void AlgorithmFillOne::Solve(Problem &problem, Answer &answer)
{
	long int h = problem.image.getHeight();
	long int w = problem.image.getWidth();
	for(int y = 0;y < h;y++){
		for(int x = 0;x < w;x++){
			if(problem.image.get(x, y)){
				problem.AffixStamp(x, y, problem.stamps[0].getNumber());
				answer.Add(x, y, problem.stamps[0].getNumber());
			}
		}
	}
}
