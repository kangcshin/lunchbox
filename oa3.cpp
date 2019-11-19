// SUBSTRINGS WITH EXACTLY K DISTINCT CHARS

#include <string>
#include <iostream>
#include <unordered_map>

using namespace std;

int most_k_chars(string &s, int k){
    if(s.size() == 0) return 0;

    unordered_map<char,int> table;
    int num = 0, left = 0;
    
    for(int i = 0; i < s.size(); i++){
        table[s[i]] += 1;
        while(table.size() > k){
            table[s[left]] -= 1;
            if(table[s[left]] == 0) table.erase(s[left]);
            left += 1;
        }
        num += i - left + 1;
    }
    return num;
}

int exact_k_chars(string &s, int k){
    return most_k_chars(s,k) - most_k_chars(s,k-1);
}

int main(){
    string s1 = "pqpqs";
    cout << exact_k_chars(s1, 2) << endl;
}