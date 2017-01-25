// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

#include <list>

int solution(vector<int> &H) {
    auto result = 0;
    std::list<int> prev;
    
    for(auto h: H) {
        while (! prev.empty() && prev.back() > h)
          prev.pop_back();

        if (! prev.empty() && prev.back() == h)
            continue;
            
        ++result;
        prev.push_back(h);
    }
    return result;
}

