/*!
 * \file AlgorithmBase.h
 * \date 2011/08/22
 * \author なつき
 */

#ifndef ALGORITHMBASE_H_
#define ALGORITHMBASE_H_

class Problem;
class Answer;

/*! すべてのアルゴリズムのベース
 *  アルゴリズムを追加する場合はこのクラスから派生する
 */
class AlgorithmBase
{
public:
	AlgorithmBase(); /*!< コンストラクタ */
	virtual ~AlgorithmBase(); /*!< デストラクタ */
	virtual void Solve(Problem &problem, Answer &answer); /*!< アルゴリズム本体 */
};

#endif /* ALGORITHMBASE_H_ */
