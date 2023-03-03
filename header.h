#pragma once
#include <iomanip>
#include <string>
#include <iostream>
#include <random>
#include <vector>
#include <algorithm>
#include <cctype>
#include <fstream>

using std::string;
using std::cout;
using std::cin;
using std::stoi;
using std::left;
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

struct studentas{
    string vardas = "", pavarde = "";
    vector<int> paz;
    int egz;
};

void read (vector<studentas> *id);
double vidurkis (vector<studentas> *id, int n);
double mediana (vector<studentas> *id, int n);
void write (vector<studentas>id);
void autoRead (vector<studentas> *id);
void autoWrite (vector<studentas> id);
bool palygintiPavardes(const studentas& a, const studentas& b);