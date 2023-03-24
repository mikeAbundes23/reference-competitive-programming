#include <bits/stdc++.h>

using namespace std;

// debug macros
#ifndef ONLINE_JUDGE
    #define printv(v) cerr << #v << ": ";for(auto x : v) cerr << x << ' '; cerr << '\n';
    #define deb(...) logger(#__VA_ARGS__, __VA_ARGS__)
    template<typename ...Args>
    void logger(string vars, Args&&... values) {
        cerr << vars << " = ";
        string delim = "";
        (..., (cerr << delim << values, delim = ", "));
        cerr << '\n';
    }
#else
    #define printv(v) 0
    #define deb(...) 0
#endif

// shortcuts
#define endl '\n'
#define pb push_back
#define fr first
#define sc second
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
#define sz(v) (int)(v).size()
#define TEST int t;cin>>t;while(t--)

typedef long long ll;
typedef string str;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<char> vc;
typedef vector<pii> vii;
typedef vector<vi> vvi;
typedef map<int,int> mii;
typedef set<int> si;
typedef set<char> sc;

void setPrec() { cout << fixed << setprecision(16); }
void setIO(string NAME = "") {
    cin.tie(0)->sync_with_stdio(0);
    setPrec();
    if(sz(NAME)) {
        freopen((NAME + ".inp").c_str(),"r",stdin);
        freopen((NAME + ".out").c_str(),"w",stdout);
    }
}

int main() {
    setIO();
    

  return 0;
}
