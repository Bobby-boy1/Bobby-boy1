#include <vector>
#include <iostream>
#include <limits.h>
#include <bits/stdc++.h>
#include <algorithm>
#include <chrono>
#include <time.h>
#include <sys/time.h>
#include <unistd.h>
using namespace std;
using namespace std::chrono;

/**
    \brief Given a complete, undirected, weighted graph in the form of an adjacency matrix,
           returns the smallest tour that visits all nodes and starts and ends at the same
           node. This dynamic programming solution runs in O(n * 2^n).
    \return the minimum cost to complete the tour
*/
int tsp(const vector<vector<int>>& cities, int pos, int visited, vector<vector<int>>& state)
{
    if(visited == ((1 << cities.size()) - 1))
        return cities[pos][0]; // return to starting city

    if(state[pos][visited] != INT_MAX)
        return state[pos][visited];

    for(int i = 0; i < cities.size(); ++i)
    {
        // can't visit ourselves unless we're ending & skip if already visited
        if(i == pos || (visited & (1 << i)))
            continue;

        int distance = cities[pos][i] + tsp(cities, i, visited | (1 << i), state);
        if(distance < state[pos][visited])
            state[pos][visited] = distance;
    }

    return state[pos][visited];
}

int main()
{
    auto start = std::chrono::high_resolution_clock::now();

    vector<vector<int>> cities = { 
    {0,445,12,24,370,260},
    {445,0,289,223,423,252},
    {12,289,0,50,50,39},
    {24,223,50,0,419,124},
    {370,423,50,419,0,33},
    {260,252,39,124,33,0}
    };

    vector<vector<int>> state(cities.size());
    for(auto& neighbors : state)
        neighbors = vector<int>((1 << cities.size()) - 1, INT_MAX);

    cout << "minimum: " << tsp(cities, 0, 1, state) << endl;

    auto finish = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed = finish - start;
    std::cout << "Elapsed time: " << elapsed.count() << " s\n";

return 0;
}