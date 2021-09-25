#include <iostream>

using namespace std;

int toInt(string a){
    int b=0;
    for(int i=0;i<a.size();i++){
        b=b*10+(a[i]-48);
    }
    return b;
}

struct elem{
    int val;
    elem *prev;
    elem *next;

    elem(int x){
        val=x;
        prev=NULL;
        next=NULL;
    }
};

struct st{
    elem *last;

    st(){
        last=NULL;
    }

    void add(int x){
        elem *added=new elem(x);
        if(last==NULL){
            last=added;
        }
        else{
            last->next=added;
            added->prev=last;
            last=added;
        }
    }

    int back(){
        int a=last->val;
        last=last->prev;
        if(last!=NULL){
            last->next=NULL;
        }
        return a;
    }
};

int main(){
    string a;
    st b;
    int c=0;

    while(cin>>a){
        if(a=="+"){
            c=b.back()+b.back();
            b.add(c);
        }
        else if(a=="-"){
            c=b.back()-b.back();
            c=-c;
            b.add(c);
        }
        else if(a=="*"){
            c=b.back()*b.back();
            b.add(c);
        }
        else{
            b.add(toInt(a));
        }
    }

    cout<<b.back();
    return 0;
}