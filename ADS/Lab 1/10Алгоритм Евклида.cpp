#include <iostream>

using namespace std;

struct GCD{
    int gcd(int a,int b){
        while(a!=0 && b!=0){
            if(a>b){
                a=a%b;
            }
            else{
                b=b%a;
            }
        }

        return a+b;
    }
};

int main(){
    GCD x;
    int a,b,c;
    cin>>a>>b;
    
    c=x.gcd(a,b);
    cout<<c;

    return 0;
}