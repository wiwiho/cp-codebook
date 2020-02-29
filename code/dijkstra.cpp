//Dijkstra algorithm for searching shortest path between 2 vertices

#include <bits/stdc++.h>

#define mp(a, b) make_pair(a, b)
#define F first
#define S second
#define pii pair<int, int>

using namespace std;

/**
 * The first element in pair should be edge weight, and the second should be vertex
 */
vector<vector<pii>> g;
int n;

int dijkstra(int start, int end){
    priority_queue<pii, vector<pii>, greater<pii>> q;
    for(pii p : g[start]){
        q.push(p);
    }
    q.push(mp(0, start));
    vector<int> dis(n, -1);
    dis[start] = 0;
    vector<int> visit(n);
    while(q.size()){
        int v = q.top().S;
        int d = q.top().F;
        if(v == end) break;
        q.pop();
        if(visit[v]) continue;
        visit[v] = true;
        for(pii p : g[v]){
            if(visit[p.S]) continue;
            if(dis[p.S] == -1 || d + p.F < dis[p.S]){
                dis[p.S] = d + p.F;
                q.push(mp(dis[p.S], p.S));
            }
        }
    }
    return dis[end];
}