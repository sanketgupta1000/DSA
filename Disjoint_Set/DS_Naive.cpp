//implementation of disjoint set, with naive union algorithm

class DisjointSet
{
private:
    //array to store parents
    int * const parent;
    //size of ds
    int size;

    //utility function to find ultimate parent of a node
    int UltP(int node)
    {
        if(parent[node]==node)
        {
            return node;
        }
        else
        {
            //path compression
            return (parent[node] = UltP(parent[node]));
        }
    }

public:
    //constructor
    DisjointSet(int s): parent(new int [s]), size(s)
    {
        //making every node its own parent
        for(int i = 0; i<s; i++)
        {
            parent[i] = i;
        }
    }

    //method to do union
    void union_(int a, int b)
    {
        //finding ultimate parents
        int pa = UltP(a);
        int pb = UltP(b);

        if(pa!=pb)
        {
            parent[pa] = pb;
        }
    }

    //method to check if two nodes are connected or not
    bool isConnected(int a, int b)
    {
        return ((UltP(a))==UltP(b));
    }

};