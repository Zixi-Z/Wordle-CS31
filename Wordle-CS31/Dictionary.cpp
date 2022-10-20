//
//  Dictionary.cpp
//

#include "Dictionary.h"
#include "Settings.h"
#include "Random.h"
#include <iostream>

namespace cs31
{


Dictionary::Dictionary() : mRequiredLength(5)
{
    // to save on memory requirements, this Dictionary
    // uses the Singleton Design Pattern
    mSingleton = Singleton::GetInstance();
    
    // a Dictionary is made up of 26 DictionarySegments
    // each segment holds all the words starting with a particular
    // first letter
    mSingleton->forWhichValues(0, 'a');
    mSingleton->forWhichValues(1, 'b');
    mSingleton->forWhichValues(2, 'c');
    mSingleton->forWhichValues(3, 'd');
    mSingleton->forWhichValues(4, 'e');
    mSingleton->forWhichValues(5, 'f');
    mSingleton->forWhichValues(6, 'g');
    mSingleton->forWhichValues(7, 'h');
    mSingleton->forWhichValues(8, 'i');
    mSingleton->forWhichValues(9, 'j');
    mSingleton->forWhichValues(10, 'k');
    mSingleton->forWhichValues(11, 'l');
    mSingleton->forWhichValues(12, 'm');
    mSingleton->forWhichValues(13, 'n');
    mSingleton->forWhichValues(14, 'o');
    mSingleton->forWhichValues(15, 'p');
    mSingleton->forWhichValues(16, 'q');
    mSingleton->forWhichValues(17, 'r');
    mSingleton->forWhichValues(18, 's');
    mSingleton->forWhichValues(19, 't');
    mSingleton->forWhichValues(20, 'u');
    mSingleton->forWhichValues(21, 'v');
    mSingleton->forWhichValues(22, 'w');
    mSingleton->forWhichValues(23, 'x');
    mSingleton->forWhichValues(24, 'y');
    mSingleton->forWhichValues(25, 'z');
}

bool Dictionary::lookup( std::string s )
{
    // does one of the DictionarySegments hold the word s?
    bool result = false;
    if (s.length() == REQUIREDLENGTH)
    {
        // force everything to lower case
        for (std::size_t i = 0; i < s.length(); i++ )
            s[i] = tolower( s[i] );
        // find the DictionarySegment where this word would reside
        int index = s[0] - 'a';
        if (mSingleton->hasValues(index, s[0]))
        {
            result = mSingleton->lookup(index, s);
        }
    }
    return( result );
}

std::string Dictionary::randomWord()
{
    // pick a random word from the Dictionary
    using namespace cs31;
    string s;
    Random r;
    int value;
    // pick a random starting letter for the random word
    r.random();
    value = r.getValue();

    // pick a random spot from the DictionarySegment
    int spot = 0;
    r.random();
    spot += r.getValue();
    r.random();
    spot += r.getValue();
    r.random();
    spot += r.getValue();
    
    // select the word from segment value and position spot
    s = mSingleton->valueAt(value, spot);
    return( s );
}

}
