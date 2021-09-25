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

struct deck{
    private:
        int count;
        elem *first;
        elem *last;

    public:
    deck(){
        first=NULL;
        last=NULL;
        count=0;
    }

    void push_front(int x){
        count++;
        elem *added=new elem(x);
        if(first==NULL){
            first=added;
            last=added;
        }
        else{
            first->prev=added;
            added->next=first;
            first=added;
        }
    }

    void push_back(int x){
        count++;
        elem *added=new elem(x);
        if(last==NULL){
            first=added;
            last=added;
        }
        else{
            last->next=added;
            added->prev=last;
            last=added;
        }
    }

    int pop_front(){
        int d;
        d=first->val;
        count--;
        if(count==0){
            first=NULL;
            last=NULL;
        }
        else{
            first=first->next;
            first->prev=NULL;
        }
        return d;
    }

    int pop_back(){
        int d;
        d=last->val;
        count--;
        if(count==0){
            last=NULL;
            first=NULL;
        }
        else{
            last=last->prev;
            last->next=NULL;
        }
        return d;
    }

    int front(){
        return first->val;
    }

    int back(){
        return last->val;
    }

    int size(){
        return count;
    }

    void clear(){
        while(count!=0){
            count--;
            if(count==0){
                first=NULL;
                last=NULL;
            }
            else{
                first=first->next;
                first->prev=NULL;
            }
        }
    }
};

int main(){
    deck dec;
    string a;
    int b,c;

    while(cin>>a){
        if(a=="push_front"){
            cin>>b;
            dec.push_front(b);
            cout<<"ok"<<endl;
        }
        
        else if(a=="push_back"){
            cin>>b;
            dec.push_back(b);
            cout<<"ok"<<endl;
        }
        
        else if(a=="pop_front"){
            if(dec.size()!=0){
                c=dec.pop_front();
                cout<<c<<endl;
            }
            else{
                cout<<"error"<<endl;
            }
        }
        
        else if(a=="pop_back"){
            if(dec.size()!=0){
                c=dec.pop_back();
                cout<<c<<endl;
            }
            else{
                cout<<"error"<<endl;
            }
        }
        
        else if(a=="front"){
            if(dec.size()!=0){
                c=dec.front();
                cout<<c<<endl;
            }
            else{
                cout<<"error"<<endl;
            }
        }
        
        else if(a=="back"){
            if(dec.size()!=0){
                c=dec.back();
                cout<<c<<endl;
            }
            else{
                cout<<"error"<<endl;
            }
        }
        
        else if(a=="size"){
            c=dec.size();
            cout<<c<<endl;
        }
        
        else if(a=="clear"){
            cout<<"ok"<<endl;
            dec.clear();
        }
        
        else if(a=="exit"){
            cout<<"bye"<<endl;
            break;
        }
    }

    return 0;
}