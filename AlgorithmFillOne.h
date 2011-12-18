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
	AlgorithmFillOne(Problem &problem, Answer &answer, int sh, int eh); /*!< コンストラクタ */
	virtual ~AlgorithmFillOne(); /*!< デストラクタ */
	virtual void operator()(); /*!< アルゴリズム本体 */
	static std::string getName()
	{
		return "FillOne";
	}
};

#endif /* ALGORITHMFILLONE_H_ */
