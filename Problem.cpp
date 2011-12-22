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
	std::lock_guard<std::mutex> lk(image_m);
	Image start(ifs);
	Image end(ifs);
	long n;
	(*ifs) >> n;
	stamps.reserve(n);
	for(int i = 0;i < n;i++){
		stamps.push_back(Stamp(ifs));
		stamps[i].setNumber(i);
	}
	stamps_size = stamps;
	std::sort(stamps_size.begin(), stamps_size.end());

	long w, h, cnt = 0;
	w = start.getWidth();
	h = start.getHeight();
	image = Image(w, h);
	for(int y = 0;y < h;y++){
		for(int x = 0;x < w;x++){
			if(start.get(x, y) != end.get(x, y)){
				image.set(x, y, 1);
				cnt++;
			}
			image.set(x, y, start.get(x, y) ^ end.get(x, y));
		}
	}
	std::cerr << "不一致数：" << cnt << std::endl;
	discord = cnt;
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
	if((unsigned long) n >= stamps.size()){
		std::cerr << "警告: スタンプ番号が範囲外" << std::endl;
		return;
	}

	/* 適用する範囲を計算 */
	long sx, sy, ox, oy, sw, sh;
	sx = x;
	sy = y;
	sw = stamps[n].getWidth();
	sh = stamps[n].getHeight();
	CalcPosition(sx, sy, ox, oy, sw, sh);

	std::lock_guard<std::mutex> lk(image_m);

	for(long cy = 0;cy < sh;cy++){
		for(long cx = 0;cx < sw;cx++){
			image.set(sx + cx, sy + cy, image.get(sx + cx, sy + cy) ^ stamps[n].get(ox + cx, oy + cy));
		}
	}

}

/*!
 *  \param [in] x X座標
 *  \param [in] y Y座標
 *  \param [in] n スタンプ番号
 */
int Problem::CalcMatch(long x, long y, long n) const
{
	if((unsigned long) n >= stamps.size()){
		std::cerr << "警告: スタンプ番号が範囲外" << std::endl;
		return 0;
	}

	/* 適用する範囲を計算 */
	long sx, sy, ox, oy, sw, sh;
	sx = x;
	sy = y;
	sw = stamps[n].getWidth();
	sh = stamps[n].getHeight();
	CalcPosition(sx, sy, ox, oy, sw, sh);

	if(sw*sh == 0){
		std::cerr << "警告: スタンプ位置が範囲外" << std::endl;
		return 0;
	}

	long count = 0, all = 0;
	for(long cy = 0;cy < sh;cy++){
		for(long cx = 0;cx < sw;cx++){
			if(stamps[n].get(ox + cx, oy+ cy)){
				all++;
				if(image.get(sx + cx, sy + cy) == stamps[n].get(ox + cx, oy + cy)){
					count++;
				}
			}
		}
	}
	if(all == 0) return 0;
	return (count*1000)/(all);
}

/*!
 *  \param [in,out] startx X座標
 *  \param [in,out] starty Y座標
 *  \param [out] offsetx X座標
 *  \param [out] offsety Y座標
 *  \param [in,out] stampw スタンプの幅
 *  \param [in,out] stamph スタンプの高さ
 */
void Problem::CalcPosition(long &startx, long &starty, long &offsetx, long &offsety, long &stampw, long &stamph) const
{
	if(startx >= image.getWidth() || starty >= image.getHeight() || startx+stampw <= 0 || starty+stamph <= 0){
		std::cerr << "警告: スタンプ位置が範囲外" << std::endl;
		startx = 0;
		starty = 0;
		offsetx = 0;
		offsety = 0;
		stampw = 0;
		stamph = 0;
		return;
	}
	/* 左,上はみ出しチェック */
	if(startx < 0){
		offsetx = -startx;
		stampw -= offsetx;
		startx = 0;
	}else{
		offsetx = 0;
	}
	if(starty < 0){
		offsety = -starty;
		stamph -= offsety;
		starty= 0;
	}else{
		offsety = 0;
	}
	/* 右,下はみ出しチェック*/
	if(startx + offsetx + stampw >= image.getWidth()){
		stampw = image.getWidth() -  offsetx - startx;
	}
	if(starty + offsety + stamph >= image.getHeight()){
		stamph = image.getHeight() - offsety - starty;
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
	number = 0;
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

bool operator<(const Problem::Image &a, const Problem::Image &b)
{
	return (a.getWidth()*a.getHeight() < b.getWidth()*b.getHeight());
}
