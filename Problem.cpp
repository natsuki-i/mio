/*!
 * \file Problem.cpp
 * \date 2011/08/20
 * \author なつき
 */

#include "prec.h"
#include "Problem.h"

/*! 文字列から問題を入力する
 *  \param [in] ifs 入力ストリーム
 */
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

	long w, h;
	w = start.getWidth();
	h = start.getHeight();
	image = Image(w, h);
	for(int y = 0;y < h;y++){
		for(int x = 0;x < w;x++){
			image.set(x, y, start.get(x, y) ^ end.get(x, y));
		}
	}
}

Problem::~Problem()
{
}

/*!
 *  \param [in] x X座標
 *  \param [in] y Y座標
 *  \param [in] n スタンプ番号
 */
void Problem::AffixStamp(long x, long y, long n)
{
	long sx, sy, ox, oy, sw, sh;
	if((unsigned long) n >= stamps.size()){
		std::cerr << "警告: スタンプ番号が範囲外" << std::endl;
		return;
	}
	if(x < 0){
		sx = 0;
		ox = x;
	}else{
		sx = x;
		ox = 0;
	}
	if(y < 0){
		sy = 0;
		oy = y;
	}else{
		sy = y;
		oy = 0;
	}
	if(x + stamps[n].getWidth() >= image.getWidth()){
		sw = image.getWidth() - x;
	}else{
		sw = stamps[n].getWidth();
	}
	if(y + stamps[n].getHeight() >= image.getHeight()){
		sh = image.getHeight() - y;
	}else{
		sh = stamps[n].getHeight();
	}
	for(long cy = 0;cy < sh;cy++){
		for(long cx = 0;cx < sw;cx++){
			image.set(
					sx + cx,
					sy + cy,
					image.get(sx + cx, sy + cy)
							^ stamps[n].get(ox + cx, oy + cy));
		}
	}

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
			image[y][x] = (line[x] == '1') ? true : false;
		}
	}
}

std::ostream& operator<<(std::ostream& os, const Problem::Image &image)
{
	for(int y = 0;y < image.height;y++){
		for(int x = 0;x < image.width;x++){
			os << image.image[y][x];
		}
		os << std::endl;
	}
	return (os);
}
