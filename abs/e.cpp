#include <bits/stdc++.h>
using namespace std;

int main () {
  int a,b,c,n,s,t=0;
  cin>>a>>b>>c>>n;
  for (int i=0;i<=a;i++) {
    for(int j=0;j<=b;j++) {
      for(int k=0;k<=c;k++) {
        s=500*i+100*j+50*k;
        t+=(s==n);
      }
    }
  }
  cout<<t<<endl;
}
