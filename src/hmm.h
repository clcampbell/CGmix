/*
 * hmm.h
 *
 *  Created on: Nov 10, 2014
 *      Author: ccampbell
 */

#ifndef HMM_H_
#define HMM_H_

#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#include <iomanip>
#include <cmath>
#include <limits>
// #include <sstream>

#include "readFiles.h"
#include "parameters.h"

using namespace std;

class hmmStates 
{
    public:
        hmmStates(){};
        ~hmmStates(){};
        vector<string> states;
        vector<int> Xpop, Xhap, Gpop, Ghap, Xindx, Gindx;
};

void generateStates(const hapDef &hapInfo, hmmStates &st );
void generateXstates(const hapDef &hapInfo, hmmStates &st );

void getXtrans(const int &to, const int &from, const double &d, const double &r, const hmmStates &st, const parameters &p, double &trX );

void getsprob( 
        const vector<int> &sites0, 
        const parameters &p, 
        const hmmStates &st,
        const vector<int> &obs,
        vector<double> &sprob );
void getsprobX( 
        const vector<int> &sites0, 
        const parameters &p, 
        const hmmStates &st,
        const vector<int> &obs,
        vector<double> &sprob );

double lookupXtrans(const int &to, const int &from, const double &d, const double &r, const hmmStates &st, const parameters &p, vector<double> &trXbin );
double lookupGtrans(const int &to, const int &from, const double &d, const double &r, const hmmStates &st, const parameters &p, vector<double> &trGbin );

void forward( 
        const vector<vector<int> > &sites,
        const positions &pos,
        const parameters &p,
        const hmmStates &st,
        const vector<int> &obs,
        const vector<double> &sprob,
        vector<vector<double> > &fwd );
void forward2( 
        const vector<vector<int> > &sites,
        const positions &pos,
        const parameters &p,
        const hmmStates &st,
        const hmmStates &st2,
        const vector<int> &obs,
        const vector<double> &sprob,
        const vector<int> &pswitch,
        vector<vector<double> > &fwd );

void backward(
        const vector<vector<int> > &sites,
        const positions &pos,
        const parameters &p,
        const hmmStates &st,
        const vector<int> &obs,
        const vector<double> &sprob,
        vector<vector<double> > &bwd,
        double &Pxb );
void backward2(
        const vector<vector<int> > &sites,
        const positions &pos,
        const parameters &p,
        const hmmStates &st,
        const hmmStates &st2,
        const vector<int> &obs,
        const vector<double> &sprob,
        const vector<int> &pswitch,
        vector<vector<double> > &bwd,
        double &Pxb);

void printMat( const vector<vector<double> > &mat );
void writeMat( const vector<vector<double> > &mat, ofstream &matfile );
void writeTmat( const vector<vector<double> > &mat, ofstream &matfile );
void logSumExp( const vector<double> &vec, double &lse );
void postDecode(
        const vector<vector<double> > &fwd,
        const vector<vector<double> > &bwd,
        const hmmStates &st,
        const double &Px,
        vector<vector<double> > &pprob,
        vector<string> &pppath,
        vector<double> &ppprob,
        vector<int> &pswitch,
        ofstream &logfile);

void viterbi(
        const vector<vector<int> > &sites,
        const positions &pos,
        const parameters &p,
        const hmmStates &st,
        const vector<int> &obs,
        const vector<double> &sprob,
        vector<vector<double> > &vit,
        vector<string> &vpath,
        vector<double> &vprob );
void viterbi2(
        const vector<vector<int> > &sites,
        const positions &pos,
        const parameters &p,
        const hmmStates &st,
        const vector<int> &obs,
        const vector<double> &sprob,
        const vector<int> &pswitch,
        vector<vector<double> > &vit,
        vector<string> &vpath,
        vector<double> &vprob );

void max( const vector<double> &vec, double maxelement );


#endif


