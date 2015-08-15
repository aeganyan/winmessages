/******************************************************************************
 * Copyright (c) 2015 Artur Eganyan
 *
 * This software is provided "AS IS", WITHOUT ANY WARRANTY, express or implied.
 ******************************************************************************/

#include <iostream>
#include "winmessages.h"

int main( int argc, char** argv )
{
    using namespace WinMessages;

    std::cout << MESSAGE_COUNT << std::endl;
    std::cout << getMessageName(7) << std::endl; // WM_SETFOCUS

    MessageRange range = getMessages(7);
    for (const Message* m = range.first; m < range.second; ++ m) {
        std::cout << m->name << std::endl; // WM_SETFOCUS and others
    }

    return 0;
}
