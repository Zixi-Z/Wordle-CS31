//
//  Singleton.h
//

#ifndef SingletonH
#define SingletonH

#include "DictionarySegment.h"
#include "Settings.h"

#include <string>
using namespace std;

namespace cs31
{

 // This class implements the Singleton Design Pattern in C++
 // https://en.wikipedia.org/wiki/Singleton_pattern
 // The Singleton class defines the GetInstance method that serves as an
 // alternative to constructor and lets clients access the same instance
 // of this class over and over.
 // This class is completely finished.
 // CS 31 students have no work to do here
 class Singleton
 {
 public:

    // Singletons should not be cloneable.
    Singleton(Singleton &other) = delete;

    void operator=(const Singleton &) = delete;

    // This is the static method that controls the access to the singleton
    // instance. On the first run, it creates a singleton object and places it
    // into the static field. On subsequent runs, it returns the client
    // existing object stored in the static field.
    static Singleton * GetInstance();
    static void destroySingleton();
     
    // This singleton delegates to DictionarySegment
    void forWhichValues( int index, char c );
    void setRequiredLength( int index, int length );
    bool hasValues( int index, char c );
    bool lookup( int index, std::string s );
    std::string valueAt( int index, int spot );
    
    //  the destructor to delete whatever was newed
    ~Singleton();
    
    // The Singleton's constructor should always be private to prevent direct
    // construction calls with the `new` operator.
private:
    Singleton();

    static Singleton* mSingleton;

    DictionarySegment mSegments[ TOTALNUMBEROFSEGMENTS ];
};

}

#endif /* Singleton_hpp */
