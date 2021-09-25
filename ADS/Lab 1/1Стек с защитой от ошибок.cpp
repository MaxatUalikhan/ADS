#include <iostream>

using namespace std;

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
    private:
        elem *last;
        int count;
    
    public:
    st(){
        last=NULL;
        count=0;
    }

    void clear(){
        while(last!=NULL){
            last=last->prev;
            if(last!=NULL){
                last->next==NULL;
            }
        }
        count=0;
    }

    int size(){
        return count;
    }

    int back(){
        return last->val;
    }

    int pop(){
        count--;
        int a;
        if(last!=NULL){
            a=last->val;
            last=last->prev;
            if(last!=NULL){
                last->next=NULL;
            }
            return a;
        }
    }

    void push(int b){
        count++;
        elem *added=new elem(b);
        if(last==NULL){
            last=added;
        }
        else{
            last->next=added;
            added->prev=last;
            last=added;
        }

    }
};

int main(){
    st stak;
    string a;
    int b,e;

    while(cin>>a){
        if(a=="push"){
            cin>>b;
            cout<<"ok"<<endl;
            stak.push(b);
        }
        
        else if(a=="pop"){
            if(stak.size()!=0){
                e=stak.pop();
                cout<<e<<endl;
            }
            else{
                cout<<"error"<<endl;
            }
        }
        
        else if(a=="back"){
            if(stak.size()!=0){
                e=stak.back();
                cout<<e<<endl;
            }
            else{
                cout<<"error"<<endl;
            }
        }
        
        else if(a=="size"){
            e=stak.size();
            cout<<e<<endl;
        }
        
        else if(a=="clear"){
            cout<<"ok"<<endl;
            stak.clear();
        }
        
        else if(a=="exit"){
            cout<<"bye"<<endl;
            break;
        }
    }

    return 0;
}