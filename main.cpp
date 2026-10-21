#include <iostream>
#include <string>
#include <clocale>
#include <algorithm> 
#include <cctype>

using namespace std;

string tanksecim;
int delmedeger;
int ates;
int aci;

void secim() {
    cout << "Tankinizi Seciniz (Tiger veya T34): ";
    cin >> tanksecim;
}

void secimdogrula() {
    // Girilen harfleri tamamen küçük harfe çeviriyoruz
    transform(tanksecim.begin(), tanksecim.end(), tanksecim.begin(), ::tolower);

    if (tanksecim == "tiger") {
        cout << "Secilen Tank: Tiger" << endl;
        cout << "Savas Baslasin! Dusman: T34" << endl;
        for (int i = 0; i < 3; i++) {
            cout << i << "\n";
        }
    }
    else if (tanksecim == "t34") {
        cout << "Secilen Tank: T34" << endl;
        cout << "Savas Baslasin! Dusman: Tiger" << endl;
        for (int i = 0; i < 3; i++) {
            cout << i << "\n";
        }
    }
    else {
        cout << "Gecersiz tank secimi!" << endl;
    }
}

void tankacisi() {
    cout << "Tankinizin acisi kac olsun? (15, 30, 90): ";
    cin >> aci;
}

void saldiri() {
    cout << "Saldiri Basladi! Atak sirasi sende." << endl;
    cout << "Ates Et (1) ya da Saklan (0): ";
    cin >> ates;
}

void ateşmantik() {
    // tanksecim artık küçük harf ("tiger" veya "t34") olduğu için buraları da küçük harfe çevirdik
    if (tanksecim == "tiger" && ates == 1) {
        if (aci == 15) {
            cout << "Karsi Tank delindi ve patladi!" << endl;
        }
        else if (aci == 30) { // 35'i 30 yaptık ki seçenekle uyuşsun
            cout << "Mermi deldi ama patlamadi!" << endl;
        }
        else {
            cout << "T34 zirhi mermiyi sektirdi, hasar yok!" << endl;
        }
    }
    else if (tanksecim == "tiger" && ates == 0) {
        cout << "Catismadan kactın!" << endl;
    }
    else if (tanksecim == "t34" && ates == 1) {
        if (aci == 15) {
            cout << "Karsi Tank delindi fakat patlamadi!" << endl;
        }
        else if (aci == 30) { // 35'i 30 yaptık
            cout << "Mermi deldi ama patlamadi!" << endl;
        }
        else {
            cout << "Tiger zirhi mermiyi sektirdi, hasar yok!" << endl;
        }
    }
    else if (tanksecim == "t34" && ates == 0) {
        cout << "Tiger'dan kactın, sonraki sefere!" << endl;
    }
}

int main() {
    setlocale(LC_ALL, "Turkish");

    secim();
    secimdogrula();

    // Eğer geçerli tank seçildiyse oyuna devam et
    if (tanksecim == "tiger" || tanksecim == "t34") {
        tankacisi();
        saldiri();
        ateşmantik();
    }

    return 0;
}