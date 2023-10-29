//implementation of disjoint set, with union by size

class DisjointSet
{
private:
    //array to store parents
    int * const parent;
    //array to store sizes
    int * const size;
    //size of ds
    int sz;

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
    DisjointSet(int s): parent(new int [s]), size(new int[s]), sz(s)
    {
        //making every node its own parent, and initializing sizes
        for(int i = 0; i<s; i++)
        {
            parent[i] = i;
            size[i] = 1;
        }
    }

    //method to do union by rank
    void unionBySize(int a, int b)
    {
        //finding ultimate parents
        int pa = UltP(a);
        int pb = UltP(b);

        if(pa!=pb)
        {
            if(size[pa]<size[pb])
            {
                //pa has less size, connecting it to pb
                parent[pa] = pb;
                size[pb]+=size[pa];
            }
            else
            {
                //pb has less size, connecting it to pa
                parent[pb] = pa;
                size[pa]+=size[pb];
            }
        }
    }

    //method to check if two nodes are connected or not
    bool isConnected(int a, int b)
    {
        return ((UltP(a))==UltP(b));
    }

};