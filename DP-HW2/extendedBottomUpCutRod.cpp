#include <iostream>
#include <vector>
#include <climits>

int cutRod(int price[], int n, std::vector<int>& r, std::vector<int>& s){
    r.resize(n + 1);
    s.resize(n + 1);

    r[0] = 0;

    for(int i = 0; i <= n; ++i){
        int q = INT_MIN;
        for(int j = 0; j <= i; ++j){
            if(q < price[j] + r[i - j]){
                q = price[j] + r[i - j];
                s[i] = j;
            }
        }
        r[i] = q;
    }
    return r[n];
}

void print(int price[], int n){
    std::vector<int> r, s;

    std::cout << "Length: ";
    for(int i = 1; i <= n; ++i){
        std::cout << i << " ";
    }
    std::cout << std::endl;

    std::cout << "Prices: ";
    for(int i = 1; i <= n; ++i){
        std::cout << price[i] << " ";
    }
    std::cout << std::endl;

    int result = cutRod(price, n, r, s);

    std::cout << "Max revenue: " << result << std::endl;

    std::cout << "Optimal cuts: ";
    while(n > 0){
        std::cout << s[n] << " ";
        n = n - s[n];
    }
}

int main(){
    int n = 10;
    int price[] = {0, 1, 3, 5, 6, 6, 7, 7, 9, 11, 13};

    print(price, n);

    return 0;
}