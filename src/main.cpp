#include <cxxopts.hpp>
#include <iostream>
#include <rang.hpp>
#include <vector>

#include <cpr/cpr.h>

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
    }
    cpr::Response r = cpr::Get(cpr::Url { "http://dict-co.iciba.com/api/dictionary.php?key=D191EBD014295E913574E1EAF8E06666&w=%E6%B5%8B%E8%AF%95" });

    return 0;
}