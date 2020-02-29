vector<int> z;

void build(string s, int n){
    z.clear();
    z.resize(n);
    int l = 0;
    for(int i = 0; i < n; i++){
        if(l + z[l] >= i) z[i] = min(z[l] + l - i, z[i - l]);
        while(i + z[i] < n && s[z[i]] == s[i + z[i]]) z[i]++;
        if(i + z[i] > l + z[l]) l = i;
    }
}
