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
        elem *first;
        elem *last;
        int count;
    
    public:
    que(){
        first=NULL;
        last=NULL;
        count=0;
    }

    void add(int a){
        count++;
        elem *added=new elem(a);
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

    int size(){
        return count;
    }

    int front(){
        return first->val;
    }

    void pop(){
        count--;
        first=first->next;
        if(first!=NULL){
            first->prev=NULL;
        }
    }
};

int main(){
    que a1,a2;
    int b,count=0;

    for(int i=0;i<5;i++){
        cin>>b;
        a1.add(b);
    }
    for(int i=0;i<5;i++){
        cin>>b;
        a2.add(b);
    }

    while(a1.size()!=0 && a2.size()!=0){
        count++;
        if(count==1000001){
            cout<<"botva";
            break;
        }
        else if(a1.front()==0 && a2.front()==9){
            a1.add(a1.front());
            a1.add(a2.front());
            a1.pop();
            a2.pop();
        }
        else if(a1.front()==9 && a2.front()==0){
            a2.add(a1.front());
            a2.add(a2.front());
            a1.pop();
            a2.pop();
        }
        else if(a1.front()>a2.front()){
            a1.add(a1.front());
            a1.add(a2.front());
            a1.pop();
            a2.pop();
        }
        else if(a1.front()<a2.front()){
            a2.add(a1.front());
            a2.add(a2.front());
            a1.pop();
            a2.pop();
        }
    }

    if(count!=1000001){
        if(a2.size()==0){
            cout<<"first "<<count;
        }
        else{
            cout<<"second "<<count;
        }
    }

    return 0;
}