#include "header.h"
#include "fun.cpp"

int main(){
    int testPazNum;
//---------------------------------------------------------------------------------------------------------------    
    cout << "Ar norite vykdyti programos testavima? (0 - ne, 1 - taip)\n";
    
    if (ask()==1){
        vector<string> names, surnames;
        vector<studentas> id;
        string failas, sortF;
        
        cout << "Kiek generuoti nd pazymiu?\n";
        testPazNum = intInput();
        
        cout << "Galutini bala skaiciuoti naudojant mediana(0) ar vidurki(1)?\n";
        int baloSkc = ask(); //kokiu budu skaiciuojmas bendras

        auto allS = std::chrono::high_resolution_clock::now();
        nameSurname (&names, &surnames);  
        cout << "\n" << "----------Testavimo rezultatai---------\n";  
            
            for (int f=1000; f<10000001; f=f*10) {
                auto begin = std::chrono::high_resolution_clock::now();

                    failas = "studentai" + to_string(f) + ".txt";
                    id.reserve(f);

                auto start = std::chrono::high_resolution_clock::now();
                    testFiles(testPazNum, names, surnames, f);
                auto end = std::chrono::high_resolution_clock::now();
                std::chrono::duration<double> diff = end-start;
                cout << failas << " sudarymas uztruko: " << diff.count() << " s.\n";
                
                
                start = std::chrono::high_resolution_clock::now();
                    autoRead(&id, failas); //nuskaitomas kiekvienas failas atskirai
                end = std::chrono::high_resolution_clock::now();
                diff = end-start;
                cout << failas << " nuskaitymas uztruko: " << diff.count() << " s.\n";

                start = std::chrono::high_resolution_clock::now();
                    sort(id.begin(), id.end(), palygintiPavardes);//isrusiuojama pagal pavardes
                end = std::chrono::high_resolution_clock::now();
                diff = end-start;
                cout << failas << " rusiavimas pagal pavardes: " << diff.count() << " s.\n";
                    
                
                    testWrite(id, baloSkc);
                
                id.clear();
                
                auto finish = std::chrono::high_resolution_clock::now();
                diff = finish-begin;
                cout << f << " irasu testo laikas: " << diff.count() << " s.\n\n";
            }
        names.clear();
        surnames.clear();

        auto allF = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> diff = allF - allS;
        cout << "Viso programa veike: " << diff.count() << " s.\n";
    }
    
    else{
        vector<studentas> id;
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
                autoRead (&id, failas);
                sort(id.begin(), id.end(), palygintiPavardes);
                autoWrite (id, "studentai_copy", baloSkc);
                break;
                }
            catch (exception const& e) {
                cerr << "Klaida: " << e.what() << endl;
                }     
            }
            
            
        } else {
            read (&id);
            sort(id.begin(), id.end(), palygintiPavardes);
            write (id);    
        }
    }
    return 0;
}
