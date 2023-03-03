#include "header.h"
#include "fun.cpp"


int main (){
    vector<studentas> id;
    
    string budas;
    cout << "Studentu duomenis vesite ranka ar nuskaitysite is failo (f/r)\n";
    while (1){
        cin >> budas; 
        if (budas == "r" || budas == "f"){
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

    if (budas == "f"){
        try {
            ifstream open_f("studentai1000000.txt");
            if (!open_f) throw runtime_error("Failas nerastas arba nepavyko atidaryti.");
            autoRead (&id);
            sort(id.begin(), id.end(), palygintiPavardes);
            autoWrite (id);
            }
        catch (exception const& e) {
            cerr << "Klaida: " << e.what() << endl;
            }  
        
    } else {
        read (&id);
        sort(id.begin(), id.end(), palygintiPavardes);
        write (id);    
    }
    return 0;
}