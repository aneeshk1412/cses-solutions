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

ll dp[SZ];

int main(int argc, char const *argv[])
{
	ios::sync_with_stdio(0);

	/* code */
	ll n, x; cin >> n >> x;
	ll coins[n];
	for (ll i=0; i<n; i++) {
		cin >> coins[i];
	}

	for (ll i=1; i<=x; i++) {
		dp[i]=0;
	}
	dp[0]=1;

	for (ll i=1; i<=x; i++) {
		for (ll j=0; j<n; j++) {
			if (i >= coins[j]) {
				dp[i] = (dp[i] + dp[i-coins[j]]) % MOD;
			}
		}
	}
	cout << dp[x] << "\n";
	
	return 0;
}