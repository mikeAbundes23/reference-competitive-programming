#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef vector<vector<ll>> vvl;

// Número máximo de vértices.
const ll MAXN = 2e5+10;

// Arreglo con los hashes de cada vértice
ll hashes[MAXN];

// Map con los hashes creados
map<ll,ll> m;

// Creamos un generador aleatorio de números usando distribunción uniforme, o usando mt19937_64.
auto gen = bind(uniform_int_distribution<>(0,1e9), mt19937_64(time(0)));
// auto gen = mt19937_64(time(o));

ll get(ll n){
    if(!m.count(n)) m[n] = gen();
    return m[n];
}

// Hasheamos los vertices usando DFS.
ll hashDFS(vvl &edges, ll vertex = 1, ll parent = 0){
    int val = 0;
    for(auto v : edges[vertex])
        if(v!=parent) val+=hashDFS(edges,v,vertex);

    return (hashes[vertex] = get(val));
}


