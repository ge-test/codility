int gcd(int a, int b) {
    auto m = a % b;
    if ( m == 0)
        return b;
        
    return gcd(b, m);
}

int solution(int N, int M) {
    // write your code in C++14 (g++ 6.2.0)
    return N / gcd(N, M);
}
