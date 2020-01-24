//Functions about vector

#include <bits/stdc++.h>

#define mp(a, b) make_pair(a, b)
#define F first
#define S second

using namespace std;

template<typename T>
T operator+(T a, T b){
    return mp(a.F + b.F, a.S + b.S);
}

template<typename T>
T operator-(T a, T b){
    return mp(a.F - b.F, a.S - b.S);
}

template<typename T>
T operator*(T a, T b){
    return mp(a.F * b, a.S * b);
}

template<typename T>
T operator/(T a, T b){
    return mp(a.F / b, a.S / b);
}

template<typename T>
T dot(T a, T b){
    return a.F * b.F + a.S * b.S;
}

template<typename T>
T cross(T a, T b){
    return a.F * b.S - a.S * b.F;
}

template<typename T>
T abs2(T a){
    return a.F * a.F + a.S * a.S;
}