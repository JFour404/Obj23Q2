#include "header.h"

struct studentas
{
    string vardas = "", pavarde = "";
    int* paz;
    int egz;
};

void Read (studentas** id, int& StudSk, int** NdSk) {
*id = new studentas [1];
*NdSk = new int [1];
string ivestis;
string pazymys;
char pasirinkimas;
int convert;
int autokiekis;

cout << "NOTE! Noredami nutraukti duomenu irasyma iveskite: /e\n\n";
cout << "Pazymiu duomenis vesite ranka ar vykdyti automatini pildyma? (r/a)\n";
while (1){
cin >> pasirinkimas; 
if (pasirinkimas == 'r' || pasirinkimas == 'a')
break;
else cout << "Prasome ivesti tinkama reiksme.\n";   
}

if (pasirinkimas == 'a'){
    cout << "Kiek sugeneruoti nd pazymiu?\n";
    while (1){
    cin >> autokiekis;   
        if(cin.fail()) {
            cout << "Ivestis nera skaicius.\n";
            cin.clear(); 
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        } 
        else if (autokiekis<0) cout << "Ivestas skaicius nera tinkamas.\n";
        else break;
    }
}

while (1){ //duomenu ivedimas
    cout << "Iveskite studento varda ir pavarde:\n";
    cin >> ivestis;
    
    if (ivestis != "/e"){
        StudSk++; //studentu masyvo prapletimas
        studentas* temp = new studentas [StudSk];
        for (int i = 0; i<StudSk-1; i++) temp[i]=(*id)[i];
        delete[] (*id);
        (*id) = temp;

        (*id)[StudSk-1].vardas = ivestis;
    } else break;

    cin >> (*id)[StudSk-1].pavarde;
    if ((*id)[StudSk-1].pavarde=="/e"){ //duomenu ivedimo stabdymas
        studentas* temp = new studentas [StudSk-1];
        for (int i = 0; i<StudSk-1; i++) temp[i]=(*id)[i];
        delete[] (*id);
        (*id) = temp;
        StudSk--;
        break;
    }

    if (pasirinkimas == 'r'){
        int* tempNd = new int [StudSk]; //prapleciamas nd skaitiklis
        for (int i = 0; i<StudSk-1; i++) tempNd[i]=(*NdSk)[i];
        delete [] (*NdSk);
        (*NdSk) = tempNd;
        (*NdSk)[StudSk-1]=0;

        (*id)[StudSk-1].paz = new int [1]; //sukuriamas pazymiu masyvas
        cout << "Iveskite namu darbu pazymius: (Noredami nutraukti ivedima iveskite: /e)\n";
        while (1){ //nd irasymas
            cin >> pazymys;
            if (pazymys=="0"||pazymys=="1"||pazymys=="2"||pazymys=="3"||pazymys=="4"||pazymys=="5"||pazymys=="6"||pazymys=="7"||pazymys=="8"||pazymys=="9"||pazymys=="10"){
                convert = stoi(pazymys); 
                (*NdSk)[StudSk-1]++;
                int *tempPaz = new int [(*NdSk)[StudSk-1]]; //prapleciamas nd masyvas
                for (int i = 0; i<(*NdSk)[StudSk-1]-1; i++) tempPaz[i]=(*id)[StudSk-1].paz[i];
                delete[] (*id)[StudSk-1].paz;
                (*id)[StudSk-1].paz = tempPaz;

                (*id)[StudSk-1].paz[(*NdSk)[StudSk-1]-1] = convert;
            } 
            else if (pazymys == "/e" && (*NdSk)[StudSk-1] != 0) break;
            else cout << "Prasome ivesti sveika pazymi nuo 0 iki 10.\n";        
        }

        cout << "Prasome ivesti egzamino rezultata:\n";
        while (1){
            pazymys = cin.get();
            if (pazymys=="0"||pazymys=="1"||pazymys=="2"||pazymys=="3"||pazymys=="4"||pazymys=="5"||pazymys=="6"||pazymys=="7"||pazymys=="8"||pazymys=="9"||pazymys=="10"){
                convert = stoi(pazymys); 
                (*id)[StudSk-1].egz = convert;
                break;
            } 
            else {
                cout << "Prasome ivesti sveika pazymi nuo 0 iki 10.\n";
            } 
        }    


    }
    else if(pasirinkimas == 'a') {
        (*id)[StudSk-1].paz = new int [autokiekis];
        random_device rd;
        mt19937 mt(rd());
        uniform_int_distribution <int> dist(1,10);
        for (int i=0; i<autokiekis; i++) 
        (*id)[StudSk-1].paz[i] = dist(mt);
        (*id)[StudSk-1].egz = dist(mt);
        (*NdSk)[StudSk-1]=autokiekis;
    }
}
}

double vidurkis (studentas* id, int pazSk, int studentas){
double suma=0;
for (int i=0; i<pazSk; i++) suma=suma+id[studentas].paz[i];
return (suma/pazSk) * 0.4 + id[studentas].egz * 0.6;
}

double mediana (studentas* id, int pazSk, int studentas){
int temp, tempId;
double med;
for (int i=0; i<pazSk-1; i++){ //pazymiai sutvarkomi nemazejimo tvarka
    temp = id[studentas].paz[i];
    for (int j=1+i; j<pazSk; j++){
        if (id[studentas].paz[j]<temp){
            temp = id[studentas].paz[j];
            tempId = j;
        }
    }
    if (temp!=id[studentas].paz[i]){
        id[studentas].paz[tempId]=id[studentas].paz[i];
        id[studentas].paz[i] = temp;
    }
}

if (pazSk==1)
return id[studentas].paz[0] * 0.4 + id[studentas].egz * 0.6;
else 
if (pazSk%2!=0)
return id[studentas].paz[pazSk-1/2+1] * 0.4 + id[studentas].egz * 0.6;
else
return ((id[studentas].paz[(pazSk-1)/2]+id[studentas].paz[(pazSk-1)/2+1])/2) * 0.4 + id[studentas].egz * 0.6;


}

void Print (studentas* id, int StudSk, int* NdSk) {
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
            } else cout << "Ivedete neteisinga reiksme\n";
    }


    for (int i=0; i<StudSk; i++){
        cout << left << setw(20) << id[i].pavarde << left << setw(15) << id[i].vardas;
        if (metodas == 'v')
        cout << fixed << setprecision(2) << vidurkis (id, NdSk[i], i) << "\n";
        else
        cout << fixed << setprecision(2) << mediana (id, NdSk[i], i) << "\n";
    }
}

int main () {
    studentas* id;
    int* NdSk;
    int StudSk=0;

    Read (&id, StudSk, &NdSk);
    Print (id, StudSk, NdSk);

    delete[] NdSk;
    for (int i=0; i<StudSk; i++)
    delete[] id[i].paz;
    delete[] id;
    return 0;
}