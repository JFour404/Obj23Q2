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
using std::remove_if;

struct studentas{
    string vardas = "", pavarde = "";
    vector<int> paz;
    int egz;
    double vidurkis;
};

template <typename Container>
void read (Container& id);
template <typename Container>
void write (Container id);
template <typename Container>
void autoRead (Container& id, string failas);
template <typename Container>
void autoWrite (Container id, string failas, int ask);
template <typename Container>
void testWrite (Container id, int ask, string strat, string comm, int boost, vector<double> &rusiavimasIDviGrupes);
template <typename Container>
void containerLess (Container id, stringstream& zaliocikai, stringstream& eiliniai, int ask);
template <typename Container, typename ContainerTemp>
void singleAdd (Container& id, int ask, ContainerTemp& zaliocikaiTemp);
template <typename Container, typename ContainerTemp>
void singleAddEnhanced (Container& id, int ask, ContainerTemp& zaliocikaiTemp);
template <typename Container, typename ContainerTemp>
void createBuff (Container good, ContainerTemp bad, stringstream& zaliocikai, stringstream& eiliniai);
template <typename Container, typename ContainerTemp>
void doubleAdd (Container& id, int ask, ContainerTemp& zaliocikaiTemp, ContainerTemp& eiliniaiTemp);

void pazNum(string failas, int &testPazNum);

void testFiles (int kiekisPaz, vector<string> names, vector<string> surnames, int f);
int ask();
int intInput ();
bool palygintiPavardes(const studentas& a, const studentas& b);
void nameSurname (vector<string>& names, vector<string>& surnames);
string askCommand (int select);
void rezSpausdinimas (vector<double> nuskaitymas, vector<double> rusiavimasPglPavardes, vector<double> rusiavimasIDviGrupes, vector<string> failoPav, int PazNum, string comm, string strat, int boost, int baloSkc, vector<double> &fileTime);

template <typename Container>
double vidurkisV2 (Container& id);
template <typename Container>
double medianaV2(Container& id);

template <typename Container>
void prep (Container& id, int testON, int genFiles, int &testPazNum, int baloSkc, string strat, string comm, int boost, vector<double> &nuskaitymas, vector<double> &rusiavimasPglPavardes, vector<double> &rusiavimasIDviGrupes, vector<string> &failoPav, vector<double> &fileTime);


