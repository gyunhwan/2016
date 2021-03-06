#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <utility>
#include <map>
#include <string>

// C++17 fold expression
// now supported in Visual Studio 2017
// 20181121_jintaeks
//
template<typename... Ns>
auto sum(Ns... ns)
{
    return (ns + ... + 0);
}

// before C++17
//
//auto sum()
//{
//    return 0;
//}
//
//template<typename N>
//auto sum(N n)
//{
//    return n;
//}
//
//template<typename N0, typename... Ns>
//auto sum(N0 n0, Ns... ns)
//{
//    return n0 + sum(ns...);
//}

int main()
{
    auto s = sum(1, 2.1f, 3.2);
    std::cout << s << std::endl;
}
