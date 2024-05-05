#include <iostream>
#include <vector>
#include <algorithm>

int minNumOfOperations(std::string str1, std::string str2){
    int n = str1.size();
    int m = str2.size();

    std::vector<std::vector<int>> dp(n + 1, std::vector<int>(m + 1, 0));

    for(int i = 0; i <= n; ++i){
        dp[i][0] = i;
    }

    for(int j = 0; j <= m; ++j){
        dp[0][j] = j;
    }

    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= m; ++j){
            if(str1[i - 1] == str2[j - 1]){
                dp[i][j] = dp[i - 1][j - 1];
            }else{
                dp[i][j] = std::min({dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]}) + 1;
            }
        }
    }
    return dp[n][m];
}

int main(){
    std::string str1, str2;
    
    std::cout << "String 1 is: ";
    std::cin >> str1;

    std::cout << "String 2 is: ";
    std::cin >> str2;

    std::cout << "The number of minimum operations is: " << minNumOfOperations(str1, str2) << std::endl;

    return 0;
}