#include "sinus.h"

Sinus::Sinus()
{

}

float Sinus::getValue(){
    return Source::getSinusValue()*amplitude;
}
