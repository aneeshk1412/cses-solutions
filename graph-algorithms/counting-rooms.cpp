#pragma GCC optimize ("Ofast")
#pragma GCC target ("avx,avx2,fma")
#pragma GCC optimize ("unroll-loops")
 
#include <iostream>
#include <vector>
#include <string>
using namespace std;
 
// Typedefs
using ll = long long;
using ull = unsigned long long;
using ld = long double;
 
// Constants
const ll MOD = 1000000007, SZ = 1000005;
const ld PI = 3.141592653589793, EPS = 1e-9;
 
// Defines 
#define IFALSE ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
 
void dfs_visit(intmax_t i, intmax_t j, vector<string>& G, intmax_t n, intmax_t m) {
    if (i >= 0 && i < n && j >= 0 && j < m) {
        if (G[i][j] == '#') {
            return;
        }
        G[i][j] = '#';
        dfs_visit(i+1, j, G, n, m);
        dfs_visit(i-1, j, G, n, m);
        dfs_visit(i, j+1, G, n, m);
        dfs_visit(i, j-1, G, n, m);
    }
}
 
int main(int argc, char const *argv[]) {
	/* code */
    intmax_t n, m;
    cin >> n >> m;
    vector<string> G(n);
    for (auto& s: G) {
        cin >> s;
    }
 
    intmax_t count = 0;
    for (intmax_t i=0; i<n; i++) {
        for (intmax_t j=0; j<m; j++) {
            if (G[i][j] == '#') continue;
            count++;
            dfs_visit(i, j, G, n, m);
        }
    }
    cout << count << "\n";
	return 0;
}