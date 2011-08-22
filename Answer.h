/*
 * Answer.h
 *
 *  Created on: 2011/08/20
 *      Author: なつき
 */

#ifndef ANSWER_H_
#define ANSWER_H_

class Answer
{
public:
	Answer();
	~Answer();
	void Add(long x, long y, long n);
	void Output(boost::shared_ptr<std::ostream> ofs);
public:
	struct stamp
	{
		long x;
		long y;
		long n;
	};
private:
	std::vector<struct stamp> stamps;
};

bool operator<(const Answer::stamp &a, const Answer::stamp &b);
bool operator==(const Answer::stamp &a, const Answer::stamp &b);

#endif /* ANSWER_H_ */
