//
//  Wordle.cpp
//

#include "Wordle.h"
#include <string>
#include <iostream>

namespace cs31
{

// by default, select a random word
Wordle::Wordle() : mRound( 0 )
{
    // pick a random word from the Dictionary
    Dictionary d;
    std::string answer = d.randomWord();
    // build a Move from the random word
    Move m;
    m.setPieces(answer);
    // save this Move as the winning Move
    mWinningMove = m;
}

// cheating approach
// save the passed Move parameter as the winning Move
Wordle::Wordle( Move m ) : mRound( 0 )
{
    mWinningMove = m;
}

// cheating approach
// save the passed string parameter as the winning Move
Wordle::Wordle( std::string s ) : mRound( 0  )
{
    Move m;
    m.setPieces(s);
    mWinningMove = m;
}

// stringify this game by printing this game's Board
std::string Wordle::display( std::string msg ) const
{
    return( mBoard.display() + msg );
}

// convert the entered word into a Move object
Move  Wordle::play(std::string turn)
{
    Move m;
    int i;
    for( i = 0; i < turn.length(); i++ )
    {
        char c = turn.at( i );
        Piece p( c );
        m.setPiece(i, c);
    }
    // if not enough letters are entered, pad with NOTVALID
    while( i < REQUIREDLENGTH)
    {
        m.setPiece( i, ' ' );
        i++;
    }
    return( m );
}

// TODO
// TODO update the Board with the passed Move parameter
//      create a Score object, add it to the Board, save it
//      as the current score value and then return it
//      increment the Round value
Score Wordle::endRound( Move m )
{
    // for now...
    Score s = Score(m, mWinningMove);
    mBoard.endRound(m, s);
    mCurrentScore = s;
    mRound++;
    return( s );
}

// TO DO select the right GAMEOUTCOME for this game
GAMEOUTCOME  Wordle::determineGameOutcome( ) const
{
    GAMEOUTCOME outcome = GAMENOTOVER;
    if (mRound <= 8 && mCurrentScore.isExactMatch() == true){
            outcome = GAMEWON;
        
    }
    else if (mRound == 8 && mCurrentScore.isExactMatch() == false){
        outcome = GAMELOST;
        }
    else if(mRound > 8 ){
        outcome = GAMELOST;
        }
    
    return( outcome );
}

// stringify the current GAMEOUTCOME value
std::string  Wordle::gameOutcomeAsString( ) const
{
    string result;
    GAMEOUTCOME outcome = determineGameOutcome();
    switch( outcome )
    {
        case GAMEWON:
            result = "You won the game!";
            break;
        case GAMELOST:
            result = "You lost the game!";
            break;
        case GAMENOTOVER:
            result = "The game is not over!";
            break;
    }
    return( result );
}

// is the game over?
bool Wordle::gameIsOver() const
{
    return( determineGameOutcome() != GAMENOTOVER );
}

// trivial getter
Board  Wordle::getBoard() const
{
    return( mBoard );
}

// is the word entered part of the game Dictionary of valid
// five letter words?
bool  Wordle::isValid( std::string turn )
{
    bool result = false;
    Dictionary d;
    if (d.lookup(turn))
    {
        result = true;
    }
    return( result );
}

// what is the winning word?
std::string Wordle::answer() const
{
    std::string s = mWinningMove.to_string();
    return( s );
}

}
