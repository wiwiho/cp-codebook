//Kruskal algorithm for minimum spanning tree

#include <bits/stdc++.h>

#define iter(a) a.begin(), a.end()
#define lsort(a) sort(iter(a))
#define F first
#define S second
#define pii pair<int, int>
#define piii pair<int, pii>

using namespace std;

vector<int> p;
int n;

vector<piii> e;

void initDSU(){
    p.resize(n);
    for(int i = 0; i < n; i++) p[i] = i;
}

int findDSU(int x){
    if(p[x] == x) return x;
    p[x] = findDSU(p[x]);
    return p[x];
}

void unionDSU(int a, int b){
    int pa = findDSU(a), pb = findDSU(b);
    p[pa] = pb;
}

int kruskal(){
    int ans = 0;
    lsort(e);
    initDSU();
    for(auto& i : e){
        int a = i.S.F, b = i.S.S;
        if(findDSU(a) == findDSU(b)) continue;
        ans += i.F;
        unionDSU(a, b);
    }
    return ans;
}