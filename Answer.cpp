/*!
 * \file Answer.cpp
 * \date 2011/08/20
 * \author なつき
 */

#include "prec.h"
#include "Answer.h"

Answer::Answer()
{
}

Answer::~Answer()
{
}

/*! 回答を追加する
 *  \param [in] x X座標
 *  \param [in] y Y座標
 *  \param [in] n スタンプ番号
 */
void Answer::Add(long x, long y, long n)
{
	struct stamp temp = { x, y, n };
	std::lock_guard<std::mutex> lk(stamps_m);
	stamps.push_back(temp);
}

/*! 回答を出力する
 *  \param [out] ofs 出力ストリーム
 *  回答をソートし、重複を削除して出力ストリームに出力する
 */
void Answer::Output(boost::shared_ptr<std::ostream> ofs)
{
	std::lock_guard<std::mutex> lk(stamps_m);
	std::sort(stamps.begin(), stamps.end());
	std::vector<stamp> temp;
	temp.reserve(stamps.size());

	// ダブり消去
	stamp pre = { -1, -1, -1 };
	int c = 0;
	BOOST_FOREACH(auto &stamp, stamps)
	{
		c++;
		if(pre == stamp){
		}else{
			if(pre.n != -1 && c % 2 == 1){
				temp.push_back(pre);
			}
			c = 0;
			pre = stamp;
		}
	}
	c++;
	if(pre.n != -1 && c % 2 == 1){
		temp.push_back(pre);
	}

	(*ofs) << temp.size() << "\r\n";
	BOOST_FOREACH(auto &stamp, temp)
	{
		(*ofs) << stamp.n << " " << stamp.x << " " << stamp.y << "\r\n";
	}
	std::cerr << "手数:" << temp.size() << std::endl;
}

/*! スタンプの位置、番号から大小を比較する
 */
bool operator<(const Answer::stamp &a, const Answer::stamp &b)
{
	if(a.x < b.x) return (true);
	else if(a.x > b.x) return (false);
	if(a.y < b.y) return (true);
	else if(a.x > b.x) return (false);
	if(a.n < b.n) return (true);
	else if(a.x > b.x) return (false);
	return (false);
}

/*! スタンプの位置、番号が一致しているか調べる
 */
bool operator==(const Answer::stamp &a, const Answer::stamp &b)
{
	if(a.x != b.x) return (false);
	if(a.y != b.y) return (false);
	if(a.n != b.n) return (false);
	return (true);
}
