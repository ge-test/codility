#include <set> //Yes, this is cheating, complexity will ne O(n * logn)
int solution(vector<int> &A) {
    // write your code in C++14 (g++ 6.2.0)
    set<int> numbers;
    for(auto a:A)
        if (a > 0)
          numbers.insert(a);

    auto prev = 0;
    for (auto a: numbers) {
        if (a - prev > 1)
            break;
        prev = a;
    }
    return prev + 1;
}