const ll INF = 1LL << 60;

template<typename T>
struct Line{
    mutable T a, b, r = 0;

    Line(T a, T b) : a(a), b(b){}

    bool operator<(Line<T> l)const{
        return a < l.a;
    }

    bool operator<(T v)const{
        return r < v;
    }
};

template<typename T>
T divfloor(T a, T b){
    return a / b - ((a ^ b) < 0 && a % b);
}

template<typename T>
struct DynamicHull{
    multiset<Line<T>, less<>> s;

    int size(){
        return s.size();
    }

    bool intersect(typename set<Line<T>>::iterator a, typename set<Line<T>>::iterator &b){
        if(b == s.end()){
            a->r = INF;
            return false;
        }
        if(a->a == b->a){
            if(a->b > b->b) a->r = INF;
            else a->r = -INF;
        }
        else{
            a->r = divfloor(b->b - a->b, a->a - b->a);
        }
        return a->r >= b->r;
    }

    void insert(T a, T b){
        Line<T> l(a, b);
        auto it = s.insert(l), after = next(it), before = it;
        while(intersect(it, after)) after = s.erase(after);
        if(before != s.begin() && intersect(--before, it)){
            it = s.erase(it);
            intersect(before, it);
        }
        while((it = before) != s.begin() && (--before)->r >= it->r) intersect(before, it = s.erase(it));
    }

    T query(T v){
        Line<T> l = *s.lower_bound(v);
        return l.a * v + l.b;
    }
};