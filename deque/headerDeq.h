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
#include <deque>

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
using std::deque;

struct studentas{
    string vardas = "", pavarde = "";
    vector<int> paz;
    int egz;
};

void read (deque<studentas>& id);
double vidurkis (deque<studentas>& id, int n);
double mediana (deque<studentas>& id, int n);
void write (deque<studentas>id);
void autoRead (deque<studentas>& id, string failas);
void autoWrite (deque<studentas> id, string failas, int ask);
void testFiles (int kiekisPaz, vector<string> names, vector<string> surnames, int f);
bool palygintiPavardes(const studentas& a, const studentas& b);
int ask();
int intInput ();
void testWrite (deque<studentas>id, int ask);
void nameSurname (vector<string>& names, vector<string>& surnames);
