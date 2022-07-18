#pragma GCC optimize ("Ofast")
#pragma GCC target ("avx,avx2,fma")
#pragma GCC optimize ("unroll-loops")
 
#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
using namespace std;
 
// Typedefs
using ll = intmax_t;
using ull = uintmax_t;
using ld = long double;
 
// Constants
const ll MOD = 1000000007, SZ = 1000005;
const ld PI = 3.141592653589793, EPS = 1e-9;
 
// Defines 
#define IFALSE ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

ull parent(ull par[], ull i) {
    return par[i] = (par[i] == i ? i : parent(par, par[i]));
}

void join(ull par[], ull counts[], unordered_set<ull>& curr_reps, ull i, ull j) {
    auto pi = parent(par, i);
    auto pj = parent(par, j);
    if (pi == pj) {
        return;
    }
    if (counts[pi] < counts[pj]) {
        auto temp = pi;
        pi = pj;
        pj = temp;
    }
    par[pj] = pi;
    counts[pi] += counts[pj];
    curr_reps.erase(pj);
}

int main(int argc, char const *argv[]) {
	/* code */
    IFALSE;
    ull V, E;
    cin >> V >> E;
    ull par[V], counts[V]; unordered_set<ull> curr_reps;
    for (ull i=0; i<V; i++) {
        par[i] = i, counts[i] = 1;
        curr_reps.insert(i);
    }

    for (ull i=0; i<E; i++) {
        ull x, y;
        cin >> x >> y;
        x--, y--;
        join(par, counts, curr_reps, x, y);
    }

    cout << curr_reps.size() - 1 << "\n";
    int last = -1;
    for (int i=0; i<V; i++) {
        if (par[i] == i) {
            if (last != -1) {
                cout << i+1 << " " << last+1 << "\n";
            }
            last = i;
        }
    }
}