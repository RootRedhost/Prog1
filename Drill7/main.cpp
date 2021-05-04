#include <iostream>
#include <stdexcept>
#include <vector>
#include <algorithm>
#include <list>
#include <array>
#include <string>


template<typename C>
void print(const C& c, const std::string& s = "")
{
    std::cout << s << '\t';
    for (auto& a : c)
        std::cout << a << ' ';
    std::cout << '\n';
}

template<typename C>
void novel(C& c, int n = 1)
{
    for (auto& a : c)
        a += n;
}

template<typename Iter1, typename Iter2>   
Iter2 my_copy(Iter1 f1, Iter1 e1, Iter2 f2)
{
    for (Iter1 p = f1; p != e1; ++p)
        *f2++ = *p;
    return f2;
}

int main()
try {
    constexpr int size = 10;

    int arr[size];
    for (int i = 0; i < size; ++i) arr[i] = i;
    print(arr, "built-in []: ");

    std::array<int, size> ai;
    std::copy(arr, arr + size, ai.begin());
    print(ai, "std::array: ");

    std::vector<int> vi(size);
    std::copy(arr, arr + size, vi.begin());
    print(vi, "std::vector: ");

    std::list<int> li(size);
    std::copy(arr, arr + size, li.begin());
    print(li, "std::list: ");

    std::cout << '\n';contents

    std::array<int, size> ai2 = ai;
    std::vector<int> vi2 = vi;
    std::list<int> li2 = li;
    print(ai2, "array copy: ");
    print(vi2, "vector copy: ");
    print(li2, "list copy: ");

    std::cout << '\n';

    novel(ai2, 2);
    novel(vi2, 3);
    novel(li2, 5);
    print(ai2, "array +2: ");
    print(vi2, "vector +3: ");
    print(li2, "list +5: ");

    std::cout << '\n';

    my_copy(ai2.begin(), ai2.end(), vi2.begin());
    my_copy(li2.begin(), li2.end(), ai2.begin());
    print(ai2, "array copied: ");
    print(vi2, "vector copied: ");
    print(li2, "list copied: ");

    std::vector<int>::iterator vit;
    vit = std::find(vi2.begin(), vi2.end(), 3);
    if (vit != vi2.end())
        std::cout << "Found at: " << std::distance(vi2.begin(), vit) << '\n';
    else
        std::cout << "Not found..\n";

    std::list<int>::iterator lit;
    lit = std::find(li2.begin(), li2.end(), 27);
    if (lit != li2.end())
        std::cout << "Found at: " << std::distance(li2.begin(), lit) << '\n';
    else
        std::cout << "Not found..\n";
}
catch(std::exception& e) {
    std::cerr << "Exception: " << e.what() << '\n';
    return 1;
}
catch(...) {
    std::cerr << "Unknown exception\n";
    return 2;
}
