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
	ll arr[n][n], pref[n+1][n+1];

	for (ll i=0; i<n; i++) {
		string s; cin >> s;
		for (ll j=0; j< (ll) s.length(); j++) {
			if (s[j] == '*') {
				arr[i][j] = 1;
			} else if (s[j] == '.') {
				arr[i][j] = 0;
			}
		}
	}
	for (ll i=0; i<n+1; i++) {
		pref[0][i]=0, pref[i][0]=0;
	}

	for (ll i=0; i<n; i++) {
		for (ll j=0; j<n; j++) {
			pref[i+1][j+1] = arr[i][j] + pref[i+1][j] + pref[i][j+1] - pref[i][j];
		}
	}

	while (q--) {
		ll y1, y2, x1, x2;
		cin >> x1 >> y1 >> x2 >> y2;
		if (x1 > x2) swap(x1, x2);
		if (y1 > y2) swap(y1, y2);

		cout << pref[x2][y2] - pref[x2][y1-1] - pref[x1-1][y2] + pref[x1-1][y1-1] << "\n";
	}
	return 0;
}