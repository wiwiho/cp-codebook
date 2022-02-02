vector<int> lcp(n);
int lst = 0;
for(int i = 0; i < n; i++){
    int now = rk[i];
    if(now == 0){
        lcp[now] = 0;
        continue;
    }
    if(lst) lst--;
    lcp[now] = lst;
    int pos = sa[now - 1];
    while(s[i + lcp[now]] == s[pos + lcp[now]]) lcp[now]++;
    lst = lcp[now];
}
