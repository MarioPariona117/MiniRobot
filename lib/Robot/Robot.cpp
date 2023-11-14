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
    double turn_t, forward_t;
    Maze maze;
public:
    ImplementRobot():maze(){};
    void find_distances_Dijkstra(){ // Tryint to implement Dijkstra to computer minimum distance
        priority_queue<pair<ld, const Point*>> q; // let's insert {-distance, Point}
        maze.clear();
        q.push(pair<ld, const Point*> {0, maze.getPoint(0, 5, 1)}); // at the beginning going right
        while(!q.empty()){
            ld cur_time_to_u = -q.top().first;
            const Point* u = q.top().second;
            q.pop();
            if(maze.get_time_computed(u) != cur_time_to_u) continue; // means that time_computed[u] < cur_distance_to_u
            for(const Point* p : maze.neighbor_points(u)){
                ld w = maze.distance(p, u);
                if(maze.get_time_computed(p) > maze.get_time_computed(u) + w){
                    maze.set_time_computed(p, maze.get_time_computed(u) + w);
                    maze.set_prev(p, u);
                    q.push(pair<ld, const Point*> {-maze.get_time_computed(p), p});
                }
            }
        }
    }

    vector<Action> compute_best_path(){
        vector<Action> actions;
        const Point* iter = maze.getPoint(11, 5, 1);
        const Point* const start = maze.getPoint(0, 5, 1);
        while(iter != start){
            const Point* prev = maze.get_prev(iter);
            actions.push_back(get_action(prev, iter));
            iter = prev;
        }
    }
    void solve_maze(){
        find_distances_Dijkstra();
        vector<Action> actions = compute_best_path();
        for()
    }
};