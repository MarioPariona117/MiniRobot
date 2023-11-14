#include <stdlib.h>
#include <assert.h>
// #include <algorithm>

using std::vector;

class Point{
public:
    int x, y;
    short int d;
    // DIRECTION CONVENTION
    // 0 : UP
    // 1 : RIGHT
    // 2 : DOWN
    // 3 : LEFT
    Point(): x(0), y(0){};
    Point(int _x, int _y, int _d): x(_x), y(_y), d(_d){};
};

class Maze{
    bool wall[12][12][4];
    Point points[12][12][4];
    ld time_computed[12][12][4];
    const Point* prev[12][12][4];
    static const long double turn_time = 1;
    static const long double forward_time = 1;
    static const short int dx[4], dy[4];
public:
    Maze(){
        for(int i = 0; i < 12; i++)
            for(int j = 0; j < 12; j++)
                for(int k = 0; k < 4; k++)
                    points[i][j][k] = Point(i, j, k);
    }

    const Point* getPoint(int x, int y, short int d){
        if(d > 4 || d < 0) return nullptr;
        if((x > 0 && x < 11 && y > 0 && y < 11) || ((x == 0 || x == 11) && (y == 5))) return &points[x][y][d];
        return nullptr;
    }

    long double distance(const Point*& p, const Point*& q){
        if(q->x == p->x && q->y == p->y){
            assert(abs(q->d - p->d) != 2);
            return turn_time;
        }
        assert(abs(q->x - p->x) + abs(q->y - p->y) == 1);
        assert(q->d == p->d);
        assert(p->x + dx[p->d] == q->x && p->y + dy[p->d] == q->y);
        return forward_time;
    }

    vector<const Point*> neighbor_points(const Point* u){
        vector<const Point*> res = {getPoint(u->x, u->y, (u->d + 1) % 4), getPoint(u->x, u->y, (u->d + 3) % 4)};
        const Point* aux = getPoint(u->x + dx[u->d], u->y + dy[u->d], u->d);
        if(aux != nullptr && !wall[u->x][u->y][u->d]) res.push_back(aux);
        return res;
    }

    void clear(){
        for(int i = 1; i < 11; i++)
                for(int j = 1; j < 11; j++)
                    for(int k = 0; k < 4; k++)
                        time_computed[i][j][k] = INF;
        time_computed[11][5][1] = INF, time_computed[0][5][1] = 0;
    }

    long double get_time_computed(const Point* u){
        return time_computed[u->x][u->y][u->d];
    }

    void set_time_computed(const Point* u, const long double& t){
        time_computed[u->x][u->y][u->d] = t;
    }

    void set_prev(const Point* u, const Point* p){
        prev[u->x][u->y][u->d] = p;
    }

    const Point* get_prev(const Point* u){
        return prev[u->x][u->y][u->d]; 
    }

};

const short int Maze::dx[4]=  {1, 0, -1, 1};
const short int Maze::dy[4] = {0, 1, 0, -1};