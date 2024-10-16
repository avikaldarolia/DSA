#include <iostream>
using namespace std;
int main() {
    long long int n;
    cin>>n;
   
    while(n!=1){
         cout<<" "<<n;
        if(n%2!=0){
            n=n*3 + 1;
            // cout<<" "<<n;
        }
        else{
            n = n/2;
            // cout<<" "<<n;
        }
    }
     cout<<" "<<1;
}