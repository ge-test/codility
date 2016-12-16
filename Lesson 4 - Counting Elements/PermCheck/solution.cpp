int solution(vector<int> &A) {
    // write your code in C++14 (g++ 6.2.0)
    const auto N{A.size()};
    std::vector<bool> present(N);
    for (const auto a:A) {
        if (a > (int)N)
            return false;
        if (present[a -1])
            return false;
        present[a - 1] = true;
    }
    return true;
}