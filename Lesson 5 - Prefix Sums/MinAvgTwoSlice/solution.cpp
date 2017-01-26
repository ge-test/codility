#include <limits>

int solution(vector<int> &A) {
    // write your code in C++14 (g++ 6.2.0)
    auto min = double(std::numeric_limits<int64_t>::max());
    auto min_pos = 0;
    
    for(auto it = 0u; it < A.size() - 1; ++ it) {
        int64_t s = A[it];
        for(auto ni = it + 1; ni < A.size(); ++ni) {
            s += A[ni];
            auto avg = s / (ni - it + 1.0);
            if (avg < min) {
                min = avg;
                min_pos = it;
            }
        }
    }
    return min_pos;
}

