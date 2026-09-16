#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
mt19937 rd(chrono::steady_clock::now().time_since_epoch().count());
long long rand(long long l, long long r) {
	return uniform_int_distribution<long long>(l, r)(rd);
}

signed main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);
	#ifdef LOCAL
		// freopen("TEST.inp", "r", stdin);
		// freopen("TEST.out", "w", stdout);
	#endif
	
	return 0;
}
