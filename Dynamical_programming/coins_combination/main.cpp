#include <iostream>
#include <vector>

int comb(std::vector<int>& arr,int num){
    std::vector<int>temp(num+1);
    temp[0]=1;
    for (auto i = 0; i <arr.size() ; i++)
    {
        for (auto j = arr[i]; j < num+1;++j){
            if((j-arr[i])>=0) temp[j]=temp[j]+temp[j-arr[i]];
            else j=arr[i];
        }
    }
    return temp.back();   
}

int main(int argc, char const *argv[])
{
    std::vector<int> a;
    int num;
    std::cin>>num;
    int temp;
    while (std::cin>>temp)
    {
        a.push_back(temp);
    }
    std::cout << comb(a,num) << std::endl;
    return 0;
}
