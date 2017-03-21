#include <algorithm>
#include <set>

static vector<int> s_primes_prods;

void populate_prime_prods(size_t N) {
    //Compute all the primes using Eratostene's sieve
    
    vector<bool> sieve(N);
    vector<int> primes;
    for (auto i = 2u; i < N; ++i) {
        if (sieve[i])
            continue;
        primes.push_back(i);
        for(auto j = i; j < N; j += i)
            sieve[j] = true;
    }

    //Now compute all prime products. Store them in a set so that they are sorted
    set<int> products;
    for(auto i = 0u; i < primes.size(); ++i)
        for(auto j = i; j < primes.size(); ++j) {
            size_t prod = primes[i] * primes[j];
            if (prod > N)
                break;
            products.insert(prod);
        }
    
    s_primes_prods.resize(products.size());
    std::copy(products.begin(), products.end(), s_primes_prods.begin());
}

vector<int> solution(int N, vector<int> &P, vector<int> &Q) {
    // write your code in C++14 (g++ 6.2.0)
    populate_prime_prods(N);
    vector<int> solution;
    
    for (auto i = 0u; i < P.size(); ++i) {
        auto start{std::lower_bound(s_primes_prods.begin(), s_primes_prods.end(), P[i])};
        auto end{std::upper_bound(s_primes_prods.begin(), s_primes_prods.end(), Q[i])};
        
        solution.push_back( end - start);
    }
    return solution;
}
