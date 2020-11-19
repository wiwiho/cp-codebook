template<typename T>
struct Node{
    T v = T(), tag = T();
    int sz = 1, l = -1, r = -1;
    int lr = -1, rr = -1;
    T rv(){
        return v + tag * (rr - lr + 1);
    }
    void addTag(T t){
        tag += t;
    }
};

template<typename T>
T pullValue(T b, T c){
    return b + c;
}

template<typename T>
struct SegmentTree{
    vector<Node<T>> st;
    int cnt = 0;

    explicit SegmentTree(int sz){
        st.resize(sz);
    }

    int node(int l, int r){
        int id = cnt++;
        st[id].lr = l;
        st[id].rr = r;
        return id;
    }

    void pull(int id){
        st[id].v = pullValue(st[id].l == -1 ? T() : st[st[id].l].rv(), st[id].r == -1 ? T() : st[st[id].r].rv());
    }

    void push(int id, int L, int R){
        int M = (L + R) / 2;
        if(st[id].l == -1) st[id].l = node(L, M);
        st[st[id].l].addTag(st[id].tag);
        if(st[id].r == -1) st[id].r = node(M + 1, R);
        st[st[id].r].addTag(st[id].tag);
        st[id].v = st[id].rv();
        st[id].tag = T();
    }

    int modify(int l, int r, T v, int L, int R, int id){
        if(id == -1) id = node(L, R);
        if(l == L && r == R){
            st[id].addTag(v);
            return id;
        }
        int M = (L + R) / 2;
        if(r <= M) st[id].l = modify(l, r, v, L, M, st[id].l);
        else if(l > M) st[id].r = modify(l, r, v, M + 1, R, st[id].r);
        else{
            st[id].l = modify(l, M, v, L, M, st[id].l);
            st[id].r = modify(M + 1, r, v, M + 1, R, st[id].r);
        }
        pull(id);
        return id;
    }

    T query(int l, int r, int L, int R, int id){
        if(id == -1) return T();
        if(l == L && r == R) return st[id].rv();
        push(id, L, R);
        int M = (L + R) / 2;
        if(r <= M) return query(l, r, L, M, st[id].l);
        else if(l > M) return query(l, r, M + 1, R, st[id].r);
        else{
            return pullValue(query(l, M, L, M, st[id].l), query(M + 1, r, M + 1, R, st[id].r));
        }
    }

};