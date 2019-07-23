//Segment Tree (for range minimum query)

#include <bits/stdc++.h>

using namespace std;

#define lc(a) a * 2 + 1
#define rc(a) a * 2 + 2

struct Node{
    int max;
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

/**
 * @param l 查詢左界
 * @param r 查詢右界
 * @param L 節點範圍
 * @param R 節點範圍
 * @param id 節點編號
 * @return
 */
int query(int l, int r, int L, int R, int id){
    if(l == L && r == R) return st[id].max;
    int m = (l + r) / 2;
    if(r <= m) return query(l, r, L, m, lc(id));
    if(l > m) return query(l, r, m + 1, R, rc(id));
    return max(query(l, m, L, m, lc(id)), query(m + 1, r, m + 1, R, rc(id)));
}

/**
 * @param i 修改位置
 * @param v 新值
 * @param L 節點範圍
 * @param R 節點範圍
 * @param id 節點編號
 */
void modify(int i, int v, int L, int R, int id){
    if(L == R){
        st[id].max = v;
        return;
    }
    int m = (L + R) / 2;
    if(i <= m) modify(i, v, L, m, lc(id));
    else modify(i, v, m + 1, R, rc(id));
    st[id].max = max(st[lc(id)].max, st[rc(id)].max);
}