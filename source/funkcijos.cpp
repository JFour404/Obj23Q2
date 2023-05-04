#include "header.h"

int ask () {
    string input;
    while (1) {
        if (!(cin >> input) || count_if(input.begin(), input.end(), [](char c){ return !isdigit(c); }) > 0 || input.find_first_of(",.") != string::npos||(input!="1" && input!="0")) {
            cout << "Neteisinga ivestis. Prasome ivesti is naujo" << std::endl;
            cin.clear(); 
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        } else {
            break;
        }
    }
    return stoi(input);
}
string askCommand (int select) {
    string input;
    if (select==0){
        while(1){
        if (!(cin >> input)||(input!="/v"&&input!="/l"&&input!="/d")){
            cout << "Neteisinga ivestis. Prasome ivesti is naujo" << std::endl;
            cin.clear(); 
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); 
            } else break;
        } 
    }
    if (select==1){
        while(1){
        if (!(cin >> input)||(input!="/0c"&&input!="/1c"&&input!="/2c")){
            cout << "Neteisinga ivestis. Prasome ivesti is naujo" << std::endl;
            cin.clear(); 
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); 
            } else break;
        } 
    }
    return input;
}
int intInput () {
    string input;
    while (1) {
        if (!(cin >> input) || count_if(input.begin(), input.end(), [](char c){ return !isdigit(c); }) > 0 || input.find_first_of(",.") != string::npos) {
            cout << "Neteisinga ivestis. Prasome ivesti is naujo" << std::endl;
            cin.clear(); 
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        } else {
            break;
        }
    }
    return stoi(input);
}
string fileSelect () {
    string failas;
    cout << "Prieinami failai: \n";
    system("cd ..\\data\\ && dir /b | findstr \\.txt$");
    while (1) {
        cout << "Iveskite failo pavadinima is saraso, is kurio norite nuskaityti duomenis: \n";
        cin >> failas;
        try {
            ifstream open_f("../data/" + failas);
            if (!open_f) throw runtime_error("Failas nerastas arba nepavyko atidaryti.");
            break;
        }
        catch (exception const& e) {
            cerr << "Klaida: " << e.what() << endl; 
        }                     
    }
    return failas;
}
template <typename Container>
void rusiavimasPav (Container& id) {
    if constexpr (std::is_same_v<Container, std::vector<studentas>>) {
        sort(id.begin(), id.end(), palygintiPavardes);
    } else if constexpr (std::is_same_v<Container, std::list<studentas>>) {
        id.sort(palygintiPavardes);
    } else if constexpr (std::is_same_v<Container, std::deque<studentas>>) {
        sort(id.begin(), id.end(), palygintiPavardes);
    } 
}

template <typename Container>
void cmdRankinis (Container &id, int baloSkc, int pazPildymas, int kiekis) {
    try {
        while (1){
            studentas temp(cin, baloSkc, pazPildymas, kiekis);
            id.push_back(temp);
        }
    } catch (const runtime_error& e) {
        cerr << e.what() << endl;
    }
    writeToCmd (id, baloSkc);
}
template <typename Container>
void writeToCmd (Container& id, int baloSkc){
    if (!id.empty()){
        cout << "\n---------------------------------------------------\n";
        cout << left << setw (20) << "Pavarde" << left << setw (15) << "Vardas" << left << setw (10) << "Galutinis";
        if (baloSkc == 1)
            cout << "(Vid.)\n";    
        else
            cout << "(Med.)\n";
        cout << "---------------------------------------------------\n";
                 
        for (auto it = id.begin(); it != id.end(); ++it){
            cout << left << setw(20) << it->Pavarde() << left << setw(15) << it->Vardas();
            if (baloSkc == 1)
            cout << fixed << setprecision(2) << it->GalBalas() << "\n";
            else
            cout << fixed << setprecision(2) << it->GalBalas() << "\n";
        }    
    } 
}

template <typename Container>
void fileBasic (Container& id, int baloSkc){
    string failas = fileSelect ();
    
    readFromFile(id, failas);

    for (auto it = id.begin(); it != id.end(); ++it)
    it->GalBalas(baloSkc);
    rusiavimasPav (id);
    
    writeToSingle(id, baloSkc);
}
template <typename Container>
void readFromFile(Container& id, string failas) { 
    stringstream buferis;
    string eil;

    ifstream open_f("../data/" + failas);
    if (!open_f.is_open()) {
        throw runtime_error("Nepavyko atidaryti " + failas);
    }
    
    buferis << open_f.rdbuf();
    open_f.close();

    buferis.seekg(0); 
    getline(buferis, eil);

    while (getline(buferis, eil)) { 
        stringstream ss(eil);
        studentas temp(ss);
        id.push_back(temp);
    }
}
template <typename Container>
void writeToSingle (Container& id, int baloSkc) {
    stringstream outputas;

    outputas << left << setw(40) << "Pavarde" << left << setw(30) << "Vardas";
    if (baloSkc == 0)
        outputas << "Bendras(med.)\n";
    else
        outputas << "Bendras(vid.)\n";
    
    for (auto it = id.begin(); it != id.end(); ++it) {
        outputas << left << setw(40) << it->Pavarde() << left << setw(30) << it->Vardas() 
        << fixed << setprecision(2) << it->GalBalas() << "\n";
        }
    
    ofstream out_f("../data/studentai_copy.txt");
    out_f << outputas.str();
    out_f.close();
}

template <typename Container>
void containerLess (Container id, stringstream& zaliocikai, stringstream& eiliniai){
    for (auto it=id.begin(); it!=id.end(); ++it){ 
        if (it->GalBalas()<5){
            zaliocikai << left << setw(40) << it->Pavarde() << left << setw(30) << it->Vardas() << right << setw(8) << fixed << setprecision(2) << it->GalBalas() << "\n";
        } 
        else
            eiliniai << left << setw(40) << it->Pavarde() << left << setw(30) << it->Vardas() << right << setw(8) << fixed << setprecision(2) << it->GalBalas() << "\n";
        } 
}
template <typename Container, typename ContainerTemp>
void singleAdd (Container& id, ContainerTemp& zaliocikaiTemp) {
    for (auto it=id.begin(); it!=id.end(); ){
        if (it->GalBalas()<5){
            zaliocikaiTemp.push_back(*it);
            it = id.erase(it);
        } else {
            ++it;
        }
    }
}
template <typename Container, typename ContainerTemp>
void singleAddEnhanced (Container& id, ContainerTemp& zaliocikaiTemp){
    auto temp = remove_if(id.begin(), id.end(), [&](const studentas &student){
        if (student.GalBalas() <5) {
            zaliocikaiTemp.push_back(student);
            return true;
        } 
        return false;
    });
    id.erase(temp, id.end());
}
template <typename Container, typename ContainerTemp>
void doubleAdd (Container id, ContainerTemp& zaliocikaiTemp, ContainerTemp& eiliniaiTemp) {
    for (auto it=id.begin(); it!=id.end(); ++it){
        if (it->GalBalas()<5){
            zaliocikaiTemp.push_back(*it);
        } else {
            eiliniaiTemp.push_back(*it);
        }
    }
}
template <typename Container, typename ContainerTemp>
void createBuff (Container good, ContainerTemp bad, stringstream& zaliocikai, stringstream& eiliniai) {
    for (auto it=good.begin(); it!=good.end(); ++it)
        eiliniai << left << setw(40) << it->Pavarde() << left << setw(30) << it->Vardas() << right << setw(8) << fixed << setprecision(2) << it->GalBalas() << "\n";
          
    for (auto it=bad.begin(); it!=bad.end(); ++it)
        zaliocikai << left << setw(40) << it->Pavarde() << left << setw(30) << it->Vardas() << right << setw(8) << fixed << setprecision(2) << it->GalBalas() << "\n";
}
void nameSurname (vector<string>& names, vector<string>& surnames){
    string eil;
    stringstream buferis;
    //----------------------------------nuskaitomi vardai, naudojant buferi---------------------------------   
    ifstream fd1("../data/names18239.txt");
    buferis << fd1.rdbuf();
    fd1.close();
    
    while (buferis){
        if (!buferis.eof()){
            getline (buferis, eil);
            names.push_back(eil);
        } else break;
    }
    buferis.clear();
//--------------------------------------nuskaitomos pavardes, naudojant buferi----------------------------
    ifstream fd2("../data/surnames29638.txt");
    buferis << fd2.rdbuf();
    fd2.close();
    
    while (buferis){
        if (!buferis.eof()){
            getline (buferis, eil);
            surnames.push_back(eil);
        } else break;
    }
}
void testFiles (int kiekisPaz, vector<string> names, vector<string> surnames, int f){
//------------------------------------pazymiu generavimas, duomenu suglaudimas-------------------------------------------------------
    stringstream outputas;
    string failas;
    
    random_device rd;
    mt19937 genSur(rd());
    uniform_int_distribution <int> distSur(1,29600);
    mt19937 genNam(rd());
    uniform_int_distribution <int> distNam(1,18200);
    mt19937 genPaz(rd());
    uniform_int_distribution <int> distPaz(1,10);
    
    for (int i=0; i<f; i++){ 
        outputas << left << setw(30) <<  names[distNam(genNam)]   << left << setw(40) << surnames[distSur(genSur)];
        for (int j=0; j<kiekisPaz; j++) outputas << left << setw(8) << distPaz(genPaz);
        outputas << right << setw(8) << distPaz(genPaz) << "\n";
    }
    //-------------------------------------duomenu isvedimas--------------------------------------------------------------------------------
    failas = "studentai" + to_string(f) + ".txt";    
    ofstream out_f("../data/" + failas);
        
    out_f << left << setw(30) << "Vardas" << left << setw(40) << "Pavarde";
    for (int j=0; j<kiekisPaz; j++) out_f << "Nd" << left << setw(6) << j+1;
    out_f << right << setw(12) << "Egz.\n";
    
    out_f << outputas.str();
    out_f.close();
}
template <typename Container> 
void fileFull (Container& id, int baloSkc, string failas, string strat, string comm, int f, vector<double> &nuskaitymas, vector<double> &rusiavimasPglPavardes, vector<double> &rusiavimasIDviGrupes, vector<string> &failoPav, vector<double> &fileTime, int &PazNum) {
    auto start = std::chrono::high_resolution_clock::time_point();
    auto end = std::chrono::high_resolution_clock::time_point();
    auto begin = std::chrono::high_resolution_clock::time_point();
    auto finish = std::chrono::high_resolution_clock::time_point();
    std::chrono::duration<double> diff = end-start;  
    begin = std::chrono::high_resolution_clock::now();
    
    stringstream zaliocikai, eiliniai;
    
    cout << left << setw(35) <<  "FAILAS" <<  failas << "\n";
    failoPav.push_back(failas);
    
     start = std::chrono::high_resolution_clock::now();
    readFromFile(id, failas);
     end = std::chrono::high_resolution_clock::now();
     diff = end-start;
     cout << left << setw(35) << "NUSKAITYMAS" << diff.count() << " s.\n";
    nuskaitymas.push_back(diff.count());
    if (PazNum == 0){
        auto it = id.begin();
        vector<int>temp = it->Paz();
        PazNum = temp.size();
    }    
        

    int contSize = id.size();
    for (auto it = id.begin(); it != id.end(); ++it)
    it->GalBalas(baloSkc);
    
     start = std::chrono::high_resolution_clock::now();
    rusiavimasPav (id);
     end = std::chrono::high_resolution_clock::now();
     diff = end-start;
     cout << left << setw(35) << "RUSIAVIMAS PAGAL PAVARDES" << diff.count() << " s.\n";
     rusiavimasPglPavardes.push_back(diff.count());

    if (strat == "/0c") {
            start = std::chrono::high_resolution_clock::now();
            containerLess (id, zaliocikai, eiliniai);
            end = std::chrono::high_resolution_clock::now();
    } else
    if (strat == "/1c"){
        if (comm == "/v"){
            start = std::chrono::high_resolution_clock::now();
            vector <studentas> zaliocikaiTemp;
            zaliocikaiTemp.reserve(f*0.45);
            singleAddEnhanced (id, zaliocikaiTemp);
            zaliocikaiTemp.shrink_to_fit();
            end = std::chrono::high_resolution_clock::now();
            createBuff (id, zaliocikaiTemp, zaliocikai, eiliniai);
        } else
        if (comm == "/d") {
            start = std::chrono::high_resolution_clock::now();
            deque <studentas> zaliocikaiTemp;
            singleAddEnhanced (id, zaliocikaiTemp);
            end = std::chrono::high_resolution_clock::now();
            createBuff (id, zaliocikaiTemp, zaliocikai, eiliniai);
        } else  
        if (comm == "/l") {
            start = std::chrono::high_resolution_clock::now();
            list <studentas> zaliocikaiTemp;
            singleAdd (id, zaliocikaiTemp);
            end = std::chrono::high_resolution_clock::now();
            createBuff (id, zaliocikaiTemp, zaliocikai, eiliniai);
        }          
    } else
    if (strat == "/2c"){
        if (comm == "/v") {
            start = std::chrono::high_resolution_clock::now();
            vector <studentas> zaliocikaiTemp;
            vector <studentas> eiliniaiTemp;
            zaliocikaiTemp.reserve(f*0.45);
            eiliniaiTemp.reserve(f*0.65);
            doubleAdd (id, zaliocikaiTemp, eiliniaiTemp);
            zaliocikaiTemp.shrink_to_fit();
            eiliniaiTemp.shrink_to_fit();
            end = std::chrono::high_resolution_clock::now();
            createBuff (eiliniaiTemp, zaliocikaiTemp, zaliocikai, eiliniai);
        } else
        if (comm == "/d") {
            start = std::chrono::high_resolution_clock::now();
            deque <studentas> zaliocikaiTemp;
            deque <studentas> eiliniaiTemp;
            doubleAdd (id, zaliocikaiTemp, eiliniaiTemp);
            end = std::chrono::high_resolution_clock::now();
            createBuff (eiliniaiTemp, zaliocikaiTemp, zaliocikai, eiliniai);
        } else
        if (comm == "/l") {
            start = std::chrono::high_resolution_clock::now();
            list <studentas> zaliocikaiTemp;
            list <studentas> eiliniaiTemp;
            doubleAdd (id, zaliocikaiTemp, eiliniaiTemp);
            end = std::chrono::high_resolution_clock::now();
            createBuff (eiliniaiTemp, zaliocikaiTemp, zaliocikai, eiliniai);
        }
    }
    diff = end-start;
    cout << left << setw(35) << "RUSIAVIMAS I DVI GRUPES" << diff.count() << " s.\n";
    rusiavimasIDviGrupes.push_back(diff.count());

        string fileGood = "eiliniai"+to_string(contSize)+".txt" , fileBad = "zaliocikai"+to_string(contSize)+".txt";
        ofstream out_z("../data/" + fileBad);
        out_z << left << setw(40) << "Pavarde" << left << setw(30) << "Vardas";
        if (baloSkc == 1)
            out_z << right << setw(20) << "Galutinis balas (vid.)\n";
        else
            out_z << right << setw(20) << "Galutinis balas (med.)\n";
        out_z << "--------------------------------------------------------------------------------------------\n";
        out_z << zaliocikai.str();
        out_z.close();

        ofstream out_e("../data/" + fileGood);
        out_e << left << setw(40) << "Pavarde" << left << setw(30) << "Vardas";
        if (baloSkc == 1)
            out_e << right << setw(20) << "Galutinis balas (vid.)\n";
        else
            out_e << right << setw(20) << "Galutinis balas (med.)\n";
        out_e << "--------------------------------------------------------------------------------------------\n";
        out_e << eiliniai.str();
        out_e.close();

     finish = std::chrono::high_resolution_clock::now();
     diff = finish-begin;
     cout << left << setw(35) << "FAILO TESTO LAIKAS" << diff.count() << " s.\n";
     cout << "------------------------------------------------------------\n\n";
     fileTime.push_back(diff.count());
}

void rezSpausdinimas (vector<double> nuskaitymas, vector<double> rusiavimasPglPavardes, vector<double> rusiavimasIDviGrupes, 
vector<string> failoPav, int PazNum, string comm, string strat, int baloSkc, vector<double> &fileTime){
    ofstream out_r("rezultatai.txt");
    out_r << "*v1.0 TESTAVIMO REZULTATAI (";
    
    if (comm=="/v")
        out_r << "vektorius, ";
    else if (comm=="/d")
        out_r << "dekas, ";
    else if (comm=="/l")
        out_r << "listas, ";
    
    if (strat=="/0c")
        out_r << "nenaudojant papildomu konteineriu, ";
    else if (strat=="/1c")
        out_r << "naudojant viena papildoma konteineri, ";
    else if (strat=="/2c")
        out_r << "naudojant du papildomus konteinerius, ";


    if (baloSkc==0)
        out_r << "mediana, ";
    else if (baloSkc==1)
        out_r << "vidurkis, ";
    
    out_r << PazNum << " paz.)*\n";

    out_r << "|" << " FAILAS " << "|";
    for (int i=0; i<failoPav.size(); i++)
        out_r << failoPav[i] << "|";
    out_r << "\n";
    out_r << "|" << " --- " << "|";
    for (int i=0; i<failoPav.size(); i++)
        out_r << " - " << "|";
    out_r << "\n";
    out_r << "|" << " NUSKAITYMAS " << "|";
    for (int i=0; i<failoPav.size(); i++)
        out_r << nuskaitymas[i] << " s. |";
    out_r << "\n";
    out_r << "|" << " RUSIAVIMAS PAGAL PAVARDES " << "|";
    for (int i=0; i<failoPav.size(); i++)
        out_r << rusiavimasPglPavardes[i] << " s. |";
    out_r << "\n";
    out_r << "|" << " RUSIAVIMAS I DVI GRUPES " << "|";
    for (int i=0; i<failoPav.size(); i++)
        out_r << rusiavimasIDviGrupes[i] << " s. |";
    out_r << "\n";
    out_r << "|" << " FAILO LAIKAS " << "|";
    for (int i=0; i<failoPav.size(); i++)
        out_r << fileTime[i] << " s. |";
    out_r << "\n";
    out_r.close();
}

template void cmdRankinis (vector<studentas>&, int, int, int);
template void cmdRankinis (deque<studentas>&, int, int, int);
template void cmdRankinis (list<studentas>&, int, int, int);
template void fileBasic (vector<studentas>&, int);
template void fileBasic (deque<studentas>&, int);
template void fileBasic (list<studentas>&, int);
template void fileFull (vector<studentas>&, int, string, string, string, int, vector<double>&, vector<double>&, vector<double>&, vector<string>&, vector<double>&, int&);
template void fileFull (deque<studentas>&, int, string, string, string, int, vector<double>&, vector<double>&, vector<double>&, vector<string>&, vector<double>&, int&);
template void fileFull (list<studentas>&, int, string, string, string, int, vector<double>&, vector<double>&, vector<double>&, vector<string>&, vector<double>&, int&);
