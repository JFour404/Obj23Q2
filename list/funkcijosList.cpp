#include "headerList.h"

void read (list<studentas>& id){
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

double vidurkis(const list<studentas>& id, list<studentas>::const_iterator it) {
    double suma = accumulate(it->paz.begin(), it->paz.end(), 0.0);
    return suma / it->paz.size();
}

// double mediana(list<studentas>& id, int n){
//     auto i=id.begin();
//     advance(i, n);
//         sort(i->paz.begin(), i->paz.end());
//         double vid = i->paz.size() / 2.0;
//         return i->paz.size() % 2 == 0 ? (i->paz[vid-1] + i->paz[vid]) / 2.0 : i->paz[vid];
// }

double mediana(const list<studentas>& id, list<studentas>::const_iterator it) {
    auto paz = it->paz;
    sort(paz.begin(), paz.end());
    double vid = paz.size() / 2.0;
    return paz.size() % 2 == 0 ? (paz[vid - 1] + paz[vid]) / 2.0 : paz[vid];
}


void write (list<studentas>id){
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
        for (auto it = id.begin(); it != id.end(); it++){
            cout << left << setw(20) << it->pavarde << left << setw(15) << it->vardas;
            if (metodas == "v")
            cout << fixed << setprecision(2) << (vidurkis (id, it))*0.4 + it->egz*0.6 << "\n";
            else
            cout << fixed << setprecision(2) << (mediana (id, it))*0.4 + it->egz*0.6 << "\n";
            j++;
        }    
    } 
}

void autoRead(list<studentas>& id, string failas) { 
    stringstream buferis;
    string eil;

    ifstream open_f(failas);
    if (!open_f.is_open()) {
        throw runtime_error("Nepavyko atidaryti " + failas);
    }
    
    buferis << open_f.rdbuf();
    open_f.close();

    buferis.seekg(0); //???
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

void autoWrite (list<studentas> id, string failas, int ask){
    string budas;
    stringstream outputas;

    if (ask == 1) {
        outputas << left << setw(40) << "Pavarde" << left << setw(30) << "Vardas" << "Bendras(vid.)\n";
        for (auto it = id.begin(); it != id.end(); ++it) {
            outputas << left << setw(40) << it->pavarde << left << setw(30) << it->vardas 
            << fixed << setprecision(2) << (vidurkis(id, it)) * 0.4 + it->egz * 0.6 << "\n";
        }
    } else {
        outputas << left << setw(40) << "Pavarde" << left << setw(30) << "Vardas" << "Bendras(med.)\n";
        for (auto it = id.begin(); it != id.end(); ++it) {
            outputas << left << setw(40) << it->pavarde << left << setw(30) << it->vardas 
            << fixed << setprecision(2) << (mediana(id, it)) * 0.4 + it->egz * 0.6 << "\n";
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

bool palygintiPavardes(const studentas& a, const studentas& b) {
    return a.pavarde < b.pavarde;
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

void testWrite (list<studentas> id, int ask){
    string fileGood = "eiliniai"+to_string(id.size())+".txt" , fileBad = "zaliocikai"+to_string(id.size())+".txt";
    stringstream zaliocikai, eiliniai;

    if (ask==1){
        auto start = std::chrono::high_resolution_clock::now();
        for (auto it = id.begin(); it != id.end(); ++it) {
            double tempVid = vidurkis(id, it) * 0.4 + it->egz * 0.6;
            if (tempVid < 5) {
                zaliocikai << left << setw(40) << it->pavarde << left << setw(30) << it->vardas << right << setw(8) << fixed << setprecision(2) << tempVid << "\n";
            } else {
                eiliniai << left << setw(40) << it->pavarde << left << setw(30) << it->vardas << right << setw(8) << fixed << setprecision(2) << tempVid << "\n";
            }
        }
        auto end = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> diff = end-start;
        cout << left << setw(35) << "RUSIAVIMAS I DVI GRUPES" << diff.count() << " s.\n";

        // start = std::chrono::high_resolution_clock::now();
        ofstream out_z(fileBad);
        out_z << left << setw(40) << "Pavarde" << left << setw(30) << "Vardas" << right << setw(20) << "Galutinis balas (vid.)\n";
        out_z << "--------------------------------------------------------------------------------------------\n";
        out_z << zaliocikai.str();
        out_z.close();

        ofstream out_e(fileGood);
        out_e << left << setw(40) << "Pavarde" << left << setw(30) << "Vardas" << right << setw(20) << "Galutinis balas (vid.)\n";
        out_e << "--------------------------------------------------------------------------------------------\n";
        out_e << eiliniai.str();
        out_e.close();
        // end = std::chrono::high_resolution_clock::now();
        // diff = end-start;
        // cout << left << setw(35) << "STUDENTU ISVEDIMAS I 2 FAILUS" << diff.count() << " s.\n";
    }
    else {
        auto start = std::chrono::high_resolution_clock::now();
        int l = 0;
        for (auto it=id.begin(); it!=id.end(); it++){ 
            double tempVid = (mediana (id, it))*0.4 + it->egz*0.6;
            if (tempVid<5){
                zaliocikai << left << setw(40) << it->pavarde << left << setw(30) << it->vardas << right << setw(8) << fixed << setprecision(2) << tempVid << "\n";
            } 
            else
                eiliniai << left << setw(40) << it->pavarde << left << setw(30) << it->vardas << right << setw(8) << fixed << setprecision(2) << tempVid << "\n";
            l++;
        } 
        auto end = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> diff = end-start;
        cout << left << setw(35) << "RUSIAVIMAS I DVI GRUPES" << diff.count() << " s.\n";

        // start = std::chrono::high_resolution_clock::now();
        ofstream out_z(fileBad);
        out_z << left << setw(40) << "Pavarde" << left << setw(30) << "Vardas" << right << setw(20) << "Galutinis balas (med.)\n";
        out_z << "--------------------------------------------------------------------------------------------\n";
        out_z << zaliocikai.str();
        out_z.close();

        ofstream out_e(fileGood);
        out_e << left << setw(40) << "Pavarde" << left << setw(30) << "Vardas" << right << setw(20) << "Galutinis balas (med.)\n";
        out_e << "--------------------------------------------------------------------------------------------\n";
        out_e << eiliniai.str();
        out_e.close(); 
        // end = std::chrono::high_resolution_clock::now();
        // diff = end-start;
        // cout << left << setw(35) << "STUDENTU ISVEDIMAS I 2 FAILUS" << diff.count() << " s.\n";   
    }
}