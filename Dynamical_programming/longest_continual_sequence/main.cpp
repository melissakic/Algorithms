#include <vector>
#include <iostream>
#include <algorithm>

void ls(std::vector<int>& a){
    //Prvo rjesenje
    // int sum=0;
    // for (auto i:a) sum+=i;
    // auto begin=a.begin();
    // auto end=--a.end();
    // while (1)
    // {
    //     if(sum-(*begin)<sum && sum-(*end)<sum) break;
    //     if(sum-(*end)>sum)sum=sum-(*end--);
    //     if(sum-(*begin)>sum)sum=sum-(*begin++);
    // }
    // for (auto i = begin; i <=end; i++) std::cout << *i<<" ";
    // std::cout <<"\n" <<sum << std::endl;

    //Drugo rjesenje
    auto start=0,end=0,temp=0;
    int maximum = a[0],current=0;
    for(int i=0; i<a.size(); i++){
        current += a[i];
        if(current < 0){
                start = i+1;
                current = 0;
            }
        else if(current > maximum){
                end = i;
                temp = start;
                maximum = current;
            }
        }
    for (auto i = temp; i <=end; i++) std::cout << a[i] << " ";
    std::cout << "\n"<<maximum << std::endl;
}


int main(int argc, char const *argv[])
{   
    std::vector<int> a;
    int temp;
    while (std::cin>>temp)
    {
        a.push_back(temp);
    }
    ls(a);
    return 0;
}
