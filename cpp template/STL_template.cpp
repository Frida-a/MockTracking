using namespace std;
#include <iostream>
#include <vector>
#include <queue>
#include <list>
#include <unordered_set>
//vector

//stack

//queue

//priority_queue
auto cmp = [](int left, int right) { return (left ^ 1) < (right ^ 1); };
std::priority_queue<int, std::vector<int>, decltype(cmp)> q5(cmp);
//list
auto cmp = [](int left, int right) {return abs(left) < abs(right);};

auto cmp = [](pair<int,int> left, pair<int,int> right) {return left.second < right.second;};
std::list<pair<int, int>, decltype(cmp)> l5(cmp);
//unordered_set unordered_map 
//unordered_multiset unordered_multimap

//set map
//multiset multimap


//operator overload

//lambda
