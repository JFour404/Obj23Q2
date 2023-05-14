#include <gtest/gtest.h>
#include "header.h"

struct studentasTest : testing::Test {
	studentas* id; 
	studentas* idNext;
	studentasTest() {
		id = new studentas;
		idNext = new studentas;
	}
	virtual ~studentasTest() {
		delete id, idNext;
	}
};

TEST_F(studentasTest, vardoKeitimas) {
	id->Vardas("Justas");
	EXPECT_EQ("Justas", id->Vardas());
}

TEST_F(studentasTest, duomenuIvedimas) {
	int tempPaz = 5;
	vector <int> temp = { 4, 5, 6 };
	id->Vardas("Jokubas");
	id->Pavarde("Zalenckis");
	id->Paz(temp);
	id->Egz(5);
	id->GalBalas(1);
	EXPECT_EQ("Jokubas", id->Vardas());
	EXPECT_EQ("Zalenckis", id->Pavarde());
	EXPECT_EQ(5, id->GalBalas());
}

TEST_F(studentasTest, pavardziuPalyginimas) {
	id->Pavarde("Alvarez");
	idNext->Pavarde("Baker");
	EXPECT_EQ(1, palygintiPavardes(*id, *idNext));
}

int main(int argc, char* argv[]) {
	testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
