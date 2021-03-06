#include <stdio.h>
#include <set>
#include <algorithm>

struct KNode
{
    int     x;
    int     y;
    KNode(int x_, int y_) : x(x_), y(y_) {}

    bool operator<(const KNode& right) const
    {
        return x < right.x && y < right.y;
        //if (y != right.y)
        //    return y < right.y;
        //return x < right.x;
    }//operator<()

    void Print() const { printf("%i, %i\r\n", x, y); }
};//struct KNode

typedef std::set<KNode> KNODE_SET;

void PrintMap(const KNODE_SET::value_type& rhs_)
{
    rhs_.Print();
}//PrintMap()

void main()
{
    KNODE_SET   nodeSet;
    nodeSet.insert(KNode(1, 2));
    nodeSet.insert(KNode(2, 1));
    nodeSet.insert(KNode(1, 1));
    nodeSet.insert(KNode(2, 2));

    //std::for_each(nodeSet.begin(), nodeSet.end(), PrintMap);
    for (const KNode& n : nodeSet)
    {
        n.Print();
    }
    /*
    1, 2.0
    press any key to continue
    */
}//main()
