//Tarjan's SCC Algorithm

#include <bits/stdc++.h>

#define eb(a) emplace_back(a)
#define pob pop_back()

using namespace std;

vector<vector<int>> g;
vector<int> st;
vector<bool> inst;
vector<int> scc;
vector<int> ts, low;
int tmp = 0;
int sccid = 0;

void initSCC(int n){
    tmp = 0;
    sccid = 0;
    st.clear();
    g.clear();
    g.resize(2 * n + 1);
    inst.clear();
    inst.resize(2 * n + 1);
    scc.clear();
    scc.resize(2 * n + 1);
    ts.clear();
    ts.resize(2 * n + 1, -1);
    low.clear();
    low.resize(2 * n + 1);
}

void dfs(int now){

    st.eb(now);
    inst[now] = true;
    ts[now] = ++tmp;
    low[now] = ts[now];

    for(int i : g[now]){
        if(ts[i] == -1){
            dfs(i);
            low[now] = min(low[now], low[i]);
        }
        else if(inst[i]) low[now] = min(low[now], ts[i]);
    }

    if(low[now] == ts[now]){
        sccid++;
        int t;
        do{
            t = st.back();
            st.pob;
            inst[t] = false;
            scc[t] = sccid;
        }
        while(t != now);
    }

}