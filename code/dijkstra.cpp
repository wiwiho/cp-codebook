// pll = (vertex, weight)
vector<vector<pll>> g;
int n;
const ll INF = 1LL << 60;

ll dijkstra(int start, int end){
    // pll = (dis, vertex)
    priority_queue<pll, vector<pll>, greater<>> pq;
    pq.push(mp(0, start));
    vector<ll> dis(n, INF);
    dis[start] = 0;
    while(!pq.empty()){
        int v = pq.top().S;
        ll d = pq.top().F;
        pq.pop();
        if(d != dis[v]) continue;
        for(pll p : g[v]){
            if(d + p.S < dis[p.F]){
                dis[p.F] = d + p.S;
                pq.push(mp(d + p.S, p.F));
            }
        }
    }
    return dis[end];
}