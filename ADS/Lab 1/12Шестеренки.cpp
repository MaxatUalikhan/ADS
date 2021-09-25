#include <iostream>

using namespace std;

struct LCM{
    int lcm(int a,int b){
        int c;

        if(a>b){
            c=a;
            while(a%b!=0){
                a+=c;
            }
            return a;
        }
    
        else{
            c=b;
            while(b%a!=0){
                b+=c;
            }
            return b;
        }
}
};

int main(){
    LCM x;
    int a,b,c;
    cin>>a>>b;

    c=x.lcm(a,b);
    cout<<c;

    return 0;
}