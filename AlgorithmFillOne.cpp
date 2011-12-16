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
	worker w1(problem, answer, 0, h/4);
	worker w2(problem, answer, h/4, h/2);
	worker w3(problem, answer, h/2, 3*h/4);
	worker w4(problem, answer, 3*h/4, h);
	std::thread t1(w1), t2(w2), t3(w3), t4(w4);
	t1.join();
	t2.join();
	t3.join();
	t4.join();
}

void AlgorithmFillOne::worker::operator()()
{
	long int w = problem.image.getWidth();
	for(int y = sy;y < ey;y++){
		for(int x = 0;x < w;x++){
			if(problem.image.get(x, y)){
				problem.AffixStamp(x, y, problem.stamps_size[0].getNumber());
				answer.Add(x, y, problem.stamps_size[0].getNumber());
			}
		}
	}
}
