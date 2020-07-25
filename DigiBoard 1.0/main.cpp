#include <iostream>
#include <windows.h>
#include <cstdio>
#include <fstream>

using namespace std;
typedef struct
{
    char event_name[60];
    char date[60];
    char time[60];
    char host[60];
    char guest_star[60];
    char venue[60];
    char CP[100];
    int price;
    char desc[100];
}locked;

typedef locked event[100];

void intro(string& n);
void main_menu(int& x, string& n);
void sign_event(event& y, int& P);
void showcase(event& y, int& P, int& x);
void information(event& y, int& P);
void again(int& x);
void procedure();
void lists();

int main()
{
    int o,id;
    string user,note[20];
    bool menu;
    event data;
    FILE *database;
    ifstream read;
    menu = true;

    database = fopen("Event.dat", "rb");
    fread(&data, sizeof(data), 1, database);
    fclose(database);

    intro(user);
    while(menu)
    {
        main_menu(o,user);
        switch(o)

        {
        case 1:
            sign_event(data,id);
            showcase(data,id,o);
            if(o == 1){
                database = fopen("Event.dat", "wb");
                fwrite(&data, sizeof(data), 1, database);
                fclose(database);
            }else{
                cout << "Try to type it right ok" << endl;
                system("pause");
                system("cls");
                again(o);
                    if(o == 1)
                    {
                        menu = true;
                        }else{
                            cout << "========== Thank You ==========" << endl;
                            menu = !true;
                                        }
            }
        break;

        case 2:
            cout << "Enter a number to show an event" << endl;
             cout << ":";cin >> id;
             system("cls");
            information(data,id);
                        again(o);
            if(o == 1)
            {
                menu = true;
            }else{
                cout << "========== Thank You ==========" << endl;
                menu = !true;
            }
            break;

        case 3:
            cout << "Choose one of this note" << endl;
            cout << "1. Manual" << endl;
            cout << "2. List of event" << endl;
            cout << ":";cin >> o;
            system("cls");
            if(o == 1){
                procedure();
            }
            else if(o == 2){
                lists();
            }

            break;

        case 4:
            cout << "========== Thank You ==========" << endl;
            menu = !true;
            break;
        }
    }
    return 0;
}

void intro(string& n)
{
    cout << "===================================" << endl;
    cout << "              Welcome              " << endl;
    cout << "===================================" << endl;
    cout << endl;
    cout << "Please enter your name" << endl;
    cout << "Name:";getline(cin, n);
               system("cls");
}
void main_menu(int& x, string& n)
{
    cout << "===================================" << endl;
    cout << "            Digitsl Board          " << endl;
    cout << "===================================" << endl;
    cout << endl;
    cout << "Hello " <<  n << " How can we help you today?" << endl;
    cout << endl;
    cout << "1. Sign an Event" << endl;
    cout << "2. Search an Event" << endl;
    cout << "3. Note" << endl;
    cout << "4. Quit" << endl;
    cout << ":";
    cin >> x;
    system("cls");
}
void sign_event(event& y, int& P)
{
    cout << "===================================" << endl;
    cout << "          Sign an Event            " << endl;
    cout << "===================================" << endl;
    cout << endl;
    cout << "Enter your event number" << endl;
    printf("ID:");cin >> P;
    if(P < 11 || P > 100){
        cout << "Space unavailable" << endl;
        cout <<"Or Space is Occupied" << endl;
                system("pause");
                system("cls");
    }
    else{

                system("cls");
        cin.ignore();
    cout << "Enter the name of the event" << endl;
    printf("Name:");gets(y[P].event_name);
    cout << "Enter the date of the event" << endl;
    printf("Date:");gets(y[P].date);
    cout << "Enter the time of the event" << endl;
    printf("Time:");gets(y[P].time);
    cout << "Enter the MC/Host of the event" << endl;
    printf("Host:");gets(y[P].host);
    cout << "Enter the Guest star(if there's any)" << endl;
    printf("Guest Star:");gets(y[P].guest_star);
    cout << "Enter the place where the event take on" << endl;
    printf("Place:");gets(y[P].venue);
    cout << "Where can this ticket found" << endl;
    printf("CP:");gets(y[P].CP);
    cout << "Enter the price of the event" << endl;
    printf("Price:");cin >> y[P].price;
    cin.ignore();
    cout << "Add some description" << endl;
    printf("Description:");gets(y[P].desc);

                    system("pause");
                    system("cls");

    }
}
void showcase(event& y, int& P, int& x)
{
    cout << "===================================" << endl;
    cout << "             Your Event            " << endl;
    cout << "===================================" << endl;
    cout << endl << endl;
    cout << "Event Name : " << y[P].event_name << endl;
    cout << "Date       : " << y[P].date << endl;
    cout << "Time       : " << y[P].time << endl;
    cout << "Host       : " << y[P].host << endl;
    cout << "Guest Star : " << y[P].guest_star << endl;
    cout << "Place      : " << y[P].venue << endl;
    cout << "CP         : " << y[P].CP << endl;
    cout << "Price      : Rp " << y[P].price << endl;
    cout << "Description: " << y[P].desc << endl;
    cout << endl;
                        system("pause");
    cout << "       is this correct?        " << endl;
    cout << "1. Yes" << endl;
    cout << "2. No " << endl;
    cin >> x;
                    system("pause");
                    system("cls");
}
void information(event& y, int& P)
{
    cout << "===================================" << endl;
    cout << "             Information           " << endl;
    cout << "===================================" << endl;
    cout << endl;
    cout << "Event Name : " << y[P].event_name << endl;
    cout << "Date       : " << y[P].date << endl;
    cout << "Time       : " << y[P].time << endl;
    cout << "Host       : " << y[P].host << endl;
    cout << "Guest Star : " << y[P].guest_star << endl;
    cout << "Place      : " << y[P].venue << endl;
    cout << "CP         : " << y[P].CP << endl;
    cout << "Price      : Rp " << y[P].price << endl;
    cout << "Description: " << y[P].desc << endl;
    cout << endl;

                    system("pause");
                    system("cls");
}
void again(int& x)
{
    cout << "Wanna go back to main menu or quit " << endl;
    cout << "1. Back to main menu " << endl;
    cout << "2. Quit " << endl;
    cin >> x;
                    system("cls");
}
void procedure()
{
    ifstream read;
    int n;
    string note[30];

read.open("note.txt");
read >> n;
    for(int x = 1;x <= n;x++)
    {
        getline(read, note[x]);
    }
    for(int x = 1;x <= n;x++)
    {
        cout << note[x] << endl;
    }
    read.close();
    cout << endl;
                system("pause");
                system("cls");
}
void lists()
{
    ifstream read;
    int n;
    string listed[20];

read.open("list.txt");
read >> n;
    for(int x = 1;x <= n;x++)
    {
        getline(read, listed[x]);
    }
    for(int x = 1;x <= n;x++)
    {
        cout << listed[x] << endl;
    }
    read.close();
    cout << endl;
                system("pause");
                system("cls");
}
