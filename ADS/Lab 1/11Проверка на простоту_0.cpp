#include <iostream>

using namespace std;

struct prime{
    bool ifPrime(int a){
        for(int i=2;i*i<=a;i++){
            if(a%i==0){
                return false;
            }
        }

        return true;
    }
};

int main(){
    prime x;
    int a;
    cin>>a;

    if(x.ifPrime(a)){
        cout<<"prime";
    }
    else{
        cout<<"composite";
    }

    return 0;
}