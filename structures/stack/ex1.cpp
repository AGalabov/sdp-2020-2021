// 13: 2 | 1 ^
// 6 : 2 | 0 |
// 3 : 2 | 1 |
// 1 : 2 | 1 |
// 0

// 13 => 1101

#include<iostream>
#include<stack>

void toBinary(int x)
{
    std::stack<int> remainders;
    while(x != 0)
    {
        remainders.push(x % 2);
        x /= 2; 
    }

    while(!remainders.empty())
    {
        std::cout<<remainders.top();
        remainders.pop();
    }
    std::cout << std::endl;
}


void toHex(int x)
{
    char y;
    int z;
    std::stack<char> remainders;
    while(x != 0)
    {
        z = x % 16;
        if(z>=10 && z<=15)
        {
          y = 'A' + z - 10;
          remainders.push(y);
        }
        else 
        {
          remainders.push('0'+z);
        }  

        x = x / 16;
    }

    while(!remainders.empty())
    {
        std::cout<<remainders.top();
        remainders.pop();
    }
    std::cout << std::endl;
}

int main()
{
    int number;
    std::cin >> number;
    std::cout << number << " => " ;
    toBinary(number);
    toHex(number);
    return 0;
}