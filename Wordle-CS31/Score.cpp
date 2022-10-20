//
//  Score.cpp
//  Bunco
//
//  Created by Howard Stahl on 2/21/22.
//  Copyright © 2022 Howard Stahl. All rights reserved.
//

#include "Score.h"
#include <stdexcept>

namespace cs31
{

// setup a default score - all WRONG ANSWER's
Score::Score()
{
    for( int i = 0; i < REQUIREDLENGTH; i++ )
    {
        array[ i ] = WRONG;
    }
}

// TODO comparing the played move to the answer move,
//      build the ANSWER array of this Score
Score::Score( Move move, Move answer )
{
    // for now...
    for (int i = 0; i < REQUIREDLENGTH; i++) {
        LETTER moveletter = move.getPiece(i).getLetter();
        
        LETTER answerletter =  answer.getPiece(i).getLetter();
        array[i] = WRONG;
        if (moveletter == answerletter ) {
            array[i] = RIGHT;
            answer.setPiece(i, Piece());
        }
    }
    
    
    for (int i = 0; i < REQUIREDLENGTH; i++) {
        for (int j = 0; j < REQUIREDLENGTH; j++) {
            if (move.getPiece(i).getLetter() == answer.getPiece(j).getLetter()) {
                if ( array[i] != RIGHT ){
                    array[i] = MAYBE;
                    answer.setPiece(j, Piece());
                }
            }
        }
    }
    
    
}

// trivial getter but throw logic_error if the index is out of range
ANSWER Score::getAnswer( int i )
{
    if (i >= 0 && i < REQUIREDLENGTH)
        return( array[ i ] );
    else
        throw std::logic_error( "invalid i value" );
}

// stringify this Score
std::string Score::to_string() const
{
    std::string s = "";
    int mCount = 0;
    int rCount = 0;
    for (int i = 0; i < REQUIREDLENGTH; i++)
    {
        switch( array[i] )
        {
            case WRONG:
                // wrongs should not be printed at all
                s += "_";
                break;
            case RIGHT:
                rCount++;
                s += "R";
                break;
            case MAYBE:
                mCount++;
                s += "M";
                break;
        }
    }
    return( s );
}

// TODO is the ANSWER array all RIGHT ANSWER's?
bool Score::isExactMatch() const
{
    bool istrue = true;
    for( int i = 0; i < REQUIREDLENGTH; i++ )
    {
        if ( array[i] != RIGHT){
           istrue =  false ;
        }
    }
    return istrue;
}

}
