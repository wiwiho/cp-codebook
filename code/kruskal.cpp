int kruskal(){
    int ans = 0;
    lsort(e);
    initDSU();
    for(auto& i : e){
        int a = i.S.F, b = i.S.S;
        if(findDSU(a) == findDSU(b)) continue;
        ans += i.F;
        unionDSU(a, b);
    }
    return ans;
}