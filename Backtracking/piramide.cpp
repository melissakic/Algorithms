#include <iostream>
#include <vector>

void print(std::vector<std::vector<int>> &grid)
{
    for (int i = 0; i < grid.size(); i++)
    {
        for (int j = 0; j < grid[0].size(); j++)
        {
            std::cout << grid[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

bool isValid(std::vector<std::vector<int>> &tri, int i, int j){
    if(i>=0 && i<tri.size() && j>=0 && j<tri.size()) return true;
    return false;
}

int maxPathSum(std::vector<std::vector<int>> &tri, int i, int j,std::vector<std::vector<int>> &lookup)
{
    if(lookup[i][j]!=-69) return lookup[i][j];
    if(!isValid(tri,i,j)) return 0;
    lookup[i][j]=tri[i][j] + std::max(maxPathSum(tri, i + 1, j,lookup),
                                maxPathSum(tri, i + 1, j + 1,lookup));
    return lookup[i][j];
}

int main()
{
    std::vector<std::vector<int>> lookup;
    lookup.resize(5);
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
           lookup[i].push_back(-69);
        }   
    }
    
    std::vector<std::vector<int>> tri = {{1, 0, 0},
                                         {4, 8, 0},
                                         {1, 5, 3},
                                         };
    std::cout << maxPathSum(tri, 0, 0,lookup);
    return 0;
}
