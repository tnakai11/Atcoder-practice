#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define Liny "Yes\n"
#define Linn "No\n"
bool DEBUG = 0;
template<class T> void dprint(T s){
  if(DEBUG){ cout << s << "\n"; }
}
// https://atcoder.jp/contests/abc244/tasks/abc244_d
// RGB の並べ替えなので実現する状態は高々3! = 6通り
// A ... 123
// B ... 132
// C ... 213
// D ... 231
// E ... 312
// F ... 321

// 1回操作
// A -> B C F
// 2回操作
// B -> A D E
// C -> A D E
// F -> A D E
// 3回操作
// A -> B C F
// D -> B C F
// E -> B C F
// ...

// 偶数回操作すると A D E のいずれかになる

// AC
// 解説曰く転倒数により一般化できるとか

void solve(){ 
    string s[4];
    for(int i=1;i<=3;++i) cin >> s[i];
    string T = "";
    REP(i,3){
        string temp; cin >> temp;
        T += temp;
    }
    bool ok = false;
    vector< vector<int> > vs;
    vs.push_back( {1,2,3} );
    vs.push_back( {2,3,1} );
    vs.push_back( {3,1,2} );
    for(auto v: vs){
        string target = "";
        for(auto index:v){
            target += s[index];
        }
        dprint(target);
        if(target==T){
            ok = true;
        }
    }
    cout << (ok?Liny:Linn);
}
int main(int argc, char *argv[]){
  if(argc>1 && argv[1][0]=='D'){DEBUG = 1;}
  solve();
  return 0;
}