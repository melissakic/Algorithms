#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>

struct Job {
    char id; // Job Id
    int dead; // Deadline of job
    int profit; // Profit if job is over before or on
                // deadline
};


void activities(std::vector<Job>& poslovi){
    std::sort(poslovi.begin(),poslovi.end(),[](const Job& prvi,const Job& drugi){return prvi.profit>drugi.profit;});
    std::vector<int> profits(poslovi.size(),0);
    int dead=0;
    for (int i = 0; i < poslovi.size(); i++)
    {
        if(dead<poslovi[i].dead){
             std::cout << poslovi[i].profit << std::endl;
             ++dead;
             }
    }
    
}

int main(int argc, char const *argv[])
{
    std::vector<Job> poslovi{ { 'a', 2, 100 },
                  { 'b', 1, 19 },
                  { 'c', 2, 27 },
                  { 'd', 1, 25 },
                  { 'e', 3, 15 } };
    activities(poslovi);
    return 0;
}
