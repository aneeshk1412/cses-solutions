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

// ll dp[SZ];

// ll max_digit(ll x) {
// 	ll m=0;
// 	while(x) {
// 		m = max(m, x % 10);
// 		x /= 10;
// 	}
// 	return m;
// }

// int main(int argc, char const *argv[])
// {
// 	ll n; cin >> n;
// 	fill(dp, dp+n+1, 0);
	
// 	for (ll i=1; i<=n; i++) {
// 		dp[i] = dp[i - max_digit(i)] + 1;
// 	}
// 	cout << dp[n] << '\n';

// 	return 0;
// }

// Notice, DP is prettymuch unrequired here, no repeating subproblems / multiple queries
// so use direct recursion (this is tail recursive so can make it iterative)

ll recursive(ll x) {
	if (x == 0) {
		return 0;
	}
	if (x < 10) {
		return 1;
	}
	ll m=0, temp=x;
	while (temp) {
		m = max(m, temp % 10);
		temp /= 10;
	}
	return recursive(x - m) + 1;
}


ll iterative(ll x) {
	ll res = 0;
	while (x) {
		ll m=0, temp=x;
		while (temp) {
			m = max(m, temp % 10);
			temp /= 10;
		}
		x -= m;
		res++;
	}
	return res;
}


int main(int argc, char const *argv[])
{
	/* code */
	ll n; cin >> n;
	cout << iterative(n) << "\n";
	return 0;
}
