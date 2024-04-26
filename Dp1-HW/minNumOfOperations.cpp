#include <iostream>
#include <vector>

int minNumOfOperations(int n){
    std::vector<int> result(n + 1);

    result[0] = 0;

    for(int i = 1; i <= n; ++i){
        result[i] = result[i - 1] + 1;

        if(i % 2 == 0){
            result[i] = std::min(result[i], result[i / 2] + 1);
        }
    }

    return result[n];
}

int main(){
    int n;
    std::cout << "Number: ";
    std::cin >> n;

    int result = minNumOfOperations(n);

    std::cout <<"The minimum number of operations is: " << result << std::endl;

    return 0;
}