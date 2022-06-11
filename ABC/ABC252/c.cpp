#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
int ctoi(char c){ return ( (c>='0' && c<='9')? c - '0': 0 );}
template<class T> void chmax(T& a, T b){ if(a<b){a=b;} }
template<class T> void chmin(T& a, T b){ if(a>b){a=b;} }
bool DEBUG = 0;
template<class T> void dprint(T s){
  if(DEBUG){ cout << s << "\n"; }
}
// https://atcoder.jp/contests/abc252/tasks/abc252_c
// 0~9 の各場合について最短時間を求める
// 一番重なっているところが最後に押されることに注目すればO(NM^2) (Mは法)
void solve(){ 
    int N; cin >> N;
    int M = 10;
    vector<string> s(N); 
    REP(i,N) {
        cin >> s[i];
    }
    int ans = 1e9+1;
    for(int x=0;x<M;++x){
        map<int,int> mp;
        int d = 0;
        int lastp = 0;
        for(int p=0;p<M;++p){
            for(int i=0;i<N;++i){
                if(ctoi(s[i][p])==x){
                    ++mp[p];
                    if(d<=mp[p]){
                        d = mp[p];
                        lastp = p;
                    }
                }
            }
        }
        int t = 10*(d-1) + lastp;
        chmin(ans,t);
    }
    cout << ans << '\n';
}
int main(int argc, char *argv[]){
  if(argc>1 && argv[1][0]=='D'){DEBUG = 1;}
  solve();
  return 0;
}