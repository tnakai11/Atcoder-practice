#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
bool DEBUG = 0;
template<class T> void dprint(T s){
  if(DEBUG){ cout << s << "\n"; }
}
// https://atcoder.jp/contests/abc250/tasks/abc250_c
// map で値 <-> 位置の対応を控えておいて最後に出力
// 右端に注意
void solve(){ 
    int N,Q; cin >> N >> Q;
    map<int,int> valOf,locOf;
    for(int i=1;i<=N;++i){
        valOf[i] = i;
        locOf[i] = i;
    }
    REP(q,Q){
        int valX; cin >> valX;
        int locX = locOf[valX];
        int locY = (locX<N?locX+1:locX-1);
        int valY = valOf[locY];
        locOf[valX] = locY;
        locOf[valY] = locX;
        valOf[locX] = valY;
        valOf[locY] = valX;
    }
    vector<int> a(N+1);
    for(int i=1;i<=N;++i){
        cout << valOf[i] << (i<N?' ':'\n');
    }
}
int main(int argc, char *argv[]){
  if(argc>1 && argv[1][0]=='D'){DEBUG = 1;}
  solve();
  return 0;
}