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

void build(ll arr[], ll n) {
	for (ll i=n-1; i>0; i--) {
		arr[i]=0;
	}
}

void updateopen(ll arr[], ll n, ll l, ll r, ll v) {
	for (l+=n, r+=n; l<r; l>>=1, r>>=1) {
		if (l&1) arr[l++] += v;
		if (r&1) arr[--r] += v;
	}
}

ll query(ll arr[], ll n, ll i) {
	ll res=0;
	for (i+=n; i>0; i>>=1) {
		res += arr[i];
	}
	return res;
}

int main(int argc, char const *argv[])
{
	/* code */
	IFALSE;
	ll n, q; cin >> n >> q;
	
	ll arr[2*n];
	for (ll i=0; i<n; i++) {
		cin >> arr[n+i];
	}
	build(arr, n);

	while (q--) {
		ll x; cin >> x;
		if (x == 1) {
			ll s, e, v; cin >> s >> e >> v;
			updateopen(arr, n, s-1, e, v);
		}
		else if (x == 2) {
			ll i; cin >> i;
			cout << query(arr, n, i-1) << "\n";
		}
	}

	return 0;
}