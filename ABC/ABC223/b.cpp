#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define ALL(a) (a).begin(),(a).end()
bool DEBUG = 0;
template<class T> void dprint(T s){
  if(DEBUG){ cout << s << "\n"; }
}
// https://atcoder.jp/contests/abc223/tasks/abc223_b
// 全パターン列挙で良さそう O(N^2)
void solve(){ 
    string s; cin >> s;
    int N = s.size();
    vector<string> v(N);
    REP(i,N){
        string t = s.substr(0,i);
        string u = s.substr(i,N-i);
        v[i] = u + t;
    }
    sort(ALL(v));
    cout << v[0] << '\n';
    cout << v[N-1] << '\n';
}
int main(int argc, char *argv[]){
  if(argc>1 && argv[1][0]=='D'){ DEBUG = 1;}
  solve();
  return 0;
}