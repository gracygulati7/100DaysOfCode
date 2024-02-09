//! Gas Station Problem
//! leetcode question 134:

//* Logic:
//* in this problem we have gas stations in circular fashion 
//* gas [] -> denotes different gas station having amount of gas in them. both gas and cost are of same size.
//* cost [] -> denotes how much fuel you need to go from a gas station to the one after it by gas[i]. 
//* like gas[i] for example gas=[1,2,3,4,5] , cost=[3,4,5,1,2]
//* so gas[0] needs 3 gas to go to gas[1] and 3 is cost[0]. 
//* so gas[i]>=cost[i] to start from a station and go to the next one.
//* so delta = gas[i]-cost[i] and delta should always be +ve to start.
//* at start the tank of car is empty.
//* solution is when u travel a whole round trip ie when starting point and ending point is same.
//* if total cost>total gas, no matter where u start u cannot complete the trip
//* so trip can only be possible is total gas>totalcost meaning total delta should be >=0 .
//* problem is to find starting point.
//* to start u should note delta>=0 at a point.

//? FOR FINDING THE STARTING POINT:
/*
1. delta >= 0 then we can start the car from that point
2. We will keep track of total delta and current delta
3. If current delta < 0 then we will change the starting point to the next station and reset the current delta to 0
4. If total delta < 0 then we can't complete the circle so we will return -1
5. But if total delta >= 0 then we will return the starting point
*/

//? link: https://leetcode.com/problems/gas-station/description/?envType=study-plan-v2&envId=top-interview-150

#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int tc = 0, tg = 0;
        for (int i = 0; i < cost.size(); i++) {
            tc += cost[i];
        }
        for (int i = 0; i < gas.size(); i++) {
            tg += gas[i];
        }
        int total_delta = tg - tc;
        int i = 0;
        int curr_delta = 0;
        int start_index = 0;

        while (i < gas.size()) {
            curr_delta += gas[i] - cost[i];
            if (curr_delta < 0) {
                start_index = i + 1;
                curr_delta = 0;
            }
            i++;
        }
        return (total_delta >= 0) ? start_index : -1;
    }
};

int main() {
    Solution solution;
    cout << "Enter the gas values : ";
    vector<int> gas;
    int gasValue;
    while (cin >> gasValue) {
        gas.push_back(gasValue);
    }
    cout << "Enter the cost values : ";
    vector<int> cost;
    int costValue;
    while (cin >> costValue) {
        cost.push_back(costValue);
    }
    int result = solution.canCompleteCircuit(gas, cost);
    cout << "The starting gas station's index is: " << result << endl;
    return 0;
}