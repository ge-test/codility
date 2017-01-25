#include <unordered_map>
struct C {
    int pos;
    uint32_t count;
    C(): pos(-1), count(0){}
    
};

int solution(vector<int> &A) {
    // write your code in C++14 (g++ 6.2.0)
    unordered_map<int, C> numbers;
    auto N{A.size() / 2};
    for(auto i = 0u; i < A.size(); ++i) {
        auto & v = numbers[A[i]];
        v.count ++;
        if (v.count > N)
            return i;
    }
    return -1;
       
}

