/*
   https://en.wikipedia.org/wiki/Maximum_subarray_problem

def max_subarray(A):
    max_ending_here = max_so_far = A[0]
    for x in A[1:]:
        max_ending_here = max(x, max_ending_here + x)
        max_so_far = max(max_so_far, max_ending_here)
    return max_so_far
*/
int solution(vector<int> &A) {
    // write your code in C++14 (g++ 6.2.0)
    auto max{A[0]}, crt{A[0]};
    for(auto it = 1u; it < A.size(); ++it) {
        crt = std::max(crt + A[it], A[it]);
        max = std::max(crt, max);
    }
    return max;
}
