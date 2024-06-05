#include<bits/stdc++.h>
#define FIO() ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
struct node{
    int roll;
    node *prev,*next;
};
node *root=NULL,*tail;
void append(int roll){
    if(root==NULL){
        root=new node();
        root->roll=roll;
        root->next=NULL;
        root->prev=NULL;
        tail=root;
    }
    else{
        node *newnode=new node();
        newnode->roll=roll;
        newnode->next=NULL;
        newnode->prev=tail;
        tail->next=newnode;///add the new node after tail node
        tail=tail->next; ///move tail pointer forward
    }
}
void print(){///print value of linked list
    node *current_node=root;
    while(current_node!=NULL){
        cout<<current_node->roll<<" ";
        current_node=current_node->next;
    }
    cout<<endl;
}
void delete_node(int roll){
    node *current_node=root;
    while(current_node->roll!=roll){
        current_node=current_node->next;
    }
    if(current_node==root){
        node *temp=root;
        root=root->next;
        root->prev=NULL;
        delete(temp);
    }
    else{
        node *previous_node=current_node->prev;
        previous_node->next=current_node->next;
        
        if (current_node->next != NULL)
            current_node->next->prev = previous_node;

        delete(current_node);
    }
}
int main(){
    FIO()

    int n;
    cin>>n;
    int x;
    for(int i=0;i<n;i++){
        cin>>x;
        append(x);
    }
    print();
    delete_node(4);
    print();
}

