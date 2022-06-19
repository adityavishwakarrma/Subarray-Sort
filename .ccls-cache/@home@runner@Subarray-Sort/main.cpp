#include <bits/stdc++.h>
using namespace std;

bool outOfOrder(vector<int> arr,int i){
  int n = arr.size();
  
  if(i<n-1 && arr[i] > arr[i+1]){
    return 1;
  } 
  if(i>0 && arr[i] < arr[i-1]){
    return 1;
  }

  return 0;
}

pair<int,int> subarraySort(vector<int> arr) {
  int n = arr.size();
  
  int l=0, r=n-1;
  
  while(l<n-1){
    if(outOfOrder(arr, l)){
      break;
    }
    l++;
  }

  while(r>=1){
    if(outOfOrder(arr, r)){
      break;
    }
    r--;
  }
  
  //already sorted
  if(l==n-1){
    return {-1,-1};
  }

  unordered_map<int, int> leftMap;
  for(int i=0; i<l; i++){
    leftMap[arr[i]] = i;
  }

  unordered_map<int, int> rightMap;
  for(int i=n-1; i>r; i--){
    rightMap[arr[i]] = i;
  }
  
  for(auto e : leftMap){
    if(arr[r] < e.first){
      if(l > e.second)
        l=e.second;
    }
  }

  for(auto e : rightMap){
    if(arr[l] > e.first){
      if(r < e.second)
        r = e.second;
    }
  }
  
  return {l,r};
}


int main() {
  cout << "Hello World!";
  vector<int> arr = {1, 2, 3, 4, 5, 8, 6, 7, 9, 10, 11};
  auto p = subarraySort(arr);
  cout<< p.first <<" and "<<p.second <<endl;

  return 0;
}