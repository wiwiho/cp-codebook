/*
 * g: block-cut tree
 * id[v]: vertex in block-cut tree which v belongs to
 * iscut[v]: whether v in origin graph is an articulation
 * bcccut[v]: whether v in block-cut tree is an articulation
 * tg: origin graph
 */

int n;

vector<vector<int>> g;
vector<int> id;
vector<bool> iscut, bcccut;

vector<vector<int>> tg;
vector<int> in, low;
int ts = 1;
stack<int> st;
int bccid = 1;

void init(){
    tg.resize(n + 1);
    in.resize(n + 1);
    low.resize(n + 1);
    id.resize(n + 1, -1);
    g.resize(2 * n + 1);
    iscut.resize(n + 1);
    bcccut.resize(2 * n + 1);
}

void addv(int b, int v){
    if(id[v] == -1){
        id[v] = b;
        return;
    }
    if(!iscut[v]){
        int o = id[v];
        iscut[v] = true;
        id[v] = bccid++;
        bcccut[id[v]] = true;
        g[o].eb(id[v]);
        g[id[v]].eb(o);
    }
    g[b].eb(id[v]);
    g[id[v]].eb(b);
}

void dfs(int now, int p){
    in[now] = low[now] = ts++;
    st.push(now);
    int cnt = 0;
    for(int i : tg[now]){
        if(i == p) continue;
        if(in[i]) low[now] = min(low[now], in[i]);
        else{
            cnt++;
            dfs(i, now);
            low[now] = min(low[now], low[i]);

            if(low[i] >= in[now]){
                int nowid = bccid++;
                while(true){
                    int x = st.top();
                    st.pop();
                    addv(nowid, x);
                    if(x == i) break;
                }
                addv(nowid, now);
            }
        }
    }
    if(cnt == 0 && now == p) addv(bccid++, now);
}
