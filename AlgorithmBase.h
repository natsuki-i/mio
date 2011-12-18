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
protected:
	Problem &problem;
	Answer &answer;
	int sh, eh;
public:
	AlgorithmBase(Problem &problem, Answer &answer, int sh, int eh); /*!< コンストラクタ */
	virtual ~AlgorithmBase(); /*!< デストラクタ */
	virtual void operator()(); /*!< アルゴリズム本体 */
	static std::string getName()
	{
		return "Dummy";
	}
};

/*!
 * \param [in, out] problem 問題
 * \param [out] answer 回答
 */
template<class T>
void Solve(Problem &problem, Answer &answer)
{
	long h = problem.image.getHeight();
	std::cerr << "開始：" << T::getName() << std::endl;
	std::vector<std::thread> t;
	int tn = atoi(options["thread"].c_str());
	if(tn <= 0) tn = 1;
	for(int i = 0;i < tn;i++){
		t.push_back(std::thread(T(problem, answer, h/tn*i, h/tn*(i+1))));
	}
	for(int i = 0;i < tn;i++){
		t[i].join();
	}
	std::cerr << "終了：" << T::getName() << std::endl;
}

#endif /* ALGORITHMBASE_H_ */
