#include "header.h"
struct studentas{
    string vardas = "", pavarde = "";
    vector<int> paz;
    int egz;
};

void read (vector<studentas> *id){
    char pasirinkimas;
    int kiekis;
    string name1, name2;
    studentas temp;

    cout << "NOTE! Noredami nutraukti duomenu irasyma, kai yra prasoma ivesti varda ir pavarde, iveskite: /e\n\n";
    cout << "Pazymiu duomenis vesite ranka ar vykdyti automatini pildyma? (r/a)\n";
    while (1){
        cin >> pasirinkimas; 
        if (pasirinkimas == 'r' || pasirinkimas == 'a')
        break;
        else {
            cout << "Prasome ivesti tinkama reiksme.\n";
            cin.clear(); 
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            }   
    }
//----------------------pazymiu kiekis-----------------------------------------------
    if (pasirinkimas == 'a'){
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
    if (pasirinkimas=='a'){
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
        int pazymys;
        cout << "Ivedus bet kuri simboli, isskyrus skaicius, skaiciu irasymas bus nutraukiamas.\n";
        cout << "Iveskite nd pazymius:\n";
        while (1){
            cin >> pazymys;
            if (cin){
                if (pazymys>=0 && pazymys <= 10) temp.paz.push_back(pazymys);
                else {
                    cout << "Ivedete netinkama pazymi. Visi like pazymiai uz blogo pazymio buvo neissaugoti.\n"; 
                    cin.clear(); 
                    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                }
            }   
            else {
                cin.clear(); 
                cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                break; 
            } 
        }
        cout << "Iveskite egzamino rezultata:\n";
        string mark;
        
        while (1){
            cin >> pazymys;
                if (cin&&(pazymys>=0 && pazymys <= 10)){
                    temp.egz = pazymys;
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

double vidurkis (vector<studentas>id, int n){
    double suma = 0;
    for (const auto& el : id[n].paz){
        suma = suma + el;
    }
    return suma/id[n].paz.size();
}

double mediana (vector<studentas> *id, int n){
    sort((*id)[n].paz.begin(), (*id)[n].paz.end());
    double vid = (*id)[n].paz.size()/2;
    return (*id)[n].paz.size() % 2 == 0 ? ((*id)[n].paz[vid-1] + (*id)[n].paz[vid]) / 2: (*id)[n].paz[vid];
}

void write (vector<studentas>id){
    char metodas;
    while (1){
        cout << "Norite skaiciuoti su vidurkiu ar mediana? (v/m)\n";
        cin >> metodas;
            if (metodas == 'v' || metodas =='m'){
                cout << "---------------------------------------------------\n";
                cout << left << setw (20) << "Pavarde" << left << setw (15) << "Vardas" << left << setw (10) << "Galutinis";
                    if (metodas == 'v')
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
        cout << left << setw(20) << id[i].vardas << left << setw(15) << id[i].vardas;
        if (metodas == 'v')
        cout << fixed << setprecision(2) << (vidurkis (id, i))*0.4 + id[i].egz*0.6 << "\n";
        else
        cout << fixed << setprecision(2) << (mediana (&id, i))*0.4 + id[i].egz*0.6 << "\n";
    }
}

int main (){
    vector<studentas> id;
    read (&id);
    write (id);
    return 0;
}