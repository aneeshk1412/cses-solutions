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
		arr[i] = arr[i<<1] + arr[i<<1|1];
	}
}

void update(ll arr[], ll n, ll i, ll v) {
	for (arr[i += n]=v; i>1; i>>=1) {
		arr[i>>1] = arr[i] + arr[i^1];
	}
}

ll findidx(ll arr[], ll n, ll i) {
	// only when n is power of 2, and array is of 0s and 1s
	// i is 1-indexed, returned is 0-indexed
	ll p=1;
	if (arr[p]<i) {
		return -1;
	}

	while (p < n) {
		if (arr[p<<=1] < i) {
			i-=arr[p]; p|=1;
		}
	}
	return p-n;
}

int main(int argc, char const *argv[]) {
	/* code */
	IFALSE;
	ll n; cin >> n;
	ll arr[n], pos[n];
	for (ll i=0; i<n; i++) {
		cin >> arr[i];
	}
	for (ll i=0; i<n; i++) {
		cin >> pos[i];
	}

	ll np=1;
	while (np<n) np<<=1;

	ll seg[2*np];
	for (ll i=0; i<n; i++) {
		seg[i+np]=1;
	}
	for (ll i=n; i<np; i++) {
		seg[i+np]=0;
	}
	build(seg, np);

	for (ll i=0; i<n; i++) {
		ll idx = findidx(seg, np, pos[i]);
		cout << arr[idx] << " ";
		update(seg, np, idx, 0);
	}
	cout << "\n";

	return 0;
}