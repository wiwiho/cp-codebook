//Disjoint Set Union

#include <bits/stdc++.h>

using namespace std;

vector<int> p;
int n;

void initDSU(){
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