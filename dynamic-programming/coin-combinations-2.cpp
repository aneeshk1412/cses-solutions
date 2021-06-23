#pragma GCC optimize ("Ofast")
#pragma GCC target ("avx,avx2,fma")

#include <bits/stdc++.h>
using namespace std;

// Typedefs
using ll = long long;
using ull = unsigned long long;
using ld = long double;

// Constants
const ll MOD = 1000000007, SZ = 1000005;
const ld PI = 3.141592653589793, EPS = 1e-9;

array<ll, SZ> dp;

int main(int argc, char const *argv[])
{
	/* code */
	ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
	ll n, x; cin >> n >> x;
	vector<ll> coins(n, 0);
	for (ll i=0; i<n; i++) {
		cin >> coins[i];
	}
	sort(coins.begin(), coins.end());

	// for (ll i=0; i<=x; i++) {
	// 	dp[i]=0;
	// }
	dp[0]=1;

	// Partial Optimized Code
	// for (ll j=0; j<n; j++) {
	// 	for (ll i=1; i<=x; i++) {
	// 		if (i >= coins[j]) {
	// 			dp[i] += dp[i - coins[j]];
	// 			dp[i] %= MOD;
	// 		}
	// 	}
	// }
	
	// Completely Optimized Code
	for (ll j=0; j<n; j++) {
		if (coins[j] == 1) { // Case of 1 handled quickly
			fill(dp.begin(), dp.begin()+x+1, 1);
		}
		else {
			// branch for coins[j] removed
			for (ll i=coins[j]; i<=x; i++) {
				dp[i] += dp[i - coins[j]];
				dp[i] %= MOD;
			}
		}
	}
	cout << dp[x] << "\n";

	return 0;
}