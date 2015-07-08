#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <exception>
#include <list>
#include <typeinfo>

using namespace std;

struct node{
  int num;
  node();
  node(int v):num(v){};
};

void runDFS(int startNode, std::vector<list<node> > &adj, std::vector< std::vector<int> > &paths, std::vector<int> path);
void printPath(std::vector<std::vector<char> > &arrayIn,std::vector<int> path);
int getNodes(std::vector<std::vector<char> > &arrayIn, std::vector<list<node> > &adj);

