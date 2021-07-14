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
	string s; cin >> s;
	ll res=0, cnt=0; char c='.';
	for (ll i=0; i < (ll)s.length(); i++) {
		if (c == s[i]) {
			cnt++;
		}
		else {
			res = max(res, cnt);
			cnt=1;
			c=s[i];
		}
	}
	res = max(res, cnt);
	cout << res << "\n";
	return 0;
}