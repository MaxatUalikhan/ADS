#include <iostream>

using namespace std;

struct elem{
    int val;
    elem *prev;
    elem *next;

    elem(int a){
        val=a;
        prev=NULL;
        next=NULL;
    }
};

struct que{
    private:
        int count;
        elem *first;
        elem *last;

    public:
    que(){
        first=NULL;
        last=NULL;
        count=0;
    }

    void push(int x){
        count++;
        elem *added=new elem(x);
        if(first==NULL){
            first=added;
            last=added;
        }
        else{
            last->next=added;
            added->prev=last;
            last=added;
        }
    }

    int pop(){
        int a;
        if(first!=NULL){
            count--;
            a=first->val;
            first=first->next;
            if(first!=NULL){
                first->prev=NULL;
            }
        }
        return a;
    }

    int front(){
        return first->val;
    }

    int size(){
        return count;
    }

    void clear(){
        count=0;
        while(first!=NULL){
            first=first->next;
            if(first!=NULL){
                first->prev==NULL;
            }
        }
    }
};

int main(){
    que q;
    string a;
    int b,c;

    while(cin>>a){
        if(a=="push"){
            cin>>b;
            q.push(b);
            cout<<"ok"<<endl;
        }
        
        else if(a=="pop"){
            if(q.size()!=0){
                c=q.pop();
                cout<<c<<endl;
            }
            else{
                cout<<"error"<<endl;
            }
        }
        
        else if(a=="front"){
            if(q.size()!=0){
                c=q.front();
                cout<<c<<endl;
            }
            else{
                cout<<"error"<<endl;
            }
        }
        
        else if(a=="size"){
            c=q.size();
            cout<<c<<endl;
        }
        
        else if(a=="clear"){
            cout<<"ok"<<endl;
            q.clear();
        }
        
        else if(a=="exit"){
            cout<<"bye"<<endl;
            break;
        }
    }
    
    return 0;
}