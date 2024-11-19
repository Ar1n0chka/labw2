// #include <iostream>
// #include <vector>
// #include <string>
// #include "02/ip_filter.hpp"
// #include <fstream>

// int main()
// {
    
//     std::vector<std::vector<std::string> > ip_pool;
//     std::ifstream file("../02/ip_filter.tsv");
//     for(std::string line; std::getline(file, line);)
//     {
//         std::vector<std::string> v = split(line, '\t');
//         ip_pool.push_back(split(v.at(0), '.'));
//     }

//     /**
//      * @brief TODO reverse lexicographically sort
//      */
//     for(std::vector<std::vector<std::string> >::const_iterator ip = ip_pool.cbegin(); ip != ip_pool.cend(); ++ip)
//     {
//         for(std::vector<std::string>::const_iterator ip_part = ip->cbegin(); ip_part != ip->cend(); ++ip_part)
//         {
//             if (ip_part != ip->cbegin())
//             {
//                 std::cout << ".";

//             }
//             std::cout << *ip_part;
//         }
//         std::cout << std::endl;
//     }
    
// }



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
    std::ifstream file("../02/ip_filter.tsv");
    while(std::getline(file, s))
    {
        auto splited = split(s.substr(0, s.find('\t')), '.');
        std::vector<int> octets = {stoi(splited[0]), stoi(splited[1]), stoi(splited[2]), stoi(splited[3])};
        ip_address.push_back(octets);
    }

    sort(ip_address.begin(), ip_address.end(), LexiSort);
    PrintAll(ip_address);
    PrintByteOne(ip_address);
    Print46and70(ip_address);
    Print46(ip_address);
}