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

struct goblin{
    elem *first;
    elem *last;
    elem *middle;
    elem *helper;
    int count;

    goblin(){
        count=0;
        first=NULL;
        last=NULL;
        middle=NULL;
        helper=NULL;
    }

    void addplus(int b){
        count++;
        elem *added=new elem(b);
        if(first==NULL){
            first=added;
            last=added;
        }
        else{
            last->next=added;
            added->prev=last;
            last=added;
            if(count==2){
                middle=last;
            }
            if(count%2!=0){
                middle=middle->next;
            }
        }
    }

    void addmult(int b){
        count++;
        elem *added=new elem(b);
        if(first==NULL){
            first=added;
            last=added;
        }
        else if(count==2){
            last->next=added;
            added->prev=last;
            last=added;
            middle=last;
        }
        else{
            helper=middle->prev;
            added->next=middle;
            added->prev=helper;
            middle->prev=added;
            helper->next=added;
            helper=NULL;
            if(count%2==0){
                middle=middle->prev;
            }

        }
    }

    int show(){
        count--;
        int a=first->val;
        first=first->next;
        if(first!=NULL){
            first->prev=NULL;
            if(count%2!=0 && count>=2){
                middle=middle->next;
            }
            if(count<2){
                middle=NULL;
            }
        }
        return a;
    }
};

int main(){
    int a,b;
    string c;
    goblin d;
    cin>>a;
    
    for(int i=0;i<a;i++){
        cin>>c;
        if(c=="+"){
            cin>>b;
            d.addplus(b);
        }
        else if(c=="*"){
            cin>>b;
            d.addmult(b);
        }
        else{
            b=d.show();
            cout<<b<<endl;
        }
    }

    return 0;
}