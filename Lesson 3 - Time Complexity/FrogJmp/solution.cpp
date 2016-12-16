int solution(int X, int Y, int D) {
    // write your code in C++14 (g++ 6.2.0)
    
    if (X == Y)
        return 0;
    auto diff{Y - X};
    auto jumps{diff / D};
    if (jumps * D != diff)
      ++ jumps;
    return jumps;
}