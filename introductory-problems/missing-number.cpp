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
	/* code */
	ll n; cin >> n;
	ll res = n * (n + 1);
	res >>= 1;

	for (int i = 0; i < n-1; ++i)
	{
		ll x; cin >> x;
		res -= x;
	}
	cout << res << "\n";
	return 0;
}