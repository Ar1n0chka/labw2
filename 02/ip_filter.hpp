#include <cassert>
#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <algorithm>


/**
 * @brief Функция для лексикографической сортировки от меньшего к большему.
 * @param a кусок первого айпи
 */
auto LexiSort = [](auto a, auto b)
{
    if (a == b) return false;
    for (auto i = 0; i < 4; i++)
    {   
        if (a[i] > b[i])
        {
            return false;
        }
        else if (a[i] < b[i])
        {
            return true;
        }
    }
    return false;
};

auto PrintAll = [](std::vector<std::vector<int>> ip_address)
{
    for (size_t i = 0; i < ip_address.size(); i++)
    {
        for (auto j = 0; j < 4; j++)
        {
            std::cout << ip_address[i][j];
            if (j < 3) std::cout << ".";
        } 
        std::cout << std::endl;
    }
};

auto PrintByteOne = [](std::vector<std::vector<int>> ip_address)
{
    for (size_t i = 0; i < ip_address.size(); i++)
    {
        for (size_t j = 0; j < 4; j++)
        {
            if (ip_address[i][0] == 1)
            {
                std::cout << ip_address[i][j];
                if (j < 3) std::cout << ".";
                else if (j == 3) std::cout << std::endl;
                else break;
            }

        } 
    }
};

auto Print46and70 = [](std::vector<std::vector<int>> ip_address)
{
    for (size_t i = 0; i < ip_address.size(); i++)
    {
        for (size_t j = 0; j < 4; j++)
        {
            if (ip_address[i][0] == 46 && ip_address[i][1] == 70)
            {
                std::cout << ip_address[i][j];
                if (j < 3) std::cout << ".";
                else if (j == 3) std::cout << std::endl;
                else break;
            }
        } 
    }
};

auto Print46 = [](std::vector<std::vector<int>> ip_address)
{
    for (size_t i = 0; i < ip_address.size(); i++)
    {
        for (size_t j = 0; j < 4; j++)
        {
            if ( std::find(ip_address[i].begin(), ip_address[i].end(), 46) != ip_address[i].end() )
            {
                std::cout << ip_address[i][j];
                if (j < 3) std::cout << ".";
                else if (j == 3) std::cout << std::endl;
                else break;
            }
        } 
    }
};

std::vector<std::string> split(const std::string &str, char d)
{
    std::vector<std::string> r;
    std::string::size_type start = 0;
    std::string::size_type stop = str.find_first_of(d);
    while(stop != std::string::npos)
    {
        r.push_back(str.substr(start, stop - start));

        start = stop + 1;
        stop = str.find_first_of(d, start);
    }

    r.push_back(str.substr(start));
    return r;
}
// #pragma once
// #include <cassert>
// #include <cstdlib>
// #include <iostream>
// #include <string>
// #include <vector>

// // ("",  '.') -> [""]
// // ("11", '.') -> ["11"]
// // ("..", '.') -> ["", "", ""]
// // ("11.", '.') -> ["11", ""]
// // (".11", '.') -> ["", "11"]
// // ("11.22", '.') -> ["11", "22"]

// /** 
//  *   разделение строки по символу d(".")
//  * @param str строка на входе 
//  * @param d символ, по которому разделяется строка
//  */
// std::vector<std::string> split(const std::string &str, char d)
// {
//     std::vector<std::string> r;

//     std::string::size_type start = 0;
//     std::string::size_type stop = str.find_first_of(d);
//     while(stop != std::string::npos)
//     {
//         r.push_back(str.substr(start, stop - start));

//         start = stop + 1;
//         stop = str.find_first_of(d, start);
//     }

//     r.push_back(str.substr(start));

//     return r;
// }
// TODO filter by first byte and output
// ip = filter(1)

// 1.231.69.33
// 1.87.203.225
// 1.70.44.170
// 1.29.168.152
// 1.1.234.8

// TODO filter by first and second bytes and output
// ip = filter(46, 70)

// 46.70.225.39
// 46.70.147.26
// 46.70.113.73
// 46.70.29.76

// TODO filter by any byte and output
// ip = filter_any(46)

// 186.204.34.46
// 186.46.222.194
// 185.46.87.231
// 185.46.86.132
// 185.46.86.131
// 185.46.86.131
// 185.46.86.22
// 185.46.85.204
// 185.46.85.78
// 68.46.218.208
// 46.251.197.23
// 46.223.254.56
// 46.223.254.56
// 46.182.19.219
// 46.161.63.66
// 46.161.61.51
// 46.161.60.92
// 46.161.60.35
// 46.161.58.202
// 46.161.56.241
// 46.161.56.203
// 46.161.56.174
// 46.161.56.106
// 46.161.56.106
// 46.101.163.119
// 46.101.127.145
// 46.70.225.39
// 46.70.147.26
// 46.70.113.73
// 46.70.29.76
// 46.55.46.98
// 46.49.43.85
// 39.46.86.85
// 5.189.203.46
