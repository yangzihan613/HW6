#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* card structure definition */
struct card {
    const char* face; /* define pointer face */
    const char* suit; /* define pointer suit */
}; /* end structure card */

typedef struct card Card; /* new type name for struct card */

/* prototypes */
void fillDeck(Card* const wDeck, const char* wFace[], const char* wSuit[]);
void shuffle(Card* const wDeck);
void deal(const Card* const wDeck);

int main(void) {
    Card deck[52]; /* define array of Cards */
    const char* face[] = { "Ace", "Deuce", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Jack", "Queen", "King" };
    const char* suit[] = { "Hearts", "Diamonds", "Clubs", "Spades" };

    srand(time( NULL )); /* randomize */

    fillDeck(deck, face, suit);
    shuffle(deck);
    deal(deck);

    return 0; /* indicates successful termination */
}

/* initialize Cards */
void fillDeck(Card* const wDeck, const char* wFace[], const char* wSuit[]) {
    for (size_t i = 0; i < 52; ++i) {
        wDeck[i].face = wFace[i % 13];
        wDeck[i].suit = wSuit[i / 13];
    }
}

/* shuffle Cards */
void shuffle(Card* const wDeck) {
    int i, j;
    Card temp;
    for ( i = 0; i < 52; ++i) {
        j = rand() % 52;
        temp = wDeck[i];
        wDeck[i] = wDeck[j];
        wDeck[j] = temp;
    }
}

/* deal Cards */
void deal(const Card* const wDeck) {
    for (int i = 0; i < 52; ++i) {
        printf("%5s of %-8s%c", wDeck[i].face, wDeck[i].suit, 
            (i + 1) % 4  ? ' ' : '\n');
    }
}
