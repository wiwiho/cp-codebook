//KMP for calculate how many times p appears in t

#include <bits/stdc++.h>

using namespace std;

//baluteshih
int kmp(string& t, string& p){

    vector<int> f(p.size() + 5);
    f[0] = -1;
    int ans = 0;
    for(int i = 1, j = 0; i < p.size(); f[++i] = ++j){
        if(p[i] == p[j]) f[i] = f[j];
        while(j != -1 && p[i] != p[j]) j = f[j];
    }
    for(int i = 0, j = 0; i - j + p.size() <= t.size(); i++, j++){
        while(j != -1 && t[i] != p[j]) j = f[j];
        if(j == p.size() - 1) ans++;
    }
    for(int i = 0; i < p.size() + 5; i++) cerr << f[i] << " ";
    cerr << "\n";
    return ans;
}