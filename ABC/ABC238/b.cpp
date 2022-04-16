#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
template<class T> void chmax(T& a, T b){ if(a<b){a=b;} }
template<class T> void chmin(T& a, T b){ if(a>b){a=b;} }
bool DEBUG = 0;
template<class T> void dprint(T s){
  if(DEBUG){ cout << s << "\n"; }
}
// https://atcoder.jp/contests/abc238/tasks/abc238_b
// mod に注意してシミュレーションすればOK
void solve(){ 
    int N; cin >> N;
    vector<int> cut(400,0);

    int angle = 0;
    cut[angle] = 1;
    REP(i,N){
        int a; cin >> a;
        angle += a;
        angle %= 360;
        cut[angle] = 1;
    }

    int ans = 0;
    int temp = 0;
    for(int turn=0;turn<2;++turn){
        for(int a=0;a<360;++a){
            if(cut[a]==1){
                chmax(ans,temp);
                temp = 0;
            }
            ++temp;
        }
    }

    chmin(ans,360);
    cout << ans << '\n';
}
int main(int argc, char *argv[]){
  if(argc>1 && argv[1][0]=='D'){DEBUG = 1;}
  solve();
  return 0;
}