#pragma once

#ifndef __335__SOLUTION_H__
#define __335__SOLUTION_H__
#include <vector>

using namespace std;

#define MAX(a, b) (((a) > (b)) ? (a) : (b))
#define MIN(a, b) (((a) < (b)) ? (a) : (b))
// int flag = 0;
class Coordination
{
public:
	int x;
	int y;

	Coordination()
	{
		this->x = 0; this->y = 0;
	}


	Coordination(int x, int y)
	{
		this->x = x, this->y = y;
	}

	void operator=(Coordination c)
	{
		this->x = c.x;
		this->y = c.y;
		// return c;
	}
};

class Line
{
	
public:
	Coordination start;
	Coordination end;
	Line(Coordination start, Coordination end)
	{
		this->start.x = start.x;
		this->start.y = start.y;
		this->end.x = end.x;
		this->end.y = end.y;
	}

	bool if_cross(Line *l)
	{
		// 平行向量不管
		if (if_parallel(this, l) && !if_collinear(this, l))
		{
			return false;
		}
		int n1 = det(this->start.x - l->end.x, 
				this->start.y - l->end.y, 
				l->start.x - l->end.x,
				l->start.y - l->end.y),
			n2 = det(this->end.x - l->end.x, 
				this->end.y - l->end.y, 
				l->start.x - l->end.x,
				l->start.y - l->end.y),
			n3 = det(l->start.x - this->end.x, 
				l->start.y - this->end.y, 
				this->start.x - this->end.x, 
				this->start.y - this->end.y),
			n4 = det(l->end.x - this->end.x,
				l->end.y - this->end.y, 
				this->start.x - this->end.x,
				this->start.y - this->end.y);

		//if (n1 * n2 < 0 && n3 * n4 < 0)
		//{
		//	flag = 1;
		//	return true;
		//} 
		//else if (n1 == 0 && online(&this->start, &l->start, &l->end))
		//{
		//	flag = 2;
		//	return true;
		//}
		//else if (n2 == 0 && online(&this->end, &l->start, &l->end)) { flag = 3; return true; }
		//else if (n3 == 0 && online(&l->start, &this->start, &this->end)) { flag = 4; return true; }
		//else if (n4 == 0 && online(&l->end, &this->start, &this->end))
		//{
		//	flag = 5;
		//	return true;
		//}
		//return false;
		return (n1 * n2 < 0 && n3 * n4 < 0) ||
			(n1 == 0 && online(&this->start, &l->start, &l->end)) ||
			(n2 == 0 && online(&this->end, &l->start, &l->end)) ||
			(n3 == 0 && online(&l->start, &this->start, &this->end))||
			(n4 == 0 && online(&l->end, &this->start, &this->end));
		
	}

	void print()
	{
		cout << "(" << start.x << "," << start.y << ") ";
		cout << "(" << end.x << "," << end.y << ")" << endl;
	}

private:

	// a in b to c
	static bool online(Coordination *a, Coordination *b, Coordination *c)
	{
		return a->x >= MIN(b->x, c->x) && 
			a->x <= MAX(b->x, c->x) && 
			a->y >= MIN(b->y, c->y) && 
			a->y <= MAX(b->y, c->y);
	}

	static int det(int x1, int y1, int x2, int y2)
	{
		return x1 * y2 - x2 * y1;
	}

	static bool if_parallel(Line* a, Line* b)
	{
		return !((a->end.x - a->start.x) * (b->end.y - b->start.y) -  
			(a->end.y - a->start.y) * (b->end.x - b->start.x));
	}
	static bool if_collinear(Line *a, Line *b)
	{
		// 首尾相连构造新线段，如果和旧线段平行，则说明两条线段位于同一直线上
		Line *temp = new Line(a->start, b->end);
		// 三线平行，共线
		return if_parallel(temp, a);
	}
};

const Coordination START_POINT(0, 0);

class Solution {
public:
	bool isSelfCrossing(vector<int>& x) {
		int size = x.size();
		if (size <= 3)
		{
			return false;
		}
		Coordination start_coorination = START_POINT;
		Coordination end_coorination = start_coorination;
		vector<Line*>line;

		// get line
		for(int i = 0; i < size; ++i)
		{
			Line *l;
			switch(i % 4)
			{
				// north
			case 0:
				end_coorination.y += x[i];
				l = new Line(start_coorination, end_coorination);
				line.push_back(l);
				break;

				// west
			case 1:
				end_coorination.x -= x[i];
				l = new Line(start_coorination, end_coorination);
				line.push_back(l);
				break;

				// south
			case 2:
				end_coorination.y -= x[i];
				l = new Line(start_coorination, end_coorination);
				line.push_back(l);
				break;

				// east
			case 3:
				end_coorination.x += x[i];
				l = new Line(start_coorination, end_coorination);
				line.push_back(l);
				break;
			default:
				break;
			}

			start_coorination = end_coorination;
		}


		//for (auto it : line)
		//{
		//	it->print();
		//}
		for(int i = 0; i < size - 2; ++i)
		{
			Line *check_line = line[i];
			for (int j = i + 2; j < size; ++j)
			{
				if (check_line->if_cross(line[j]))
				{
					return true;
				}
			}
		}

		return false;
	}
};
#endif