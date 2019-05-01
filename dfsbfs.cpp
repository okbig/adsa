#include<iostream>
#define MAX 20
using namespace std;

class graph
{
    friend class stack;
    int n,i,j;
    int adj[MAX][MAX];
    int visited[MAX];

public:
    graph()
    {
        for(i=0;i<MAX;i++)
        {
            for(j=0;j<MAX;j++)
            {
                adj[i][j] = 0;
            }
        }

    }
    void create();
    void dfs();
    void bfs();
    void initialize_visited();
};

class stack
{
    int item[MAX];
    int top;

    public:
        stack() { top = -1;}
        int pop();
        int isEmpty();
        int isFull();
        void push(int);
};//stack declaration

class queue
{
    int item[MAX];
    int front , rear;

    public:
        queue() {front = rear = -1;}
        int pop();
        int isEmpty();
        int isFull();
        void push(int);
};//Queue declaration

/* Stack Definitions Starts here */

int stack :: pop()
{
    int x;
    if(isEmpty())
    cout<<"\n Stack Empty.";
    else
    {
        x = item[top];
        top--;
    }
    return x;
}//pop

int stack :: isEmpty()
{
    if(top==-1)
        return 1;
    else
        return 0;
}//isEmpty

int stack :: isFull()
{
    if(top==MAX)
        return 1;
    else
        return 0;
}//isFull

void stack :: push(int x)
{
    if(isFull())
        cout<<"\n Stack is Full";
    else
    {
        top++;
        item[top] = x;
    }

}

/* Stack definitions Ends here */

/* Queue definitions starts here */
int queue :: pop()
{
    int x;
    if(isEmpty())
    cout<<"\n Queue is Empty.";
    else
    {
        x = item[front];
        front++;
    }
    return x;
}//pop

int queue :: isEmpty()
{
    if((front==-1) || (front>rear))
        return 1;
    else
        return 0;
}//isEmpty

int queue :: isFull()
{
    if(front==MAX)
        return 1;
    else
        return 0;
}//isFull

void queue :: push(int x)
{
    if(isFull())
        cout<<"\n Queue is Full";
    else
    {
        if(front==-1)
            front++;
        item[++rear] = x;
    }

}

/* Queue definitions Ends here */



void graph :: create()
{
    int ch;
    cout<<"No. of vertices in the graph";
    cin >>n;

    for(i=0;i<n-1;i++) //vertices/nodes
        {
            for(j=i+1;j<n;j++)//Adjacency nodes
            {
                cout<<"Does "<<i<<" and "<<j<<" has edge between them ? : ";
                cin>>ch;
                if(ch==1)
                {
                    adj[i][j]=1;
                    adj[j][i]=1;
                }

            }
        }
}//created

void graph :: dfs()
{
    stack s;
    int i;
    cout<<"\n\t DFS \n";
    cout<<"Enter starting vertex :: ";
    cin>>i;

    s.push(i);//push starting vertex into stack
    while(!s.isEmpty()) //till stack is not empty
    {
        i = s.pop(); // pop the vertex
        if(visited[i]==1)//give if the vertex is visited
            continue;

        cout<<" "<<i;//print the vertex
        visited[i] = 1;//set is as visited

        for(int k=0;k<n;k++)
        {
            if(adj[i][k]==1 && visited[k]==0)
                s.push(k);
        }//for

    }//while
}//dfs

void graph :: bfs()
{
    queue q;
    int i;
    cout<<"\n\t BFS \n";
    cout<<"Enter starting vertex :: ";
    cin>> i;

    q.push(i);//push starting vertex into queue
    while(!q.isEmpty()) //till queue is not empty
    {
        i = q.pop(); // pop the vertex from queue
        if(visited[i]==1)//ignore if the vertex is visited
            continue;

        cout<<" "<<i;//print the vertex
        visited[i] = 1;//set is as visited

        for(int k=0;k<n;k++)//for accesing adjacent elements of i
        {
            if(adj[i][k]==1 && visited[k]==0)//if edge is present and new vertex is not visited
                q.push(k);
        }//for

    }//while

}//bfs

void graph :: initialize_visited()
{
    for (int i=0;i<MAX;i++)
        visited[i]=0;
}

int main()
{

    graph g;
    g.create();
    g.initialize_visited();
    g.dfs();
    g.initialize_visited();
    g.bfs();
    return 0;
}
