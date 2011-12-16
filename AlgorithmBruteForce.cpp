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
	long h = problem.image.getHeight();
	std::cerr << "開始：BruteForce" << std::endl;
	worker w1(problem, answer, 0, h/4);
	worker w2(problem, answer, h/4, h/2);
	worker w3(problem, answer, h/2, 3*h/4);
	worker w4(problem, answer, 3*h/4, h);
	std::thread t1(w1), t2(w2), t3(w3), t4(w4);
	t1.join();
	t2.join();
	t3.join();
	t4.join();
	std::cerr << "終了：BruteForce" << std::endl;
}

void AlgorithmBruteForce::worker::operator()()
{
	long pw = problem.image.getWidth();
	long num = problem.stamps.size();
	long cnt = 0;
	BOOST_REVERSE_FOREACH(auto stamp, problem.stamps_size)
	{
		cnt++;
		long w = stamp.getWidth();
		long h = stamp.getHeight();
		long n = stamp.getNumber();
		std::cerr << "進捗：BruteForce " << cnt*100/num << std::endl;
		if(w*h == 1)continue;
		for(int  y = sy -h/2+1;y < ey - h/2;y++){
			for(int x = -w/2+1;x < pw - w/2;x++){
				if(problem.CalcMatch(x, y, n) >= 800){
					problem.AffixStamp(x, y, n);
					answer.Add(x, y, n);
				}
			}
		}
	}
}

