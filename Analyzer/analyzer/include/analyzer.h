#ifndef __ANALYZER_H__
#define __ANALYZER_H__
#include <map>
#include <set>
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

class Analyzer
{
public:
    Analyzer (string FuncList) 
    {
        LoadFuncList (FuncList);
    }

    ~Analyzer () {}

private:
    map<unsigned, string> FuncId2Name;
    set <unsigned> UnCoveredFuncs;

private:
    inline void LoadFuncList (string FuncList)
    {
        // FuncId2Name
    }
public:
    void StartReadQueue ();
    string GetUncoveredFuncs ();

};
#endif