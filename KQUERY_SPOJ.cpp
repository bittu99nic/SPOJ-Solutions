/*
** Vishal Raj Roy
** Indian Institute of Technology Kharagpur
*/

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

#define posLSB(X) __builtin_ctz(X)
#define num1bit(X) __builtin_popcount(X)
#define numlead0(X) __builtin_clz(X)
#define gcd(X,Y) __gcd(X,Y)
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define mt make_tuple
#define lb lower_bound
#define ub upper_bound
#define bs binary_search
#define ifpresent(CON,VAL) (CON.find(VAL) != CON.end())
#define all(x) x.begin(),x.end()
#define at(X,N) get<N>(X)
#define ins insert
#define xx first
#define yy second
#define sz(x) ((int)x.size())
#define count_ones __builtin_popcountl
#define nl cout<<"\n";
#define name(X) (#X)
#define watch(X) cout << (#X) << " is " << (X) << "\n"
#define sqr(x) ((x)*(x))
#define mod(x, m) ((((x) % (m)) + (m)) % (m))
#define max3(a, b, c) max(a, max(b, c))
#define min3(a, b, c) min(a, min(b, c))
#define mem(x,val) memset((x),(val),sizeof(x))
#define rite(X) freopen(X,"w",stdout)
#define read(X) freopen(X,"r",stdin)
//FOR(i,1,10) gives 1,2,3,....,9 and FOR(i,10,1) gives 9,8,....,1 also FOR(it, end(v), begin(v)) and FOR(it, begin(v), end(v))
#define FOR(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
#define SEL(X,C) for( auto & X : C )
#define ima INT_MAX
#define imi INT_MIN
#define lma LLONG_MAX
#define lmi LLONG_MIN
#define error(args...) { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args); }
#define tk(args...) take(args);

void err(istream_iterator<string> it) {} template<typename T, typename... Args> void err(istream_iterator<string> it, T a, Args... args) { cout << *it << " = " << a << "\n"; err(++it, args...);}
void take() {} template<typename T, typename... Args> void take( T & a, Args & ... args ) { cin>>a; take(args...); }
template <class T> struct custom_hash { static uint64_t splitmix64(uint64_t x) { x += 0x9e3779b97f4a7c15; x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9; x = (x ^ (x >> 27)) * 0x94d049bb133111eb; return x ^ (x >> 31); } T operator()(uint64_t x) const { static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count(); return splitmix64(x + FIXED_RANDOM);} T operator()(tuple<uint64_t,uint64_t> x) const { static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count(); return splitmix64(get<0>(x) + FIXED_RANDOM)^(splitmix64(get<1>(x) + FIXED_RANDOM) >> 1); } }; // T operator()(pair<uint64_t,uint64_t> x) const { static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count(); return splitmix64(x.first + FIXED_RANDOM)^(splitmix64(x.second + FIXED_RANDOM) >> 1); } }; 
template <class L, class R> ostream & operator<<(ostream &os, pair<L,R> P) { return os << "(" << P.xx << "," << P.yy << ")"; } template<class L, class R> ostream &operator<<(ostream &os, tuple<L,R> P) {return os << "(" << get<0>(P) << "," << get<1>(P) <<")"; } template<class L, class R, class S> ostream &operator<<(ostream &os, tuple<L,R,S> P) { return os << "(" << get<0>(P) << "," << get<1>(P) << ","<< get<2>(P) <<")"; } template<class T, class A> ostream &operator<<(ostream& os, vector<T,A> V) {os /*<< name(V)<< " is "*/ << "\n"; FOR(i,0,sz(V)) os <<"  "<< name(V) << "["<<i<<"] = "<< V[i] << "\n"; return os; /*<<"\n";*/ } template<class T, class H, class P, class A> ostream &operator<<(ostream& os, unordered_set<T,H,P,A> S) { os /*name(S) << " is"*/<<" ["; int i = 0; for(auto ELE : S) {os << ELE; if(i < sz(S)-1 ) os<<", "; i++; } return os <<  "]"; /*<<"\n"; */ } template<class S, class T, class H, class P, class A> ostream &operator<<(ostream& os, unordered_map<S,T,H,P,A> M) { os /*name(S) << " is"*/<<"\n"; for( auto ELE : M ) os <<"  "<< name(M) << "["<<ELE.xx<<"] = "<< ELE.yy << "\n"; return os; /*<<"\n";*/ } template<class T, class C, class A> ostream &operator<<(ostream& os, multiset<T,C,A> S) { os /*name(S) << " is"*/<<"["; int i = 0; for(auto ELE : S) {os << ELE; if(i < sz(S)-1 ) os<<", "; i++; } return os <<  "]"; /*<<"\n"; */ } template<class T, class R> ostream &operator<<(ostream& os, gp_hash_table<T,null_type,custom_hash<R>> S) { os /*name(S) << " is"*/<<" ["; int i = 0; for(auto ELE : S) {os << ELE; if(i < sz(S)-1 ) os<<", "; i++; } return os <<  "]"; /*<<"\n"; */ } template<class T, class Z, class R> ostream &operator<<(ostream& os, gp_hash_table<T,Z,custom_hash<R>> M) { os /*name(S) << " is"*/<<"\n"; for( auto ELE : M ) os <<"  "<< name(M) << "["<<ELE.xx<<"] = "<< ELE.yy << "\n"; return os; /*<<"\n";*/ } template<class T, class R> ostream &operator<<(ostream& os, cc_hash_table<T,null_type,custom_hash<R>> S) { os /*name(S) << " is"*/<<" ["; int i = 0; for(auto ELE : S) {os << ELE; if(i < sz(S)-1 ) os<<", "; i++; } return os <<  "]"; /*<<"\n"; */ } template<class T, class Z, class R> ostream &operator<<(ostream& os, cc_hash_table<T,Z,custom_hash<R>> M) { os /*name(S) << " is"*/<<"\n"; for( auto ELE : M ) os <<"  "<< name(M) << "["<<ELE.xx<<"] = "<< ELE.yy << "\n"; return os; /*<<"\n";*/ }

using st = string; typedef long long int li; typedef pair<int, int> ii; typedef pair<int, ii> iii; typedef tuple<int,int> i2; typedef tuple<int,int,int> i3; typedef vector<int> vi; typedef vector<ii> vii; typedef vector<i2> vi2; typedef vector<i3> vi3; typedef vector<iii> viii; typedef vector<vi> vvi; typedef vector<vvi> vvvi; typedef pair<li, li> ll; typedef pair<li, ll> lll; typedef tuple<li,li> l2; typedef tuple<li,li,li> l3; typedef vector<li> vl; typedef vector<ll> vll; typedef vector<l2> vl2; typedef vector<l3> vl3; typedef vector<lll> vlll; typedef vector<vl> vvl; typedef vector<vvl> vvvl; typedef double db; typedef complex<db> cd; typedef vector<cd> vcd; template <class S> using ve = vector<S>; template <class S> using gr = greater<S>; template <class S> using le = less<S>; template <class S, class T = le<S>> using ms =  multiset<S,T>; template <class S,class T = null_type, class R = size_t> using gp =  gp_hash_table<S,T,custom_hash<R>>; template <class S,class T = null_type, class R = size_t> using cc =  cc_hash_table<S,T,custom_hash<R>>; template <class S,class T, class R = size_t> using um =  unordered_map<S,T,custom_hash<R>>; template <class S, class R = size_t> using us =  unordered_set<S,custom_hash<R>>;

/*
Welcome to VISHAL RAJ ROY's template library :) the following are here to serve you>>
v_ = vector of '_'                   |    li = long long int      |   For fast insertion/deletion ->
vl = vector of long                  |    db = double             |               gp<T,S,R>
vi = vector of int                   |    st = string             |   For fast read/write -> cc<T,S,R>
supported:                           |    ii = pair<int,int>      |   For slow everything ->
1) vi, vvi, vvvi   4) vl, vvl, vvvl  |    iii = pair<int,ii>      |        um<T,S,R> .. R = ( size_t or uint64_t )
2) vii, viii       5) vll, vlll      |    i2 = tuple<int,int>     |        and us<T,R> .. R = ( size_t or uint64_t )
3) vi2, vi3        6) vl2, vl3       |    cdb = complex double    |   supported :
7) vcd                               |    i3 = tuple<int,int,int> |   int/li/pair -> int/li/string/pair...pair<int/li,int/li>
watch(X) is the WATCH DOG, it can print anything and everything, COULD'NT believe? just try it>> 
error(a,b,c,......) takes many parameters and shows you their true face>> 
tk(a,b,c,..) just sucks the variable from the stdin, pure black magic isn't it!>
*/

const double pi = 2 * acos(0.0);
const int oo = 0x3f3f3f3f; // don't use for long long
const double inf = 1.0/0.0;

vi vv; vi3 qq;

class segtree { // left and right inclusive
    private:
        vi v, tree; int n;
    public:
        segtree() {};
        segtree( int N ) { n = N; v.assign(n,1); tree.assign(4*n+4,0); build(1,0,n-1); }
        int func( int a, int b ) { return a+b; } // any associative function
        void build( int node, int l, int r ) {
            if( l == r ) tree[node] = v[l];
            else { int m = (l+r)/2, le = 2*node, ri = 2*node+1; build(le,l,m); build(ri,m+1,r); tree[node] = func(tree[le],tree[ri]); }
        }
        int query( int node, int l, int r, int ql, int qr ) {
            if( ql > qr ) return 0;
            else if( l == ql && r == qr ) return tree[node];
            else { int m = (l+r)/2; return func(query(2*node,l,m,ql,min(qr,m)),query(2*node+1,m+1,r,max(m+1,ql),qr)); }
        }
        void update( int node, int l, int r, int index, int newval ) {
            if( l == r ) tree[node] = newval;
            else { int m = (l+r)/2; ( m<index ? update(2*node+1,m+1,r,index,newval):update(2*node,l,m,index,newval)); tree[node] = tree[2*node]+tree[2*node+1]; }
        }
        int query(int l, int r) { return query(1,0,n-1,l,r); } 
        void update(int index, int newval) { update(1,0,n-1,index,newval); } 
};

bool comp( int a, int b ) {
    return vv[a] < vv[b];
}

bool comp2( int a, int b ) {
    return at(qq[a],2) < at(qq[b],2);
}

int main() {
    ios_base::sync_with_stdio(0);
    // read("rr.txt");
    int n; cin>>n; vv.assign(n,0); FOR(i,0,n) cin>>vv[i]; int q; cin>>q;
    FOR(i,0,q) {
        int iu,j,k; cin>>iu>>j>>k; qq.pb({iu,j,k});
    } vi qqq(q,0); FOR(i,0,q) qqq[i] = i; sort(all(qqq),comp2); segtree tr(n);
    vi pp(n,0); FOR(i,0,n) pp[i] = i; sort(all(pp),comp);
    int i, j; i = j = 0; vi ans(q,0);
    while( j < q && i < n ) {
        int l,m,nn; tie(l,m,nn) = qq[qqq[j]];
        while( i < n && vv[pp[i]] <= nn ) {
            tr.update(pp[i],0); i++;
        }
        ans[qqq[j]] = tr.query(l-1,m-1);j++;
    }
    for(;j<q;j++) ans[qqq[j]] = 0;
    SEL(x,ans) cout<<x<<"\n";
    return 0;
}
