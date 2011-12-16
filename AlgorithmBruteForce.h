/*!
 * \file AlgorithmBruteForce.h
 * \date 2011/08/22
 * \author なつき
 */

#ifndef ALGORITHMBRUTEFORCE_H_
#define ALGORITHMBRUTEFORCE_H_

#include "AlgorithmBase.h"

/*! 力任せアルゴリズム
 *  
 */
class AlgorithmBruteForce: public AlgorithmBase
{
public:
	AlgorithmBruteForce(); /*!< コンストラクタ */
	virtual ~AlgorithmBruteForce(); /*!< デストラクタ */
	virtual void Solve(Problem &problem, Answer &answer); /*!< アルゴリズム本体 */
};

#endif /* ALGORITHMBRUTEFORCE_H_ */
