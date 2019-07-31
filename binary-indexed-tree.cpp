//Binary indexed tree for getting prefix sum
//1-indexed, so vector BIT and a should be resized to n + 1

#include <bits/stdc++.h>

using namespace std;

vector<int> BIT;
vector<int> a;

int n;

int lowbit(int x){
    return x & (-x);
}

void build(){
    for(int i = 1; i <= n; i++)
        for(int j = i; j > i - lowbit(i); j--)
            BIT[i] += a[j];
}

void modify(int x, int v){
    int t = a[x];
    a[x] = v;
    for(; x <= n; x += lowbit(x)) BIT[x] = BIT[x] - t + v;
}

int sum(int x){
    int ans = 0;
    for(; x; x -= lowbit(x)) ans += BIT[x];
    return ans;
}