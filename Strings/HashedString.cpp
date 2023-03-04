#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// Constantes
const ll N = 2e5+1;
const ll MOD = 212345678987654321LL;
const ll base = 33;

// Operaciones
ll add(ll a, ll b){ return ((a+b)%MOD + MOD)%MOD; }
ll mult(__int128 a, __int128 b){ return ((a*1LL*b)%MOD + MOD)%MOD; }
ll binpow(ll a, ll n){
    if(!n) return 1;
    ll res = binpow(a,n>>1);
    res = mult(res,res);
    if(n&1) return mult(res,a);
    return res;
}
// Calculamos el inverso modular
ll baseinv = binpow(base, MOD - 2);

ll pws[N];
ll inv[N];

class HashedString {
private:
    ll n;
    vector<ll> h;

public:
    HashedString(string s){
        n = s.size()+1;
        h = vector<ll>(n);
        for(ll i = 1; i < n ; i++)
            h[i] = add(h[i-1] , mult(pws[i], s[i-1]));
    }

    ll get(ll l,ll r){ return mult(add(h[r],-h[l]),inv[l]); }
};

// Calcula las potencias de la base y sus inversos modulares
void precalculate(){
    pws[0] = 1;
    inv[0] = 1;
    for(ll i = 1 ; i < N ; i++){
        pws[i] = mult(pws[i-1],base);
        inv[i] = mult(inv[i-1], baseinv);
    }
}
