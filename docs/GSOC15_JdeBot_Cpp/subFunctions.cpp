#include "subFunctions.h"
using namespace std;


void runDFS(int startNode, std::vector<list<node> > &adj, std::vector< std::vector<int> > &paths, std::vector<int> path){
  int curNode;
  path.push_back(startNode);
  for (list<node>::iterator it=adj[startNode].begin();it != adj[startNode].end();it++){
    curNode=it->num;
    if(find(path.begin(),path.end(),curNode) != path.end()){
      // Current node exists in path.
      paths.push_back(path);
      continue;
    } else {
      // Current node does not exists in path. Do a recursive call:
      runDFS(curNode,adj,paths,path);
    }
  }
}

void printPath(std::vector<std::vector<char> > &arrayIn,std::vector<int> path){
  // Prints the labyrinth with path.
  double rows=arrayIn.size();
  double cols=arrayIn[0].size();
  for(int i=0;i<rows;i++){
    for(int j=0;j<cols;j++){
      if (arrayIn[i][j]!='#'){
        //If the node is present in path, print its index:
        std::vector<int>::iterator it = find(path.begin(),path.end(),int(arrayIn[i][j]-48));
        if(it != path.end()){
          cout << it - path.begin();
        }
        //Else print . (dot)
        else{
          cout << ".";
        }
      }else{
        cout << "#";
      }
    }
    cout << endl;
  }  
}


int getNodes(std::vector<std::vector<char> > &arrayIn, std::vector<list<node> > &adj){
  double rows=arrayIn.size();
  double cols=arrayIn[0].size();
  //cout << "number of cols: " << cols << "number of rows: " << rows << endl;
  int nod=48;
  for(int i=0;i<rows;i++){
    for(int j=0;j<cols;j++){
      if (arrayIn[i][j]=='.'){
        arrayIn[i][j]=char(nod++);
      }
    //  cout << arrayIn[i][j] << " ";
    }
    //cout << endl;
  }
  adj.resize(nod-47); //Number of nodes + 1
  for(int i=0;i<rows;i++){
    for(int j=0;j<cols;j++){
      if (arrayIn[i][j]!='#'){
        // Process for all nodes found in labyrinth
        adj[int(arrayIn[i][j]-48)].push_back(node(int(arrayIn[i][j]-48)));
        try{
          char neighbour=arrayIn.at(i-1).at(j);
          if (neighbour != '#'){
            adj[int(arrayIn[i][j]-48)].push_back(node(int(neighbour-48)));
          }
        } catch (exception& e){
          //cout << "Standard exception: " << e.what() << endl;
        }
        try{
          char neighbour=arrayIn.at(i).at(j-1);
          if (neighbour != '#'){
            adj[int(arrayIn[i][j]-48)].push_back(node(int(neighbour-48)));
          }
        } catch (exception& e){
          //cout << "Standard exception: " << e.what() << endl;
        }
        try{
          char neighbour=arrayIn.at(i+1).at(j);
          if (neighbour != '#'){
            adj[int(arrayIn[i][j]-48)].push_back(node(int(neighbour-48)));
          }
        } catch (exception& e){
          //cout << "Standard exception: " << e.what() << endl;
        }
        try{
          char neighbour=arrayIn.at(i).at(j+1);
          if (neighbour != '#'){
            adj[int(arrayIn[i][j]-48)].push_back(node(int(neighbour-48)));
          }
        } catch (exception& e){
          //cout << "Standard exception: " << e.what() << endl;
        }
      }
    //  cout << arrayIn[i][j] << " ";
    }
    //cout << endl;
  }
  // Return number of nodes.
  return (nod - 48);
}
