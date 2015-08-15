WinMessages
-----------

Here is a list of windows messages, and helper functions returning a 
message name by its identifier. The list is not complete, but it contains 
a lot of messages described in MSDN. Please note that it may contain not 
only messages but also notification codes.

The code was compiled with mingw 5.1.0. If you have compilation errors, 
you can try to comment out messages which cause problems (they can simply 
be not supported or exist in different header files).


Example
-------

```cpp
using namespace WinMessages;

// The name of the first found message with id = 7
std::cout << getMessageName(7) << std::endl;

// Names of all found messages with id = 7
MessageRange range = getMessages(7);
for (const Message* m = range.first; m < range.second; ++ m) {
	std::cout << m->name << std::endl;
}
```
