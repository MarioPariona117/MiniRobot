
class Point{
private:
    int x, y;
    int d;
    // DIRECTION CONVENTION
    // 0 : UP
    // 1 : RIGHT
    // 2 : DOWN
    // 3 : LEFT
public:
    Point(): x(0), y(0);
    Point(int _x, int _y, int d): x(_x), y(_y), d(_d);
}