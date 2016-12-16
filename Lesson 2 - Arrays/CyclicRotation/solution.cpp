vector<int> solution(vector<int> &A, int K) {
    // write your code in C++14 (g++ 6.2.0)
    if (A.size() < 1)
        return A;
        
    auto R = A.size() - K % A.size();
    
    std::vector<int> result(A.begin() + R, A.end());
    result.insert(result.end(),  A.begin(), A.begin() + R);
    return result;
}