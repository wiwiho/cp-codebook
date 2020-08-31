#include <bits/stdc++.h>

#define eb(a) emplace_back(a)

using namespace std;

// tg is the origin graph, g is the result
vector<vector<int>> tg, g;
int bcc; // = n+1, initially
vector<int> low, in;
int tts = 1;
stack<int> st;
vector<vector<int>> c;
vector<bool> iscut;

void dfsbcc(int now, int p){ // calculate low
    low[now] = in[now] = tts++;
    for(int i : tg[now]){
        if(i == p) continue;
        if(in[i]) low[now] = min(low[now], in[i]);
        else{
            dfsbcc(i, now);
            low[now] = min(low[now], low[i]);
            c[now].eb(i);
        }
        if(low[i] >= in[now] && now != 1) iscut[now] = true;
    }
    if(now == 1 && c[now].size() > 1) iscut[now] = true;
}

void dfsbcc2(int now, int p){ // build block-cut tree
    st.push(now);
    for(int i : c[now]){
        dfsbcc2(i, now);
    }
    if(now == 1){
        if(st.size() > 1){
            while(!st.empty()){
                g[st.top()].eb(bcc);
                g[bcc].eb(st.top());
                st.pop();
            }
            bcc++;
        }
    }
    else if((p != 1 && low[now] >= in[p]) || (p == 1 && c[p].size() > 1)){
        while(!st.empty()){
            int t = st.top();
            g[st.top()].eb(bcc);
            g[bcc].eb(st.top());
            st.pop();
            if(t == now) break;
        }
        g[bcc].eb(p);
        g[p].eb(bcc);
        bcc++;
    }
}