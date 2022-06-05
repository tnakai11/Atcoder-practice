#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define ALL(a) (a).begin(),(a).end()
#define Liny "Yes\n"
#define Linn "No\n"
bool DEBUG = 0;
template<class T> void dprint(T s){
  if(DEBUG){ cout << s << "\n"; }
}
// https://atcoder.jp/contests/abc253/tasks/abc253_a
// (a<=b && b<=c) or (c<=b && b<=a)
// 一般的に解くならソートかなあ
void solve(){ 
    vector<int> a(3),v(3);
    REP(i,3){
        int x; cin >> x;
        a[i] = x;
        v[i] = x;
    }
    sort(ALL(v));
    string ans = Linn;
    if(a[1]==v[1]){
        ans = Liny;
    }
    cout << ans;
}
int main(int argc, char *argv[]){
  if(argc>1 && argv[1][0]=='D'){DEBUG = 1;}
  solve();
  return 0;
}