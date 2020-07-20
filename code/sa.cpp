#include <bits/stdc++.h>

#define eb(a) emplace_back(a)

using namespace std;

vector<int> sa(string s){
    s += '$';
    int n = s.size();
    int t = __lg(n) + 1;

    vector<vector<int>> rk(t + 1, vector<int>(n)), b;

    vector<vector<int>> c1(27);
    for(int i = 0; i < n; i++) c1[s[i] == '$' ? 0 : s[i] - 'a' + 1].eb(i);;
    for(int i = 0; i < 27; i++){
        if(!c1[i].empty()) b.eb(c1[i]);
    }
    b.resize(n);
    for(int i = 0; i < n; i++){
        for(int k : b[i]) rk[0][k] = i;
    }

    for(int i = 1; i <= t; i++){
        vector<vector<int>> tb(n);
        for(int j = 0; j < n; j++){
            for(int k : b[j]){
                int tmp = ((k - (1 << (i - 1))) % n + n) % n;
                int now = rk[i - 1][tmp];
                tb[now].eb(tmp);
            }
        }
        b = tb;
        int cnt = -1;
        for(int j = 0; j < n; j++){
            int lst = -1;
            for(int k : b[j]){
                int now = rk[i - 1][(k + (1 << (i - 1))) % n];
                if(now != lst) cnt++;
                rk[i][k] = cnt;
                lst = now;
            }
        }
    }

    return rk[t];
}