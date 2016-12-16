static const size_t MAX{1'000'000'000};

int solution(vector<int> &A) {
    // write your code in C++14 (g++ 6.2.0)
    size_t passing{}, total{};
    for (auto a:A) {
        if (a == 1) {
            total += passing;
            if (total > MAX)
                return -1;
        } else
            ++ passing;
    }
    return total;
}