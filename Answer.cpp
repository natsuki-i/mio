/*
 * Answer.cpp
 *
 *  Created on: 2011/08/20
 *      Author: なつき
 */

#include "prec.h"
#include "Answer.h"

Answer::Answer()
{
}

Answer::~Answer()
{
}

void Answer::Add(long x, long y, long n)
{
	struct stamp temp = { x, y, n };
	stamps.push_back(temp);
}

void Answer::Output(boost::shared_ptr<std::ostream> ofs)
{
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
			if(pre.n != -1 && c%2 == 1){
				temp.push_back(pre);
			}
			c = 0;
			pre = stamp;
		}
	}
	c++;
	if(pre.n != -1 && c%2 == 1){
		temp.push_back(pre);
	}

	(*ofs) << temp.size() << std::endl;
	BOOST_FOREACH(auto &stamp, temp)
	{
		(*ofs)<< stamp.n  << stamp.x << " " << stamp.y << " " << std::endl;
	}
}

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

bool operator==(const Answer::stamp &a, const Answer::stamp &b)
{
	if(a.x != b.x) return (false);
	if(a.y != b.y) return (false);
	if(a.n != b.n) return (false);
	return (true);
}
