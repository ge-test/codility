int solution(int X, vector<int> &A) {
    // write your code in C++14 (g++ 6.2.0)
    auto jumps{X};
    std::vector<bool> leafs(X);
    for (auto i = 0u; i < A.size(); ++i) {
        auto a{A[i] - 1};
        if (a > X)
            continue;
        if (leafs[a])
            continue;
        leafs[a] = true;
        --jumps;
        if (jumps == 0)
            return i;
    }
    return -1;
}