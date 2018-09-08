/**
 * Project: Chess
 * Name: Chessman.cpp
 * Purpose: Chessman class implementation
 *
 * @author Bartosz Gorski "Alvirx"
 * @version 1.0 29.08.2018
*/
#include "Chessman.h"

Chessman::Chessman(bool white) : white(white)
{
}


bool Chessman::isWhite() const {
    return white;
}
