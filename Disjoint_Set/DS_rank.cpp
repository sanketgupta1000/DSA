//implementation of disjoint set, with union by rank

class DisjointSet
{
private:
    //array to store parents
    int * const parent;
    //array to store ranks
    int * const rank;
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
    DisjointSet(int s): parent(new int [s]), rank(new int[s]), size(s)
    {
        //making every node its own parent, and initializing ranks
        for(int i = 0; i<s; i++)
        {
            parent[i] = i;
            rank[i] = 1;
        }
    }

    //method to do union by rank
    void unionByRank(int a, int b)
    {
        //finding ultimate parents
        int pa = UltP(a);
        int pb = UltP(b);

        if(pa!=pb)
        {
            if(rank[pa]<rank[pb])
            {
                //pa has less rank, connecting it to pb
                parent[pa] = pb;
            }
            else if(rank[pb]<rank[pa])
            {
                //pb has less rank, connecting it to pa
                parent[pb] = pa;
            }
            else
            {
                //both have same rank
                parent[pa] = pb;
                rank[pb]++;
            }
        }
    }

    //method to check if two nodes are connected or not
    bool isConnected(int a, int b)
    {
        return ((UltP(a))==UltP(b));
    }

};