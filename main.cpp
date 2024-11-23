#include <cassert>
#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <algorithm>
#include "02/ip_filter.hpp"


int main()
{
    std::vector<std::vector<int>> ip_address;
    std::string s;
    std::ifstream file("../02/ip_filter.tsv");//read
    while(std::getline(file, s))//open
    {
        auto splited = split(s.substr(0, s.find('\t')), '.');
        std::vector<int> octets = {stoi(splited[0]), stoi(splited[1]), stoi(splited[2]), stoi(splited[3])}; //str to int
        ip_address.push_back(octets);
    }

    sort(ip_address.begin(), ip_address.end(), LexiSort);
    PrintAll(ip_address);
    PrintByteOne(ip_address);
    Print46and70(ip_address);
    Print46(ip_address);
}