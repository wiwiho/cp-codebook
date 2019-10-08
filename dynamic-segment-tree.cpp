//Dynamic segment tree for range sum query

#include <bits/stdc++.h>

typedef long long ll;
using namespace std;

struct Node;

struct Node{
    ll v = 0;
    Node* lc = nullptr, * rc = nullptr;
    ll sz = 0, lazy = 0;
    ll realSum(){
        return v + sz * lazy;
    }
};

Node* build(int l, int r){
    Node* n = new Node();
    n->sz = r - l + 1;
    return n;
}

void add(int l, int r, int L, int R, int v, Node* n){
    if(l == L && r == R){
        n->lazy += v;
        return;
    }
    int M = (L + R) / 2;
    if(n->lc == nullptr) n->lc = build(L, M);
    if(n->rc == nullptr) n->rc = build(M + 1, R);
    if(r <= M) add(l, r, L, M, v, n->lc);
    else if(l > M) add(l, r, M + 1, R, v, n->rc);
    else{
        add(l, M, L, M, v, n->lc);
        add(M + 1, r, M + 1, R, v, n->rc);
    }
    n->v = n->lc->realSum() + n->rc->realSum();
}

void push(int l, int r, Node* n){
    int m = (l + r) / 2;
    if(n->lc == nullptr) n->lc = build(l, m);
    if(n->rc == nullptr) n->rc = build(m + 1, r);
    n->lc->lazy += n->lazy;
    n->rc->lazy += n->lazy;
    n->v += n->lazy * n->sz;
    n->lazy = 0;
}

ll query(int l, int r, int L, int R, Node* n){
    if(l == L && r == R) return n->realSum();
    int M = (L + R) / 2;
    push(L, R, n);
    if(r <= M) return query(l, r, L, M, n->lc);
    else if(l > M) return query(l, r, M + 1, R, n->rc);
    else{
        return query(l, M, L, M, n->lc) + query(M + 1, r, M + 1, R, n->rc);
    }
}