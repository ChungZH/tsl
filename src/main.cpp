#include <cxxopts.hpp>
#include <iostream>
#include <locale>
#include <vector>

#include <cpr/cpr.h>
#include <cpr/util.h>

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
        std::string urlYD = "http://fanyi.youdao.com/openapi.do?keyfrom=node-fanyi&key=110811608&type=data&doctype=json&version=1.1&q=" + cpr::util::urlEncode(word);
        std::string urlICB = "http://dict-co.iciba.com/api/dictionary.php?key=D191EBD014295E913574E1EAF8E06666&w=" + cpr::util::urlEncode(word);
        cpr::Response rYD = cpr::Get(cpr::Url { urlYD });
        cpr::Response rICB = cpr::Get(cpr::Url { urlICB });
        cout << rYD.text << endl;
        cout << rICB.text << endl;
    }
    return 0;
}
