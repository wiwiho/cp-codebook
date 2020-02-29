const ll INFINITE = 2147483647;

int n;
vector<vector<pii>> g;

int spfa(int start, int end){

    vector<int> dis(n, INFINITE);
    int start;
    cin >> start;
    dis[start] = 0;

    queue<int> q;
    q.push(start);
    vector<bool> inq(n);
    inq[start] = true;
    vector<int> cnt(n);

    while(!q.empty()){
        int v = q.front();
        q.pop();
        inq[v] = false;
        for(pii p : g[v]){
            if(!(dis[p.F] == INFINITE || dis[v] + p.S < dis[p.F])) continue;
            cnt[p.F]++;
            if(cnt[p.F] >= n) return -INFINITE; //negetive cycle
            dis[p.F] = dis[v] + p.S;
            if(!inq[p.F]){
                inq[p.F] = true;
                q.push(p.F);
            }
        }

    }
    return dis[end];
}
