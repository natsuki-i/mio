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

/*!
 * \param [in,out] problem 問題
 * \param [in,out] answer 回答
 * \param [in] sy 上端
 * \param [in] ey 下端
 */
AlgorithmFillOne::AlgorithmFillOne(Problem &problem, Answer &answer, int sh, int eh)
	: AlgorithmBase(problem, answer, sh, eh)
{
}

AlgorithmFillOne::~AlgorithmFillOne()
{
}

/*!
 * \param [in, out] problem 問題
 * \param [out] answer 回答
 */
void AlgorithmFillOne::operator()()
{
	long int w = problem.image.getWidth();
	for(int y = sh;y < eh;y++){
		for(int x = 0;x < w;x++){
			if(problem.image.get(x, y)){
				problem.AffixStamp(x, y, problem.stamps_size[0].getNumber());
				answer.Add(x, y, problem.stamps_size[0].getNumber());
			}
		}
	}
}

