#include<bits/stdc++.h>
#define FIO() ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
struct node{
    bool endmark;
    node *next[26+1];
    node(){
        endmark=false;
        for(int i=0;i<26;i++)
            next[i]=NULL;
    }
};
void insert(node *root,string st){
    node *cur_node=root;
    for(int i=0;i<st.size();i++){
        int id=st[i]-'a';
        if(cur_node->next[id]==NULL)
            cur_node->next[id]=new node();
        cur_node=cur_node->next[id];
    }
    cur_node->endmark=true;
}
bool search(node *root,string st){
    node *cur_node=root;
    for(int i=0;i<st.size();i++){
        int id=st[i]-'a';
        if(cur_node->next[id]==NULL)
            return false;
        cur_node=cur_node->next[id];
    }
    return cur_node->endmark;
}
bool isEmpty(node *root){
    for(int i=0;i<26;i++){
        if(root->next[i])
            return false;
    }
    return true;
}
node *remove(node *root,string st,int depth=0){///remove particular string from the trie
    if(!root)return NULL;
    if(depth==st.size()){
        if(root->endmark)
            root->endmark=false;

        if(isEmpty(root)){
            delete(root);
            root=NULL;
        }
        return root;
    }

    int id=st[depth]-'a';
    root->next[id]=remove(root->next[id],st,depth+1);

    if(isEmpty(root)&&root->endmark==false){
        delete(root);
        root=NULL;
    }
    return root;
}
void del(node *cur_node){///destroy trie
    for(int i=0;i<26;i++){
        if(cur_node->next[i])
            del(cur_node->next[i]);
    }
    delete(cur_node);
}
int main(){
    FIO()

    node *root=new node();
    int n;
    cin>>n;
    string s[n];
    for(int i=0;i<n;i++){
        cin>>s[i];
        insert(root,s[i]);
    }
    int q;
    cin>>q;
    string str;
    while(q--){
        cin>>str;
        if(search(root,str))cout<<"Found\n";
        else cout<<"Not Found\n";
    }
    remove(root,"hero");
    if(search(root,"hero"))cout<<"Found\n";
    else cout<<"Not Found\n";
    del(root);///destroy trie
    return 0;
}

