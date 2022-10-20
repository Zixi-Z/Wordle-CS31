//
//  Piece.cpp
//

#include "Piece.h"

namespace cs31
{

// by default, a Piece is invalid
Piece::Piece() : mLetter(NOTVALID)
{
}

// build a Piece based on the character parameter
Piece::Piece( char c )
{
    pickLetter( c );
}

// build a Piece based on the first letter of the string parameter
Piece::Piece( std::string s )
{
    // don't walk off the end of the string...
    if (s.length() > 0)
    {
        pickLetter( s.at( 0 ) );
    }
}

void  Piece::pickLetter( char c )
{
    switch( c )
    {
        case 'A':
        case 'a':
            mLetter = A;
            break;
        case 'B':
        case 'b':
            mLetter = B;
            break;
        case 'C':
        case 'c':
            mLetter = C;
            break;
        case 'D':
        case 'd':
            mLetter = D;
            break;
        case 'E':
        case 'e':
            mLetter = E;
            break;
        case 'F':
        case 'f':
            mLetter = F;
            break;
        case 'G':
        case 'g':
            mLetter = G;
            break;
        case 'H':
        case 'h':
            mLetter = H;
            break;
        case 'I':
        case 'i':
            mLetter = I;
            break;
        case 'J':
        case 'j':
            mLetter = J;
            break;
        case 'K':
        case 'k':
            mLetter = K;
            break;
        case 'L':
        case 'l':
            mLetter = L;
            break;
        case 'M':
        case 'm':
            mLetter = M;
            break;
        case 'N':
        case 'n':
            mLetter = N;
            break;
        case 'O':
        case 'o':
            mLetter = O;
            break;
        case 'P':
        case 'p':
            mLetter = P;
            break;
        case 'Q':
        case 'q':
            mLetter = Q;
            break;
        case 'R':
        case 'r':
            mLetter = R;
            break;
        case 'S':
        case 's':
            mLetter = S;
            break;
        case 'T':
        case 't':
            mLetter = T;
            break;
        case 'U':
        case 'u':
            mLetter = U;
            break;
        case 'V':
        case 'v':
            mLetter = V;
            break;
        case 'W':
        case 'w':
            mLetter = W;
            break;
        case 'X':
        case 'x':
            mLetter = X;
            break;
        case 'Y':
        case 'y':
            mLetter = Y;
            break;
        case 'Z':
        case 'z':
            mLetter = Z;
            break;

        default:
            mLetter = NOTVALID;
            break;
    }
}


LETTER Piece::getLetter() const
{
    return( mLetter );
}

std::string  Piece::getLetterAsString() const
{
    std::string s;
    switch( mLetter )
    {
        case A:
            s = "A";
            break;
        case B:
            s = "B";
            break;
        case C:
            s = "C";
            break;
        case D:
            s = "D";
            break;
        case E:
            s = "E";
            break;
        case F:
            s = "F";
            break;
        case G:
            s = "G";
            break;
        case H:
            s = "H";
            break;
        case I:
            s = "I";
            break;
        case J:
            s = "J";
            break;
        case K:
            s = "K";
            break;
        case L:
            s = "L";
            break;
        case M:
            s = "M";
            break;
        case N:
            s = "N";
            break;
        case O:
            s = "O";
            break;
        case P:
            s = "P";
            break;
        case Q:
            s = "Q";
            break;
        case R:
            s = "R";
            break;
        case S:
            s = "S";
            break;
        case T:
            s = "T";
            break;
        case U:
            s = "U";
            break;
        case V:
            s = "V";
            break;
        case W:
            s = "W";
            break;
        case X:
            s = "X";
            break;
        case Y:
            s = "Y";
            break;
        case Z:
            s = "Z";
            break;

        default:
            s = " ";
            break;
    }
    return( s );

}

}
