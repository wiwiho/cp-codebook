int n;

vector<vector<int>> g;
vector<int> id;
vector<bool> iscut, bcccut;

vector<vector<int>> tg;
vector<int> in, low, cnt;
vector<bool> vst;
int ts = 1;
stack<int> st;
int bccid = 1;

void init(){
    tg.resize(n + 1);
    in.resize(n + 1);
    low.resize(n + 1);
    cnt.resize(n + 1);
    vst.resize(n + 1);
    id.resize(n + 1, -1);
    g.resize( 2 * n + 1);
    iscut.resize(n + 1);
    bcccut.resize(2 * n + 1);
}

void addedge(int u, int v){
    g[u].eb(v);
    g[v].eb(u);
}

void dfsc(int now, int p){
    vst[now] = true;
    for(int i : tg[now]){
        if(i == p || vst[i]) continue;
        cnt[now]++;
        dfsc(i, now);
    }
}

void dfs(int now, int p){
    in[now] = low[now] = ts++;
    st.push(now);
    for(int i : tg[now]){
        if(i == p) continue;
        if(in[i]) low[now] = min(low[now], in[i]);
        else{
            dfs(i, now);
            low[now] = min(low[now], low[i]);

            if((now != p && low[i] >= in[now]) || (now == p && cnt[now] > 1)){
                int nowid = bccid++;
                while(true){
                    int x = st.top();
                    if(iscut[x]) id[x] = nowid;
                    else addedge(nowid, id[x]);
                    st.pop();
                    if(x == i) break;
                }
                iscut[now] = true;
                if(id[now] == -1) id[now] = bccid++;
                bcccut[id[now]] = true;
                addedge(id[now], nowid);
            }
        }
    }
    if(now == p && cnt[now] == 1 && !iscut[now]){
        int nowid = bccid++;
        while(!st.empty()){
            int x = st.top();
            if(!iscut[x]) id[x] = nowid;
            else addedge(nowid, id[x]);
            st.pop();
        }
    }
}

