//
//  Singleton.cpp
//

#include "Singleton.h"
#include "Settings.h"

namespace cs31
{

// client code should not be allowed to access this contructor
Singleton::Singleton()
{
}

// when the singleton is destroy, deflate all the segments that
// have been inflated so far
Singleton::~Singleton()
{
    if(mSingleton!=nullptr)
    {
        for (int i=0; i < TOTALNUMBEROFSEGMENTS; i++)
        {
            mSegments[i].deflate();
        }
    }
}

// delete the singleton
void Singleton::destroySingleton()
{
    if(mSingleton!=nullptr)
    {
        delete( mSingleton );
        mSingleton = nullptr;
    }
}

// the one static singleton available for all clients to use
Singleton * Singleton::mSingleton = nullptr;

// allow client access to the one static singleton
Singleton * Singleton::GetInstance()
{
    // This is a safer way to create an instance since
    // instance = new Singleton
    // is dangerous in case two instance threads wants to
    // access at the same time
    if(mSingleton==nullptr)
    {
        mSingleton = new Singleton();
    }
    return mSingleton;
}

// delegates to the DictionarySegment involved
void Singleton::forWhichValues( int index, char c )
{
    mSegments[ index ].forWhichValues( c );
}

// delegates to the DictionarySegment involved
void Singleton::setRequiredLength( int index, int length )
{
    mSegments[ index ].setRequiredLength(length);
}

// delegates to the DictionarySegment involved
bool Singleton::hasValues( int index, char c )
{
    return( mSegments[ index ].hasValues( c ) );
}

// delegates to the DictionarySegment involved
bool Singleton::lookup( int index, std::string s )
{
    return( mSegments[ index ].lookup( s ) );
}

// delegates to the DictionarySegment involved
std::string Singleton::valueAt( int index, int spot )
{
    return( mSegments[ index ].valueAt( spot ) );
}

}
