*This project has been created as part of the 42 curriculum by alexfuen.*

## Description
minitalk is a small inter-process communication (IPC) project designed to establish a reliable data transmission channel between two separate programs: a **client** and a **server**. Using exclusively UNIX signals (`SIGUSR1` and `SIGUSR2`), the client encodes text into raw binary data and transmits it bit by bit to the server, which reconstructs and prints the original message in real time.

The project is split into a mandatory part and a bonus part:

**Mandatory part** incorporates the following main features:
- A server program that outputs its process ID (`PID`) at startup and waits passively for incoming signals.
- A client program taking two arguments: the target server's `PID` and the string to send.
- Bitwise serialization: each byte (character) is decomposed into 8 bits and sent using `SIGUSR1` (representing `0`) and `SIGUSR2` (representing `1`).
- Robust signal handling on the server side using `sigaction` to avoid signal loss and preserve message integrity.
- Immediate standard output display of the reconstructed message as soon as the string is fully received.
- Fast and reliable message handling without memory leaks or race conditions.

**Bonus part** extends the mandatory version with:
- Bidirectional signal acknowledgment: the server sends an acknowledgment signal back to the client for every received bit (handshake protocol), guaranteeing transmission synchronization.
- End-of-transmission signal: the server acknowledges when the full string has been received and processed, allowing the client to safely exit with a confirmation message.
- Full Unicode / UTF-8 multi-byte support: correctly reconstructs and prints multi-byte characters (emojis, accents, non-Latin scripts) without buffering corruption.

Memory is properly managed throughout; no memory leaks occur during data transmission or on program termination.

## Instructions
To compile and run the project, the standard `Makefile` rules apply:
- Run `make` or `make all` to compile the mandatory executables `server` and `client`.
- Run `make bonus` to compile the bonus executables `server` and `client` with acknowledgment and Unicode support.
- Other available `Makefile` rules include `clean`, `fclean`, and `re`.

### Running the programs
1. Start the server first in a dedicated terminal:
```bash
./server
```
2. The server will print its process ID:
```bash
PID : 421337
```
3. In another terminal, run the client by passing the server's PID and the message:
```bash
./client 421337 "hello world"
```

## Resources
Resources for this project were:
 - https://man7.org/linux/man-pages/man2/sigaction.2.html — Linux man page for the sigaction system call
- https://man7.org/linux/man-pages/man2/kill.2.html — Linux man page for sending signals to processes with kill
- https://man7.org/linux/man-pages/man7/signal.7.html — Overview of standard POSIX signals and signal-safety
- https://en.wikipedia.org/wiki/Bitwise_operation — Fundamentals of bit manipulation and bitwise operators in C
