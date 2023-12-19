#include<bits/stdc++.h>
using namespace std;

vector<int>* KMP(string& text , string& pattern){

    vector<int>* ans = new vector<int>();
    
    vector<int> lsp(pattern.size() , 0);
    
    {
        int i{1},len{};
        while(i<pattern.size()){
            if(pattern[len] == pattern[i])
                len++ , lsp[i] = len , i++;
            else if(len == 0)
                i++;
            else    
                len = lsp[len-1];
        }
    }

    {
        int i{},len{};
        while(i<text.size()){
            if(pattern[len] == text[i])
                len++,i++;
            else if(len == 0)
                i++;
            else
                len = lsp[len-1];

            if(len == pattern.size()){
                (*ans).push_back(i-pattern.size());
                len = lsp[len-1];
                // i++;
            }
        }
    }
    
    return ans;

}

int main(){
    
    string text  = "AAAAAAAAA" , pattern = "AAA";
    // string text  = "AABAACAADAABAAABAA" , pattern = "AABA";
    vector<int>* ans = KMP(text , pattern);
    cout<<"Pattern in a string start from positions : ";
    for(auto a : *ans)
        cout<<a<<",";

}