#include<iostream>
#include<stack>
#include<vector>

struct Point
{
	int x, y;

	Point down()
	{
		return {x + 1, y};
	}
	Point right()
	{
		return {x,y +1 };
	}
	Point up()
	{
		return {x - 1,y};
	}
	Point left()
	{
		return {x,y - 1};
	}

	bool operator != (const Point& other)
	{
		return x != other.x || y != other.y;
	}
};

bool validPosition(const Point& curr, const int maze[][5], size_t n, size_t m)
{
	return curr.x >= 0 &&
			curr.y >= 0 &&
			curr.x < n &&
			curr.y < m &&
			maze[curr.x][curr.y] == 1;
			
}

bool findPath(const int maze[][5] , size_t n, size_t m, const Point& goal)
{
	std::stack<Point> s;
	s.push({0, 0});
	std::vector<std::vector<bool>> visited(n, std::vector<bool>(m, false));

	while(!s.empty() && s.top() != goal)
    {
		Point current = s.top();
		s.pop();
		visited[current.x][current.y]=true;
	
		if(validPosition(current.up(),maze,n,m) && !visited[current.up().x][current.up().y]) {
			s.push(current.up());
		}

		if(validPosition(current.left(),maze,n,m) && !visited[current.left().x][current.left().y]) {
			s.push(current.left());
		}

		if(validPosition(current.right(),maze,n,m) && !visited[current.right().x][current.right().y]) {
			s.push(current.right());
		}

		if(validPosition(current.down(),maze,n,m) && !visited[current.down().x][current.down().y]) {
			s.push(current.down());
		}
	}

	return !s.empty();
}

int main()
{
  int maze[4][5] = {
            {1, 0, 1, 1, 0},
            {1, 1, 1, 0, 1},
            {0, 1, 0, 1, 0},
            {1, 1, 1, 0, 1}
        };

	std::cout << std::boolalpha << findPath(maze,4,5,{0,3}) << std::endl;
	std::cout << std::boolalpha << findPath(maze,4,5,{3,0}) << std::endl;
	std::cout << std::boolalpha << findPath(maze,4,5,{3,4}) << std::endl;

  return 0;
}