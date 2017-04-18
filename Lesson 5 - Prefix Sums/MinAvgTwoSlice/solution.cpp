#include <vector>
#include <algorithm>

class S {
public:
    size_t start_index;
    size_t elements_count;
    double sum;
    
    S(double ss): start_index(0), elements_count(2), sum(ss){}
    
    double avg() const {
        return sum / elements_count;
    }
    
    void add(int value) {
        sum += value;
        ++ elements_count;
    }
    
    void optimize_head(const std::vector<int> &A) {
        while(elements_count > 2) {
            auto new_count = elements_count - 1;
            auto new_sum = sum - A[start_index];
            auto new_avg = new_sum / new_count;
            if (new_avg < avg()) {
                --elements_count;
                ++ start_index;
                sum = new_sum;
            } else
                break;
        }
    }
    void reset(size_t index, int val) {
        start_index = index;
        elements_count = 2;
        sum = val;
    }
};

int solution(std::vector<int> &A) {
    S best(A[0] + A[1]);
    auto crt = best;
    
    for(auto index = 2u; index < A.size(); ++index) {
        crt.add(A[index]);
        crt.optimize_head(A);
        if (crt.avg() < best.avg())
            best = crt;
        else
            crt.reset(index - 1, A[index] + A[index - 1]);
    }
    
    return  best.start_index;
}

//**********************************************************
//   Testing body
//**********************************************************

//https://codility.com/demo/results/trainingGWTANA-GJR/

#include <cstdlib>
#include <iostream>

#include <numeric>
#include <cmath>
#include <chrono>

typedef std::vector<int> VI;
typedef std::pair<int, size_t> Value;
typedef std::vector<Value> ValueV;

std::ostream & operator << (std::ostream & os, const VI &v) {
    os << "[";
    for (auto it = v.begin(); ;) {
        os << *it;
        ++ it;
        if (it == v.end())
            break;
        os << ", ";
    }
    os << "]";
    return os;
}


std::ostream & operator << (std::ostream & os, const ValueV &v) {
    os << "[";
    for (auto it = v.begin(); ;) {
        os << "(" << it->first <<", " << it->second << ")";
        ++ it;
        if (it == v.end())
            break;
        os << ", ";
    }
    os << "]";
    return os;
}


struct Entry {
    std::vector<int> v1;
    int count;
    Entry(std::initializer_list<int> i1, int c): v1(i1), count(c){}
};

/*
 * 
 */
int main(int argc, char** argv) {
    std::vector<Entry> tests{ 
        { {4,2,2,5,1,5,8}, 1},
        { {2,4,2,6,-6,-10}, 4},
        { {-3, -5, -8, -4, -10}, 2},
    };
    
    for(auto &test : tests) {
        std::cout << "Testing (" << test.v1 << ")" << std::endl;
        
        auto result = solution(test.v1);
        if (result == test.count)
            std::cout << " PASSED" << std::endl;
        else
            std::cout << " FAILED expected=" << test.count <<", got=" << result << std::endl;
    }
    return 0;
}

