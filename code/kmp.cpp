//KMP for calculate how many times p appears in t

#include <bits/stdc++.h>

using namespace std;

vector<int> f;
void build(string& t){
    f.clear();
    f.resize(t.size());
    int p = -1;
    f[0] = -1;
    for(int i = 1; i < t.size(); i++){
        while(p != -1 && t[p + 1] != t[i]) p = f[p];
        if(t[p + 1] == t[i]) f[i] = p + 1;
        else f[i] = -1;
        p = f[i];
    }
}

int kmp(string& s, string& t){
    int ans = 0;
    int p = -1;
    for(int i = 0; i < s.size(); i++){
        while(p != -1 && t[p + 1] != s[i]) p = f[p];
        if(t[p + 1] == s[i]) p++;
        if(p + 1 == t.size()){
            ans++;
            p = f[p];
        }
    }
    return ans;
}