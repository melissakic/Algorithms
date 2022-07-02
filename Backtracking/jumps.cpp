#include <iostream>
#include <vector>

int steps(std::vector<int>& temp,int step,int indeks){
    if(indeks==temp.size()-1){
        return step;}
    for (int i = step; i <step+indeks; i++)
    {   
        step++;
        if(steps(temp,step,i)) return step;
        step--;
    }
    return step;
}



int main(int argc, char const *argv[])
{
    std::vector<int> temp{1,3,2,1,5,7,4,6,9};
    std::cout << steps(temp,0,0) << std::endl;
    return 0;
}
