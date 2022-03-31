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


}

int compareCard(aCard c1, aCard c2) { //card 1(c1) and card 2(c2)

    if (c1.cardSuit == c2.cardSuit) { // checks if suits(enum) are equal
        if (c1.cardVal > c2.cardVal) { // if suits are equal, but the value of c1 is middleer than c1, func return -1. 
            return -1;
        }
        else if (c1.cardVal == c2.cardVal) { //checks if the value of c1 and c2 are equal, and if yes, returns 0.
            return 0;
        }
        else { // Only one case is left, which is if c2 value is bigger than c1
            return 1; // if yes, it return 1. 
        }
    }
    else { // If the suits are different, then the two cards can never be equal. 
        if (c1.cardSuit > c2.cardSuit) {//checks the value of suit in the enum, and if c1 suit is bigger it return -1. 
            return -1;
        }
        else { // Becuase they can't be equal, else means c2's suit's is bigger than c1's, if so, it returns 1. 
            return 1;
        }
    }
}

void swapCard(int n1, int n2, aCard pack[]) {

    aCard temp = pack[n1];

    temp = pack[n1];
    pack[n1] = pack[n2];
    pack[n2] = temp;
    
}

void bubbleSort(aCard pack[], int numOfCards) {

    int i, j, c = 0, s = 0;

    for (i = 0; i <= numOfCards - 2; i++)
    {
        for (j = numOfCards - 2; j >=i; j--) {
            c++;
            if (compareCard(pack[j], pack[j+1]) == -1) {
                swapCard(j, j+1, pack);
             
                s++;
            }
        } 
    }
    cout << "comparissions: " << c << endl;
    cout << "Swaps: " << s << endl;
}

int qc = 0; 
int qs = 0;
int partition(aCard pack[], int low, int middle)
{
    int pivot = middle;
    int i = (low - 1); // Index of smaller element and indicates the right position of pivot found so far


    for (int j = low; j <= middle - 1; j++)
    {
        // If current element is smaller than the pivot
        qc++;
        if (compareCard(pack[j], pack[pivot]) == 1)
        {
            i++; // increment index of smaller element
            swapCard(i, j, pack);
            //printPack("swapped", pack, middle+1);
            qs++;
        }
    }
    swapCard(i+1, middle, pack);
    //printPack("swapped-outer", pack, middle + 1);
    qs++;
    return (i + 1);
    
}

/* The main function that implements QuickSort
arr[] --> Array to be sorted,
low --> Starting index,
middle --> Ending index */
void quickSort(aCard pack[], int low, int middle)
{
    if (low < middle)
    {
        /* pi is partitioning index, arr[p] is now
        at right place */
        int pi = partition(pack, low, middle);

        // Separately sort elements before
        // partition and after partition
        quickSort(pack, low, pi - 1);
        quickSort(pack, pi + 1, middle);
    }

}




const int maxCard = 20;

aCard thePack[maxCard];




// H < C < D < S


int main() {


    for (int ct = 0; ct < maxCard; ct++)
        thePack[ct] = getCard("12345678");

    printPack("unsorted", thePack, maxCard);

    quickSort(thePack, 0, maxCard/2);

    printPack("Bubble sorted", thePack, maxCard);
    
   

}

