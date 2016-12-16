int solution(vector<int> &A) {
    // write your code in C++14 (g++ 6.2.0)
    auto res{0};
    for(auto a:A)
        res ^= a;
    return res;
}

/*
	Solution 2:
#include <numeric>

int solution(vector<int> &A) {
    // write your code in C++14 (g++ 6.2.0)
    return std::accumulate(A.begin(), A.end(), 0, [](auto a, auto b) { return a^b; });
}
*/