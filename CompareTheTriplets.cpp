#include <bits/stdc++.h>
#include <iostream>
using namespace std;

int main(){

    int a[3],b[3];
    int a1=0,  b1=0;
    int i,j;

    for (i=0;i<3;i++){
        cin>>a[i];
    }
    for (j=0;j<3;j++){
        cin>>b[j];

    }
for(i=0,j=0;i<3,j<3;i++,j++){
    if(a[i]>b[j])
    a1++;
    if(b[j]>a[i])
    b1++;
}
    cout<<a1<<" "<<b1<<endl;


    return 0;
}
