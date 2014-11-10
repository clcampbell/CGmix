

#ifndef READFILES_H_
#define READFILES_H_

#include <vector>
#include <string>
#include <iostream>
#include <fstream> // read files
#include <sstream>

using namespace std;

void readSites(const string &sitefname, vector<vector<double> > &sites );
void readLocs(const string &locfname, vector<int> &locs );
void readHapInfo(const string &fname, vector<vector<string> > &hapInfo );

void print1Dvec(const vector<int>& vec);
void print2Dvec(const vector<vector<double> >& vec);
void print2DvecString(const vector<vector<string> >& vec);


#endif


