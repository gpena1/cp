#include <iostream>
#include <vector>
#include <algorithm>

#define x first
#define y second
#define epsilon 1e-6
#define vec(p,q) {q.x-p.x, q.y-p.y}

using namespace std;
using ll = long long;
using point = pair<ll, ll>;

// Function to compute the cross product of two vectors
ll cross(const point& a, const point& b) {
    return a.x * b.y - a.y * b.x;
}

// Function to compute the convex hull, including collinear points
vector<point> convex_hull(vector<point>& points) {
    sort(points.begin(), points.end());

    vector<point> hull;

    // Build the lower hull
    for (const auto& p : points) {
        while (hull.size() >= 2 && cross(vec(hull[hull.size() - 2], hull[hull.size() - 1]), vec(hull[hull.size() - 1], p)) < 0) {
            hull.pop_back();
        }
        hull.push_back(p);
    }

    // Build the upper hull
    size_t lower_hull_size = hull.size();
    for (auto it = points.rbegin(); it != points.rend(); ++it) {
        while (hull.size() > lower_hull_size && cross(vec(hull[hull.size() - 2], hull[hull.size() - 1]), vec(hull[hull.size() - 1], (*it))) < 0) {
            hull.pop_back();
        }
        // Avoid adding the same point twice
        if (hull.back() != *it) {
            hull.push_back(*it);
        }
    }

    hull.pop_back(); // Remove the last point because it's the same as the first point in the lower hull

    return hull;
}