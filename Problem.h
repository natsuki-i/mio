/*
 * Problem.h
 *
 *  Created on: 2011/08/20
 *      Author: natsuki
 */

#ifndef PROBLEM_H_
#define PROBLEM_H_

class Problem
{
public:
	Problem(boost::shared_ptr<std::istream> ifs);
	~Problem();
private:
	class Image
	{
	public:
		Image() :
				width(0), height(0), image()
		{
		}
		Image(long w, long h) :
				width(w), height(h), image(h, std::vector<bool>(w, false))
		{
		}
		~Image()
		{
		}
	private:
		long width;
		long height;
		std::vector<std::vector<bool> > image;
	};
	Image start, end;
	std::vector<Image> stamps;
};

#endif /* PROBLEM_H_ */
