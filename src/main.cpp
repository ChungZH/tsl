#include <cxxopts.hpp>
#include <iostream>
#include <rang.hpp>
#include <vector>
#include <codecvt>
#include <locale>

#include <cpr/cpr.h>

using std::cin;
using std::cout;
using std::endl;
using std::ofstream;
using std::ostream;

int main(int argc, char** argv)
{
    cxxopts::Options options("tsl", "Translate in terminal.");

    options.add_options()("h,help", "Print usage");

    auto result = options.parse(argc, argv);

    if (result.count("help")) {
        cout << options.help() << endl;
        exit(0);
    }
    const std::vector<std::string> words(result.unmatched());
    for (const auto word : words) {
        cpr::Response r = cpr::Get(cpr::Url { "http://fanyi.youdao.com/openapi.do?keyfrom=node-fanyi&key=110811608&type=data&doctype=json&version=1.1&q="+word });
        cout << r.text << endl;
    }
    return 0;
}
