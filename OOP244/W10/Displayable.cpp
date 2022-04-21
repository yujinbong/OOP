/*------------------------------------------------------
Workshop 10 part 1
 name: Yujin Bong
SECTION : NCC
PROFESSOR : Arezoo.tony
Module: Displayable
Version 1.0
Author : Fardad Soleimanloo  22/04/01
Revision History
-----------------------------------------------------------
Date       Reason
----------------------------------------------------------- */
#include "Displayable.h"
using namespace  std;
namespace sdds{
    std::ostream& operator<<(std::ostream& os, const Displayable& D){
        return D.display(os);
    }
}
