int solution(vector<int> &A) {
    // write your code in C++14 (g++ 6.2.0)
    uint64_t N{A.size()};
    auto expected_sum = (N + 1) * (N + 2) / 2;
    for (auto a:A)
        expected_sum -= a;
    return expected_sum;
}