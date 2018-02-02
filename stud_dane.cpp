#include <iostream>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

using namespace std;

struct Student
{
    string Imie;
    string Nazw;
    int Num;
};


int main()
{
    char menu = 0;
    int t = 0;
    
    //Student Uzytkownicy [5];
    //Student * uczen = new Student;
    
    Student Uzytkownicy [5] =
    {
        {"Morty" , "Smith" , 123456}
    };
    
    /*
    uczen->Imie = "Morty";
    uczen->Nazw = "Smith";
    uczen->num = 123456;
    */

    cout << "MENU" << endl;
    cout << "w- wpisywanie nowych danych" << endl;
    cout << "s- sortowanie po numerze indeksu" << endl;
    cout << "u- usuwanie danych po numerze indeksu" << endl;
    cout << "p- pokazywanie danych studentów" << endl;
    cout << "k- KONIEC PROGRAMU!" << endl;
    
    do
    {
        cout << endl << "Prosze wybrac opcje (m- menu): ";
        cin >> menu;
        
        switch(menu)
        {
            case 'w':
                for(short licz = 0; licz < 5; licz++)
                {
                    cout << "Podaj imie: ";
                    cin >> Uzytkownicy[licz].Imie;
                    cout << endl << "Podaj nazwisko: ";
                    cin >> Uzytkownicy[licz].Nazw;
                    cout << endl << "Podaj nr indeksu: ";
                    cin >> Uzytkownicy[licz].Num;
                    cout << endl;
                }
                
                break;
            case 'm':
                
                cout << "MENU" << endl;
                cout << "w- wpisywanie nowych danych" << endl;
                cout << "s- sortowanie po numerze indeksu" << endl;
                cout << "u- usuwanie danych po numerze indeksu" << endl;
                cout << "p- pokazywanie danych studentów" << endl;
                cout << "k- KONIEC PROGRAMU!" << endl;
                
                break;
            case 'p':
                
                for(short licz = 0; licz < 5; licz++)
                {
                    cout << "Imie i Nazwisko: " << Uzytkownicy[licz].Imie <<
                    " " << Uzytkownicy[licz].Nazw << "nr indeksu:" <<
                    Uzytkownicy[licz].Num << endl;
                }
                
            case 'u':
                
                for(short licz = 0; licz < 5; licz++)
                {
                cout << "Podaj nr indeksu: ";
                cin >> Uzytkownicy[licz].Num;
                t = Uzytkownicy[licz].Num;
                if (t==Uzytkownicy[licz].Num)
                    {
                        delete Uzytkownicy[licz];
                    }
                }
        }
    }
    while (menu != 'k');
    cout << "Zakonczono program" << endl;
    
    return 0;
}

