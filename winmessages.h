/******************************************************************************
 * Copyright (c) 2015 Artur Eganyan
 *
 * This software is provided "AS IS", WITHOUT ANY WARRANTY, express or implied.
 ******************************************************************************/

#ifndef WINMESSAGES_H
#define WINMESSAGES_H

#include <utility>

namespace WinMessages {

struct Message
{
    unsigned int id;
    const char* name;
};

typedef std::pair<const Message*, const Message*> MessageRange;

extern Message messages[];
extern const int MESSAGE_COUNT;

/**
 * Returns a range of messages with id as [first; second). If id is not
 * found, first == second. This function is not thread-safe.
 *
 * \note
 * On the first call it sorts messages. The first call can be placed in
 * main() if this possible delay is important.
 */
MessageRange getMessages( unsigned int id );

/**
 * Returns the name of the first found message with id. If it is not
 * found, returns "MESSAGE(id)". This function is not thread-safe.
 */
const char* getMessageName( unsigned int id );

} // namespace WinMessages

#endif
