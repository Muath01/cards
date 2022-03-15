#include <iostream>
#include "cardlib.h"
#include <vector>
#include <algorithm>
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

// Start testing repo 13/03......................

string cardToString(aCard c) {

    string result;
    string cSuits = "HCDS";
    string cValues = "A23456789JQK";
    string suit = cSuits.substr(c.cardSuit, 1);
    string value = cValues.substr(c.cardVal - 1, 1);

    result = value + suit;

    return result;
}


// H < C < D < S



void printPack(string mess, aCard pack[], int numOfCard) {

    string result = mess + ": ";
    string card;

    for (int i = 0; i < numOfCard; i++)
    {
        card = cardToString(pack[i]);
        result += card;
        if (i < numOfCard - 1) result += ", ";
    }

    cout << result << endl;

   /* for (int i = numOfCard-1; i > 0; i--) {

        card = cardToString(pack[i]);
        result += card;
        if (i>1) result +=  ", ";
    }

    cout << result << endl;*/
}

int compareCard(aCard c1, aCard c2) { //card 1(c1) and card 2(c2)

    if (c1.cardSuit == c2.cardSuit) { // checks if suits(enum) are equal
        if (c1.cardVal > c2.cardVal) { // if suits are equal, but the value of c1 is higher than c1, func return -1. 
            return -1;
        }
        else if (c1.cardVal == c2.cardVal) { //checks if the value of c1 and c2 are equal, and if yes, returns 0.
            return 0;
        }
        else{ // Only one case is left, which is if c2 value is bigger than c1
            return 1; // if yes, it return 1. 
        }
    }
    else { // If the suits are different, then the two cards can never be equal. 
        if (c1.cardSuit > c1.cardSuit) {//checks the value of suit in the enum, and if c1 suit is bigger it return -1. 
            return -1; 
        }
        else { // Becuase they can't be equal, else means c2's suit's is bigger than c1's, if so, it returns 1. 
            return 1;
        }
    }
}

//void swapCard(int n1, int n2, aCard pack[]) {
//
//    int temp;
//    cardToString(pack[n1]) = temp;
//    cardToString(pack[0]) = cardToString(pack[1]);
//    cout << endl << "CARD: " << temp << endl;
//}



const int maxCard = 5;

aCard thePack[maxCard];


int main(){
    
    
    for (int ct = 0; ct < maxCard; ct++)
        thePack[ct] = getCard("28014385");

    printPack("deck", thePack, maxCard);

    //compareCard(thePack[0], thePack[1]);

    cardToString(thePack[0]) = cardToString(thePack[1]);
    cout << "CARD: " << cardToString(thePack[0]);

    

    
}

