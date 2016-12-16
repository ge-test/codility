#include <set>

int solution(vector<int> &A) {
    // write your code in C++14 (g++ 6.2.0)
    set<int> numbers;
    for(auto a:A)
        numbers.insert(a);
    return numbers.size();
}