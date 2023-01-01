#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define Liny "Yes\n"
#define Linn "No\n"
bool DEBUG = 0;
// https://atcoder.jp/contests/abc278/tasks/abc278_c
// 有向な連結リストを構成する
void solve(){ 
    int N,Q; cin >> N >> Q;
    map< int, map<int,int> > follow;
    REP(count,Q){
        int t,a,b; cin >> t >> a >> b;
        if(t==1){
            follow[a][b] = 1;
            continue;
        }
        if(t==2){
            follow[a][b] = 0;
            continue;
        }
        bool isSougo = follow[a][b]>0 && follow[b][a];
        cout << (isSougo?Liny:Linn);
    }
}
int main(int argc, char *argv[]){
  if(argc>1 && argv[1][0]=='D'){DEBUG = 1;}
  solve();
  return 0;
}