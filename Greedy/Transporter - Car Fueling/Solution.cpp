/*
    Copyright (C) 2020, Sathira Silva.
    
    Approach:   To calculate the least amount of money needed to reach the destination, the problem can be reduced in to two problems:
                    (1). In which stations should Frank Martin stop?
                    (2). How many units of gasoline should Frank Martin buy from the stations he stops?
                    i.e. How many units of gasoline should Frank Martin buy in each station? If it is 0, he shouldn't buy from that
                    station because maybe there's a cheaper station than that and he can pass that station with enough fuel.
                So, if Martin can reach a farther cheaper station at S than the current station at T, the better choice is to go to that
                station with (S - T) amount of fuel. Otherwise (if there's no such station or he can't reach that station using current
                amount of fuel he has), refill the tank.
                In order to determine the next farthest reachable station using the current fuel amount, the stations must be sorted
                by their distances from the outset. To find the next cheapest station for each station, use stacks because stacks only
                consumes O(n) (The naive approach consumes O(n^2)). Push the stations starting from the last into the stack. At the
                current station during the iteration, pop the stack until stack until we find the next cheaper station.
                
    Total Time Complexity:  O(nlogn)
*/

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

struct station {
    int dist, price;
    bool operator<(const station &s) {
        return dist < s.dist;
    }
};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t, n, maxFuel, currentFuel, target;
    station stations[50000];
    int stack[50000], nextStation[50000];
    cin >> t;
    for (int test = 0; test < t; test++) {
        cin >> n >> maxFuel >> currentFuel >> target;
        for (int station = 0; station < n; station++)
            cin >> stations[station].dist >> stations[station].price;
        sort(stations, stations + n);
        int len = 0;
        // Find next station to stop for each station which has cheapest rates, using a stack.
        for (int i = n - 1; i >= 0; i--) {
            while (stacklen > 0 && stations[stack[len - 1]].price >= stations[i].price)
                len--;
            nextStation[i] = (len == 0 ? -1 : stack[len - 1]);
            stack[len] = i;
            len++;
        }
        // Move to 1st station.
        currentFuel -= stations[0].dist;
        long long money = 0;
        for (int i = 0; i < n; i++) {
            // Impossible to reach the next station.
            if (currentFuel < 0) {
                break;
            }
            int requiredFuel = min(maxFuel, (nextStation[i] == -1 ? target : stations[nextStation[i]].dist) - stations[i].dist);
            if (requiredFuel > currentFuel) {
                money += (long long) (requiredFuel - currentFuel) * stations[i].price;
                currentFuel = requiredFuel;
            }
            currentFuel -= (i == n - 1 ? target : stations[i + 1].dist) - stations[i].dist;
        }
        if (currentFuel < 0) {
            cout << "-1" << endl;
        } else {
            cout << money << endl;
        }
    }
    return 0;
}
