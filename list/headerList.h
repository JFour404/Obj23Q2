#pragma once
#include <iomanip>
#include <string>
#include <iostream>
#include <random>
#include <vector>
#include <algorithm>
#include <cctype>
#include <sstream>
#include <fstream>
#include <limits>
#include <chrono>
#include <list>

using std::string;
using std::cout;
using std::cin;
using std::stoi;
using std::left;
using std::right;
using std::fixed;
using std::setw;
using std::setprecision;
using std::mt19937;
using std::random_device;
using std::uniform_int_distribution;
using std::vector;
using std::isspace;
using std::endl;
using std::ifstream;
using std::stringstream;
using std::ofstream;
using std::sort;
using std::runtime_error;
using std::exception;
using std::cerr;
using std::to_string;
using std::count_if;
using std::isdigit;
using std::list;
using std::advance;

struct studentas{
    string vardas = "", pavarde = "";
    vector<int> paz;
    int egz;
    double vidurkis;
};

void read (list<studentas>& id);
double vidurkis(const list<studentas>& id, list<studentas>::const_iterator it);
double mediana (const list<studentas>& id, list<studentas>::const_iterator it);
void write (list<studentas>id);
void autoRead (list<studentas>& id, string failas);
void autoWrite (list<studentas> id, string failas, int ask);
void testFiles (int kiekisPaz, vector<string> names, vector<string> surnames, int f);
bool palygintiPavardes(const studentas& a, const studentas& b);
int ask();
int intInput ();
void testWrite (list<studentas>id, int ask);
void nameSurname (vector<string>& names, vector<string>& surnames);
void doubleAdd (list<studentas>& id, int ask, list<studentas>& zaliocikaiTemp, list<studentas>& eiliniaiTemp);
