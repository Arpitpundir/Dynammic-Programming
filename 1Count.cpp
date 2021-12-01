#include<bits/stdc++.h>
using namespace std;

int main(){
  
  int n, k;
  cin>>n>>k;
  vector<int> a;

  for(int i = 0;i < n;i++){

    int temp;
    cin>>temp;
    a.push_back(temp);
  }

  int left = 0, right = 0, zero = 0, ans = 0, ansL = 0, ansR = 0;

 

  while(right < n){

       if(a[right] == 0)
       zero++;

    while(zero > k && left <= right){

      if(a[left] == 0){

        zero--;
      }

      left++;
    }

    if(a[left]){

      if(ans < right - left +1){

        ans = right-left+1;
        ansL = left+1;
        ansR = right;
        //cout<<left<<" "<<right<<" "<<zero<<endl;
      }
    }else if(ans < right - left){

      ans = right - left;
      ansL = left;
      ansR = right;
      //cout<<left<<" "<<right<<" "<<zero<<endl;

    }
    right++;

  }
  for(int i = 0;i < n;i++){

    if(i >= ansL && i <= ansR){
      cout<<"1 ";
    }else{
      cout<<a[i]<<" ";
    }
  }
}