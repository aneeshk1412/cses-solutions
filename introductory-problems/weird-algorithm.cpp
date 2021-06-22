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
	ll n; cin >> n;
	cout << n << " ";
	while (n != 1) {
		if (n & 1) {
			n = 3 * n + 1;
			cout << n << " ";
		}
		else {
			n >>= 1;
			cout << n << " ";
		}
	}
	cout << "\n";
	return 0;
}