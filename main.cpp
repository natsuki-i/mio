/*!
 * \file main.cpp
 * \date 2011/8/19
 * \author なつき
 */

#include "prec.h"
#include "Problem.h"
#include "Answer.h"
#include "AlgorithmBase.h"
#include "AlgorithmBruteForce.h"
#include "AlgorithmFillOne.h"

std::map<std::string, std::string> options; /*!< コマンドラインオプション */

/*! オプションの解析
 *  \param [in] args 引数の配列
 *  \return オプションの連想配列
 */
std::map<std::string, std::string> parse_options(std::vector<std::string> &args)
{
	using namespace std;
	map<string, string> ret;
	try{
		for(auto it = args.begin();it != args.end();it++){
			if((*it)[0] == '-'){
				switch((*it)[1]){
				// \TODO: オプションを追加する場合はここに追記すること
				case 'i':
					if(++it == args.end()) throw "arg";
					ret.insert(make_pair("input", *(it)));
					break;
				case 'o':
					if(++it == args.end()) throw "arg";
					ret.insert(make_pair("output", *(it)));
					break;
				case 'b':
					if(*it == "-bf"){
						if(++it == args.end()) throw "arg";
						if(!boost::regex_match(*it, boost::regex("[0-9]+"))){
							throw "arg";
						}
						ret.insert(make_pair("bf-thread", *it));
						if(++it == args.end()) throw "arg";
						if(!boost::regex_match(*it, boost::regex("[0-9]+"))){
							throw "arg";
						}
						ret.insert(make_pair("bf-threshold", *it));
						ret.insert(make_pair("bruteforce", "true"));
					}else{
						ret.insert(make_pair(*it, "true"));
					}
					break;
				default:
					ret.insert(make_pair(*it, "true"));
					break;
				}
			}
		}
	} catch(...){
		cout << "Usage: mio [-i input] [-o output] [-bf thread threshold [-bf-rev] ]" << endl;
		return (map<string, string>());
	}
	ret.insert(make_pair("stat", "ok"));
	return (ret);
}

struct noop
{
	/*! 何もしない関数 */
	void operator()(...) const
	{
	}
};

/*! エントリポイント
 * \param [in] argc 引数の数
 * \param [in] argv コマンド文字列の配列
 */
int main(int argc, const char *argv[])
{
	using namespace std;
	// オプション解析
	vector<string> args;
	for(int i = 1;i < argc;i++){
		args.push_back(argv[i]);
	}
	options = parse_options(args);
	if(options["stat"] != "ok"){
		return -1;
	}

	// IOストリーム用意
	boost::shared_ptr<istream> ifs;
	boost::shared_ptr<ostream> ofs;
	if(options["input"] != ""){
		ifs.reset(new ifstream(options["input"].c_str(), ios::in));
	}else{
		ifs.reset(&cin, noop());
	}
	if(options["output"] != ""){
		ofs.reset(new ofstream(options["output"].c_str(), ios::out));
	}else{
		ofs.reset(&cout, noop());
	}

	Problem problem(ifs);
	Answer answer;

	vector<AlgorithmBase*> al;
	if(options["bruteforce"] != ""){
		al.push_back(new AlgorithmBruteForce);
	}
	al.push_back(new AlgorithmFillOne);

	BOOST_FOREACH(auto a, al){
		a->Solve(problem, answer);
	}

	answer.Output(ofs);

	return (0);
}
