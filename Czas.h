#ifndef CZAS_H
#define CZAS_H
#include <iostream>
#include <windows.h>

using namespace std;

class Czas
{
    public:

        int rok;
        int miesiac;
        int dzien;

        int dzientygodnia;

        int godzina;
        int minuta;
        int sekunda;
        string tryb = "[start]";

        /*SYSTEMTIME st;
        GetSystemTime(&st);
        cout << "Biezacy rok to " << st.wYear<< endl;
        cout << "Biezacy miesiac to " << st.wMonth<< endl;
        cout << "Biezacy dzien tygodnia to " << st.wDayOfWeek<< endl;
        cout << "Biezacy dzien  to " << st.wDay<< endl;
        cout << "Biezaca godzina  to " << st.wHour<< endl;
        cout << "Biezaca minuta  to " << st.wMinute<< endl;
        cout << "Biezaca sekunda  to " << st.wSecond<< endl;
        cout << "Biezaca milisekunda  to " << st.wMilliseconds<< endl;*/

        Czas()
        {

        }

        void pobiezCzas()
        {
            SYSTEMTIME st;
            GetSystemTime(&st);

            this->rok=st.wYear;
            this->miesiac=st.wMonth;
            this->dzien=st.wDay;

            this->dzientygodnia=st.wDayOfWeek;

            this->godzina=st.wHour;
            this->minuta=st.wMinute;
            this->sekunda=st.wSecond;
        }

        void wypiszCzas()
        {
            cout<<this->dzien<<"/"<<this->miesiac<<"/"<<this->rok<<" "
            <<this->godzina<<":"<<this->minuta<<":"<<this->sekunda<<endl;
        }

        void ustawStrefe(int s)
        {
            pobiezCzas();
            this->godzina+=s;
        }

        void ustawCzasPolski()
        {
            pobiezCzas();
            if(this->miesiac==10&&this->dzien==31)
            {
                ustawStrefe(2);
            }
            else if(this->miesiac==10&&this->dzien==30&&(this->dzientygodnia==7||this->dzientygodnia<=5))
            {
                ustawStrefe(2);
            }
            else if(this->miesiac==10&&this->dzien==29&&(this->dzientygodnia==7||this->dzientygodnia<=4))
            {
                ustawStrefe(2);
            }
            else if(this->miesiac==10&&this->dzien==28&&(this->dzientygodnia==7||this->dzientygodnia<=3))
            {
                ustawStrefe(2);
            }
            else if(this->miesiac==10&&this->dzien==27&&(this->dzientygodnia==7||this->dzientygodnia<=2))
            {
                ustawStrefe(2);
            }
            else if(this->miesiac==10&&this->dzien==26&&(this->dzientygodnia==7||this->dzientygodnia<=1))
            {
                ustawStrefe(2);
            }
            else if(this->miesiac==10&&this->dzien==25&&(this->dzientygodnia==7))
            {
                ustawStrefe(2);
            }
            else if(this->miesiac==3&&this->dzien==31)
            {
                ustawStrefe(1);
            }
            else if(this->miesiac==3&&this->dzien==30&&(this->dzientygodnia==7||this->dzientygodnia<=5))
            {
                ustawStrefe(1);
            }
            else if(this->miesiac==3&&this->dzien==29&&(this->dzientygodnia==7||this->dzientygodnia<=4))
            {
                ustawStrefe(1);
            }
            else if(this->miesiac==3&&this->dzien==28&&(this->dzientygodnia==7||this->dzientygodnia<=3))
            {
                ustawStrefe(1);
            }
            else if(this->miesiac==3&&this->dzien==27&&(this->dzientygodnia==7||this->dzientygodnia<=2))
            {
                ustawStrefe(1);
            }
            else if(this->miesiac==3&&this->dzien==26&&(this->dzientygodnia==7||this->dzientygodnia<=1))
            {
                ustawStrefe(1);
            }
            else if(this->miesiac==3&&this->dzien==25&&(this->dzientygodnia==7))
            {
                ustawStrefe(1);
            }
            else if(this->miesiac>=11&&this->miesiac<=3)
            {
                ustawStrefe(2);
            }
            else
            {
                ustawStrefe(1);
            }

            if(this->godzina>=24)
            {
                this->godzina-=24;
                this->dzien++;
            }
        }

};

#endif // CZAS_H
