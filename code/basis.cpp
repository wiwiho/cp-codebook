const int mxdigit = 50;

vector<ll> b(mxdigit + 1);

void add(ll t){
    for(int i = mxdigit; i >= 0; i--){
        if(!(1LL << i & t)) continue;
        if(b[i] != 0){
            t ^= b[i];
            continue;
        }
        for(int j = 0; j < i; j++){
            if(1LL << j & t) t ^= b[j];
        }
        for(int j = i + 1; j <= mxdigit; j++){
            if(1LL << i & b[j]) b[j] ^= t;
        }
        b[i] = t;
        break;
    }
}