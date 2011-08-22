/*
 * main.cpp
 *
 *  Created on: 2011/8/19
 *      Author: なつき
 */

#include "prec.h"
#include "Problem.h"
#include "Answer.h"

std::map<std::string, std::string> parse_options(std::vector<std::string> &args)
{
	using namespace std;
	map<string, string> ret;
	try
	{
		for (vector<string>::iterator it = args.begin(); it != args.end(); it++)
		{
			if ((*it)[0] == '-')
			{
				switch ((*it)[1])
				{
				// TODO: オプションを追加する場合はここに追記すること
				case 'i':
					if (++it == args.end())
						throw "arg";
					ret.insert(make_pair("input", *(it)));
					break;
				case 'o':
					if (++it == args.end())
						throw "arg";
					ret.insert(make_pair("output", *(it)));
					break;
				default:
					ret.insert(make_pair(*it, ""));
					break;
				}
			}
		}
	} catch (...)
	{
		cout << "Usage: mio -i input -o output" << endl;
		return (map<string, string>());
	}
	return (ret);
}

// 何もしないダミー関数
struct noop{
	void operator()(...) const {}
};

int main(int argc, const char *argv[])
{
	using namespace std;
	// オプション解析
	vector<string> args;
	for (int i = 1; i < argc; i++)
	{
		args.push_back(argv[i]);
	}
	map<string, string> opt = parse_options(args);

	// IOストリーム用意
	boost::shared_ptr<istream> ifs;
	boost::shared_ptr<ostream> ofs;
	if(opt["input"] != ""){
		ifs.reset(new ifstream(opt["input"].c_str(), ios::in));
	}else{
		ifs.reset(&cin, noop());
	}
	if(opt["output"] != ""){
		ofs.reset(new ofstream(opt["output"].c_str(), ios::out));
	}else{
		ofs.reset(&cout, noop());
	}
	return (0);
}
