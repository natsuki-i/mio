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
	/*! ワーカースレッド
	 * 
	 */
	struct worker{
		/*! コンストラクタ
		 * \param [in,out] problem
		 * \param [in,out] answer
		 * \param [in] sy 上端
		 * \param [in] ey 下端
		 */
		worker(Problem &problem, Answer &answer, int sy, int ey):
			problem(problem), answer(answer), sy(sy), ey(ey)
		{
		}
		Problem &problem;
		Answer &answer;
		int sy, ey;
		void core(const long &pw, const long &ph, const int threshold, const Problem::Stamp &stamp);
		void operator()();
	};
public:
	AlgorithmBruteForce(); /*!< コンストラクタ */
	virtual ~AlgorithmBruteForce(); /*!< デストラクタ */
	virtual void Solve(Problem &problem, Answer &answer); /*!< アルゴリズム本体 */
};

#endif /* ALGORITHMBRUTEFORCE_H_ */
