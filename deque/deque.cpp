#include "headerDeq.h"
#include "funkcijosDeq.cpp"

int main(){
    int testPazNum, testON, genFiles;
//---------------------------------------------------------------------------------------------------------------    
    cout << "Ar norite vykdyti programos testavima? (0 - ne, 1 - taip)\n";
    testON = ask();
    

    if (testON==1){
        vector<string> names, surnames;
        deque<studentas> id;
        string failas, sortF;
        
        cout << "Naudoti jau sugeneruotus failus(0) ar sugeneruoti naujus(1)?\n";
        genFiles = ask ();

        cout << "Galutini bala skaiciuoti naudojant mediana(0) ar vidurki(1)?\n";
        int baloSkc = ask(); //kokiu budu skaiciuojmas bendras
        
        if (genFiles==1){
            cout << "Kiek generuoti nd pazymiu?\n";
            testPazNum = intInput();
        }

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
                // begin = std::chrono::high_resolution_clock::now();

                    failas = "studentai" + to_string(f) + ".txt";
                    //id.reserve(f);
                    cout << left << setw(35) <<  "FAILAS" <<  failas << "\n";

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

                start = std::chrono::high_resolution_clock::now();
                    sort(id.begin(), id.end(), palygintiPavardes);//isrusiuojama pagal pavardes
                end = std::chrono::high_resolution_clock::now();
                diff = end-start;
                cout << left << setw(35) << "RUSIAVIMAS PAGAL PAVARDES" << diff.count() << " s.\n";
                    
                
                    testWrite(id, baloSkc);
                
                id.clear();
                
                // finish = std::chrono::high_resolution_clock::now();
                // diff = finish-begin;
                // cout << left << setw(35) << "FAILO TESTO LAIKAS" << diff.count() << " s.\n";
                cout << "------------------------------------------------------------\n\n";
            }
        names.clear();
        surnames.clear();

        auto allF = std::chrono::high_resolution_clock::now();
        diff = allF - allS;
        cout << left << setw(35) << "VISA PROGRAMA VEIKE" << diff.count() << " s.\n";
        cout << "############################################################\n";
    }
    
    else{
        deque<studentas> id;
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
                sort(id.begin(), id.end(), palygintiPavardes);
                autoWrite (id, "studentai_copy", baloSkc);
                break;
                }
            catch (exception const& e) {
                cerr << "Klaida: " << e.what() << endl;
                }     
            }
            
            
        } else {
            read (id);
            sort(id.begin(), id.end(), palygintiPavardes);
            write (id);    
        }
    }
    return 0;
}
