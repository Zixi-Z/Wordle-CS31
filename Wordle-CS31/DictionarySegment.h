//
//  DictionarySegment.h
//

#ifndef DictionarySegment_h
#define DictionarySegment_h

#include <string>
#include <set>

namespace cs31
{

// This DictionarySegment class provides a chunk of the Dictionary
// database for a particular starting letter.
// This class is completely finished.
// CS 31 students have no work to do here
class DictionarySegment
{
public:
    DictionarySegment( int requiredLength = 5 );
    // which letter is this segment for?
    void forWhichValues( char c );
    // how long are each of the strings in this segment?
    void setRequiredLength( int i );
    
    // is the character c the one this segment is for?
    bool hasValues( char c );
    // does the string s reside in this segment?
    bool lookup( std::string s );
    // return  the string found in position spot
    std::string valueAt( int spot );

    // load all the words into this segment
    void inflate();
    // purge all the words in this segment
    void deflate();
private:
    // has this segment been inflated already?
    bool mInflated;
    // the starting letter of all the words in this segment
    char mValue;
    // the length of all the words in this sgement
    int  mRequiredLength;
    // the in-memory database in this segment
    std::set< std::string > mSegment;
};

}

#endif /* DictionarySegment_hpp */
