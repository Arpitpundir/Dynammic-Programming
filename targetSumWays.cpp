/*You are given a list of non-negative integers, a1, a2, ..., an, and a target, S. Now you have 2 symbols + and -. For each integer, you should choose one from + and - as its new symbol.

Find out how many ways to assign symbols to make sum of integers equal to target S.*/

int findTargetSumWays(vector<int> &nums, int s){
  int n = nums.size();
  unordered_map<int, int> hm;
  hm[0] = 1;
  for(int i=0;i<n;i++){
    auto mp = hm;
    hm.clear();

    for(auto it = mp.begin(; it != mp.end(); it++){
      hm[it->first + nums[i]] += it->second;
      hm[it->first - nums[i]] += it->second;
    }
  }
  return hm[s];
}