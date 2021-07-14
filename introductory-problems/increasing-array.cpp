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

int main(int argc, char const *argv[]) {
	/* code */
	IFALSE;
	ll n; cin >> n;
	
	/*
	ll arr[n];
	for (ll i=0; i<n; i++) {
		cin >> arr[i];
	}

	ll moves=0;
	for (ll i=1; i<n; i++) {
		moves += (arr[i]<arr[i-1]) * (arr[i-1]-arr[i]);
		arr[i] += (arr[i]<arr[i-1]) * (arr[i-1]-arr[i]);
	}
	cout << moves << "\n";
	*/

	ll xprev; cin >> xprev;
	ll moves=0;
	for (ll i=1; i<n; i++) {
		ll xnext; cin >> xnext;
		if (xnext < xprev) {
			moves += (xprev - xnext);
		}
		else {
			xprev = xnext;
		}
	}
	cout << moves << "\n";

	return 0;
}