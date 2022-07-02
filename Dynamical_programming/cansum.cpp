#include <iostream>
#include <vector>
void print(std::vector<std::vector<int>>& grid){
    for (int i = 0; i < grid.size(); i++)
    {
        for (int j = 0; j < grid[0].size(); j++)
        {
            std::cout << grid[i][j] <<" ";
        }
        std::cout << std::endl;
    }
    
}

// bool cansum(int sum,const std::vector<int>& nums,std::vector<bool>& lookup){
//     if(lookup[sum]==true) return lookup[sum]; 
//     if(sum==0) return true;
//     if(sum<0) return false;
//     for (int i = 0; i < nums.size(); i++)
//     {
//         if(cansum(sum-nums[i],nums,lookup)) {
//             lookup[sum]=true;
//             return true;
//             }
//     }
//     lookup[sum]=false;
//     return lookup[sum];
// }

bool cansum(int sum,const std::vector<int>& nums){
    std::vector<std::vector<int>> lookup;
    lookup.resize(nums.size()+1);
    for (int i = 0; i < lookup.size(); i++) lookup[i].resize(sum+1);
    for (int i = 0; i < lookup.size(); i++)
    {
       lookup[i][0]=1;
    }
    for (int i = 1; i < lookup.size(); i++)
    {
        for (int j = 1; j < lookup[i].size(); j++)
        {   
            auto temp=j-nums[i-1];//5-3
            if(temp<0) lookup[i][j]=lookup[i-1][j];
            if(j==sum){

            }
            lookup[i][j]=std::max(lookup[i-1][j],lookup[i][temp]);
        }
    }
     print(lookup);
    
    return lookup[nums.size()][sum];
}

int main(int argc, char const *argv[])
{
    std::vector<int> nums{3,5};
    int sum=4;
    std::cout << cansum(sum,nums) << std::endl;
    return 0;
}
