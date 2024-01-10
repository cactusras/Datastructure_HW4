#include <iostream>
#include <chrono>
#include <cmath>
#include <set>
#include <unordered_set>

auto timeUsage(){
    int n = pow(2,20);
    std::multiset<int> balanceBinarySearchTree;
    std::unordered_multiset<int> hashTable;

    auto cpu__time_used = std::chrono::nanoseconds(0);
    //計時
    for(int i=0; i<n; i++){
        int num = rand() % (n);
        auto start = std::chrono::high_resolution_clock::now();
        balanceBinarySearchTree.insert(num);
        hashTable.insert(num);
        auto end = std::chrono::high_resolution_clock::now();
        cpu__time_used += std::chrono::duration_cast<std::chrono::nanoseconds>(end - start);
    }
    int m = 10000;
    for(int i=0; i<m; i++){
        int search = rand()%(n);
        // auto start = std::chrono::high_resolution_clock::now();
        balanceBinarySearchTree.find(search);
        hashTable.find(search);
        // auto end = std::chrono::high_resolution_clock::now();
        // cpu__time_used += std::chrono::duration_cast<std::chrono::nanoseconds>(end - start);
    }
    return cpu__time_used;
}
auto getAvg(int n){
    auto sum = std::chrono::nanoseconds(0);
    for(int i=0; i<n; i++){
        auto usedTime = timeUsage();
        std::cout<<"第"<<i<<"次 : "<<usedTime.count()<<"\n";
        sum += usedTime;
    }
    return sum/n;
}
int main() {
    // Seed the random number generator
    srand(time(NULL));
    //calculate the average used time of the action
    auto usedTime_Average = getAvg(10);
    std::cout << "程式平均執行時間：" << usedTime_Average.count() << "nanoseconds" <<"\n";
    std::cout<<"finish";
    return 0;
}