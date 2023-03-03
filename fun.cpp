#include "header.h"

void read (vector<studentas> *id){
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
        if (cin){
            for (int i=0; i<kiekis; i++){
            random_device rd;
            mt19937 mt(rd());
            uniform_int_distribution <int> dist(1,10);
            for (int i=0; i<kiekis; i++) temp.paz.push_back(dist(mt));
            temp.paz.push_back(dist(mt)); 
            }
        }
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
        (*id).push_back(temp);
    }
}
}

double vidurkis (vector<studentas> *id, int n){
    double suma = 0;
    for (const auto& el : (*id)[n].paz){
        suma = suma + el;
    }
    return suma/(*id)[n].paz.size();
}

double mediana (vector<studentas> *id, int n){
    sort((*id)[n].paz.begin(), (*id)[n].paz.end());
    double vid = (*id)[n].paz.size()/2;
    return (*id)[n].paz.size() % 2 == 0 ? ((*id)[n].paz[vid-1] + (*id)[n].paz[vid]) / 2: (*id)[n].paz[vid];
}

void write (vector<studentas>id){
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


        for (int i=0; i<id.size(); i++){
            cout << left << setw(20) << id[i].pavarde << left << setw(15) << id[i].vardas;
            if (metodas == "v")
            cout << fixed << setprecision(2) << (vidurkis (&id, i))*0.4 + id[i].egz*0.6 << "\n";
            else
            cout << fixed << setprecision(2) << (mediana (&id, i))*0.4 + id[i].egz*0.6 << "\n";
        }    
    } 
}

void autoRead (vector<studentas> *id) { 
    ifstream open_f("studentai1000000.txt");
    string eil;
    getline(open_f, eil);

    while (getline(open_f, eil)) { 
        stringstream ss(eil);
        int pazymys;
        studentas temp;

        ss >> temp.vardas >> temp.pavarde;
        while (ss >> pazymys) temp.paz.push_back(pazymys);
        temp.egz = temp.paz.back();
        temp.paz.pop_back();

        (*id).push_back(temp);
        temp.paz.clear();
        vector<int>().swap(temp.paz);
  }
  open_f.close();
}

void autoWrite (vector<studentas> id){
    string budas;
    stringstream outputas;
    cout << "Norite skaiciuoti su vidurkiu ar mediana? (v/m)\n";
    while (1){
        cin >> budas; 
        if (budas == "v" || budas == "m"){
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

    if (budas == "v"){
        for (int i=0; i<id.size(); i++){
            outputas << left << setw(20) << id[i].pavarde << left << setw(15) << id[i].vardas 
            << fixed << setprecision(2) << (vidurkis (&id, i))*0.4 + id[i].egz*0.6 << "\n";
        }    
    } else {
        for (int i=0; i<id.size(); i++){
            outputas << left << setw(20) << id[i].pavarde << left << setw(15) << id[i].vardas 
            << fixed << setprecision(2) << (mediana (&id, i))*0.4 + id[i].egz*0.6 << "\n";
        } 
    }
    
//------------------------------------------------------------------------------
    ofstream out_f("studenati_copy.txt");
    out_f << outputas.str();
    out_f.close();
}

bool palygintiPavardes(const studentas& a, const studentas& b) {
    return a.pavarde < b.pavarde;
}

