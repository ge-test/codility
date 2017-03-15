int solution(vector<int> &A) {
    // write your code in C++14 (g++ 6.2.0)
    
    ssize_t N = (ssize_t) A.size();
    
    if (N < 2)
        return 0;
        
    int profit{0};
    
    for (int last = N - 1, crt = N - 2; crt >= 0; --crt) {
        auto crt_profit = A[last] - A[crt];
        if (crt_profit > profit) {
            profit = crt_profit;
            continue;
        }
        
        if (crt_profit < 0)
            last = crt;
    }
    return profit > 0 ? profit: 0;
}
