#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define Liny "Yes\n"
#define Linn "No\n"
#define pci pair<char,int>
#define MP make_pair
bool DEBUG = 0;
template<class T> void dprint(T s){
  if(DEBUG){ cout << s << "\n"; }
}
// https://atcoder.jp/contests/abc259/tasks/abc259_c
// S,T の両方を圧縮して同じ文字列が得られるかどうか
// 圧縮ルール X..X -> XX
// WA 
// T はいじれない
// S,T をトークン化する
vector<pci> func(string s){
    vector<pci> v;
    int N = s.size();
    char x = ' ';
    int count = 0;
    REP(i,N){
        char c = s[i];
        if(x==c){
            count += 1;
        }else{
            v.emplace_back(MP(x,count));
            x = c;
            count = 1;
        }
    }
    v.emplace_back(MP(x,count));
    return v;
}

bool solve(){ 
    string s,t; cin >> s >> t;
    vector<pci> a = func(s);
    vector<pci> b = func(t);
    if(a.size()!=b.size()) return false;
    REP(i,a.size()){
        if(a[i].first!=b[i].first) return false;
        if(a[i].second>b[i].second) return false;
        if(a[i].second==b[i].second) continue;
        if(a[i].second==1) return false;
    }
    return true;
}
int main(int argc, char *argv[]){
  if(argc>1 && argv[1][0]=='D'){DEBUG = 1;}
  cout << (solve()?Liny:Linn);
  return 0;
}