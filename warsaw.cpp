#pragma GCC optimize ("Ofast")

// 17.4.1.2 Headers

// C
#ifndef _GLIBCXX_NO_ASSERT
#include <cassert>
#endif
#include <cctype>
#include <cerrno>
#include <cfloat>
#include <ciso646>
#include <climits>
#include <clocale>
#include <cmath>
#include <csetjmp>
#include <csignal>
#include <cstdarg>
#include <cstddef>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>

#if __cplusplus >= 201103L
#include <ccomplex>
#include <cfenv>
#include <cinttypes>
#include <cstdbool>
#include <cstdint>
#include <ctgmath>
#include <cwchar>
#include <cwctype>
#endif

// C++
#include <algorithm>
#include <bitset>
#include <complex>
#include <deque>
#include <exception>
#include <fstream>
#include <functional>
#include <iomanip>
#include <ios>
#include <iosfwd>
#include <iostream>
#include <istream>
#include <iterator>
#include <limits>
#include <list>
#include <locale>
#include <map>
#include <memory>
#include <new>
#include <numeric>
#include <ostream>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <stdexcept>
#include <streambuf>
#include <string>
#include <typeinfo>
#include <utility>
#include <valarray>
#include <vector>

#if __cplusplus >= 201103L
#include <array>
#include <atomic>
#include <chrono>
#include <condition_variable>
#include <forward_list>
#include <future>
#include <initializer_list>
#include <mutex>
#include <random>
#include <ratio>
#include <regex>
#include <scoped_allocator>
#include <system_error>
#include <thread>
#include <tuple>
#include <typeindex>
#include <type_traits>
#include <unordered_map>
#include <unordered_set>
#endif

using namespace std;

template <class T>
struct rge {
	T b, e;
};

template <class T>
rge<T> range(T i, T j) {
	return rge<T>{i, j};
}

template <class T>
auto dud(T* x) -> decltype(cerr << *x, 0);

template <class T>
char dud(...);

struct debug
{
#ifdef LOCAL
	~debug() {
		cerr << "\n";
	}

	template<std::size_t...> struct seq{};

	template<std::size_t N, std::size_t... Is>
	struct gen_seq : gen_seq<N-1, N-1, Is...>{};

	template<std::size_t... Is>
	struct gen_seq<0, Is...> : seq<Is...>{};

	template<class Tuple, std::size_t... Is>
	void print_tuple(debug& os, Tuple const& t, seq<Is...>)	{
		using swallow = int[];
		(void)swallow{0, (void(os << ", " + 2 * (Is == 0) << get<Is>(t)), 0)...};
	}

	template <class T>
	typename enable_if<sizeof dud<T>(0) != 1, debug&>::type operator<<(T i) {
		cerr << boolalpha << i;
		return *this;
	}

	template <class T>
	typename enable_if<sizeof dud<T>(0) == 1, debug&>::type operator<<(T i) {
		return *this << range(begin(i), end(i));
	}
	
	template <class T, class U> debug& operator<<(pair<U, T> p) {
		return *this << "(" << p.first << ", " << p.second << ")";
	}

	template <class T> debug& operator<<(rge<T> d) {
		*this << "[";
		for(auto it = d.b; it != d.e; it++)
			*this << ", " + 2 * (it == d.b) << *it;
		return *this << "]";
	}

	template <class... Args> debug& operator<<(tuple<Args...> t) {
		*this << "(";
		print_tuple(*this, t, gen_seq<sizeof...(Args)>());
		return *this << ")";
	}
#else
	template <class T> debug& operator<<(const T&) {
		return *this;
	}
#endif
};

#define imie(...) " [" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "] "


// Typedefs
using ll = long long;
using ull = unsigned long long;
using ld = long double;

// Constants
const ll MOD = 1000000007, SZ = 1000005;
const ld PI = 3.141592653589793, EPS = 1e-9;

// Defines
#define IFALSE ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
#define INPUTFILE freopen("input.txt", "r", stdin)
#define OUTPUTFILE freopen("output.txt", "w", stdout)
#define TESTCASE(t) ll t; cin >> t; while(t--)
#define getcurrtime() cerr << "Time = " << ((double)clock()/CLOCKS_PER_SEC) << "\n";

#define fi first
#define se second
#define ln cout << "\n"

#define forn(i, n) for(ll i=0; i<(n); i++)
#define forab(i, a, b) for(ll i=(a); i<=(b); i++)
#define rforn(i, n) for(ll i=(n)-1; i>=0; i--)
#define rforab(i, a, b) for(ll i=(b); i>=(a); i--)

// Number of Set Bits : __builtin_popcount(x) __builtin_popcountl(x) __builtin_popcountll(x)
// Parity of Set Bits : __builtin_parity(x) __builtin_parityl(x) __builtin_parityll(x)
// Leading Zeros : __builtin_clz(x) __builtin_clzl(x) __builtin_clzll(x)
// Trailing Zeros : __builtin_ctz(x) __builtin_ctzl(x) __builtin_ctzll(x)

// gcd(x, y) : gcd of x and y, 0 if both 0

void solve() {
	
}

// Start Here
int main(int argc, char const *argv[]) {
	IFALSE;
	TESTCASE(t)
	{
		solve();
	}
	return 0;
}

// Debug Example, compile with -DLOCAL flag
	// unordered_map<int, int> S;
	// tuple<int, float, string> G = {5, 10.5, "helloworld"};
	// int n = 10;
	// int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	// S[0]=0;
	// S[1]=1;
	// S[2]=4;
	// S[3]=9;
	// S[4]=16;
	// debug() << imie(S) << imie(range(arr, arr+10));
	// debug() << imie(5) "+" imie(PI) "-" imie(n);
	// debug() << imie(G);