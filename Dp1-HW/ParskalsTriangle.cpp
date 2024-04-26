#include <iostream>
#include <vector>

std::vector<std::vector<int>> ParskalsTriangle(int n){
    std::vector<std::vector<int>> result(n);

    result[0] = {1};
    result[1] = {1, 1};

    for(int i = 2; i < n; ++i){
        result[i].resize(i + 1);
        result[i][0] = 1;
        result[i][i] = 1;

        for(int j = 1; j < i; ++j){
            result[i][j] = result[i - 1][j - 1] + result[i - 1][j];
        }
    }

    return result;
}

void print(std::vector<std::vector<int>>& result){
    for(int i = 0; i < result.size(); ++i){
        for(int j = 0; j < result[i].size(); ++j){
            std::cout << result[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

int main(){
    int n;
    std::cout << "Number: ";
    std::cin >> n;

    std::vector<std::vector<int>> result = ParskalsTriangle(n);

    std::cout << "Parskal's triangle is: " << std::endl;
    print(result);

    return 0;
}