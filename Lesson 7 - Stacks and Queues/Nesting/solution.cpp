int solution(string &S) {
    // write your code in C++14 (g++ 6.2.0)
    string prev;
    for(auto s:S) {
        if (s == '(')
            prev += '(';
        else {
            if (prev.empty())
                return 0;
            if (prev.back() != '(')
                return 0;
            prev.pop_back();
        }
    }
    return prev.empty();
}
