#include <iostream>
#include <fstream>
#include "Czas.h"

using namespace std;

void ukryj()
{
	HWND okno = GetConsoleWindow();
	ShowWindow( okno, SW_HIDE );
}

void pokaz()
{
	HWND okno = GetConsoleWindow();
	ShowWindow( okno, SW_SHOW );
}

int main()
{
	SetConsoleTitle("logi");
    ukryj();
    string linia="brak danych [koniec]";
    fstream koniec;
    fstream start;
    fstream temp;
    Czas czas = Czas();

    koniec.open("D:\\odczyt\\koniec.txt",ios::in);
    if(koniec.good())
    {
        getline(koniec,linia);
    }
    koniec.close();

    koniec.open("D:\\odczyt\\logi.txt",ios::out | ios::app);
    koniec<<linia<<endl;
    koniec.close();

    czas.ustawCzasPolski();

    start.open("D:\\odczyt\\logi.txt",ios::out | ios::app);
    start<<czas.dzien<<"\t"<<czas.miesiac<<"\t"<<czas.rok<<"\t"<<czas.godzina<<"\t"<<czas.minuta<<"\t"<<czas.sekunda<<"\t"<<czas.tryb<<endl;
    start.close();


    czas.tryb="[koniec]";

    while(true)
    {
        temp.open("D:\\odczyt\\koniec.txt",ios::out);
        czas.ustawCzasPolski();
        temp<<czas.dzien<<"\t"<<czas.miesiac<<"\t"<<czas.rok<<"\t"<<czas.godzina<<"\t"<<czas.minuta<<"\t"<<czas.sekunda<<"\t"<<czas.tryb<<endl;
        temp.close();
        Sleep(60000);
    }


    return 0;
}
