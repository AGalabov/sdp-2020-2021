#include<iostream>
#include<stack>

struct Point
{
	int x, y;
};

bool findPath(int** maze, size_t n, size_t m, int goalX, int goalY)
{
	// std::stack<Point> s;
	// s.push({0, 0});

	// while(s.top().x != goalX || s.top().y != goalY)
  //   {
	// 	Point curr{s.top().x, s.top().y};
	// 	if (curr.x + 1 >= 0 && curr.x + 1 < n && curr.y >= 0 && curr.y < m && 
	// 	maze[curr.x + 1][curr.y] == 1)
	// 	{
	// 		s.push({curr.x + 1, curr.y});
	// 	}
	// 	else if (curr.x >= 0 && curr.x < n && curr.y + 1 >= 0 && curr.y + 1 < m && 
	// 	maze[curr.x][curr.y + 1] == 1)
	// 	{
	// 		s.push({curr.x, curr.y + 1});
	// 	}
	// 	else if (curr.x >= 0 && curr.x < n && curr.y - 1 >= 0 && curr.y - 1 < m &&
	// 	maze[curr.x][curr.y - 1] == 1)
	// 	{
	// 		s.push({curr.x, curr.y - 1});
	// 	}
	// 	else if (curr.x - 1 >= 0 && curr.x - 1 < n && curr.y >= 0 && curr.y < m &&
	// 	maze[curr.x + 1][curr.y] == 1)
	// 	{
	// 		s.push({curr.x - 1, curr.y});
	// 	}
	// }
}

int main()
{
  int maze[4][5] = {
            {1, 0, 1, 1, 0},
            {1, 1, 1, 0, 1},
            {0, 1, 0, 1, 1},
            {1, 1, 1, 1, 1}
        };

  return 0;
}