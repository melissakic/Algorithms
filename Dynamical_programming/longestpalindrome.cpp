#include <iostream>
#include <vector>


std::string findpalindrome(std::string& rijec){
    std::string temp;
    for (auto i = 0; i < rijec.size(); i++)
    {
        int l=i,r=i;
        while(l>=0 && r<rijec.size() && rijec[l]==rijec[r]){
           if((r-l+1)>temp.length()){
            for (int i =l; i <= r; i++)
            {
                temp=std::string(rijec,l,r);
            }
           }
           l--;
           r++;
        }
    }
    
    return temp;
}


int main(int argc, char const *argv[])
{
    std::string temp("bananak");
    std::cout << findpalindrome(temp) << std::endl;
    return 0;
}
