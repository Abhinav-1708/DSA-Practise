#include <bits/stdc++.h>
#include <iostream>
using namespace std;

class Item
{
public:
    float weight;
    int val;
};
class Node
{
public:
    int level;
    int profit;
    int bound;
    float weight;
};

bool comparison(Item a, Item b)
{
    return (((double)a.val / a.weight) > ((double)b.val / b.weight));
}

int bound(Node u, int n, int W, Item arr[])
{
    if (u.weight > W)
        return 0;
    int profit_bound = u.profit;
    int j = u.level + 1;
    int total_wt = u.weight;
    while ((j < n) && (total_wt + arr[j].weight <= W))
    {
        total_wt += arr[j].weight;
        profit_bound += arr[j].val;
        ++j;
    }
    if (j < n)
    {
        profit_bound += (W - total_wt) * arr[j].val / arr[j].weight;
    }
    return profit_bound;
}

int knapsack(int W, Item arr[], int n)
{
    sort(arr, arr + n, comparison); //to sort the arr by w/val
    queue<Node> Q;
    Node u, v;
    u.level = -1;
    u.profit = u.weight = 0;
    Q.push(u);
    int maxProfit = 0;
    while (!Q.empty())
    {
        u = Q.front();
        Q.pop();
        if (u.level == -1)
            v.level = 0;
        if (u.level == n - 1)
            continue;
        v.level = u.level + 1;
        v.weight = u.weight + arr[v.level].weight;
        v.profit = u.profit + arr[v.level].val;
        if (v.weight <= W && v.profit > maxProfit)
            maxProfit = v.profit;
        v.bound = bound(v, n, W, arr);
        if (v.bound > maxProfit)
            Q.push(v);
        v.weight = u.weight;
        v.profit = u.profit;
        v.bound = bound(v, n, W, arr);
        if (v.bound > maxProfit)
            Q.push(v);
    }

    return maxProfit;
}
int main()
{
    int n; // Number of elements
    cin >> n;
    int W; // Capacity of knapsack
    cin >> W;
    Item arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i].weight;
    }
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i].val;
    }
    cout << knapsack(W, arr, n);
}