#pragma GCC optimize ("Ofast")
#pragma GCC target ("avx,avx2,fma")
#pragma GCC optimize ("unroll-loops")
 
#include <iostream>
#include <vector>
#include <string>
#include <deque>
#include <algorithm>
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

void bfs(bool vis[], ull par[], int dis[], vector<ull> adj[], ull s) {
    deque<ull> Q;
    vis[s] = true;
    dis[s] = 0;
    par[s] = s;
    Q.push_back(s);
    while (!Q.empty()) {
        auto u = Q.front(); Q.pop_front();
        for (auto v: adj[u]) {
            if (vis[v]) {
                continue;
            }
            vis[v] = true;
            dis[v] = dis[u] + 1;
            par[v] = u;
            Q.push_back(v);
        }
    }
}

int main(int argc, char const *argv[]) {
	/* code */
    IFALSE;
    ull V, E;
    cin >> V >> E;
    bool vis[V];
    int dis[V];
    ull par[V];
    for (auto& a: vis) {
        a = false;
    }
    for (auto& a: dis) {
        a = -1;
    }
    for (auto& a: par) {
        a = 0; 
    }
    vector<ull> adj[V];
    ull x, y;
    for (ull i=0; i<E; i++) {
        cin >> x >> y;
        x--, y--;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    bfs(vis, par, dis, adj, 0);

    vector<ull> res;
    ull s = V-1;
    if (dis[s] == -1) {
        cout << "IMPOSSIBLE\n";
        return 0;
    }
    
    while (par[s] != s) {
        res.push_back(s);
        s = par[s];
    }
    res.push_back(s);

    reverse(begin(res), end(res));
    
    cout << size(res) << '\n';
    for (auto a: res) {
        cout << a+1 << " ";
    }
    cout << "\n";
}