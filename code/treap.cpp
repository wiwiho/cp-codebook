mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());

template<typename T>
struct Node{
    int l = -1, r = -1, pri = rnd(), sz = 1;
    T v, sum, tag;
    T rsum(){
        return sum + tag * sz;
    }
};

template<typename T>
struct Treap{
    vector<Node<T>> tr;
    int ts = 0;
    explicit Treap(int sz){
        tr.resize(sz);
    }

    int node(T v){
        int r = ts++;
        tr[r].v = v;
        tr[r].sum = 0;
        tr[r].tag = 0;
        return r;
    }

    void pull(int r){
        if(r != -1){
            tr[r].sz = 1;
            tr[r].sum = tr[r].v;
            if(tr[r].l != -1){
                tr[r].sum += tr[tr[r].l].rsum();
                tr[r].sz += tr[tr[r].l].sz;
            }
            if(tr[r].r != -1){
                tr[r].sum += tr[tr[r].r].rsum();
                tr[r].sz += tr[tr[r].r].sz;
            }
        }
    }

    void push(int r){
        if(r == -1) return;
        if(tr[r].l != -1){
            tr[tr[r].l].tag += tr[r].tag;
        }
        if(tr[r].r != -1){
            tr[tr[r].r].tag += tr[r].tag;
        }
        tr[r].sum = tr[r].rsum();
        tr[r].v += tr[r].tag;
        tr[r].tag = 0;
    }

    void merge(int a, int b, int& r){
        push(a);
        push(b);
        if(a == -1 && b == -1) r = -1;
        else if(a == -1) r = b;
        else if(b == -1) r = a;
        else{
            if(tr[a].pri > tr[b].pri){
                r = a;
                merge(tr[a].r, b, tr[a].r);
            }
            else{
                r = b;
                merge(a, tr[b].l, tr[b].l);
            }
        }
        pull(r);
    }

    void split1(int a, T k, int& r1, int& r2){
        if(a == -1){
            r1 = r2 = -1;
            return;
        }
        push(a);
        if(tr[a].v < k){
            r1 = a;
            split1(tr[a].r, k, tr[a].r, r2);
        }
        else{
            r2 = a;
            split1(tr[a].l, k, r1, tr[a].l);
        }
        pull(a);
    }

    void split2(int a, int k, int& r1, int& r2){
        if(a == -1){
            r1 = r2 = -1;
            return;
        }
        push(a);
        if(k == 0){
            r1 = -1;
            r2 = a;
            return;
        }
        if(tr[a].l == -1 || tr[tr[a].l].sz < k){
            r1 = a;
            if(tr[a].l != -1) split2(tr[a].r, k - tr[tr[a].l].sz - 1, tr[a].r, r2);
            else split2(tr[a].r, k - 1, tr[a].r, r2);
        }
        else{
            r2 = a;
            split2(tr[a].l, k, r1, tr[a].l);
        }
        pull(a);
    }

    void printtr(int now){
        if(now == -1) return;
        printtr(tr[now].l);
        cerr << now << "," << tr[now].v + tr[now].tag << "," << tr[now].rsum() << "," << tr[now].tag << " ";
        printtr(tr[now].r);
    }
    
    void print(int r){
        printtr(r);
        cerr << "\n";
    }

};