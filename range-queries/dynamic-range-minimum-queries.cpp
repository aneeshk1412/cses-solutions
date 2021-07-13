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
		arr[i] = min(arr[i<<1], arr[i<<1|1]);
	}
}

void update(ll arr[], ll n, ll i, ll v) {
	for (arr[i+=n]=v; i>1; i>>=1) {
		arr[i>>1] = min(arr[i], arr[i^1]);
	}
}

ll queryopen(ll arr[], ll n, ll l, ll r) {
	ll res = INT64_MAX;
	for (l+=n, r+=n; l<r; l>>=1, r>>=1) {
		if (l&1) res = min(res, arr[l++]);
		if (r&1) res = min(res, arr[--r]);
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
		if (x==1) {
			ll k, u; cin >> k >> u;
			update(arr, n, k-1, u);
		}
		else if (x==2){
			ll s, e; cin >> s >> e; s--;
			cout << queryopen(arr, n, s, e) << "\n";
		}
	}

	return 0;
}