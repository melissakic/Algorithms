#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <functional>


namespace std{
    template<>
    struct hash<pair<std::string,std::string>>{
        size_t operator()(const pair<std::string,std::string>& other)const{
            return hash<std::string>{}(other.first);
        }
    };
}

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


//Dinamicko rjesenje
// int lcis(std::string& prva,std::string& druga){
//     std::vector<std::vector<int>> tabela;
//     tabela.resize(druga.size()+1);
//     for (int i = 0; i < tabela.size(); i++) tabela[i].resize(prva.size()+1);
//     print(tabela);
//     tabela[0][0]=1;
//     for (int i = 1; i < druga.size()+1; i++)
//     {
//         for (int j = 1; j <prva.size()+1; j++)
//         {
//             if(druga[i-1]==prva[j-1]) tabela[i][j]=1+tabela[i][j-1];
//             else tabela[i][j]=std::max(tabela[i][j-1],tabela[i-1][j]);
//         }
        
//     }
//     std::cout << std::endl;
//     print(tabela);
//     return tabela[druga.size()][prva.size()];
// }


int lcis(std::string& prvi,std::string& drugi,std::unordered_map<std::pair<std::string,std::string>,int>& lookup){
    if(lookup.find({prvi,drugi}) != lookup.end()) return lookup[{prvi,drugi}];
    if(prvi.size()==0 || drugi.size()==0) return 0;
    if(prvi.back()==drugi.back()){
        auto temp=prvi;
        auto temp1=drugi;
        prvi.pop_back();
        drugi.pop_back();
        lookup[{temp,temp1}]=1+lcis(prvi,drugi,lookup);
        return lookup[{temp,temp1}];
    }
    else{
        auto temp=prvi;
        auto temp1=drugi;
        drugi.pop_back();
        prvi.pop_back();
        lookup[{temp,temp1}]=std::max(lcis(prvi,temp1,lookup),lcis(temp,drugi,lookup));
        return lookup[{temp,temp1}];
    }
}




int main(int argc, char const *argv[])
{
    std::string prva("ABCDEFGH");
    std::string druga("ABC");
    std::unordered_map<std::pair<std::string,std::string>,int> lookup;
    std::cout << lcis(prva,druga,lookup) << std::endl;
    return 0;
}
