#include <iostream>
#include "cardlib.h"
using namespace std;

aCard getCard(string stdno)
{  // function returns a card  - using student number stdno (8 numerical chars)
    aCard ans;
    string rcardstr = stdno.substr(rand() % 8, 1) + stdno.substr(rand() % 8, 1);    // two random characters from stdno
    int rcard = stoi(rcardstr) % 52;          // get integer in range 0..51
    string res = "  ";
    ans.cardVal = 1 + rcard % 13;                          // give cardVal 1..13 
    ans.cardSuit = static_cast<Suit>(rcard / 13);         // and for suit
    return ans;
}

// Start testing repo 13/03

string cardToString(aCard c) {

    string result;
    string cSuits = "HCDS";
    string cValues = "A23456789JQK";
    string suit = cSuits.substr(c.cardSuit, 1);
    string value = cValues.substr(c.cardVal - 1, 1);

    result = value + suit;

    return result;

}



const int maxCard = 3;

aCard thePack[maxCard];

void printPack(string mess, aCard pack[], int numOfCard) {


    string result = mess + ": ";
    string card;


    for (int i = 0; i < numOfCard; i++) {

        card = cardToString(pack[i]);
        result += card + ", ";
    }
    cout << result;

}


//int main()
{
    aCard one;
    one.cardSuit = spades;
    one.cardVal = 5;




    for (int ct = 0; ct < maxCard; ct++)
        thePack[ct] = getCard("28014355");

    printPack("deck", thePack, maxCard);
}

