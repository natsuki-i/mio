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
private:
	void core(const long &pw, const long &ph, const int threshold, const Problem::Stamp &stamp);
public:
	AlgorithmBruteForce(Problem &problem, Answer &answer, int sh, int eh); /*!< コンストラクタ */
	virtual ~AlgorithmBruteForce(); /*!< デストラクタ */
	virtual void operator()(); /*!< アルゴリズム本体 */
	static std::string getName()
	{
		return "BruteForce";
	}
};

#endif /* ALGORITHMBRUTEFORCE_H_ */
