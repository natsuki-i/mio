/*!
 * \file Problem.h
 * \date 2011/08/20
 * \author なつき
 */

#ifndef PROBLEM_H_
#define PROBLEM_H_

/*! 問題を保持するクラス
 *  画像一枚とスタンプを保持する
 *  画像が全て0になったとき回答終了である
 */
class Problem
{
public:
	Problem(boost::shared_ptr<std::istream> ifs); /*!< コンストラクタ */
	~Problem(); /*!< デストラクタ */
	void AffixStamp(long x, long y, long n); /*!< 指定した座標にスタンプを適用する */
public:
	/*! 画像を保持するクラス
	 *  問題画像、スタンプの両方に使用する
	 */
	class Image
	{
	public:
		/*! コンストラクタ
		 *  サイズ0の画像を生成する
		 */
		Image() :
				width(0), height(0), image()
		{
		}

		/*! コンストラクタ
		 *  指定したサイズで画像を生成する
		 *  \param [in] w 幅
		 *  \param [in] h 高さ
		 */
		Image(long w, long h) :
				width(w), height(h), image(h, std::vector<bool>(w, false))
		{
		}
		/*! コンストラクタ
		 *  文字列から画像を生成する
		 *  \param [in] ifs 入力ストリーム
		 */
		Image(boost::shared_ptr<std::istream> ifs);
		~Image()
		{
		}
		/*! 幅を取得する
		 *  \return 幅
		 */
		inline long getWidth(void)
		{
			return (width);
		}

		/*! 高さを取得する
		 *  \return 高さ
		 */
		inline long getHeight(void)
		{
			return (height);
		}

		/*! 指定座標の色を取得する
		 *  \param [in] x X座標
		 *  \param [in] y Y座標
		 *  \return 色(true:黒/false:白)
		 */
		inline bool get(long x, long y)
		{
			return (image[y][x]);
		}

		/*! 指定座標の色を設定する
		 *  \param [in] x X座標
		 *  \param [in] y Y座標
		 *  \param [in] b 色(true:黒/false:白)
		 */
		inline bool set(long x, long y, bool b)
		{
			return (image[y][x] = b);
		}

		/*! デバッグ用
		 *  std::cout << image;
		 *  で画像を出力する
		 */
		friend std::ostream& operator<<(std::ostream &os, const Image &image);
	private:
		long width;
		long height;
		std::vector<std::vector<bool> > image;
	};
public:
	Image image; /*!< 回答中の画像 */
	std::vector<Image> stamps; /*!< スタンプ */
};

#endif /* PROBLEM_H_ */
