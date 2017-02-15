#pragma once
#ifndef __407__SOLUTION_H__
#define __407__SOLUTION_H__
#include <vector>
#include <limits>
#include <queue>
using std::vector;
using std::numeric_limits;
using std::priority_queue;
// #define max__(a,b) (((a) > (b)) ? (a) : (b))

template<typename T> void print_queue(T& q) {
	while (!q.empty()) {
		q.top().print();
		q.pop();
	}
	std::cout << '\n';
}



class Cell
{
public:
	int x;
	int y;
	int height;

	Cell (int x, int y, int height)
	{
		this->x = x;
		this->y = y;
		this->height = height;
	}
	void print() const
	{
		std::cout << "(" << x << "," << y << "):" << height << std::endl;
	}
	bool operator==(Cell c) const
	{
		return this->x == c.x && this->y == c.y && this->height == c.height;
	}
};

class Solution {
public:
	int trapRainWater(vector<vector<int>>& heightMap) {
		int row = heightMap.size();
		if (row <= 0)
		{
			return 0;
		}
		
		int column = heightMap[0].size();
		if (column <= 0)
		{
			return 0;
		}
		int max = numeric_limits<int>::max();
		// visited

		auto cmp = [&](Cell* c1, Cell* c2)
		{
			return c1->height > c2->height;
		};
		vector<vector<bool>>visited(row, vector<bool>(column, false));
		priority_queue<Cell*, vector<Cell*>, decltype(cmp)>pq(cmp);

		// exclude edge
		for(int i = 0; i < row; ++i)
		{
			visited[i][0] = true;
			pq.push(new Cell(i, 0, heightMap[i][0]));
			visited[i][column - 1] = true;
			pq.push(new Cell(i, column - 1, heightMap[i][column - 1]));
		}
		for(int i = 0; i < column; ++i)
		{
			visited[0][i] = true;
			pq.push(new Cell(0, i, heightMap[0][i]));
			visited[row - 1][i] = true;
			pq.push(new Cell(row - 1, i, heightMap[row - 1][i]));
		}
		// print_queue(pq);
		int direction_x[4] = { 0, 0, 1, -1 },
			direction_y[4] = { 1, -1, 0, 0 };
		int count = 0;
		while(!pq.empty())
		{
			Cell *c = pq.top();
			c->print();
			pq.pop();
			for(int i = 0; i < 4; ++i)
			{
				int nx = c->x + direction_x[i];
				int ny = c->y + direction_y[i];
				if (nx >= 0 && nx < row && ny >= 0 && ny < column && !visited[nx][ny]) {
					visited[nx][ny] = true;
					count = count + this->max(0, c->height - heightMap[nx][ny]);
					pq.push(new Cell(nx, ny, this->max(heightMap[nx][ny], c->height)));
				}
			}
			delete c;
		}
		return count;
	}

	template<typename T> static T max (T a, T b)
	{
		return (((a) > (b)) ? (a) : (b));
	}
};
#endif
