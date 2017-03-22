
#include <map>
#include <list>
#include <algorithm>

typedef pair<int, size_t> Elem;
typedef list<Elem> Stack;

/*
 * Extract the numbers ordered by their appearance count.
 * I.E:
 *    input = [4,3,4,4,4,2]
 *    output = [(4,4), (3,1), (2,1)]
 */
Stack extract_numbers(vector<int> &A) {
    map<int, size_t> m;
    for(auto a:A)
        m[a] ++;
    
    //Need a temporary vector as sort only works on collections with random iterator
    vector<Elem> tmp(m.size());
    copy(m.begin(), m.end(), tmp.begin());
    
    sort(tmp.begin(), tmp.end(), [](const auto &a, const auto &b){
        //if two numbers have the same amount of occurencesm sort by their value
        return a.second == b.second ? a.first < b.first : a.second > b.second; 
    });
    
    Stack result(tmp.size());
    copy(tmp.begin(), tmp.end(), result.begin());
    
    return result;
}

/*
 * Convenience find function
 */
Stack::iterator __find(Stack &stack, int val) {
    for(auto it = stack.begin(); it != stack.end(); ++it)
        if (it->first == val)
            return it;
    return stack.end();
}



/*
 * Decrement the number of occurrences of the specified value.
 * It is assumed that the value is present in the list.
 * If the value reaches zero occurrences the it'll be removed from the list completely.
 * Otherwise, the value will bubble up.  
 */
bool dec(Stack &stack, int val) {
   auto it = __find(stack, val);
   -- it->second;
   
   if (it->second == 0) {
       stack.erase(it);
       return false;
   }
   
   auto next = it;
   ++ next;
   
   if (it->second < next->second) {
       stack.erase(it);
       while(next->second > it->second && next != stack.end())
          ++ next;
       
       stack.insert(next, *it);
   }
   return true;
}

void rem(Stack &stack, int val) {
   auto it = __find(stack, val);
   if (it != stack.end()) {
       stack.erase(it);
   }    
}

/*
 * Increment the number of occurrences of the specified value.
 * If the value is not found in the collection, then it will be added to the end of the list with the number of occurrences set to 1.
 * If the value is found, then the list will be reordered so that it maintains its property.
 */
void inc(Stack &stack, int val) {
   auto it = __find(stack, val);
   if (it == stack.end()) {
       stack.push_back(std::make_pair(val, 1));
       return;
   }
   
   ++ it->second;
   
   if (it == stack.begin())
       return;
   
   auto next = it;
   -- next;
   
   if (it->second > next->second) {
       stack.erase(it);
       while(next->second > it->second && next != stack.begin())
          -- next;
       
       stack.insert(next, *it);
   }
}

int solution(vector<int> &A) {
    // write your code in C++14 (g++ 6.2.0)
    auto N = A.size();
    auto right = extract_numbers(A);
    Stack left;
    auto count = 0;
    
    for(auto it = 1u; it <= N; ++it) {
        auto val = A[it - 1];
        
        if (dec(right, val))
            inc(left, val); //Increment, as the value is still present on the right side
        else if (!left.empty())
            rem(left, val); // Remove the value from the lest side because it was removed from the right
        else
            continue;
        
 
        
        if (left.empty() || right.empty())
            continue;
        
        auto max_left = left.front();
        auto max_right = right.front();
        
        if (max_left.first == max_right.first 
            && max_left.second > it / 2
            && max_right.second > (N - it) / 2 ) {
                ++ count;
            }
    }
        
    return count;
}

