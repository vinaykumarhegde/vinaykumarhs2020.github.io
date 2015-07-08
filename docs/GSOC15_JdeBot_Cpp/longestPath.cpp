/********************************************************
GSOC-2015 C++ Challenge for JdeBot.
Author: Vinaykumar Hegde
Date: Mar 20, 2015
********************************************************/
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <exception>
#include <list>
#include <typeinfo>
#include "subFunctions.h"

using namespace std;


int main (int argc, char *argv[]) {
  if (argc < 2){
    fprintf(stdout,"Usage: %s <filename>\n",argv[0]);
    return 1;
  }
  std::vector<std::vector<char> > labirynth;
  string line;int i=0;
  ifstream myfile (argv[1]);
  if (myfile.is_open()){
    while ( getline (myfile,line) ){
      std::vector<char> v;
      for (int j=0;j<line.size();j++){
        v.push_back(line[j]);
      }
      labirynth.push_back(v);
    }
    myfile.close();
  }
  else cout << "Unable to open file";
  std::vector<list<node> > adj;
  std::vector< std::vector<int> > paths;
  std::vector<int> path;
  int nrNodes=getNodes(labirynth,adj);
  for(int i=0;i<=nrNodes;i++){
    runDFS(i,adj,paths,path);
  }
  int maxSize=0;int index=0;
  for(int j=0;j<paths.size();j++){
    if(paths[j].size()>maxSize){
      index=j;
      maxSize=paths[j].size();
    }
  }
  //cout << "Max size:" << maxSize << "Index: " << index << endl;
  cout << maxSize << endl;
  printPath(labirynth,paths[index]);
  return 0;
}