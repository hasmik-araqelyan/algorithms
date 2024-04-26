#include <iostream>
#include <vector>

int nthTermOfSequence(int n){
    std::vector<int> result(n + 1);

    result[0] = 0;
    result[1] = 1;
    result[2] = 1;

    for(int i = 3; i <= n; ++i){
        result[i] = result[i - 1] + result[i - 2] + result[i - 3];
    }

    return result[n];
}

int main(){
    int n;

    std::cout << "Number: ";
    std::cin >> n;

    int result =  nthTermOfSequence(n);

    std::cout << "The nth term of this sequence is: " << result <<  std::endl;

    return 0;
}