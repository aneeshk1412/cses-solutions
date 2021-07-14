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
	if (n == 2 || n == 3) {
		cout << "NO SOLUTION\n";
	}
	else {
		for (ll i=2; i<=n; i+=2) {
			cout << i << " ";
		}
		for (ll i=1; i<=n; i+=2) {
			cout << i << " ";
		}
		cout << "\n";
	}
	return 0;
}