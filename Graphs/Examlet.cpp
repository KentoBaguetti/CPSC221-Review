#include <vector>
#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <list>
#include <set>
#include <queue>
#include <functional>
#include <cmath>
using namespace std;

// for 0 index heap
int heapSubTree (int index, vector<int>& heap) {

    int count = 0;
    int curr = index;
    bool flag = true;

    while (flag) {

        if ((curr * 2) + 1 <= heap.size() - 1) {
            curr = (curr * 2) + 1;
            count++;
        } else {
            flag = false;
        }

    }

    return count;

}

int heapSubTree_betterr (int index, vector<int>& heap) {

    int count = 0;
    int curr = index;

    // take advantage of the fact that a heap is a complete binary tree, so you only
    // need to search down the left "subtree"
    while ((curr * 2) + 1 < heap.size()) {

        count++;
        curr = (curr * 2) + 1;

    }

    return count;

}