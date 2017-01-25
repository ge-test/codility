#include <list>

int solution(vector<int> &A, vector<int> &B) {
    // write your code in C++14 (g++ 6.2.0)
    std::list<int> prev;
    auto extra{0};
    for (auto i = 0u; i < A.size(); ++i) {
        auto a{A[i]};
        
        if (B[i]) {
            prev.push_back(a);
            continue;
        }
        
        while(!prev.empty() && prev.back() < a)
            prev.pop_back();
        if (prev.empty())
            ++ extra;
    }
    return prev.size() + extra;
}
