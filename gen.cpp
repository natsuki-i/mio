/*
 * gen.cpp
 *
 *  Created on: 2011/08/25
 *      Author: なつき
 */

#include "prec.h"


void genImage(boost::shared_ptr<std::ostream> ofs, long w, long h)
{
	using namespace std;
	(*ofs) << w << endl << h << endl;
	for(int y = 0;y < h;y++){
		for(int x = 0;x < w;x++){
			(*ofs) << rand()%2;
		}
		(*ofs) << endl;
	}
}

// 何もしないダミー関数
struct noop{
	void operator()(...) const {}
};

int main(int argc, char *argv[])
{
	using namespace std;
	try{
		string filename;
		long w = -1, h = -1, n = -1;
		for(int i = 1; i < argc; i++)
		{
			if(argv[i][0] == '-'){
				if(strlen(argv[i]) < 3){
					throw string("option");
				}
				switch (argv[i][1])
				{
				case 'w':
				case 'x':
					w = atoi(&argv[i][2]);
					break;
				case 'h':
				case 'y':
					h = atoi(&argv[i][2]);
					break;
				case 'n':
					n = atoi(&argv[i][2]);
					break;
				case 'o':
					filename = string(&argv[i][2]);
					break;
				default:
					throw string("option");
				}
			}
		}
		if(w < 0){
			cerr << "width:";
			cin >> w;
		}
		if(h < 0){
			cerr << "height:";
			cin >> h;
		}
		if(n < 0){
			cerr << "n:";
			cin >> n;
		}
		if(w < 1 || w > 640 || h < 1 || h > 480 || n < 1 || n > 128){
			throw string("size");
		}
		boost::shared_ptr<ostream> ofs;
		cout << filename << endl;
		if(filename != ""){
			ofs.reset(new ofstream(filename.c_str(), ios::out));
		}else{
			ofs.reset(&cout, noop());
		}

		srand((unsigned)time(NULL));

		genImage(ofs, w, h);
		genImage(ofs, w, h);
		(*ofs) << n << endl;
		(*ofs) << 1 << endl << 1 << endl << 1 << endl;
		long min_w = min(128L, w);
		long min_h = min(128L, h);
		for(int i = 1;i < n;i++){
			genImage(ofs, min_w, min_h);
		}


	}catch(string &e){
		if(e == "option"){
			cerr << "Usage: gen [options]" << endl;
		}else if(e == "size"){
			cerr << "Error: illegal size" << endl;
			cerr << "       1 <= w <= 640" << endl;
			cerr << "       1 <= h <= 480" << endl;
			cerr << "       1 <= n <= 128" << endl;
		}
	}
	return (0);
}

