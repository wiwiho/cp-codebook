//Functions about vector

#include <bits/stdc++.h>

#define mp(a, b) make_pair(a, b)
#define F first
#define S second

using namespace std;

#define numt int
#define pairt pair<numt, numt>

pairt operator+(pairt& a, pairt& b){
    return mp(a.F + b.F, a.S + b.S);
}

pairt operator-(pairt& a, pairt& b){
    return mp(a.F - b.F, a.S - b.S);
}

pairt operator*(pairt& a, numt b){
    return mp(a.F * b, a.S * b);
}

pairt operator/(pairt& a, numt b){
    return mp(a.F / b, a.S / b);
}

numt dot(pairt& a, pairt& b){
    return a.F * b.F + a.S * b.S;
}

numt cross(pairt& a, pairt& b){
    return a.F * b.S - a.S * b.F;
}

/**
 * @return abs(a)^2
 */
numt abs2(pairt& a){
    return a.F * a.F + a.S * a.S;
}