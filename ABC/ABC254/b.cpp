#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
typedef long long ll;
bool DEBUG = 0;
template<class T> void dprint(T s){
  if(DEBUG){ cout << s << "\n"; }
}
// https://atcoder.jp/contests/abc254/tasks/abc254_b
// パスカルの三角形
// 書いてある通りに漸化式を処理すればOK
void solve(){ 
    int N; cin >> N;
    vector< vector<ll> > v(N);
    REP(i,N){
        vector<ll> w(i+1);
        REP(j,i+1){
            if(j==0 || j==i) w[j] = 1;
            else w[j] = v[i-1][j-1] + v[i-1][j];
        }
        v[i] = w;
    }
    REP(i,N){
        int M = v[i].size();
        REP(j,M){
            cout << v[i][j] << (j<M-1?' ':'\n');
        }
    }
}
int main(int argc, char *argv[]){
  if(argc>1 && argv[1][0]=='D'){DEBUG = 1;}
  solve();
  return 0;
}