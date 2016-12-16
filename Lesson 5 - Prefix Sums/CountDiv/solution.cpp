int solution(int A, int B, int K) {
    // write your code in C++14 (g++ 6.2.0)
     auto rem = A % K == 0;
    if (A == B)
        return rem;
    
    A /= K;
    B /= K;
    
    if (A == B)
        return rem;
    
    return B - A + rem ;
}