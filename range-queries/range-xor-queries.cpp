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
	ll arr[n], pref[n+1];
	pref[0]=0;

	for (ll i=0; i<n; i++) {
		cin >> arr[i];
		pref[i+1]=pref[i]^arr[i];
	}

	while (q--) {
		ll s, e; cin >> s >> e;
		cout << (pref[e] ^ pref[s-1]) << "\n";
	}
	return 0;
}