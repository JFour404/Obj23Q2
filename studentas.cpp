#include "studentas.h"
#include "header.h"

bool palygintiPavardes(const studentas& a, const studentas& b) {
    return a.Pavarde() < b.Pavarde();
}

double studentas::vidurkis (){
    double suma = 0;
    for (auto it = m_Paz.begin(); it != m_Paz.end(); ++it) {
        suma += *it;
    }
    return suma/m_Paz.size()* 0.4 + m_Egz * 0.6;
}

double studentas::mediana (){
    sort(m_Paz.begin(), m_Paz.end());
    double vid = m_Paz.size() / 2.0;
    return m_Paz.size() % 2 == 0 ? 
        ((m_Paz[vid - 1] + m_Paz[vid]) / 2.0) * 0.4 + m_Egz * 0.6 : 
        m_Paz[vid] * 0.4 + m_Egz * 0.6;
}

void studentas::randomGradeGen(int kiekis){
    random_device rd;
    mt19937 mt(rd());
    uniform_int_distribution <int> dist(1,10);
    for (int i=0; i<kiekis; i++) m_Paz.push_back(dist(mt));
    m_Egz=(dist(mt));
}

studentas::studentas(istream& is, int baloSkc, int pazPildymas, int kiekis) {
    cout << "\nIveskite studento varda (iveskite /e, kad nutraukti): ";
    is >> m_Vardas;
    if (m_Vardas == "/e") {
        throw runtime_error("Ivedimas nutrauktas.");
    }
    cout << "Iveskite studento pavarde: ";
    is >> m_Pavarde;
    if (m_Pavarde == "/e") {
        throw runtime_error("Ivedimas nutrauktas.");
    }
    
    if (pazPildymas == 0){
        cout << "Noredami nutraukti pazymiu irasymas iveskite /e.\n";
        cout << "Iveskite nd pazymius: ";
        string pazymys;
        while (1){
                cin >> pazymys;
                if (pazymys != "/e"){
                    if (pazymys=="0"||pazymys=="1"||pazymys=="2"||pazymys=="3"||pazymys=="4"||pazymys=="5"||pazymys=="6"||pazymys=="7"||pazymys=="8"||pazymys=="9"||pazymys=="10") 
                        m_Paz.push_back(stoi(pazymys));
                    else {
                        cout << "Ivedete netinkama pazymi. Visi like pazymiai uz blogo pazymio buvo neissaugoti.\n"; 
                        cin.clear(); 
                        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    }
                }   
                else {
                    cin.clear(); 
                    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    if (!m_Paz.empty())
                    break; 
                    else cout << "Turite ivesti bent viena pazymi.\n";
                } 
            }
        
        cout << "Iveskite studento egzamino pazymi: ";
        while (1){
            if (is >> m_Egz && m_Egz>0 &&m_Egz<11)
                break;
            else {
                cout << "Netinkama ivestis. Veskite is naujo: ";
                cin.clear(); 
                cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); 
            } 
        }
    } else {
        randomGradeGen(kiekis);
    }


    if (baloSkc == 1)
        m_GalBalas = vidurkis();
    else
        m_GalBalas = mediana();

    is.clear();
    is.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

studentas::studentas(stringstream& ss) {
    int pazymys;
    ss >> m_Vardas >> m_Pavarde;
        while (ss >> pazymys) m_Paz.push_back(pazymys);
        if (m_Paz.empty()) {
            throw runtime_error("Netinkamas formatas: nerastas pazymys");
        }
        m_Egz = m_Paz.back();
        m_Paz.pop_back();
}