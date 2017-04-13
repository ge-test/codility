#include <algorithm>
#include <vector>
#include <cmath>
std::vector<int> PRIMES;

void fill_primes(size_t N) {
    PRIMES.clear();
    std::vector<bool> sieve(N);
    for (auto i = 2u; i <= N; ++i) {
        if (sieve[i])
            continue;
        PRIMES.push_back(i);
        for(auto j = i; j < N; j += i)
            sieve[j] = true;
    }
}


int count(int &a, int &b, const std::vector<int> &primes = PRIMES) {
    
    for (auto prim_it = primes.begin(); prim_it != primes.end(); ++prim_it) {
        auto v{*prim_it};
        auto max{std::max(a, b)};
        if (v > max)
            break;
        
        if (a % v == 0) {
            if (b % v != 0)
                return 0;
            while (a % v == 0)
                a /= v;
            while (b % v == 0)
                b /= v;
        }
        
        if (b % v == 0) {
            if (a % v != 0)
                return 0;
            while (a % v == 0)
                a /= v;
            while (b % v == 0)
                b /= v;
        }
    }
    
    return 1;
}

int gcd(int a, int b) {
    for(;;) {
        auto m = a % b;
        if ( m == 0)
            break;
        a = b;
        b = m;
    }
    return b;
}

int max_gcd(std::vector<int> &A, std::vector<int> &B) {
    auto res = 1;
    for (auto it_a{A.begin()}, it_b{B.begin()}; it_a != A.end(); ++it_a, ++it_b) {
        auto g = gcd(*it_a, *it_b);
        
        auto max = std::max(*it_a / g , *it_b / g);
        if (max > res)
            res = max;
    }
    return res;
}

void reduce_primes(int &v) {
    for(auto prim: PRIMES) {
        if (v % prim == 0) {
            while(v % prim == 0)
                v /= prim;
            v *= prim;;
        }
    }
}

int solution(std::vector<int> &A, std::vector<int> &B) {
    //Reducing first common divisors
    fill_primes(100);
    for (auto it = 0u; it < A.size(); ++it) {
        reduce_primes(A[it]);
        reduce_primes(B[it]);
    }
    
    //Attempt to reduce the ma expected prime furthermore by dividing with gcd
    fill_primes(max_gcd(A, B));
    
    int result = 0;

    for (auto it = 0u; it < A.size(); ++it)
        result += count(A[it], B[it]);

    return result;
}
