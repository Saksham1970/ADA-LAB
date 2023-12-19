#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
        Node *left,*right;
        char ch;
        int freq;

        Node(char ch , int freq)
            :ch(ch),freq(freq),left(nullptr),right(nullptr){}

        Node(int freq , Node *left, Node *right)
            :ch('_'),freq(freq),left(left),right(right){}

};

class cmp{
    public:
    bool operator()(Node* a ,Node* b){
            return a->freq > b->freq;
    }
};

Node* buildTree(vector<char>& ch , vector<int>& freq){

    priority_queue<Node* , vector<Node*> , cmp> minheap;
    for(int i{} ; i<freq.size() ; i++)
        minheap.push(new Node(ch[i],freq[i]));
    
    while(minheap.size() > 1){
        Node* a = minheap.top();
        minheap.pop();
        Node* b = minheap.top();
        minheap.pop();

        minheap.push( new Node( a->freq + b->freq , a , b ) );
    }

    return minheap.top();

}
void decode(Node* head , string& code , vector<pair<char , string>>& ans){

    if(head->left == nullptr){
        ans.push_back({head->ch , code});
        return;
    }
    code.push_back('0');
    decode(head->left , code , ans);
    code.pop_back();
    code.push_back('1');
    decode(head->right , code , ans);
    code.pop_back();

}
void printAns(vector<pair<char , string>>& ans){
    for(auto i : ans)
        cout<<i.first<<" : "<<i.second<<endl;
}

int main(){

    vector<pair<char , string>> ans;
    vector<char> ch = {'a','b','c','d','e','f'};
    vector<int> freq = {5,9,12,13,16,45};
    string code;
    cout<<"------------------------------------------------------------"<<endl;
    cout<<"Build huffman code for for the following table "<<endl;
    cout<<"------------------------------------------------------------"<<endl;
    for(int i{} ; i<ch.size() ; i++)
        cout<<ch[i]<<" : "<<freq[i]<<endl;
    cout<<"------------------------------------------------------------"<<endl;
    
    Node* head = buildTree(ch , freq);
    decode(head, code , ans);

    cout<<"Printing huffman code "<<endl;
    cout<<"------------------------------------------------------------"<<endl;
    printAns(ans);
    cout<<"------------------------------------------------------------"<<endl;
    
}