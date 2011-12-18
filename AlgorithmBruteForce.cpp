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

/*!
 * \param [in,out] problem 問題
 * \param [in,out] answer 回答
 * \param [in] sy 上端
 * \param [in] ey 下端
 */
AlgorithmBruteForce::AlgorithmBruteForce(Problem &problem, Answer &answer, int sh, int eh)
	:AlgorithmBase(problem, answer, sh, eh)
{
}

AlgorithmBruteForce::~AlgorithmBruteForce()
{
}

void AlgorithmBruteForce::operator()()
{
	long pw = problem.image.getWidth();
	long ph = problem.image.getHeight();
	long num = problem.stamps.size();
	long cnt = 0;
	int threshold = atoi(options["bf-threshold"].c_str());
	if(options["-bf-rev"] != ""){
		BOOST_FOREACH(auto &stamp, problem.stamps_size)
		{
			cnt++;
			std::cerr << "進捗：BruteForce " << cnt*100/num << std::endl;
			core(pw, ph, threshold, stamp);
		}
	}else{
		BOOST_REVERSE_FOREACH(auto &stamp, problem.stamps_size)
		{
			cnt++;
			std::cerr << "進捗：BruteForce " << cnt*100/num << std::endl;
			core(pw, ph, threshold, stamp);
		}
	}
}

void AlgorithmBruteForce::core(const long &pw, const long &ph, const int threshold, const Problem::Stamp &stamp)
{
		long w = stamp.getWidth();
		long h = stamp.getHeight();
		long n = stamp.getNumber();
		if(w*h == 1) return;
		long th = 1000-((1000-threshold)* (1-((double)w*h)/((double)pw*ph)));
		std::cerr << w << " " << h << " " << th << std::endl;
		for(int  y = sh -h/2+1;y < eh - h/2;y++){
			for(int x = -w/2+1;x < pw - w/2;x++){
				if(problem.CalcMatch(x, y, n) >= th){
					problem.AffixStamp(x, y, n);
					answer.Add(x, y, n);
				}
			}
		}
}

