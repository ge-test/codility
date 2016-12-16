vector<int> solution(int N, vector<int> &A) {
    // write your code in C++14 (g++ 6.2.0)
    vector<int> result(N);
    
    int64_t lastMax{}, max{};
    for (auto a:A) {
        if (a <= N ) {
            auto & crt = result[a - 1];
            if ( crt < lastMax)
                crt = lastMax;
            ++ crt;
            if (crt > max)
                max = crt;
        } else {
            lastMax = max;
        }
    }
    for (auto it = result.begin(); it != result.end(); ++it)
      if (*it < lastMax)
        *it = lastMax;
        
    return result;
}