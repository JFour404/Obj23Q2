#pragma once
#include "header.h"

class zmogus {
protected:
    string m_Vardas, m_Pavarde;
public:
    zmogus () : m_Vardas(""), m_Pavarde("") {}
    zmogus (string vardas, string pavarde) : m_Vardas(vardas), m_Pavarde(pavarde) {}

    virtual void Vardas (string vardas) = 0;
    virtual void Pavarde (string pavarde) = 0;
    virtual inline string Vardas () const = 0;
    virtual inline string Pavarde () const = 0;

    virtual ~zmogus() {}
};

class studentas : public zmogus {
private:
    vector<int> m_Paz;
    int m_Egz;
    double m_GalBalas;
public:
    //kostruktoriai
    studentas () : zmogus () {}
    studentas (string vardas, string pavarde, vector<int> paz, int egz) : zmogus(vardas, pavarde), m_Paz(paz), m_Egz(egz) {}
    studentas (istream& is, int baloSkc, int pazPildymas, int kiekis);
    studentas (stringstream& ss);

    //set'eriai
    void Vardas (string vardas) override { m_Vardas = vardas; }
    void Pavarde (string pavarde) override { m_Pavarde = pavarde; }
    void Paz (vector <int> paz) { m_Paz = paz; }
    void PazAdd (int paz) { m_Paz.push_back(paz); }
    void Egz (int egz) { m_Egz = egz; }
    void GalBalas (int baloSkc) { baloSkc == 0 ? m_GalBalas = mediana() : m_GalBalas = vidurkis();}
    
    //get'eriai
    inline string Vardas ()  const override { return m_Vardas; }
    inline string Pavarde () const override { return m_Pavarde; }
    inline vector<int> Paz () const { return m_Paz; }
    inline int Egz () const { return m_Egz; }
    inline double GalBalas () const { return m_GalBalas; }

    double vidurkis();
    double mediana();
    void randomGradeGen(int kiekis);

    //copy c-tor
    studentas (const studentas& other) :
        zmogus (other),
        m_Paz(other.m_Paz),
        m_Egz(other.m_Egz),
        m_GalBalas(other.m_GalBalas) {}

    //move c-tor
    studentas (studentas&& other) :
        zmogus(std::move(other)),
        m_Paz(std::move(other.m_Paz)),
        m_Egz(other.m_Egz),
        m_GalBalas(other.m_GalBalas) {
            other.m_Vardas = "";
            other.m_Pavarde = "";
            other.m_Egz = 0;
            other.m_GalBalas = 0;
        }
    
    //copy =
    studentas& operator= (const studentas& other){
        if (&other == this) return *this;

        m_Vardas = other.m_Vardas;
        m_Pavarde = other.m_Pavarde;
        m_Paz = other.m_Paz;
        m_Egz = other.m_Egz;
        m_GalBalas = other.m_GalBalas;

        return *this;
    }

    //move =
    studentas& operator= (studentas&& other){
        if (&other == this) return *this;

        m_Vardas = other.m_Vardas;
        m_Pavarde = other.m_Pavarde;
        m_Paz = std::move(other.m_Paz);
        m_Egz = other.m_Egz;
        m_GalBalas = other.m_GalBalas;
        other.~studentas();
            other.m_Vardas = "";
            other.m_Pavarde = "";
            other.m_Egz = 0;
            other.m_GalBalas = 0;
        return *this;
    }

    ~studentas () {m_Paz.clear();}
};

bool palygintiPavardes(const studentas& a, const studentas& b);
