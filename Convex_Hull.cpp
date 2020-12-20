#include<bits/stdc++.h>
using namespace std;

void file_input_output()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
}

// Convex Hull: Given a set of points in the plane, 
// Convex Hull is a smallest convex polygon with minimum area and minimum perimeter 
// such that each point lies either on the boundary of polygon or inside it.

// // Graham Scan Algorithm
// 1. Sort all the points using the below comparison:
// 	i) xi < xj
// 	ii) if(xi == yi) yi < yj
// 2. This will make p[0] as bottom-left most point and p[n-1] as top-right most point
// 3. Orientation of Point (Clockwise, Anticlockwise and Collinear):
//    https://github.com/archit-aggarwal/C-Cpp-Codes/blob/master/Point%20Orientation.jpeg
// 4. Now Divide all points in upper half and lower half of the area divided by line joining p[0] and p[n-1] points.
// 5. For points in upper half, no point should make a counter clockwise turn with its previous point, in order to be
//    included in the convex hull. 
// 6. Similarly, for points in lower half, no point in convex hull should make a clockwise turn with previous point.
// 7. Points p[0], p[n-1] and all collinear points on this line will come in both upper half and lower half, 
//    hence need to be removed once from the final result.
// 8. Final Result will be (Points in Upper Half) Union (Points in Lower Half) satisfying the condition in (5) & (6).


struct point {
	int x, y;

	// for sorting
	bool operator<(point &b)
	{
		if (b.x == x) return y < b.y;
		return x < b.x;
	}

	// for comparing whether two points are same
	bool operator==(point &b)
	{ return x == b.x && y == b.y; }
};

bool cw(point a, point b, point c)
{ return a.x * (b.y - c.y) + b.x * (c.y - a.y) + c.x * (a.y - b.y) > 0; }

bool ccw(point a, point b, point c)
{ return a.x * (b.y - c.y) + b.x * (c.y - a.y) + c.x * (a.y - b.y) < 0; }

bool collinear(point a, point b, point c)
{ return a.x * (b.y - c.y) + b.x * (c.y - a.y) + c.x * (a.y - b.y) == 0; }

void convex_hull(vector<point> &p)
{
	if (p.size() <= 2) return;
	sort(p.begin(), p.end());
	int n = p.size();

	// Bottom-Left Most point
	point p1 = p[0];
	// Top-Right Most point
	point p2 = p[n - 1];

	vector<point> upper, lower;
	upper.push_back(p1);
	lower.push_back(p1);

	// Divide p[i] in Upper Half or Lower Half
	for (int i = 1; i < n; i++)
	{
		// First Point(p1) , Last point(p2) & Collinear Points
		// will be in both Upper Half & Lower Half

		// Upper Half
		if ((i == n - 1) || !ccw(p1, p[i], p2)) {
			// Remove Inner Points in Upper Half (which have left turn)
			// I can directly join p[size -2] with p[i] no need of p[size-1]
			while (upper.size() >= 2
			        && ccw(upper[upper.size() - 2], upper[upper.size() - 1], p[i]))
			{ upper.pop_back(); }
			upper.push_back(p[i]);
		}

		// Lower Half
		if ((i == n - 1) || !cw(p1, p[i], p2)) {
			// Remove Inner Points in Lower Half (which have right turn)
			// I can directly join p[size -2] with p[i] no need of p[size-1]
			while (lower.size() >= 2
			        && cw(lower[lower.size() - 2], lower[lower.size() - 1], p[i]))
			{ lower.pop_back(); }
			lower.push_back(p[i]);
		}
	}

	// Now Upper & Lower will contains all elements but since p1, p2 &
	// collinear points lie in both upper & lower halfs, they need to be
	// removed once. Final result is stored back in p vector.
	p.clear();
	for (auto i : upper) p.push_back(i);
	for (auto j : lower) p.push_back(j);
	sort(p.begin(), p.end());
	p.resize(unique(p.begin(), p.end()) - p.begin());
	// This function makes all elements unique
	// but it needs to be sorted first.
}

int main()
{
	file_input_output();
	int n; cin >> n;
	vector<point> p(n);
	for (int i = 0; i < n; i++)
		cin >> p[i].x >> p[i].y;
	convex_hull(p);
	for (auto i : p) cout << i.x << " " << i.y << endl;
}
