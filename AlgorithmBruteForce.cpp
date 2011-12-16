/*!
 * \file AlgorithmBruteForce.cpp
 * \date 2011/08/22
 * \author なつき
 */

#include "prec.h"
#include "Problem.h"
#include "Answer.h"
#include "AlgorithmBase.h"
#include "AlgorithmBruteForce.h"

AlgorithmBruteForce::AlgorithmBruteForce()
{
}

AlgorithmBruteForce::~AlgorithmBruteForce()
{
}

/*!
 * \param [in, out] problem 問題
 * \param [out] answer 回答
 */
void AlgorithmBruteForce::Solve(Problem &problem, Answer &answer)
{
	using namespace std;
	long pw = problem.image.getWidth();
	long ph = problem.image.getHeight();
	BOOST_REVERSE_FOREACH(auto stamp, problem.stamps_size)
	{
		long w = stamp.getWidth();
		long h = stamp.getHeight();
		long n = stamp.getNumber();
		if(w*h == 1)continue;
		for(int  y = -h/2+1;y < ph - h/2;y++){
			for(int x = -w/2+1;x < pw - w/2;x++){
				if(problem.CalcMatch(x, y, n) >= 800){
					problem.AffixStamp(x, y, n);
					answer.Add(x, y, n);
				}
			}
		}
	}
}

