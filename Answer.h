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
	std::mutex stamps_m; /*!< スタンプ情報を操作する際のミューテックス */
};

/*!
 * スタンプの比較
 * \param [in] a 左辺
 * \param [in] b 右辺
 * \return 左辺のほうが小さい場合trueを返す
 * x,y,nの順に比較する
 */
bool operator<(const Answer::stamp &a, const Answer::stamp &b);
/*!
 * スタンプの比較
 * \param [in] a 左辺
 * \param [in] b 右辺
 * \return 完全に一致する場合trueを返す
 */
bool operator==(const Answer::stamp &a, const Answer::stamp &b);

#endif /* ANSWER_H_ */
