/*!
 * \file AlgorithmBase.cpp
 * \date 2011/08/22
 * \author なつき
 */

#include "prec.h"
#include "Problem.h"
#include "Answer.h"
#include "AlgorithmBase.h"

/*!
 * \param [in,out] problem 問題
 * \param [in,out] answer 回答
 * \param [in] sy 上端
 * \param [in] ey 下端
 */
AlgorithmBase::AlgorithmBase(Problem &problem, Answer &answer, int sh, int eh)
	: problem(problem), answer(answer), sh(sh), eh(eh)
{
}

AlgorithmBase::~AlgorithmBase()
{
}

/*!
 */
void AlgorithmBase::operator()()
{
	// Do something.
}

