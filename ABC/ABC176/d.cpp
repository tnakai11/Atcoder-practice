#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
typedef long long ll;
typedef long double ld;
#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define REPR(i,n) for(int i=n; i>-1; --i)
#define ALL(a) (a).begin(),(a).end()
#define FILL(a,n,x) REP(i,(n)){ (a)[i]=(x); }
#define CINA(a,n) REP(i,(n)){ cin >> (a)[i]; }
#define FILL2(a,n,m,x) REP(i,(n)){ REP(j,(m)){(a)[i][j]=(x);} }
#define CINA2(a,n,m) REP(i,(n)){ REP(j,(m)){cin >> (a)[i][j];} }
#define Liny "Yes\n"
#define Linn "No\n"
#define LINY "YES\n"
#define LINN "NO\n"
int keta(ll x){ if(x<10){return 1;} else{return keta(x/10) + 1;}}
int keta_wa(ll x){ if(x<10){return x;} else{return keta_wa(x/10) + x%10;} }
int ctoi(char c){ return ( (c>='0' && c<='9')? c - '0': 0 );}
int __stoi(string s){ return atoi(s.c_str()); }
ll sum(ll a[],ll N){ return accumulate(a,a+N,0LL);}
ll gcd(ll a,ll b){if(a<b)swap(a,b); return b?gcd(b,a%b):a;}
ll lcm(ll a,ll b){if(a<b){swap(a,b);} return a/gcd(a,b)*b;}
template<class T> void chmax(T& a, T b){ if(a<b){a=b;} }
template<class T> void chmin(T& a, T b){ if(a>b){a=b;} }
template<class T> bool isIn(T a,vector<T> v){ for(T x:v){ if(a==x){return true;}} return false;}
string strReplace(string s,string target, string replacement){
    if (!target.empty()) {
     std::string::size_type pos = 0;
      while ((pos = s.find(target, pos)) != std::string::npos) {
        s.replace(pos, target.length(), replacement);
        pos += replacement.length();
      }
    }
    return s;
}
const ll MOD = 998244353;
using mint = modint998244353;
// using mint = static_modint<MOD>;
#define pii pair<int,int>
#define pll pair<ll,ll>
#define MP make_pair
bool DEBUG = 0;
template<class T> void dprint(T s){
  if(DEBUG){ cout << s << "\n"; }
}

// https://atcoder.jp/contests/abc176/tasks/abc176_d
// 埋めてからワープを繰り返せばいけそう
// 遷移先の重複に注意
// ループの終了条件に注意

int H,W;
pii c,d;
string s[1005];
int cost[1005][1005];
const int MAX = 1e+9;

struct jump{
    int h,w,next_h,next_w;
};

void solve(){ 
    cin >> H >> W;
    cin >> c.first >> c.second;
    cin >> d.first >> d.second;
    --c.first;
    --c.second;
    --d.first;
    --d.second;
    CINA(s,H);
    FILL2(cost,H,W,MAX);

    queue<pii> q;
    queue<jump> r;
    cost[c.first][c.second] = 0;
    q.push(MP(c.first,c.second));
    while(!q.empty() || !r.empty()) {
        while(!q.empty()){
            int h = q.front().first;
            int w = q.front().second;
            q.pop();
            for(int next_h=h-1;next_h<=h+1;++next_h){
                if(next_h<0 || next_h>=H) continue;
                for(int next_w=w-1;next_w<=w+1;++next_w){
                    if(next_w<0 || next_w>=W) continue;
                    if(abs(next_h-h)+abs(next_w-w)!=1) continue;
                    if(s[next_h][next_w]=='#') continue;
                    if(cost[next_h][next_w]<=cost[h][w]) continue;
                    cost[next_h][next_w] = cost[h][w];
                    q.push(MP(next_h,next_w));
                }
            }

            for(int next_h=h-2;next_h<=h+2;++next_h){
                if(next_h<0 || next_h>=H) continue;
                for(int next_w=w-2;next_w<=w+2;++next_w){
                    if(next_w<0 || next_w>=W) continue;
                    if(s[next_h][next_w]=='#') continue;
                    if(cost[next_h][next_w]<=cost[h][w]+1) continue;
                    r.push({h,w,next_h,next_w});
                }
            }
        }
        while(!r.empty()){
            int h = r.front().h;
            int w = r.front().w;
            int next_h = r.front().next_h;
            int next_w = r.front().next_w;
            r.pop();
            if(cost[next_h][next_w]>cost[h][w]+1){
                cost[next_h][next_w] = cost[h][w] + 1;
                q.push( MP(next_h,next_w) );
            }
        }
    }
    
    if(DEBUG){
        REP(h,H){
            REP(w,W){
                cout << cost[h][w] << ' ';
            }
            cout << endl;
        }
    }

    int ans = cost[d.first][d.second];
    if(ans==MAX) ans = -1;
    cout << ans << '\n';

}
int main(int argc, char *argv[]){
  if(argc>1 && argv[1][0]=='D'){ DEBUG = 1;}
  solve();
  return 0;
}