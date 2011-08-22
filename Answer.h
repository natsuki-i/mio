/*
 * Answer.h
 *
 *  Created on: 2011/08/20
 *      Author: natsuki
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
private:
	struct stamp
	{
		long x;
		long y;
		long n;
		bool operator<(const struct stamp &s)
		{
			if (x < s.x)
				return (true);
			else
				return (false);
			if (y < s.y)
				return (true);
			else
				return (false);
			if (n < s.n)
				return (true);
			else
				return (false);
			return (false);
		}
		bool operator==(const struct stamp &s)
		{
			if (x != s.x)
				return (false);
			if (y != s.y)
				return (false);
			if (n != s.n)
				return (false);
			return (true);
		}
	};
	std::vector<struct stamp> stamps;
};

#endif /* ANSWER_H_ */
