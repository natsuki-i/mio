/*
 * Problem.cpp
 *
 *  Created on: 2011/08/20
 *      Author: なつき
 */

#include "prec.h"
#include "Problem.h"

Problem::Problem(boost::shared_ptr<std::istream> ifs)
{
	Image start(ifs);
	Image end(ifs);
	long n;
	(*ifs) >> n;
	stamps.reserve(n);
	for(int i = 0;i < n;i++){
		stamps.push_back(Image(ifs));
	}

}

Problem::~Problem()
{
}

void Problem::AffixStamp(long x, long y, long n)
{
	// TODO:
}

Problem::Image::Image(boost::shared_ptr<std::istream> ifs)
{
	long w, h;
	(*ifs) >> w >> h;
	width = w;
	height = h;
	image.resize(h, std::vector<bool>(w));
	for(int y = 0;y < h;y++){
		std::string line;
		(*ifs) >> line;
		for(int x = 0;x < w;x++){
			image[y][x] = (line[x] == '1')?true:false;
		}
	}
}
