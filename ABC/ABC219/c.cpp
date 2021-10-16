#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define ALL(a) (a).begin(),(a).end()
bool DEBUG = 0;
template<class T> void dprint(T s){
  if(DEBUG){ cout << s << "\n"; }
}
// https://atcoder.jp/contests/abc219/tasks/abc219_c
// 制約が緩いので
// neo-abc -> abc と
// 変換したものをソートしてから
// abc -> neo-abc で出力すればいいかな

map<char,char> mp; // old -> neo
map<char,char> rmp; // neo -> old

string convertToOldABC(string s){
    REP(i,s.size()){
        s[i] = rmp[ s[i] ];
    }
    return s;
}
string convertToNeoABC(string s){
    REP(i,s.size()){
        s[i] = mp[ s[i] ];
    }
    return s;
}

void solve(){ 
    string x; cin >> x;
    REP(i,x.size()){
        char oldAlpabet = (char)('a'+i);
        mp[ oldAlpabet ] = x[i];
        rmp[ x[i] ] = oldAlpabet;
    }
    int N; cin >> N;
    vector<string> v(N);
    REP(i,N){
        string s; cin >> s;
        v[i] = convertToOldABC(s);
    }
    sort(ALL(v));
    for(auto s:v){
        cout << convertToNeoABC(s) << '\n';
    }
}
int main(int argc, char *argv[]){
  if(argc>1 && argv[1][0]=='D'){ DEBUG = 1;}
  solve();
  return 0;
}