#include <iostream>

using namespace std;

struct elem{
    char val;
    elem *prev;
    elem *next;

    elem(char a){
        val=a;
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

    void add(char a){
        count++;
        elem *added=new elem(a);
        if(last==NULL){
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

    void pop(){
        count--;
        if(last!=NULL){
            last=last->prev;
            if(last!=NULL){
                last->next=NULL;
            }
        }
    }

    int top(){
        return last->val;
    }

    bool empty(){
        if(count==0){
            return true;
        }
        else{
            return false;
        }
    }
};

bool check(string a){
    st x;

    for(int i=0;i<a.size();i++){
        if(a[i]=='{' || a[i]=='[' || a[i]=='('){
            x.add(a[i]);
        }
        else{
            if(x.size()==0){
                return false;
            }
            if(a[i]=='}' && x.top()!='{'){
                return false;
            }
            if(a[i]==']' && x.top()!='['){
                return false;
            }
            if(a[i]==')' && x.top()!='('){
                return false;
            }
            x.pop();
        }
    }

    return x.empty();
}


int main(){
    string a;
    cin>>a;

    if(check(a)){
        cout<<"yes";
    }
    else{
        cout<<"no";
    }

    return 0;
}