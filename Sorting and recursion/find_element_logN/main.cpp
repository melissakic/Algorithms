#include <iostream>
#include <vector>

int najmanji(std::vector<int>& a,int lo,int hi){
    if(a[lo]<a[hi])return a[lo];
   int mid=lo+(hi-lo)/2;
   if(a[mid]>a[mid+1])return a[mid+1];
   if(a[mid]<a[mid-1])return a[mid];
   if(a[mid]>a[hi]) return najmanji(a,mid+1,hi);
   return najmanji(a,lo,mid-1);
}

int main(int argc, char const *argv[])
{
    std::vector<int>a;
    int temp;
    while (std::cin>>temp)
    {
        a.push_back(temp);
    }
    std::cout << najmanji(a,0,a.size()-1) << std::endl;
    return 0;
}
