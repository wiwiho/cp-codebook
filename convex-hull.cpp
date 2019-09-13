//Andrew's Monotone Chain Algorithm for build a convex hull

#include <bits/stdc++.h>

#define iter(a) a.begin(), a.end()
#define lsort(a) sort(iter(a))
#define mp(a, b) make_pair(a, b)
#define pb(a) push_back(a)
#define F first
#define S second
#define pll pair<ll, ll>

typedef long long ll;

using namespace std;

pll operator-(pll a, pll b){
    return mp(a.F - b.F, a.S - b.S);
}

ll cross(pll a, pll b){
    return a.F * b.S - a.S * b.F;
}

vector<pll> getConvexHull(vector<pll>& pnts){

    int n = pnts.size();
    lsort(pnts);

    vector<pll> hull;
    hull.reserve(n);

    for(int i = 0; i < 2; i++){
        int t = hull.size();
        for(pll pnt : pnts){
            while(hull.size() - t >= 2 && cross(hull.back() - hull[hull.size() - 2], pnt - hull[hull.size() - 2]) <= 0){
                hull.pop_back();
            }
            hull.pb(pnt);
        }
        hull.pop_back();
        reverse(iter(pnts));
    }

    return hull;
}