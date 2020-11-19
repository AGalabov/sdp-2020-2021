#include <iostream>
#include<utility>
#include "Queue.h"

int main()
{
	Queue<int> myQueue;

	Queue<std::pair<int,int>> tasks;
    
    std::pair<int,int> pair;

    std::cin >> pair.first;
    while(pair.first != 0)
    {
        pair.second = 0;
        // This means enqueue
		if(pair.first == 1)
        {
            std::cin >> pair.second;
        }
		tasks.push_back(pair);

        std::cin >> pair.first;
    }

	while(!tasks.empty())
	{
		switch(tasks.front().first)
		{
			case 1: 
			{
				myQueue.push_back(tasks.front().second);
				break;
			}
			case 2:
			{
				myQueue.pop_front(); 
				break;
			}
			case 3: 
			{
				std::cout<<myQueue.front();
				 break;
			}
		}
        tasks.pop_front();
	}

    return 0;
}