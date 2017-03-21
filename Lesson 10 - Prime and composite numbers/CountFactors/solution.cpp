#include <cmath>

int solution(int N) {
    // write your code in C++14 (g++ 6.2.0)
    int count = 0;
    auto left = 1;
    auto sn = (int)std::sqrt(N) + 1;
    
    for(; left < sn; ++ left) {
        if( N % left == 0) {
            auto r = N / left;
            if (r < left)
                break;
            count += r == left ? 1 : 2;
        }
        
    }
    return count;
}
