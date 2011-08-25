/*
 * Problem.h
 *
 *  Created on: 2011/08/20
 *      Author: なつき
 */

#ifndef PROBLEM_H_
#define PROBLEM_H_

class Problem
{
public:
	Problem(boost::shared_ptr<std::istream> ifs);
	~Problem();
	void AffixStamp(long x, long y, long n);
public:
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
		Image(boost::shared_ptr<std::istream> ifs);
		~Image()
		{
		}
		inline long getWidth(void)
		{
			return (width);
		}
		inline long getHeight(void)
		{
			return (height);
		}
		inline bool get(long x, long y)
		{
			return (image[y][x]);
		}
		inline bool set(long x, long y, bool b)
		{
			return (image[y][x] = b);
		}
		friend std::ostream& operator<<(std::ostream &os, const Image &image);
	private:
		long width;
		long height;
		std::vector<std::vector<bool> > image;
	};
public:
	Image image;
	std::vector<Image> stamps;
};

#endif /* PROBLEM_H_ */
