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
using std::istream;

#include "studentas.h"

int ask ();
string askCommand (int select);
int intInput ();
string askCommand (int select);
string fileSelect ();
template <typename Container>
void rusiavimasPav (Container& id);

template <typename Container>
void cmdRankinis (Container &id, int baloSkc, int pazPildymas, int kiekis);
template <typename Container>
void writeToCmd (Container& id, int baloSkc);
void writeToSingle (ifstream& is, int baloSkc);

template <typename Container>
void containerLess (Container id, stringstream& zaliocikai, stringstream& eiliniai);
template <typename Container, typename ContainerTemp>
void singleAdd (Container& id, ContainerTemp& zaliocikaiTemp);
template <typename Container, typename ContainerTemp>
void singleAddEnhanced (Container& id, ContainerTemp& zaliocikaiTemp);
template <typename Container, typename ContainerTemp>
void createBuff (Container good, ContainerTemp bad, stringstream& zaliocikai, stringstream& eiliniai);
template <typename Container, typename ContainerTemp>
void doubleAdd (Container id, ContainerTemp& zaliocikaiTemp, ContainerTemp& eiliniaiTemp);
void nameSurname (vector<string>& names, vector<string>& surnames);
void testFiles (int kiekisPaz, vector<string> names, vector<string> surnames, int f);

template <typename Container>
void fileBasic (Container& id, int baloSkc);
template <typename Container>
void readFromFile(Container& id, string failas);

template <typename Container> 
void fileFull (Container& id, int baloSkc, string failas, string strat, string comm, int f, vector<double> &nuskaitymas, vector<double> &rusiavimasPglPavardes, vector<double> &rusiavimasIDviGrupes, vector<string> &failoPav, vector<double> &fileTime, int &PazNum);

void rezSpausdinimas (vector<double> nuskaitymas, vector<double> rusiavimasPglPavardes, vector<double> rusiavimasIDviGrupes, 
vector<string> failoPav, int PazNum, string comm, string strat, int baloSkc, vector<double> &fileTime);
