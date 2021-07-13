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

/*
	Pretty smart use of segment trees
	Consider [1, n] : if max([1,n/2]) > q recurse in [1,n/2] else in [n/2 + 1, n]
*/


void build(ll arr[], ll n) {
	for (ll i=n-1; i>0; i--) {
		arr[i] = max(arr[i<<1], arr[i<<1|1]);
	}
}

void update(ll arr[], ll n, ll i, ll v) {
	for (arr[i += n]=v; i>1; i>>=1) {
		arr[i>>1] = max(arr[i], arr[i^1]);
	}
}

ll queryclose(ll arr[], ll n, ll l, ll r) {
	ll res = INT64_MIN;
	for (l+=n, r+=n; l<=r; l>>=1, r>>=1) {
		if (l&1) res = max(res, arr[l++]);
		if (!(r&1)) res = max(res, arr[r--]);
	}
	return res;
}

ll findfirst(ll arr[], ll n, ll h) {
	// find first element in original array which is >= h
	// only works when n is power of 2
	ll i=1;
	if (arr[i] < h) {
		return -1;
	}

	while (i < n) {
		if (arr[i<<=1] < h) i|=1;
	}
	return i-n;
}


int main(int argc, char const *argv[])
{
	/* O(log(n)*log(n)) per query solution (uses range queries for binary search)
	IFALSE;
	ll n, m; cin >> n >> m;
	
	ll arr[2*n];
	for (ll i=0; i<n; i++) {
		cin >> arr[i+n];
	}
	build(arr, n);
	
	while (m--) {
		ll h; cin >> h;
		
		if (arr[1] < h) {
			cout << 0 << " ";
			continue;
		}

		ll s=0, e=n-1;
		while (s < e) {
			ll mid=(s+e)/2;
			if (queryclose(arr, n, s, mid) >= h) {
				e=mid;
			}
			else {
				s=mid+1;
			}
		}
		cout << s+1 << " ";
		update(arr, n, s, arr[s+n]-h);
	}
	cout << "\n";
	*/

	/* O(log(2n)) per query solution, traverse segment tree from top down
	   Extra space needed since top down traversal does not work in the compressed 2n space version
	   Requires space O(4n) version
	 */
	IFALSE;
	ll n, m; cin >> n >> m;
	ll np=1;
	while (np<n) np<<=1;
	
	
	ll arr[2*np];
	for (ll i=0; i<n; i++) {
		cin >> arr[i+np];
	}
	for (ll i=n; i<np; i++) {
		arr[i+np]=INT64_MIN;
	}
	build(arr, np);

	while (m--) {
		ll h; cin >> h;
		ll i=findfirst(arr, np, h)+1;
		cout << i << " ";
		if (i) {
			update(arr, np, i-1, arr[np+i-1]-h);
		}
	}
	cout << "\n";


	return 0;
}