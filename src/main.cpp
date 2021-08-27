#include <cxxopts.hpp>
#include <iostream>
#include <rang.hpp>

int main()
{
    std::cout << "Plain old text"
              << rang::fg::green << "Rang styled text!!"
              << rang::style::reset << std::endl;
    return 0;
}