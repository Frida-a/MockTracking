using namespace std;
#include <iostream>
#include <vector>


// knapsack01
// 1. dp[i][j]: maxValue for first i items with their maxWeight less or equal to j
// 2. dp[i][j] = max( dp[i-1][j], dp[i-1][j-w[i]]+v[i] )
// 3. dp[0][j] = 0 if j<w[0] else v[0] ; dp[i][0] = 0;
void knapsack01(vector<int> weight, vector<int> value, int bagweight){

    // initialize
    vector<vector<int>> dp(weight.size(), vector<int>(bagweight+1, 0));
    for (int j = weight[0]; j <= bagweight; j++) {
        dp[0][j] = value[0];
    }

    //the order of two for-loops doesn't matter
    for(int i=1; i<weight.size(); i++){
        for(int j = 0; j<=bagweight; j++){
            if(j < weight[i]) dp[i][j] = dp[i-1][j];
            else dp[i][j] = max(dp[i-1][j], dp[i-1][j - weight[i]] + value[i]);
        }
    }

    cout << dp[weight.size() -1][bagweight] << endl;

}
void knapsack01withSpaceCompress(vector<int> weight, vector<int> value, int bagweight){

    // initialize
    vector<int> dp(bagweight+1, 0);
    // items in outer for-loop; bagweight in inner for-loop, bagweight in reversed order
    for(int i=0; i<weight.size(); i++){
        for(int j = bagweight; j >= weight[i]; j--){
            dp[j] = max(dp[j], dp[j - weight[i]] + value[i]);
        }
    }

    cout << dp[bagweight] << endl;
}

// knapsack-complete
// 1. dp[i][j]: maxValue for first i items with their maxWeight less or equal to j
// 2. dp[i][j] = max( dp[i-1][j], dp[i][j-w[i]]+v[i] )
// 3. dp[0][j] = 0 if j<w[0] else v[0] ; dp[i][0] = 0;
void knapsackComplete(vector<int> weight, vector<int> value, int bagweight){


    // initialize
    vector<vector<int>> dp(weight.size(), vector<int>(bagweight+1, 0));
    for (int j = weight[0]; j <= bagweight; j++) {
        dp[0][j] = value[0] * (j / weight[0]);
    }

    //the order of two for-loops doesn't matter
    for(int i = 1; i < weight.size(); i++){
        for(int j = 0; j<=bagweight; j++){
            if(j < weight[i]) dp[i][j] = dp[i-1][j];
            else dp[i][j] = max(dp[i-1][j], dp[i][j - weight[i]] + value[i]);
        }
    }

    cout << dp[weight.size() -1][bagweight] << endl;
}

void knapsackCompleteWithSpaceCompress(vector<int> weight, vector<int> value, int bagweight){


    // initialize
    vector<int> dp(bagweight+1, 0);
    // bagweight in order
    // items in outer for-loop; bagweight in inner for-loop -> combination
    // bagweight in outer for-loop; items in inner for-loop -> permutation
    for(int i=0; i<weight.size(); i++){
        for(int j = weight[i]; j <= bagweight; j++){
            dp[j] = max(dp[j], dp[j - weight[i]] + value[i]);
        }
    }

    cout << dp[bagweight] << endl;
}

//variation:
// 1. at most **capacity,** return plan number/ max_value
// 2. exactly **capacity,** return plan number/ max_value/ min_value
// 3. at least **capacity,** return plan number/ min_value


// strings

// state

// region

int main(){
    vector<int> weight = {1, 3, 4};
    vector<int> value = {15, 20, 30};
    int bagweight = 4;
    knapsack01(weight, value, bagweight);
    knapsack01withSpaceCompress(weight, value, bagweight);
    knapsackComplete(weight, value, bagweight);
    knapsackCompleteWithSpaceCompress(weight, value, bagweight);
    return 0;
}