#pragma GCC optimize ("Ofast")
#pragma GCC target ("avx,avx2,fma")
#pragma GCC optimize ("unroll-loops")

#include <bits/stdc++.h>
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

int main(int argc, char const *argv[])
{
	/* code */
	IFALSE;
	ll n, q; cin >> n >> q;
	
	ll a[n];
	for (ll i=0; i<n; i++) {
		cin >> a[i];
	}

	ll logf[n+1]; // logf[i] = floor(log_2(i)) O(n) data structure
	logf[0]=0, logf[1]=0;
	for (ll i=2; i<n+1; i++) {
		logf[i] = logf[i / 2] + 1;
	}

	ll sparsetab[logf[n] + 1][n]; // O(n log n) data structure
	for (ll i=0; i <= logf[n]; i++) {
		ll curlen = 1 << i;
		for (ll j=0; j+curlen <= n; j++) {
			if (curlen == 1) {
				sparsetab[i][j] = a[j];
			}
			else {
				sparsetab[i][j] = min(sparsetab[i-1][j], sparsetab[i-1][j + (curlen / 2)]);
			}
		}
	}

	while (q--) {
		ll s, e; cin >> s >> e;
		s--, e--;
		ll pow = logf[e - s + 1];
		cout << min(sparsetab[pow][s], sparsetab[pow][e - (1 << pow) + 1]) << "\n";
	}

	return 0;
}