#include <algorithm>
vector<int> solution(vector<int> &A) {
    const auto N{A.size()};
    const auto max = *std::max_element(A.begin(), A.end());
    std::vector<int> sieve(max + 1);
    
    for(auto a:A)
        ++ sieve[a];
    
    std::vector<int> counts(sieve);
    
    for (auto it = sieve.begin() + 1; it != sieve.end() - 1; ++ it) {
        if (*it == 0)
            continue;
        auto val = it - sieve.begin();
        auto count = counts[val];
        
        for(auto next = 2 * val; next <= max; next += val)
            if (sieve[next])
                sieve[next] += count;
    }

    std::vector<int> result(N);
    for(auto i = 0u; i < N; ++i)
        result[i] = N - sieve[A[i]];
    return result;
}
