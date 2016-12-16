enum class eValues {
    A = 1,
    C = 2,
    G = 3,
    T = 4
};

static const int INF{100'000'1};

struct Distance{
    int A, G, C, T;
    Distance(): A(INF), G(INF), C(INF), T(INF) {}
    
    void inc() {
        ++A;
        ++G;
        ++C;
        ++T;
    }
    
    void set(const char a) {
        switch(a) {
            case 'A': A = 0; break;
            case 'G': G = 0; break;
            case 'C': C = 0; break;
            case 'T': T = 0; break;
            default:
                throw std::runtime_error("unexpected character");
        }
    }
    eValues get(int begin, int end) {
        auto diff = end - begin;
        
        if (this->A <= diff)
            return eValues::A;
        if (this->C <= diff)
            return eValues::C;
        if (this->G <= diff)
            return eValues::G;
            
        return eValues::T;
    }
};

vector<int> solution(string &S, vector<int> &P, vector<int> &Q) {
    // write your code in C++14 (g++ 6.2.0)
    vector<Distance> distances(S.length());
    
    Distance distance;
    auto d_it=distances.rbegin();
    
    for(auto it = S.rbegin(); it != S.rend(); ++it, ++ d_it) {
        distance.inc();
        distance.set(*it);
        *d_it = distance;
    }
 
    vector<int> result(P.size());
    for (auto it = 0u; it < P.size(); ++it) {
        result[it] = (int)distances[P[it]].get(P[it], Q[it]);       
    }
    return result;
}