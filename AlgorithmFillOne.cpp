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

void AlgorithmFillOne::Solve(Problem &problem, Answer &answer)
{
	bool f=false;
	long int h = problem.image.getHeight();
	long int w = problem.image.getHeight();
	long sc = problem.stamps.size();
	long n=0;
	while(n < sc){
		long h = problem.stamps[n].getHeight();
		long w = problem.stamps[n].getWidth();
		if((h == 1) && (w == 1) && (problem.stamps[n].get(0, 0))){
			break;
		}
		n++;
	}
	if(n != sc){
		for(int y = 0;y < h;y++){
			for(int x = 0;x < w;x++){
				f = problem.image.get(x, y);
				if(f){
					problem.AffixStamp(x, y, n);
					answer.Add(x, y, n);
				}
			}
		}
	}
	// Do something.
}
