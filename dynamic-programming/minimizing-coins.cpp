#pragma GCC optimize ("Ofast")

#include <bits/stdc++.h>
using namespace std;

// Typedefs
using ll = long long;
using ull = unsigned long long;
using ld = long double;

// Constants
const ll MOD = 1000000007, SZ = 1000005;
const ld PI = 3.141592653589793, EPS = 1e-9;

// ll dp[SZ][2];
ll dp[SZ];

int main(int argc, char const *argv[])
{
	/* partially optimized code */
	/* 
	ll n, x; 
	cin >> n >> x;
	vector<ll> C(n, 0);
	
	for (auto& c: C) {
		cin >> c;
	}

	// convert vector to unique elements
	sort(C.begin(), C.end(), greater<ll>());
	auto ip = unique(C.begin(), C.end());
	C.resize(distance(C.begin(), ip));
	n = C.size();

	for (int i=0; i<=x; i++) {
		dp[i][0] = -1;
	}
	
	for (int i=0; i<2; i++) {
		dp[0][i] = 0;
	}

	ll cur = 0;
	for (int j=1; j<=n; j++) {
		ll prev = cur;
		cur = 1 - cur;
		for (int i=1; i<=x; i++) {
			ll t1=-1, t2=-1;
			t1 = dp[i][prev];
			if (i >= C[j-1]) {
				t2 = dp[i-C[j-1]][cur];
			}

			if (t1 == -1 && t2 == -1) {
				dp[i][cur] = -1;
			}
			else if (t2 == -1) {
				dp[i][cur] = t1;
			}
			else if (t1 == -1) {
				dp[i][cur] = t2 + 1;
			}
			else {
				dp[i][cur] = min(t1, t2+1);
			}
		}
	}

	cout << dp[x][cur] << "\n";
	*/

	/* optimized code */
	ll n, x; cin >> n >> x;
	vector<ll> coins;
	for (ll i=0; i<n; i++) {
		ll c; cin >> c;
		if (c <= x) {
			coins.push_back(c);
		}
	}

	// convert to unique coins since all coins infinitely available
	sort(coins.begin(), coins.end(), greater<ll>());
	auto ip = unique(coins.begin(), coins.end());
	coins.resize(distance(coins.begin(), ip));
	n = coins.size();

	for (ll i=0; i<=x; i++) {
		dp[i] = MOD; // inf
	}

	dp[0] = 0;

	for (ll j=0; j<n; j++) {
		for (ll i=0; i<=x; i++) {
			if (i >= coins[j]) {
				dp[i] = min(dp[i], dp[i - coins[j]] + 1);
				// DP[i][j] = min(DP[i][j-1], DP[i-coins[j]][j] + 1)
				// can be done by 2 state DP (pre and cur)
				// DP[i][cur] = min(DP[i][pre], DP[i-coins[cur]][cur] + 1)
				// can be further done in 1 array, since DP[i] is DP[i][pre] before changing
				// and DP[i-coins[cur]][cur] is already computed at DP[i - coins[cur]], since (i - coins[cur] < i)
			}
		}
	}

	if (dp[x] == MOD) {
		cout << "-1";
	}
	else {
		cout << dp[x];
	}
	cout << "\n";

	return 0;
}