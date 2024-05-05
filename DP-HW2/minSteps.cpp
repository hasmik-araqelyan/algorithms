#include <iostream>
#include <vector>
#include <algorithm>

int minSteps(std::string str1, std::string str2){
    int n = str1.size();
    int m = str2.size();

    std::vector<std::vector<int>> dp(n + 1, std::vector<int>(m + 1, 0));

    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= m; ++j){
            if(str1[i - 1] == str2[j - 1]){
                dp[i][j] = dp[i - 1][j - 1] + 1;
            }else{
                dp[i][j] = std::max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    int result = n + m - 2 * dp[n][m];
    return result;
}

int main(){
    std::string str1;
    std::string str2;

    std::cout << "String 1 is: ";
    std::cin >> str1;

    std::cout << "String 2 is: ";
    std::cin >> str2;

    std::cout << "The minimum number of steps is: " << minSteps(str1, str2);

    return 0;
}