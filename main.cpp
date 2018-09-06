
#include <iostream>
#include <algorithm>
#include <chrono>
#include <vector>
#include "wc.h"

auto main() -> int
{
    std::chrono::steady_clock::time_point start, end;
    std::chrono::duration<double, std::milli> elapsed;
    std::vector<int> arr, arr2;
    for (int i = 0; i < 1000000; ++i) arr.push_back(i);

    start = std::chrono::high_resolution_clock::now();
    random_shuffle(arr.begin(), arr.end());
    end = std::chrono::high_resolution_clock::now();
    elapsed = end - start;
    std::cout << "shuffle time = " << elapsed.count() << "milliseconds" << std::endl;
    std::cout << arr[3] << std::endl;
    std::cout << arr[0] << std::endl;

    std::cout << "############  wc  #############" << std::endl;
    start = std::chrono::high_resolution_clock::now();
    wc::sort(arr.begin(), arr.end());
    std::cout << arr[3] << std::endl;
    std::cout << arr[0] << std::endl;
    end = std::chrono::high_resolution_clock::now();
    elapsed = end - start;
    std::cout << "sort time = " << elapsed.count() << "milliseconds" << std::endl;


    arr2 = arr;
    std::cout << "############  stl  #############" << std::endl;
    start = std::chrono::high_resolution_clock::now();
    std::sort(arr2.begin(), arr2.end());
    std::cout << arr2[3] << std::endl;
    std::cout << arr2[0] << std::endl;
    end = std::chrono::high_resolution_clock::now();
    elapsed = end - start;
    std::cout << "sort time = " << elapsed.count() << "milliseconds" << std::endl;

    getchar();
    return 0;
}