#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define Liny "Yes\n"
#define Linn "No\n"
bool DEBUG = 0;
template<class T> void dprint(T s){
  if(DEBUG){ cout << s << "\n"; }
}
// https://atcoder.jp/contests/abc259/tasks/abc259_d
// 共有点を持つ円どうしを繋いだグラフを作る O(N^2)
// s,t を持つ円どうしが繋がっているかBFSで判定 O(N^2)
struct circle{
    ll x,y,r;
};
circle c[3005];
vector<int> neighbor[3005];
int visited[3005];
void solve(){ 
    int N; cin >> N;
    ll sx,sy; cin >> sx >> sy;
    ll tx,ty; cin >> tx >> ty;
    REP(i,N){
        cin >> c[i].x;
        cin >> c[i].y;
        cin >> c[i].r;
    }
    REP(i,N){
        for(int j=i+1;j<N;++j){
            ll a = c[i].x - c[j].x;
            ll b = c[i].y - c[j].y;
            ll l = c[i].r + c[j].r;
            ll m = abs(c[i].r - c[j].r);
            if(m*m <= a*a+b*b && a*a+b*b <= l*l){
                neighbor[i].emplace_back(j);
                neighbor[j].emplace_back(i);
            }
        }
    }
    ll si = -1;
    REP(i,N){
        ll a = c[i].x - sx;
        ll b = c[i].y - sy;
        ll l = c[i].r;
        if(a*a+b*b == l*l){
            si = i;
            break;
        }
    }
    ll ti = -1;
    REP(i,N){
        ll a = c[i].x - tx;
        ll b = c[i].y - ty;
        ll l = c[i].r;
        if(a*a+b*b == l*l){
            ti = i;
            break;
        }
    }

    queue<int> q;
    visited[si] = 1;
    q.push(si);
    while(!q.empty()){
        int x = q.front(); q.pop();
        for(int n: neighbor[x]){
            if(visited[n]) continue;
            visited[n] = 1;
            q.push(n);
        }
    }
    cout << (visited[ti]?Liny:Linn);
}
int main(int argc, char *argv[]){
  if(argc>1 && argv[1][0]=='D'){DEBUG = 1;}
  solve();
  return 0;
}