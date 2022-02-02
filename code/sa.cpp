#include <bits/stdc++.h>

#define eb(a) emplace_back(a)
#define iter(a) a.begin(), a.end()
#define id(a) ((a) - 'a')

using namespace std;

string s;
vector<int> rk;
vector<int> sa;
int n;

void build_sa(){
    sa.resize(n);
    rk.resize(n);
    vector<int> t1(n), t2(n);
    vector<int> cnt(max(n, 27));

    for(int i = 0; i < n; i++) cnt[id(s[i])]++, t1[i] = id(s[i]);
    for(int i = 1; i < 27; i++) cnt[i] += cnt[i - 1];
    for(int i = n - 1; i >= 0; i--) sa[--cnt[id(s[i])]] = i;
    
    for(int k = 1; k < n; k *= 2){
        fill(iter(cnt), 0);
        for(int i = 0; i < n; i++) cnt[t1[i]]++;
        for(int i = 1; i < cnt.size(); i++) cnt[i] += cnt[i - 1];
        int p = 0;
        for(int i = n - k; i < n; i++) t2[p++] = i;
        for(int i = 0; i < n; i++) if(sa[i] >= k) t2[p++] = sa[i] - k;
        for(int i = n - 1; i >= 0; i--) sa[--cnt[t1[t2[i]]]] = t2[i];
        t2[sa[0]] = p = 0;

        for(int i = 1; i < n; i++){
            int a = sa[i], b = sa[i - 1];
            if(t1[a] == t1[b] && a + k < n && b + k < n && t1[a + k] == t1[b + k]);
            else p++;
            t2[sa[i]] = p;
        }
        if(n == p + 1) break;
        t1.swap(t2);
    }

    for(int i = 0; i < n; i++) rk[sa[i]] = i;
}
