#include <iostream>
#include <algorithm>
#include <vector>


int lis(std::vector<int>& a){
    std::vector<int> loookup(a.size());
    for (auto i = 0; i <a.size(); i++) loookup[i]=1;
    for (int i =a.size()-2; i >=0; i--){
        for (int j = i+1; j <a.size() ;++j){
            if(a[i]<a[j]) loookup[i]=std::max(loookup[i],1+loookup[j]);
        }}
    return *std::max_element(loookup.begin(),loookup.end());
}


int main(int argc, char const *argv[])
{
    std::vector<int> a;
    int temp;
    while (std::cin>>temp)
    {
        a.push_back(temp);
    }
    std::cout << lis(a) << std::endl;
    return 0;
}
