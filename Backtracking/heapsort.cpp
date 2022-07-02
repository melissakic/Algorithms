#include <iostream>
#include <vector>

void makeheap(std::vector<int>& array,int indeks,int size){
     if(array[indeks]<array[indeks*2+1] && indeks*2+1<size){
     std::swap(array[indeks],array[indeks*2+1]);
     makeheap(array,indeks*2+1,size);
    }
    if(array[indeks]<array[indeks*2+2] && indeks*2+2<size){
     std::swap(array[indeks],array[indeks*2+2]);
     makeheap(array,indeks*2+2,size);}
     return;
}


void heapsort(std::vector<int>& array){
    for (int i = (array.size()-1)/2; i >=0; i--) makeheap(array,i,array.size());
    for (int i = array.size()-1; i >0; i--)
    {
       std::swap(array[0],array[i]);
       makeheap(array,0,i); 
    }
    
    
}

int main(int argc, char const *argv[])
{
    std::vector<int> temp;
    int input;
    while (std::cin>>input) temp.push_back(input);
    heapsort(temp);
    std::cout << "\n" << std::endl;
    for (auto i:temp) std::cout << i <<" ";
    
    return 0;
}

