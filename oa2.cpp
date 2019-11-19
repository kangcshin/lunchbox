// TWO SUMS - UNIQUE PAIRS




#include <unordered_map>
#include <algorithm>
#include <vector>
using namespace std;
int findUniquePairs(vector<int>&arr, int target){
    unsigned int size = arr.size();
    if(!size) return 0;
    sort(arr.begin(), arr.end());
    unordered_map<int, int> umap;
    int pairs = 0;

    for(unsigned int i =0; i < size-1&& arr[i] < target;++i){
        for(unsigned int j = i+1; j<size && arr[j] < target; ++j){
            if(arr[i]+arr[j] == target){
                if(umap.find(arr[i])==umap.end() && umap.find(arr[j])==umap.end()){
                    umap[arr[j]]=arr[i];
                    umap[arr[i]]=arr[j];
                    ++pairs;
                }
            }

        }
    }   
    return pairs;
}
int main(){
    int targets[5]{47,2,6,6,2};
    int solutions[5]{2,1,1,1,0};
    vector<int>arr{1,1,2,45,46,46};
    vector<int>arr2{1,1};
    vector<int>arr3{1,5,1,5};
    vector<int>arr4{1,5,1,1};
    vector<int>arr5{1,2,4,8};
    int i =0; 
    vector<vector<int>>problems{arr,arr2,arr3,arr4,arr5};
    for(auto p: problems){
        solutions[i]==findUniquePairs(p,targets[i])? cout << "correct\n":cout<<"incorrect\n";
        ++i;
    }   
}   

