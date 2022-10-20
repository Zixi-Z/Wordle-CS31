//
//  Dictionary.h
//

#ifndef Dictionary_H
#define Dictionary_H

#include <string>
#include "Singleton.h"

namespace cs31
{

// This Dictionary class provides Wordle the ability to
// search the available database of five letter words as
// well as pick a random word from the database.
// This class is completely finished.
// CS 31 students have no work to do here
class Dictionary
{
public:
    Dictionary();
    
    // is this word in the database?
    bool lookup( std::string s );
    // pick a random word from the database
    string randomWord();
private:
    int mRequiredLength;
    // to save memory requirements, this Dictionary
    // uses the Singleton Design Pattern
    Singleton * mSingleton;
};

}

#endif
