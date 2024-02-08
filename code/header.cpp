#include <bits/stdc++.h>

using namespace std;

#define StarBurstStream ios_base::sync_with_stdio(false); cin.tie(0);
#define iter(a) a.begin(), a.end()
#define pb emplace_back
#define mp make_pair
#define ff first
#define ss second
#define topos(a) ((a) = (((a) % MOD + MOD) % MOD))
#define uni(a) a.resize(unique(iter(a)) - a.begin())
#define SZ(a) int(a.size())
#ifdef LOCAL
void debug(){cerr << "\n";}
template<class T, class ... U> void debug(T a, U ... b){cerr << a << " ", debug(b...);}
template<class T> void pary(T l, T r) {
	while (l != r) cerr << *l << " ", l++;
	cerr << "\n";
}
#else
#define debug(...) void()
#define pary(...) void()
#endif

typedef long long ll;
typedef long double ld;

using pii = pair<int, int>;
using pll = pair<ll, ll>;

const ll MOD = 1000000007;
const ll MAX = 2147483647;

template<typename A, typename B>
ostream& operator<<(ostream& o, pair<A, B> p){
    return o << '(' << p.ff << ',' << p.ss << ')';
}

ll ifloor(ll a, ll b){
    if(b < 0) a *= -1, b *= -1;
    if(a < 0) return (a - b + 1) / b;
    else return a / b;
}

ll iceil(ll a, ll b){
    if(b < 0) a *= -1, b *= -1;
    if(a > 0) return (a + b - 1) / b;
    else return a / b;
}

int main(){
    StarBurstStream;

    return 0;
}
