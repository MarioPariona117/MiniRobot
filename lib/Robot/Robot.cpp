#include "Robot.h"
#include "../Point/Point.h"

#include <map> // for map<N, M>
#include <vector> // for vector<N>
#include <queue> // for priority_queue<N>
#include <utility> // for pair<N, M> :: for pair<int, int> a({1, 2}), we have a.first = 1, a.second = 2

using std::map;
using std::vector;
using std::priority_queue;
using std::pair;

typedef long double ld;

const ld INF = 1e9;

class ImplementRobot: public Robot{
private:
    map<Point, vector<Point>> neighboors;
    map<Point, ld> time_computed;
    double turn_t, forward_t;
public:
    void compute_best_path(){ // Tryint to implement Dijkstra to computer minimum distance
        priority_queue<pair<ld, Point>> q; // let's insert {-distance, Point}
        for(auto p : neighboors){
            time_computed[p.first] = INF;
        }
        time_computed[Point(0, 0, 1)] = 0;
        q.push(pair<ld, Point>{0, Point(0, 0, 1)}); // at the beginning going right
        while(q.empty()){ 
            ld cur_distance_to_u = q.top().first;
            Point u = q.top().second;
            q.pop();
            if(time_computed[u] != cur_distance_to_u) continue; // means that time_computed[u] < cur_distance_to_u
            for(Point p : neighboors[u]){
                ld w = calc(q, p);
                if(time_computed[p] > time_computed[u] + w){
                    time_computed[p] = time_computed[u] + w;
                    q.push({-time_computed[p], p});
                }
                
            }
        }
    }
    void solve_maze(){
    }
};