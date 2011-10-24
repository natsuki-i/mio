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
public:
	AlgorithmFillOne(); /*!< コンストラクタ */
	virtual ~AlgorithmFillOne(); /*!< デストラクタ */
	virtual void Solve(Problem &problem, Answer &answer); /*!< アルゴリズム本体 */
};

#endif /* ALGORITHMFILLONE_H_ */
