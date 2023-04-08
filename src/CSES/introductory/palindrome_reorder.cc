#include<bits/stdc++.h>
using namespace std;int main(){string z,f,s;getline(cin,z);int a[26]={0},x=0;char l;for(auto c:z)a[c-'A']++;for(int i=0;i<26;i++){if(a[i]%2){l='A'+i;x++;}}if(x>1)cout<<"NO SOLUTION"<<endl;else{for(int i=0;i<26;i++){string v(a[i]/2,'A'+i);f+=v;s=v+s;}if(x)f+=l;cout<<f<<s<<endl;}}
