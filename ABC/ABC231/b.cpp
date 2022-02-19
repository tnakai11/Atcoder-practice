#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define ALL(a) (a).begin(),(a).end()
bool DEBUG = 0;
template<class T> void dprint(T s){
  if(DEBUG){ cout << s << "\n"; }
}
// https://atcoder.jp/contests/abc231/tasks/abc231_b
// map で OK
// ソートして数え上げる方法もありはする
void solve(){ 
    int N; cin >> N;
    vector<string> s(N);
    REP(i,N) cin >> s[i];
    sort(ALL(s));
    string ans = "";
    int ansCount = 0;
    int count = 0;
    REP(i,N){
        if(i==0 || s[i-1]!=s[i]){
            if(ansCount<count){
                ansCount = count;
                ans = s[ max(0,i-1) ];
            }
            count = 0;
        }
        ++count;
    }
    if(ansCount<count){
        ansCount = count;
        ans = s[N-1];
    }
    cout << ans << '\n';
}
int main(int argc, char *argv[]){
  if(argc>1 && argv[1][0]=='D'){ DEBUG = 1;}
  solve();
  return 0;
}