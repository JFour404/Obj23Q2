#include "header.h"
#include "funkcijos.cpp"




int main(){
    int testPazNum, testON, genFiles, baloSkc, boost;
    string comm, strat;
    vector <double> nuskaitymas, rusiavimasPglPavardes, rusiavimasIDviGrupes, fileTime;
    vector <string> failoPav;
//---------------------------------------------------------------------------------------------------------------    
    cout << "\nPasirinkite konteinerio tipa: \n/v (vector)\n/d (deque)\n/l (list)\n";
    comm = askCommand(0);

    cout << "\nPasirinkite studentu skirstymo strategija:\n/0c (nenaudojant papildomu konteineriu)\n/1c (naudojant 1 papildoma konteineri)\n/2c (naudojant 2 papildomus konteinerius)\n";
    strat = askCommand(1);

    if (strat == "/1c"){
        cout << "\nAr norite naudoti pagerinta startegija? (0 - ne, 1 - taip)\n";
        boost = ask();
    }
    
    cout << "\nAr norite vykdyti programos testavima? (0 - ne, 1 - taip)\n";
    testON = ask();


    if ((testON==1)){
        cout << "\nNaudoti jau sugeneruotus failus(0) ar sugeneruoti naujus(1)?\n";
        genFiles = ask ();

        cout << "\nGalutini bala skaiciuoti naudojant mediana(0) ar vidurki(1)?\n";
        baloSkc = ask(); //kokiu budu skaiciuojmas bendras
            
        if (genFiles==1){
            cout << "\nKiek generuoti nd pazymiu?\n";
            testPazNum = intInput();
        }
    }
    
    if (comm == "/v"){
        vector<studentas> id;   
        prep (id, testON, genFiles, testPazNum, baloSkc, strat, comm, boost, nuskaitymas, rusiavimasPglPavardes, rusiavimasIDviGrupes, failoPav, fileTime);
    } else 
    
    if (comm == "/d"){
        deque<studentas> id;   
        prep (id, testON, genFiles, testPazNum, baloSkc, strat, comm, boost, nuskaitymas, rusiavimasPglPavardes, rusiavimasIDviGrupes, failoPav, fileTime);
    } else
    
    if (comm == "/l"){
        list<studentas> id;   
        prep (id, testON, genFiles, testPazNum, baloSkc, strat, comm, boost, nuskaitymas, rusiavimasPglPavardes, rusiavimasIDviGrupes, failoPav, fileTime);
    }
    
    rezSpausdinimas (nuskaitymas, rusiavimasPglPavardes, rusiavimasIDviGrupes, failoPav, testPazNum, comm, strat, boost, baloSkc, fileTime);
    return 0;
}


