//Segment tree with lazy tag for range add and range sum query

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define lc(a) a * 2 + 1
#define rc(a) a * 2 + 2

struct Node{
    ll sum = 0;
    ll tag = 0;
    int size = 1;
    ll realSum(){
        return sum + tag * size;
    }
};

typedef struct Node Node;

vector<int> a;
vector<Node> st;

void build(int l, int r, int node){
    if(l == r){
        st[node].sum = a[l];
        return;
    }
    int m = (l + r) / 2;
    build(l, m, lc(node));
    build(m + 1, r, rc(node));
    st[node].sum = st[lc(node)].sum + st[rc(node)].sum;
    st[node].size = st[lc(node)].size + st[rc(node)].size;
}

void push(int node){
    if(st[node].tag == 0) return;
    st[lc(node)].tag += st[node].tag;
    st[rc(node)].tag += st[node].tag;
    st[node].sum = st[node].realSum();
    st[node].tag = 0;
}

ll query(int l, int r, int L, int R, int node){
    if(l == L && r == R) return st[node].realSum();
    push(node);
    int m = (L + R) / 2;
    if(r <= m) return query(l, r, L, m, lc(node));
    if(l > m) return query(l, r, m + 1, R, rc(node));
    return query(l, m, L, m, lc(node)) + query(m + 1, r, m + 1, R, rc(node));
}

void modify(int l, int r, int v, int L, int R, int node){
    if(L == R){
        st[node].sum += v;
        return;
    }
    if(l == L && r == R){
        st[node].tag += v;
        return;
    }
    int m = (L + R) / 2;
    if(r <= m) modify(l, r, v, L, m, lc(node));
    else if(l > m) modify(l, r, v, m + 1, R, rc(node));
    else{
        modify(l, m, v, L, m, lc(node));
        modify(m + 1, r, v, m + 1, R, rc(node));
    }
    st[node].sum = st[lc(node)].realSum() + st[rc(node)].realSum();
}