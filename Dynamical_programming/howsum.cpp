#include <iostream>
#include <vector>

void print(std::vector<int>& temp){
    for (auto i:temp)
    {
        std::cout << i << " ";
    }
}


// bool howsum(int sum,const std::vector<int>& nums,std::vector<int>& result,std::vector<int>& temp){
//     if(sum==0){
//         if(temp.size()<result.size()) return true;
//         temp=result;
//         return true;}
//     if(sum<0) return false;
//     for (int i = 0; i < nums.size(); i++)
//     {
//         result.push_back(nums[i]);
//          howsum(sum-nums[i],nums,result,temp); 
//          result.pop_back();
//     }
//     return false;
// }


void howsum(int sum,std::vector<int> nums){
    std::vector<std::vector<std::vector<int>>> table;
    table.resize(nums.size()+1);
    for (size_t i = 0; i < table[0].size(); i++) table[i].resize(sum+1);
    for (int i = 1; i <= nums.size(); i++)
    {
        for (int j = 1; j <=sum ; j++)
        {
           if(j-nums[i-1]<0) {
           table[i][j]=table[i-1][j];
           }
           else{
           int temp=j-nums[i-1];
           std::vector<int> joj;
           joj=table[i][temp];
            joj.push_back(nums[i-1]);
            table[i][j].swap(joj);
           }
        }
        
    }
    // auto f=table[nums.size()][sum];
    // for (auto i:f)
    // {
    //     std::cout << i << " ";
    // }
    
}



int main(int argc, char const *argv[])
{
    std::vector<int> nums{1,2,3};
    int sum=4;
    howsum(sum,nums);
    
    return 0;
}