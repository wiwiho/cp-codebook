template<typename T>
struct BIT{
    
private:
    vector<T> bit;
    int lowbit(int x){
        return x & (-x);
    }

public:
    explicit BIT(int sz){
        bit.resize(sz + 1);
    }

    void modify(int x, T v){
        for(; x < bit.size(); x += lowbit(x)) bit[x] += v;
    }

    T get(int x){
        T ans = T();
        for(; x; x -= lowbit(x)) ans += bit[x];
        return ans;
    }
};