/*!
 * \file AlgorithmFillOne.h
 * \date 2011/08/25
 * \author らきせぶん
 */

#ifndef ALGORITHMFILLONE_H_
#define ALGORITHMFILLONE_H_

#include "AlgorithmBase.h"

/*! 1x1のスタンプで埋めるアルゴリズム
 *  最後に実行し漏れをなくすことが目的である
 *  スタンプ番号0が1x1のスタンプであることを前提とする
 */
class AlgorithmFillOne: public AlgorithmBase
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
		void operator()();
	};
public:
	AlgorithmFillOne(); /*!< コンストラクタ */
	virtual ~AlgorithmFillOne(); /*!< デストラクタ */
	virtual void Solve(Problem &problem, Answer &answer); /*!< アルゴリズム本体 */
};

#endif /* ALGORITHMFILLONE_H_ */
