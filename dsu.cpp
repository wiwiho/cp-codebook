//Disjoint Set Union

#include <bits/stdc++.h>

using namespace std;

vector<int> dsu, rk;

void initDSU(int n){
    dsu.resize(n);
    rk.resize(n);
    for(int i = 0; i < n; i++) dsu[i] = i, rk[i] = 1;
}

int findDSU(int x){
    if(dsu[x] == x) return x;
    dsu[x] = findDSU(dsu[x]);
    return dsu[x];
}

void unionDSU(int a, int b){
    int pa = findDSU(a), pb = findDSU(b);
    if(rk[pa] > rk[pb]) swap(pa, pb);
    if(rk[pa] == rk[pb]) rk[pb]++;
    dsu[pa] = pb;
}