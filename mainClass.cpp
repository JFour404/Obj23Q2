#include "header.h"

int main () {
    string conType;
    int baloSkc, duomNuskaitymas;
    auto allS = std::chrono::high_resolution_clock::time_point();
//--------------------------------
    cout << "\nPasirinkite konteinerio tipa: \n/v (vector)\n/d (deque)\n/l (list)\n";
    conType = askCommand(0);
    cout << "\nGalutini bala skaiciuoti naudojant: \n(0) mediana \n(1) vidurki\n";
    baloSkc = ask(); 
    cout << "\nDuomenu nuskaitymas is: \n(0) failo \n(1) konsoles\n";
    duomNuskaitymas = ask();
//--------------------------------
    if (duomNuskaitymas == 1){
        int pazPildymas;
        cout << "\nPazymius: \n(0) vesite ranka \n(1) generuoti atsitiktinius\n";
        pazPildymas = ask();
        int kiekis = 0;
        if (pazPildymas == 1){
            cout << "\nKiek sugeneruoti nd pazymiu?\n";
            kiekis = intInput();
        }

        if (conType == "/v"){
            vector <studentas> id;
            cmdRankinis (id, baloSkc, pazPildymas, kiekis);
        } else
        if (conType == "/d"){
            deque <studentas> id;
            cmdRankinis (id, baloSkc, pazPildymas, kiekis);
        } else
        if (conType == "/l"){
            list<studentas> id;
            cmdRankinis (id, baloSkc, pazPildymas, kiekis);
        }
    } else {
        cout << "\nAr norite studentus isskaidyti i dvi grupes? (1 - taip, 0 - ne)\n";
        int skaidymas = ask();
        if (skaidymas == 1){
            cout << "\nNorite pasirinkti faila (0) ar naudoti testavimo failus(1)?\n(studentai1000.txt, studentai10000.txt, studentai100000.txt, studentai1000000.txt, studentai10000000.txt)\n";
            int defaultFiles = ask();
            if (defaultFiles == 1){
                cout << "\nAr norite nukurti naujus testavimo failus? (taip - 1, ne - 0)\n";
                if (ask() == 1) {
                    cout << "\nKiek sugeneruoti nd pazymiu?\n";
                    int pazSkc = intInput();
                    vector<string> name;
                    vector<string> surname;
                    nameSurname (name, surname);
                    for (int f=1000; f<10000001; f=f*10){
                        testFiles (pazSkc, name, surname, f);
                    }
                }    
            }
            cout << "\nPasirinkite studentu skirstymo strategija:\n/0c (nenaudojant papildomu konteineriu)\n/1c (naudojant 1 papildoma konteineri)\n/2c (naudojant 2 papildomus konteinerius)\n";
            string dalinimoStrat = askCommand(1);
            allS = std::chrono::high_resolution_clock::now();
            if (defaultFiles == 0){
                string failas = fileSelect();
                cout << "\n" << "############################################################\n";  
                cout << right << setw (40) << "TESTAVIMO REZULTATAI\n";
                cout << "############################################################\n";
                if (conType == "/v"){
                    vector <studentas> id;
                    fileFull (id, baloSkc, failas, dalinimoStrat, conType);
                } else
                if (conType == "/d"){
                    deque <studentas> id;
                    fileFull (id, baloSkc, failas, dalinimoStrat, conType);
                } else
                if (conType == "/l"){
                    list<studentas> id;
                    fileFull (id, baloSkc, failas, dalinimoStrat, conType);
                }
            } else {
                cout << "\n" << "############################################################\n";  
                cout << right << setw (40) << "TESTAVIMO REZULTATAI\n";
                cout << "############################################################\n";
                for (int f=1000; f<10000001; f=f*10) {
                    string failas = "studentai" + to_string(f) + ".txt";
                    if (conType == "/v"){
                        vector <studentas> id;
                        fileFull (id, baloSkc, failas, dalinimoStrat, conType);
                    } else
                    if (conType == "/d"){
                        deque <studentas> id;
                        fileFull (id, baloSkc, failas, dalinimoStrat, conType);
                    } else
                    if (conType == "/l"){
                        list<studentas> id;
                        fileFull (id, baloSkc, failas, dalinimoStrat, conType);
                    }
                }
            } 
        }else {
            if (conType == "/v"){
                vector <studentas> id;
                fileBasic (id, baloSkc);
            } else
            if (conType == "/d"){
                deque <studentas> id;
                fileBasic (id, baloSkc);
            } else
            if (conType == "/l"){
                list<studentas> id;
                fileBasic (id, baloSkc);
            }
        }
    }
    auto allF = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> diff = allF - allS;
    cout << left << setw(35) << "VISA PROGRAMA VEIKE" << diff.count() << " s.\n";
    cout << "############################################################\n";
    return 0;
}
