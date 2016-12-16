#include <algorithm>

int solution(vector<int> &A) {
    // write your code in C++14 (g++ 6.2.0)
    std::sort(A.begin(), A.end());
    
    auto N = A.size();
    
    if (A[N-1] < 0)
        return A[N-1] * A[N-2] * A[N-3];
        
    return std::max(A[N - 3] * A[N - 2], A[0] * A[1]) * A[N - 1];
}