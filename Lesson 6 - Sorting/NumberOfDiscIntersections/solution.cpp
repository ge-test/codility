#include <algorithm>

#define MAX 10'000'000

struct Circle {
    int64_t left, right;
    void set(int64_t center, int radius) {
        left = (center - radius);
        right = (center + radius);
    }
            
};

vector<Circle> transform(vector<int> &A) {
    auto N = A.size();
    vector<Circle> v(N);
    
    for(auto i = 0u; i < N; ++i)
      v[i].set(i, A[i]);
     
    std::sort(v.begin(), v.end(), [](auto a, auto b) { return a.left < b.left; });
    return v;
}

int solution(vector<int> &A) {
    // write your code in C++14 (g++ 6.2.0)
    vector<Circle> v(transform(A));
    
    auto count = 0; 
    for(auto i = 0u; i < v.size(); ++i) {
        for (auto j = i + 1; j < v.size(); ++j) {
            if (v[j].left > v[i].right)
              break;
            ++ count;
            if (count > MAX)
                return -1;
        }
    }
    return count;
}
