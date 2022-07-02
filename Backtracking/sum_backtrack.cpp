#include <iostream>
#include <vector>
#include <algorithm>

bool nadji(std::vector<int>& nums,int target){
    if(target==0) return true;
    if(target<0) return false;
    for (int i = nums.size()-1; i >=0; i--)
    {
        if(nums[i]<target){
            int temp=nums[i];
            target-=temp;
            nums.erase(std::find(nums.begin(),nums.end(),temp));
            if(nadji(nums,target)){
                return true;}
            nums.push_back(target);
            target+=temp;
        }
    }
    
    return false;
}

int main(int argc, char const *argv[])
{
    std::vector<int> nums{15, 22, 14, 26, 32, 9, 16, 8};
    int target=53;
    nadji(nums,target);
    return 0;
}
