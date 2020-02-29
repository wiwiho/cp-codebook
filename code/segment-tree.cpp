template<typename T>
struct Node{
    T v = 0, tag = 0;
    int sz = 1, l = -1, r = -1;
    T rv(){
        return v + tag * sz;
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
void pull(Node<T> &a, Node<T> &l, Node<T> &r){
    a.v = pullValue(l.rv(), r.rv());
    a.sz = l.sz + r.sz;
}

template<typename T>
void push(Node<T> &a, Node<T> &l, Node<T> &r){
    l.addTag(a.tag);
    r.addTag(a.tag);
    a.v = a.rv();
    a.tag = 0;
}

template<typename T>
struct SegmentTree{
    vector<Node<T>> st;
    int cnt = 0;

    explicit SegmentTree(int sz){
        st.resize(4 * sz);
    }

    int build(int l, int r, vector<T>& o){
        int id = cnt++;
        if(l == r){
            st[id].v = o[l];
            return id;
        }
        int m = (l + r) / 2;
        st[id].l = build(l, m, o);
        st[id].r = build(m + 1, r, o);
        pull(st[id], st[st[id].l], st[st[id].r]);
        return id;
    }

    void modify(int l, int r, int v, int L, int R, int id){
        if(l == L && r == R){
            st[id].addTag(v);
            return;
        }
        int M = (L + R) / 2;
        if(r <= M) modify(l, r, v, L, M, st[id].l);
        else if(l > M) modify(l, r, v, M + 1, R, st[id].r);
        else{
            modify(l, M, v, L, M, st[id].l);
            modify(M + 1, r, v, M + 1, R, st[id].r);
        }
        pull(st[id], st[st[id].l], st[st[id].r]);
    }

    T query(int l, int r, int L, int R, int id){
        if(l == L && r == R) return st[id].rv();
        push(st[id], st[st[id].l], st[st[id].r]);
        int M = (L + R) / 2;
        if(r <= M) return query(l, r, L, M, st[id].l);
        else if(l > M) return query(l, r, M + 1, R, st[id].r);
        else{
            return pullValue(query(l, M, L, M, st[id].l), query(M + 1, r, M + 1, R, st[id].r));
        }
    }

};