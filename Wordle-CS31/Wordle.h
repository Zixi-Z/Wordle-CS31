//
//  Wordle.h
//

#ifndef WORDLE_H
#define WORDLE_H

#include "Settings.h"
#include "Dictionary.h"
#include "Board.h"
#include "Score.h"
#include "Move.h"
#include "Enums.h"
#include <string>

namespace cs31
{

// The Wordle object plays the game
// It holds a Board, a winning Move, the current Score and a round count
// CS 31 students have TODO methods to complete documented below
class Wordle
{
public:
    // by default, select a random word
    Wordle();
    // specify the winning word as a Move
    Wordle( Move m ); // cheating
    // specify the winning word as a string
    Wordle( std::string s ); // cheating
            
    // stringify this Wordle object which occurs repetitively
    // as the game proceeds
    std::string display( std::string msg = "" ) const;
    
    // is the word entered part of the game Dictionary of valid
    // five letter words?
    bool  isValid( std::string turn );
    
    // convert the entered word into a Move object
    Move  play( std::string turn );
    
    // TODO update the Board with the passed Move parameter
    Score endRound( Move m );
    
    // TODO construct a GAMEOUTCOME based on the state of this Wordle game
    GAMEOUTCOME  determineGameOutcome( ) const;
    
    // stringify the current GAMEOUTCOME value
    std::string  gameOutcomeAsString( ) const;
    
    // is the game over?
    bool gameIsOver() const;
    
    // trivial getter
    Board  getBoard() const;
    
    // what is the winning word?
    std::string answer() const;
private:
    // the game's current round of play
    int    mRound;
    // this game's Board
    Board  mBoard;
    // this game's winning Move
    Move   mWinningMove;
    // this game's current Score
    Score  mCurrentScore;
};

}


#endif
