#include <iostream>

using namespace std;

struct vector{
    int a[100000];
    string b[100000];
    int top;

    vector(){
        top=0;
    }

    void push(int c,string d){
        a[top]=c;
        b[top]=d;
        top++;
    }

    void sort(){
        int e;
        string l;

        for(int i=0;i<top;i++){
            for(int j=top-1;j>=i+1;j--){
                if(a[j]<a[j-1]){
                    e=a[j];
                    a[j]=a[j-1];
                    a[j-1]=e;
                    l=b[j];
                    b[j]=b[j-1];
                    b[j-1]=l;
                }
            }
        }
    }

    void out(int f){
        cout<<a[f]<<" "<<b[f]<<endl;
    }
};

int main(){
    vector vect;
    int in;
    int p=0;
    string bi;

    while(cin>>in){
        cin>>bi;
        vect.push(in,bi);
        p++;
    }

    vect.sort();

    for(int i=0;i<p;i++){
        vect.out(i);
    }

    return 0;
}