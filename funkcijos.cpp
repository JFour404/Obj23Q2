#include "header.h"

template <typename Container>
void containerLess (Container id, stringstream& zaliocikai, stringstream& eiliniai, int ask){
    double tempVid;
    for (auto i=id.begin(); i!=id.end(); i++){ 
        if (ask == 1)
            tempVid = (vidurkisV2 (i))*0.4 + i->egz*0.6;
        else  
            tempVid = (medianaV2 (i))*0.4 + i->egz*0.6;
        if (tempVid<5){
            zaliocikai << left << setw(40) << i->pavarde << left << setw(30) << i->vardas << right << setw(8) << fixed << setprecision(2) << tempVid << "\n";
        } 
        else
            eiliniai << left << setw(40) << i->pavarde << left << setw(30) << i->vardas << right << setw(8) << fixed << setprecision(2) << tempVid << "\n";
        } 
}

template <typename Container, typename ContainerTemp>
void singleAdd (Container& id, int ask, ContainerTemp& zaliocikaiTemp) {
    for (auto it=id.begin(); it!=id.end(); ){
        if (ask == 1)
            it->vidurkis = (vidurkisV2 (it))*0.4 + it->egz*0.6;
         else
            it->vidurkis = (medianaV2 (it))*0.4 + it->egz*0.6;
        if (it->vidurkis<5){
            zaliocikaiTemp.push_back(*it);
            it = id.erase(it);
        } else {
            ++it;
        }
    }
}

template <typename Container, typename ContainerTemp>
void singleAddEnhanced (Container& id, int ask, ContainerTemp& zaliocikaiTemp){
    for (auto it=id.begin(); it!=id.end(); ){
        if (ask == 1)
            it->vidurkis = (vidurkisV2 (it))*0.4 + it->egz*0.6;
         else
            it->vidurkis = (medianaV2 (it))*0.4 + it->egz*0.6;
            
            ++it;
    }

    auto temp = remove_if(id.begin(), id.end(), [&](const studentas &student){
        if (student.vidurkis <5) {
            zaliocikaiTemp.push_back(student);
            return true;
        } 
        return false;
    });

    id.erase(temp, id.end());
}


template <typename Container, typename ContainerTemp>
void doubleAdd (Container& id, int ask, ContainerTemp& zaliocikaiTemp, ContainerTemp& eiliniaiTemp) {
    
    for (auto it=id.begin(); it!=id.end(); it++){
        if (ask == 1)
            it->vidurkis = (vidurkisV2 (it))*0.4 + it->egz*0.6;
         else
            it->vidurkis = (medianaV2 (it))*0.4 + it->egz*0.6;
        if (it->vidurkis<5){
            zaliocikaiTemp.push_back(*it);
        } else {
            eiliniaiTemp.push_back(*it);
        }
    }
}

template <typename Container, typename ContainerTemp>
void createBuff (Container good, ContainerTemp bad, stringstream& zaliocikai, stringstream& eiliniai) {
    for (auto it=good.begin(); it!=good.end(); it++)
        eiliniai << left << setw(40) << it->pavarde << left << setw(30) << it->vardas << right << setw(8) << fixed << setprecision(2) << it->vidurkis << "\n";
          
    for (auto it=bad.begin(); it!=bad.end(); it++)
        zaliocikai << left << setw(40) << it->pavarde << left << setw(30) << it->vardas << right << setw(8) << fixed << setprecision(2) << it->vidurkis << "\n";
}

template <typename Container>
double vidurkisV2 (Container& id){
    double suma = 0;
    for (auto i = id->paz.begin(); i != id->paz.end(); ++i) {
        suma += *i;
    }
    return suma/id->paz.size();
}

template <typename Container>
double medianaV2(Container& id){
    auto paz = id->paz;
    sort(paz.begin(), paz.end());
    double vid = paz.size() / 2.0;
    return paz.size() % 2 == 0 ? (paz[vid - 1] + paz[vid]) / 2.0 : paz[vid];
}

bool palygintiPavardes(const studentas& a, const studentas& b) {
    return a.pavarde < b.pavarde;
}



template <typename Container>
void read (Container& id){
    string pasirinkimas;
    int kiekis;
    string name1, name2;
    studentas temp;

    cout << "NOTE! Noredami nutraukti duomenu irasyma, kai yra prasoma ivesti varda ir pavarde, iveskite: /e\n\n";
    cout << "Pazymiu duomenis vesite ranka ar vykdyti automatini pildyma? (r/a)\n";
    while (1){
        cin >> pasirinkimas; 
        if (pasirinkimas == "r" || pasirinkimas == "a") {
            cin.clear(); 
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            break;
        }
        else {
            cout << "Prasome ivesti tinkama reiksme.\n";
            cin.clear(); 
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            }   
    }
//----------------------pazymiu kiekis-----------------------------------------------
    if (pasirinkimas == "a"){
        cout << "Kiek sugeneruoti nd pazymiu?\n";
        while (1){
        cin >> kiekis;   
            if(cin.fail()) {
                cout << "Ivestis nera skaicius.\n";
                cin.clear(); 
                cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            } 
            else if (kiekis<0) cout << "Ivestas skaicius nera tinkamas.\n";
            else break;
        }
        cin.clear(); 
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
//---------------------------------------------------------------------------------
while (1){
//-----------------------vardo ir pavardes nuskaitymas-----------------------------
        cout << "Iveskite studento varda ir pavarde: \n"; 
        cin >> name1;
        if (name1 == "/e") break;
        cin >> name2;
        if (name2 == "/e") break; 
        else{
        temp.vardas = name1;
        temp.pavarde = name2;
        }
//----------------------------------------------------------------------------------
    if (pasirinkimas=="a"){
//------------------------pazymiu ivedimas automatiniu budu--------------------------
            random_device rd;
            mt19937 mt(rd());
            uniform_int_distribution <int> dist(1,10);
            for (int i=0; i<kiekis; i++) temp.paz.push_back(dist(mt));
            temp.egz=(dist(mt));
            id.push_back(temp);
    }
//-------------------------------------------------------------------------------------
    else {
//-----------------------pazymiu nuskaitymas (rankiniu budu)-------------------------
        string pazymys;
        cout << "Noredami nutraukti pazymiu irasymas iveskite /e.\n";
        cout << "Iveskite nd pazymius:\n";
        while (1){
            cin >> pazymys;
            if (pazymys != "/e"){
                if (pazymys=="0"||pazymys=="1"||pazymys=="2"||pazymys=="3"||pazymys=="4"||pazymys=="5"||pazymys=="6"||pazymys=="7"||pazymys=="8"||pazymys=="9"||pazymys=="10") 
                    temp.paz.push_back(stoi(pazymys));
                else {
                    cout << "Ivedete netinkama pazymi. Visi like pazymiai uz blogo pazymio buvo neissaugoti.\n"; 
                    cin.clear(); 
                    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                }
            }   
            else {
                cin.clear(); 
                cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                if (!temp.paz.empty())
                break; 
                else cout << "Turite ivesti bent viena pazymi.\n";
            } 
        }
        cout << "Iveskite egzamino rezultata:\n";
        string mark;
        
        while (1){
            cin >> pazymys;
                if (cin&&(pazymys=="0"||pazymys=="1"||pazymys=="2"||pazymys=="3"||pazymys=="4"||pazymys=="5"||pazymys=="6"||pazymys=="7"||pazymys=="8"||pazymys=="9"||pazymys=="10")){
                    temp.egz = stoi(pazymys);
                    break;
                } 
                else {
                    cout << "Netinkama ivestis. Veskite is naujo:\n";
                    cin.clear(); 
                    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); 
                    }
            
        }
        id.push_back(temp);
    }
}
}

template <typename Container>
void write (Container id){
    string metodas;
    
    if (!id.empty()){
        while (1){
            cout << "Norite skaiciuoti su vidurkiu ar mediana? (v/m)\n";
            cin >> metodas;
                if (metodas == "v" || metodas == "m"){
                    cout << "---------------------------------------------------\n";
                    cout << left << setw (20) << "Pavarde" << left << setw (15) << "Vardas" << left << setw (10) << "Galutinis";
                        if (metodas == "v")
                        cout << "(Vid.)\n";    
                        else
                        cout << "(Med.)\n";
                    cout << "---------------------------------------------------\n";
                    break;
                } else {
                    cout << "Ivedete neteisinga reiksme\n";
                    cin.clear(); 
                    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                } 
        }

        int j=0; 
        for (auto i = id.begin(); i != id.end(); i++){
            cout << left << setw(20) << i->pavarde << left << setw(15) << i->vardas;
            if (metodas == "v")
            cout << fixed << setprecision(2) << (vidurkisV2 (i))*0.4 + i->egz*0.6 << "\n";
            else
            cout << fixed << setprecision(2) << (medianaV2 (i))*0.4 + i->egz*0.6 << "\n";
            j++;
        }    
    } 
}

template <typename Container>
void autoRead(Container& id, string failas) { 
    stringstream buferis;
    string eil;

    ifstream open_f(failas);
    if (!open_f.is_open()) {
        throw runtime_error("Nepavyko atidaryti " + failas);
    }
    
    buferis << open_f.rdbuf();
    open_f.close();

    buferis.seekg(0); 
    getline(buferis, eil);

    while (getline(buferis, eil)) { 
        stringstream ss(eil);
        int pazymys;
        studentas temp;

        ss >> temp.vardas >> temp.pavarde;
        while (ss >> pazymys) temp.paz.push_back(pazymys);
        if (temp.paz.empty()) {
            throw runtime_error("Netinkamas formatas: nerastas pazymys");
        }
        temp.egz = temp.paz.back();
        temp.paz.pop_back();

        id.push_back(temp);
    }
}

template <typename Container>
void autoWrite (Container id, string failas, int ask){
    string budas;
    stringstream outputas;

    if (ask == 1) {
        outputas << left << setw(40) << "Pavarde" << left << setw(30) << "Vardas" << "Bendras(vid.)\n";
        for (auto i = id.begin(); i != id.end(); ++i) {
            outputas << left << setw(40) << i->pavarde << left << setw(30) << i->vardas 
            << fixed << setprecision(2) << (vidurkisV2(i)) * 0.4 + i->egz * 0.6 << "\n";
        }
    } else {
        outputas << left << setw(40) << "Pavarde" << left << setw(30) << "Vardas" << "Bendras(med.)\n";
        for (auto i = id.begin(); i != id.end(); ++i) {
            outputas << left << setw(40) << i->pavarde << left << setw(30) << i->vardas 
            << fixed << setprecision(2) << (medianaV2(i)) * 0.4 + i->egz * 0.6 << "\n";
        }
    }
    
//------------------------------------------------------------------------------
    ofstream out_f(failas);
    out_f << outputas.str();
    out_f.close();
}


void nameSurname (vector<string>& names, vector<string>& surnames){
    string eil;
    stringstream buferis;
    //----------------------------------nuskaitomi vardai, naudojant buferi---------------------------------   
    ifstream fd1("names18239.txt");
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
    ifstream fd2("surnames29638.txt");
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
//------------------------------------pazymiu generavimas, duomenu suklaudimas-------------------------------------------------------
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
    ofstream out_f(failas);
        
    out_f << left << setw(30) << "Vardas" << left << setw(40) << "Pavarde";
    for (int j=0; j<kiekisPaz; j++) out_f << "Nd" << left << setw(6) << j+1;
    out_f << right << setw(12) << "Egz.\n";
    
    out_f << outputas.str();
    out_f.close();
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

template <typename Container>
int pazSkc (Container& id){
    return id->paz.size();
}

template <typename Container>
void testWrite (Container id, int ask, string strat, string comm, int boost, vector<double> &rusiavimasIDviGrupes){
    string fileGood = "eiliniai"+to_string(id.size())+".txt" , fileBad = "zaliocikai"+to_string(id.size())+".txt";
    stringstream zaliocikai, eiliniai;

        

        auto start = std::chrono::high_resolution_clock::time_point();
        auto end = std::chrono::high_resolution_clock::time_point();

        if (strat == "/0c") {
            start = std::chrono::high_resolution_clock::now();
            containerLess (id, zaliocikai, eiliniai, ask);
            end = std::chrono::high_resolution_clock::now();
        }
        else
        if (strat == "/1c"){
            if (comm == "/v"){
                start = std::chrono::high_resolution_clock::now();
                vector <studentas> zaliocikaiTemp;
                if (boost == 1)
                singleAddEnhanced (id, ask, zaliocikaiTemp);
                else
                singleAdd (id, ask, zaliocikaiTemp);
                end = std::chrono::high_resolution_clock::now();
                createBuff (id, zaliocikaiTemp, zaliocikai, eiliniai);
            } else
            if (comm == "/d") {
                start = std::chrono::high_resolution_clock::now();
                deque <studentas> zaliocikaiTemp;
                if (boost == 1)
                singleAddEnhanced (id, ask, zaliocikaiTemp);
                else
                singleAdd (id, ask, zaliocikaiTemp);
                end = std::chrono::high_resolution_clock::now();
                createBuff (id, zaliocikaiTemp, zaliocikai, eiliniai);
            } else  
            if (comm == "/l") {
                start = std::chrono::high_resolution_clock::now();
                list <studentas> zaliocikaiTemp;
                if (boost == 1)
                singleAddEnhanced (id, ask, zaliocikaiTemp);
                else
                singleAdd (id, ask, zaliocikaiTemp);
                end = std::chrono::high_resolution_clock::now();
                createBuff (id, zaliocikaiTemp, zaliocikai, eiliniai);
            }
                
        } else
            if (strat == "/2c"){
                if (comm == "/v") {
                    start = std::chrono::high_resolution_clock::now();
                    vector <studentas> zaliocikaiTemp;
                    vector <studentas> eiliniaiTemp;
                    doubleAdd (id, ask, zaliocikaiTemp, eiliniaiTemp);
                    end = std::chrono::high_resolution_clock::now();
                    createBuff (eiliniaiTemp, zaliocikaiTemp, zaliocikai, eiliniai);
                }
                if (comm == "/d") {
                    start = std::chrono::high_resolution_clock::now();
                    deque <studentas> zaliocikaiTemp;
                    deque <studentas> eiliniaiTemp;
                    doubleAdd (id, ask, zaliocikaiTemp, eiliniaiTemp);
                    end = std::chrono::high_resolution_clock::now();
                    createBuff (eiliniaiTemp, zaliocikaiTemp, zaliocikai, eiliniai);
                }
                if (comm == "/l") {
                    start = std::chrono::high_resolution_clock::now();
                    list <studentas> zaliocikaiTemp;
                    list <studentas> eiliniaiTemp;
                    doubleAdd (id, ask, zaliocikaiTemp, eiliniaiTemp);
                    end = std::chrono::high_resolution_clock::now();
                    createBuff (eiliniaiTemp, zaliocikaiTemp, zaliocikai, eiliniai);
                }
            }

        std::chrono::duration<double> diff = end-start;
        rusiavimasIDviGrupes.push_back(diff.count());
        
        cout << left << setw(35) << "RUSIAVIMAS I DVI GRUPES" << diff.count() << " s.\n";
        ofstream out_z(fileBad);
        out_z << left << setw(40) << "Pavarde" << left << setw(30) << "Vardas";
        if (ask == 1)
            out_z << right << setw(20) << "Galutinis balas (vid.)\n";
        else
            out_z << right << setw(20) << "Galutinis balas (med.)\n";
        out_z << "--------------------------------------------------------------------------------------------\n";
        out_z << zaliocikai.str();
        out_z.close();

        ofstream out_e(fileGood);
        out_e << left << setw(40) << "Pavarde" << left << setw(30) << "Vardas";
        if (ask == 1)
            out_e << right << setw(20) << "Galutinis balas (vid.)\n";
        else
            out_e << right << setw(20) << "Galutinis balas (med.)\n";
        out_e << "--------------------------------------------------------------------------------------------\n";
        out_e << eiliniai.str();
        out_e.close();
}

template <typename Container>
void prep (Container& id, int testON, int genFiles, int &testPazNum, int baloSkc, string strat, string comm, int boost, vector<double> &nuskaitymas, vector<double> &rusiavimasPglPavardes, vector<double> &rusiavimasIDviGrupes, vector<string> &failoPav, vector<double> &fileTime){
            if (testON==1){
            vector<string> names, surnames;
            string failas, sortF;

            auto start = std::chrono::high_resolution_clock::time_point();
            auto end = std::chrono::high_resolution_clock::time_point();
            auto begin = std::chrono::high_resolution_clock::time_point();
            auto finish = std::chrono::high_resolution_clock::time_point();
            std::chrono::duration<double> diff = end-start;

            auto allS = std::chrono::high_resolution_clock::now();
            nameSurname (names, surnames);  
            cout << "\n" << "############################################################\n";  
            cout << right << setw (40) << "TESTAVIMO REZULTATAI\n";
            cout << "############################################################\n";  

                for (int f=1000; f<10000001; f=f*10) {
                    begin = std::chrono::high_resolution_clock::now();

                        failas = "studentai" + to_string(f) + ".txt";
                        //id.reserve(f);
                        cout << left << setw(35) <<  "FAILAS" <<  failas << "\n";
                        failoPav.push_back(failas);

                    if (genFiles == 1){
                        start = std::chrono::high_resolution_clock::now();
                            testFiles(testPazNum, names, surnames, f);
                        end = std::chrono::high_resolution_clock::now();
                        diff = end-start;
                        cout << left << setw(35) << "SUDARYMAS" << diff.count() << " s.\n";    
                    }
                    
                    
                    
                    start = std::chrono::high_resolution_clock::now();
                        autoRead(id, failas); //nuskaitomas kiekvienas failas atskirai
                    end = std::chrono::high_resolution_clock::now();
                    diff = end-start;
                    cout << left << setw(35) << "NUSKAITYMAS" << diff.count() << " s.\n";
                    nuskaitymas.push_back(diff.count());

                    start = std::chrono::high_resolution_clock::now();
                        
                    if constexpr (std::is_same_v<Container, std::vector<studentas>>) {
                        sort(id.begin(), id.end(), palygintiPavardes);
                    } else if constexpr (std::is_same_v<Container, std::list<studentas>>) {
                        id.sort(palygintiPavardes);
                    } else if constexpr (std::is_same_v<Container, std::deque<studentas>>) {
                        sort(id.begin(), id.end(), palygintiPavardes);
                    }
        
                    end = std::chrono::high_resolution_clock::now();
                    diff = end-start;
                    cout << left << setw(35) << "RUSIAVIMAS PAGAL PAVARDES" << diff.count() << " s.\n";
                    rusiavimasPglPavardes.push_back(diff.count());    
                    
                        testWrite(id, baloSkc, strat, comm, boost, rusiavimasIDviGrupes);
                    
                    id.clear();
                    
                    finish = std::chrono::high_resolution_clock::now();
                    diff = finish-begin;
                    cout << left << setw(35) << "FAILO TESTO LAIKAS" << diff.count() << " s.\n";
                    cout << "------------------------------------------------------------\n\n";
                    fileTime.push_back(diff.count());
                }
            names.clear();
            surnames.clear();

            auto allF = std::chrono::high_resolution_clock::now();
            diff = allF - allS;
            cout << left << setw(35) << "VISA PROGRAMA VEIKE" << diff.count() << " s.\n";
            cout << "############################################################\n";
        }
        
        else{
            
            string budas, failas;
            cout << "Studentu duomenis vesite ranka (0) ar nuskaitysite is failo (1)\n";
            
            if (ask() == 1){
                cout << "Prieinami failai: \n";
                system("dir /b | findstr \\.txt$");
                while (1) {
                    cout << "Iveskite failo pavadinima is saraso, is kurio norite nuskaityti duomenis: \n";
                    cin >> failas;
                try {
                    ifstream open_f(failas);
                    if (!open_f) throw runtime_error("Failas nerastas arba nepavyko atidaryti.");
                    cout << "Galutini bala skaiciuoti naudojant mediana(0) ar vidurki(1)?\n";
                    int baloSkc = ask(); //kokiu budu skaiciuojmas bendras
                    autoRead (id, failas);
                    
                    if constexpr (std::is_same_v<Container, std::vector<studentas>>) {
                        sort(id.begin(), id.end(), palygintiPavardes);
                    } else if constexpr (std::is_same_v<Container, std::list<studentas>>) {
                        id.sort(palygintiPavardes);
                    } else if constexpr (std::is_same_v<Container, std::deque<studentas>>) {
                        sort(id.begin(), id.end(), palygintiPavardes);
                    } 
            
                    autoWrite (id, "studentai_copy", baloSkc);
                    break;
                    }
                catch (exception const& e) {
                    cerr << "Klaida: " << e.what() << endl;
                    }     
                }
                
                
            } else {
                read (id);
                
                if constexpr (std::is_same_v<Container, std::vector<studentas>>) {
                    sort(id.begin(), id.end(), palygintiPavardes);
                } else if constexpr (std::is_same_v<Container, std::list<studentas>>) {
                    id.sort(palygintiPavardes);
                } else if constexpr (std::is_same_v<Container, std::deque<studentas>>) {
                    sort(id.begin(), id.end(), palygintiPavardes);
                } 
        
                write (id);    
            }
        }
    auto it = id.begin();
    testPazNum = pazSkc (it);
    }

void rezSpausdinimas (vector<double> nuskaitymas, vector<double> rusiavimasPglPavardes, vector<double> rusiavimasIDviGrupes, 
vector<string> failoPav, int PazNum, string comm, string strat, int boost, int baloSkc, vector<double> &fileTime){
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

    if (boost==1)
        out_r << "pagerinta strategija, ";

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