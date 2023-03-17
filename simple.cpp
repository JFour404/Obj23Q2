#include "header.h"
#include "fun.cpp"

int main(){
    int testPazNum;
//---------------------------------------------------------------------------------------------------------------    
    cout << "Ar norite vykdyti programos testavima? (0 - ne, 1 - taip)\n";
    
    if (ask()==1){
        cout << "Kiek generuoti nd pazymiu?\n";
        testPazNum = intInput();
        cout << "Galutini bala skaiciuoti naudojant mediana(0) ar vidurki(1)?\n";
        int baloSkc = ask(); //kokiu budu skaiciuojmas bendras
            cout << "\n" << "----------Testavimo rezultatai---------\n";
            testFiles(testPazNum); //sugeneruojami 5 failai 
            vector<studentas> id;
            string failas, sortF;
            
            for (int f=1000; f<100001; f=f*10) {
                id.reserve(f);
                failas = "studentai" + to_string(f) + ".txt";
                autoRead(&id, failas); //nuskaitomas kiekvienas failas atskirai
                
                    cout << "\n";
                    auto start = std::chrono::high_resolution_clock::now();
                    auto st=start;
                sort(id.begin(), id.end(), palygintiPavardes);//isrusiuojama pagal pavardes
                    auto end = std::chrono::high_resolution_clock::now();
                    std::chrono::duration<double> diff = end-start;
                    cout << failas << " rusiavimas pagal pavardes: " << diff.count() << " s.\n";
                    cout << "\n";
                
                
                testWrite(id, baloSkc);
                id.clear();
            }
    }
    else{

    }
    return 0;
}



// auto start = chrono::high_resolution_clock::now(); 
// auto st=start;
// chrono::duration<double> diff = chrono::high_resolution_clock::now()-start;

// start = chrono::high_resolution_clock::now();
// diff = chrono::high_resolution_clock::now()-start;

// end = chrono::high_resolution_clock::now();
// diff = end-start; // Skirtumas (s)



// auto start = std::chrono::high_resolution_clock::now();
// auto st=start;

// auto end = std::chrono::high_resolution_clock::now();
// std::chrono::duration<double> diff = end-start;
// cout << failas << " sudarymas uztruko: " << diff.count() << " s.\n";