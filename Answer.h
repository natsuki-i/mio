/*!
 * \file Answer.h
 * \date 2011/08/20
 * \author なつき
 */

#ifndef ANSWER_H_
#define ANSWER_H_

/*! 回答を保持するクラス
 *  スタンプを押した座標を保持する
 */
class Answer
{
public:
	Answer(); /*!< コンストラクタ */
	~Answer(); /*!< デストラクタ */
	void Add(long x, long y, long n);
	void Output(boost::shared_ptr<std::ostream> ofs);
public:
	/*! スタンプ情報 */
	struct stamp
	{
		long x; /*!< X座標 */
		long y; /*!< Y座標 */
		long n; /*!< スタンプ番号 */
	};
private:
	std::vector<struct stamp> stamps; /*!< スタンプ情報の配列 */
};

bool operator<(const Answer::stamp &a, const Answer::stamp &b);
bool operator==(const Answer::stamp &a, const Answer::stamp &b);

#endif /* ANSWER_H_ */
