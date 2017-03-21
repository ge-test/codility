#include <cmath>
int solution(int N) {
    // write your code in C++14 (g++ 6.2.0)
    int sn = sqrt(N) + 1;
    auto right = N;
    for (auto left= 1 ; left < sn; ++left) {
        if (N % left == 0)
            right = N / left;
    }
    
    return 2 * (N /right + right);
}

