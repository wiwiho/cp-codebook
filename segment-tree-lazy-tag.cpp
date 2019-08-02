//Segment tree for range maximum query and range modify with lazy tag

#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

const ll MAX = 2147483647;

#define lc(a) a * 2 + 1
#define rc(a) a * 2 + 2

struct Node{
    int max;
    int tag = -MAX;
    bool isLazy(){
        return tag != -MAX;
    }
    int realMax(){
        return isLazy() ? tag : max;
    }
};

typedef struct Node Node;

vector<Node> st;
vector<int> a;

void build(int l, int r, int id){
    if(l == r){
        st[id].max = a[l];
        return;
    }
    int m = (l + r) / 2;
    build(l, m, lc(id));
    build(m + 1, r, rc(id));
    st[id].max = max(st[lc(id)].max, st[rc(id)].max);
}

void push(int id){
    if(!st[id].isLazy()) return;
    st[lc(id)].tag = st[id].tag;
    st[rc(id)].tag = st[id].tag;
    st[id].tag = -MAX;
}

/**
 * @param l 查詢左界
 * @param r 查詢右界
 * @param L 節點範圍
 * @param R 節點範圍
 * @param id 節點編號
 * @return
 */
int query(int l, int r, int L, int R, int id){
    if(l == L && r == R) return st[id].realMax();
    push(id);
    int m = (L + R) / 2;
    if(r <= m) return query(l, r, L, m, lc(id));
    if(l > m) return query(l, r, m + 1, R, rc(id));
    return max(query(l, m, L, m, lc(id)), query(m + 1, r, m + 1, R, rc(id)));
}

/**
 * @param l 修改左界
 * @param r 修改右界
 * @param v 新值
 * @param L 節點範圍
 * @param R 節點範圍
 * @param id 節點編號
 */
void modify(int l, int r, int v, int L, int R, int id){
    if(L == R){
        st[id].max = v;
        return;
    }
    if(l == L && r == R){
        st[id].tag = v;
        return;
    }
    push(id);
    int m = (L + R) / 2;
    if(r <= m) modify(l, r, v, L, m, lc(id));
    else if(l > m) modify(l, r, v, m + 1, R, rc(id));
    else{
        modify(l, m, v, L, m, lc(id));
        modify(m + 1, r, v, m + 1, R, rc(id));
    }
    st[id].max = max(st[lc(id)].realMax(), st[rc(id)].realMax());
}