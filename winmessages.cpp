/******************************************************************************
 * Copyright (c) 2015 Artur Eganyan
 *
 * This software is provided "AS IS", WITHOUT ANY WARRANTY, express or implied.
 ******************************************************************************/

#include <algorithm>
#include <stdio.h>
#include <string.h>
#include "winmessages.h"

namespace WinMessages {

bool operator <( const Message& m1, const Message& m2 )
{
    if (m1.id < m2.id) return true;
    if (m1.id > m2.id) return false;
    if (m1.name && m2.name) {
        // Messages with "WM_" prefix are less than others
        bool wm1 = !strncmp(m1.name, "WM_", 3);
        bool wm2 = !strncmp(m2.name, "WM_", 3);
        if (wm1 != wm2) return wm1;
        return strcmp(m1.name, m2.name) < 0;
    }
    return false;
}

MessageRange getMessages( unsigned int id )
{
    static int firstCall = 1;
    if (firstCall) {
        firstCall = 0;
        std::sort(messages, messages + MESSAGE_COUNT);
    }
    Message lookup = {id, NULL};
    return std::equal_range(messages, messages + MESSAGE_COUNT, lookup);
}

const char* getMessageName( unsigned int id )
{
    MessageRange range = getMessages(id);
    if (range.first < range.second) {
        return range.first->name;
    } else {
        static char name[32];
        sprintf(name, "MESSAGE(%u)", id);
        return name;
    }
}

} // namespace WinMessages
