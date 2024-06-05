#include<bits/stdc++.h>
#define FIO() ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
struct node{
    int roll;
    node *next;
};
node *root=NULL;
void append(int roll){///add node
    if(root==NULL)///If the list is empty
    {
        root=new node();///create new node in root
        root->roll=roll;
        root->next=NULL;
    }
    else{
        node *current_node=root;
        while(current_node->next!=NULL)///Find the last node
        {
            current_node=current_node->next;///go to next address
        }
        node *newnode=new node();
        newnode->roll=roll;
        newnode->next=NULL;
        current_node->next=newnode;///link the last node with new node

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
void add_node_in_middle(int roll1,int roll2){///add node in middle
    node *current_node=root;
    while(current_node->roll!=roll1){
        current_node=current_node->next;
    }
    node *newnode=new node();
    newnode->roll=roll2;
    newnode->next=current_node->next;
    current_node->next=newnode;
}
void delete_node(int roll){///delete any node
    node *current_node=root;
    node *previous_node=NULL;
    while(current_node->roll!=roll) ///Searching node
    {
        previous_node=current_node;///Save the previous node
        current_node=current_node->next;
    }
    if(current_node==root){ ///Delete root
        node *temp=root;
        root=root->next;
        delete(temp);
    }
    else///delete non-root node
    {
        previous_node->next=current_node->next; ///previous node points the current node's next node
        delete(current_node);///free current node
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
    add_node_in_middle(4,5);
    print();
    delete_node(4);
    print();
}
