#include <iostream>
#include <vector>

using namespace std;

struct datum
{

    int tag;
    int monat;
};


int main()
{
    int abholtermine_blau;
    int abholtermine_gelb;
    int abholtermine_rest;
    int abholtermine_gruen;
    int tag;
    int monat;

    vector<datum> dates_blaue_tonne;
    vector<datum> dates_gelbe_tonne;
    vector<datum> dates_gruenabfall;
    vector<datum> dates_restmuell;

    cout << "wie viele termine für die blaue Tonne\n";

    cin >> abholtermine_blau;

    for (int i = 0; i < abholtermine_blau; i++)
    {

        cout << "Zuerst Tag dann Monat eingeben" << endl;

        cout << "welcher Tag\n";

        cin >> tag;

        cout << "welcher Monat\n";

        cin >> monat;

        datum d = {tag, monat};

        dates_blaue_tonne.push_back(d);

        cout << dates_blaue_tonne[i].tag << "." << dates_blaue_tonne[i].monat << endl;
    }

    cout << "wie viele termine für die gelbe Tonne\n";

    cin >> abholtermine_gelb;

    for (int i = 0; i < abholtermine_gelb; i++)
    {

        cout << "Zuerst Tag dann Monat eingeben" << endl;

        cout << "welcher Tag\n";

        cin >> tag;

        cout << "welcher Monat\n";

        cin >> monat;

        datum d = {tag, monat};

        dates_gelbe_tonne.push_back(d);

        cout << dates_gelbe_tonne[i].tag << "." << dates_gelbe_tonne[i].monat << endl;
    }

    cout << "wie viele termine für Restmuell\n";

    cin >> abholtermine_rest;

    for (int i = 0; i < abholtermine_rest; i++)
    {

        cout << "Zuerst Tag dann Monat eingeben" << endl;

        cout << "welcher Tag\n";

        cin >> tag;

        cout << "welcher Monat\n";

        cin >> monat;

        datum d = {tag, monat};

        dates_restmuell.push_back(d);

        cout << dates_restmuell[i].tag << "." << dates_restmuell[i].monat << endl;
    }

    cout << "wie viele termine für Gruenabfall\n";

    cin >> abholtermine_gruen;

    for (int i = 0; i < abholtermine_gruen; i++)
    {

        cout << "Zuerst Tag dann Monat eingeben" << endl;

        cout << "welcher Tag\n";

        cin >> tag;

        cout << "welcher Monat\n";

        cin >> monat;

        datum d = {tag, monat};

        dates_gruenabfall.push_back(d);

        cout << dates_gruenabfall[i].tag << "." << dates_gruenabfall[i].monat << endl;
    }

    datum aktuelles_datum; // nur für den test. eig gibt die uhr das aktuelle datum vor
    aktuelles_datum.tag = 26;
    aktuelles_datum.monat = 3;

    // nachfolgender Teil muss in die loop

    for (int f = 0; f < abholtermine_blau; f++)
    {

        if (aktuelles_datum.tag == dates_blaue_tonne[f].tag && aktuelles_datum.monat == dates_blaue_tonne[f].monat)
        {

            cout << "blaue lampe an\n";
        }

        else
        {

            // led aus
        }
    }

    for (int f = 0; f < abholtermine_gelb; f++)
    {

        if (aktuelles_datum.tag == dates_gelbe_tonne[f].tag && aktuelles_datum.monat == dates_gelbe_tonne[f].monat)
        {

            cout << "gelbe lampe an\n";
        }

        else
        {

            // led aus
        }
    }

    for (int f = 0; f < abholtermine_gruen; f++)
    {

        if (aktuelles_datum.tag == dates_gruenabfall[f].tag && aktuelles_datum.monat == dates_gruenabfall[f].monat)
        {

            cout << "gruene lampe an\n";
        }

        else
        {

            // led aus
        }
    }

    for (int f = 0; f < abholtermine_rest; f++)
    {

        if (aktuelles_datum.tag == dates_restmuell[f].tag && aktuelles_datum.monat == dates_restmuell[f].monat)
        {

            cout << "rote lampe an\n";
        }

        else
        {

            // led aus
        }
    }

    return 0;
}