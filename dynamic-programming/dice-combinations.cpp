#pragma GCC optimize ("-O3")

#include <bits/stdc++.h>
using namespace std;

// Typedefs
using ll = long long;
using ull = unsigned long long;
using ld = long double;

// Constants
const ll MOD = 1000000007;
const ld PI = 3.141592653589793;
const ld EPS = 1e-9;

int main(int argc, char const *argv[])
{
	/* code simple */
	// ll n; cin >> n;
	// ll dp[n+1];
	// dp[0] = 1;

	// for (ll i=1; i<=n; i++) {
	// 	dp[i] = 0;
	// 	for (ll j=1; j<=6; j++) {
	// 		if (i-j >= 0) {
	// 			dp[i] += dp[i-j];
	// 			dp[i] %= MOD;
	// 		}
	// 	}
	// }

	// cout << dp[n] << "\n";
	// return 0;

	/* code space optimized */
	ll n; cin >> n;
	deque<ll> dp;
	dp.push_back(1); // dp[0];

	for (ll i=1; i<=n; i++) {
		ll dp_i = 0;
		for (auto a: dp) {
			dp_i += a;
			dp_i %= MOD;
		}
		dp.push_back(dp_i);
		while (dp.size() > 6) {
			dp.pop_front();
		}
	}

	cout << dp.back() << "\n";
	return 0;
}