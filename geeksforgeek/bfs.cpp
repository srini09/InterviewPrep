#include<iostream>
#include<map>
#include<list>
#include<queue>
#include<cstring>

using namespace std;

class myGraph
{
public:
myGraph(){};
myGraph(int V);
void addEdge(int i, int j);
void printEdges();
void BFS(int Root);
private:
int nVertices;
/*adjacency list*/
list<int> *iEdges;
bool *iVisited;
};


myGraph::myGraph(int V)
{
	nVertices = V;
	iEdges = new list<int>[V];		
	iVisited = new bool[V];
	memset(iVisited,false,sizeof(bool)*V);
}

void myGraph::addEdge(int i, int j)
{
	iEdges[i].push_back(j);
}
void myGraph::BFS(int S)
{

	iVisited[S] = true;
	queue<int>layers;
	layers.push(S);
	while(!layers.empty())
{

	int s	= layers.front();
	cout<<s<<" ";
	layers.pop();
	/*get the adjacent vertices and put them in q*/
	list<int>::iterator it;
	for(it = iEdges[s].begin(); it != iEdges[s].end() && !iVisited[*it]; ++it)
	{
		layers.push(*it);
		iVisited[*it] = true;
	}	
}		
}
 
void myGraph::printEdges()
{
	list<int>::iterator it;
	int i;
	for(i=0;i<nVertices;i++)
        {
		list<int> temp = iEdges[i];
		for(it = temp.begin();it != temp.end(); ++it)
		{
			cout<<i<<", "<<*it <<endl;
		}
		cout<<endl;
		
	}
}



int main()
{
myGraph G(4);
G.addEdge(0,1);
G.addEdge(0,2);
G.addEdge(1,2);
G.addEdge(2,0);
G.addEdge(2,3);
G.addEdge(3,3);
G.printEdges();
cout<<"BFS"<<endl;
G.BFS(2);
cout<<endl;
}
