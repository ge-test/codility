#include <numeric>

int solution(vector<int> &A) {
    // write your code in C++14 (g++ 6.2.0)
    auto left{ static_cast<int64_t>(A[0])};
    auto right{std::accumulate(A.begin() +1, A.end(), static_cast<int64_t>(0))};
    auto min = std::abs(left - right);
    for(auto i=1u; i < A.size() - 1; ++i) {
        left += A[i];
        right -= A[i];
        auto new_min = std::abs(left - right);
        if (new_min < min)
            min = new_min;
    }
    
    return min;
}