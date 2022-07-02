#include <iostream>
#include <unordered_map>
#include <vector>
#include "print.hpp"

int count(int n, int k, int target,std::vector<std::vector<int>>& lookup)
{
    if(lookup[n][target]!=0) return lookup[n][target];
    // if the desired sum is reached with `n` dices
    if (n == 0) {
        return (target == 0) ? 1 : 0;
    }
 
    // the desired sum can't be reached with the current configuration
    if (target < 0 || n<0) {
        return 0;
    }
 
    // if the subproblem is seen for the first time, solve it and
    // store its result in a 2D array or map
        // recur for all possible solutions
        for (int i = 1; i <= k; i++) {
            lookup[n][target] += count(n - 1, k, target - i, lookup);
        }
 
    // return solution to the current subproblem
    return lookup[n][target];
}
 

int main(int argc, char const *argv[])
{
    int broj_kockica=4;
    int strane=6;
    int suma=30;
    std::vector<std::vector<int>> lookup(broj_kockica + 1, std::vector<int>(suma + 1));
    print(lookup);
    std::cout << count(broj_kockica,strane,suma,lookup) << std::endl;
    return 0;
}
