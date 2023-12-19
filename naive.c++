#include<bits/stdc++.h>
using namespace std;

vector<int>* naive(string& text , string& pattern){

    vector<int>* ans = new vector<int>();
    for(size_t i{} ; i <= text.size()-pattern.size() ; i++){
        size_t count{};

        for(size_t j{} ; j<pattern.size() ; j++){
            if(pattern[j] == text[j+i])
                count++;
            else
                break;
        }

        if(count == pattern.size())
            (*ans).push_back(i);
    }
    
    return ans;
}

int main(){

    string text  = "AABAACAADAABAAABAA" , pattern = "AABA";
    vector<int>* ans = naive(text , pattern);
    cout<<"Pattern in a string start from positions : ";
    for(auto a : *ans)
        cout<<a<<",";

}