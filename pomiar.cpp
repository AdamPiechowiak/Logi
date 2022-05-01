#include <iostream>
#include <fstream>
#include "Czas.h"

using namespace std;

int main()
{
    fstream start;
    Czas czas = Czas();

    czas.ustawCzasPolski();
	
    czas.tryb="[pomiar]";
    
    start.open("D:\\odczyt\\logi.txt",ios::out | ios::app);
    start<<czas.dzien<<"\t"<<czas.miesiac<<"\t"<<czas.rok<<"\t"<<czas.godzina<<"\t"<<czas.minuta<<"\t"<<czas.sekunda<<"\t"<<czas.tryb<<endl;
    start.close();
    
    getchar();

    return 0;
}
