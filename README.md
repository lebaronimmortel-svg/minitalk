*This project has been created as part of the 42 curriculum by alexfuen*

# Description

The minitalk project is about creating a communication program in the form of a client and a server.
The project must perform this task using only UNIX signals.
The server program is meant to receive the message sent by the client,
and the client program is here to send the message to the server using its processus ID.

# Instructions

To compile this program, open a terminal in the minitalk folder, then type make.
To execute the server, type ./server. To execute the client, type ./client followed by
the server's PID and the string you want to send to the server.
Example 1 : ./client 14587693 "hello world"
Example 2 : ./client 14587875 minitalk

# Resources

https://stackoverflow.com/questions/40049751/malloc-inside-linux-signal-handler-cause-deadlock

https://fr.wikipedia.org/wiki/Kill_(Unix)

https://www.geeksforgeeks.org/cpp/left-shift-right-shift-operators-c-cpp/

and of course the man

I also used ChatGPT as an improved Internet navigator to find some technical information such as :
- what are signals
- how does a signal handler work
- which are the different signals I can send to a process
- etc...
