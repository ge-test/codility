/*See https://en.wikipedia.org/wiki/Maximum_subarray_problem
Kadane's algorithm begins with a simple inductive question: if we know the maximum subarray sum ending at position {\displaystyle i} i, what is the maximum subarray sum ending at position {\displaystyle i+1} i+1? The answer turns out to be relatively straightforward: either the maximum subarray sum ending at position {\displaystyle i+1} i+1 includes the maximum subarray sum ending at position {\displaystyle i} i as a prefix, or it doesn't. Thus, we can compute the maximum subarray sum ending at position {\displaystyle i} i for all positions {\displaystyle i} i by iterating once over the array. As we go, we simply keep track of the maximum sum we've ever seen. Thus, the problem can be solved with the following code, expressed here in Python:

def max_subarray(A):
    max_ending_here = max_so_far = A[0]
    for x in A[1:]:
        max_ending_here = max(x, max_ending_here + x)
        max_so_far = max(max_so_far, max_ending_here)
    return max_so_far
*/
int solution(std::vector<int> &A) {
    
    std::vector<int> left(A.size()), right(A.size());
    
    for(auto it = 1u; it < A.size() - 1; ++ it)
        left[it] = std::max(left[it -1] + A[it], A[it]);
    
    for(int it = A.size() - 2; it > 0; -- it)
        right[it] = std::max(right[it + 1] + A[it], A[it]);
    
    auto max{0};
    
    for(auto it = 1u; it < A.size() - 1; ++it)
        max = std::max(
                std::max(left[it - 1], 0) + std::max(right[it + 1], 0),
                max);
    
    return max;
}

