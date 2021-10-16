# 42_codam_minitalk


## Usage

Compile with `make all`.

Start the server by running `server/server`. Open a second terminal instance, then run the client using `client/client <pid> <message>` where `<pid>` is the PID mentioned by the server on startup and `<message>` is the message you'd like to send to the server.


## How it works

When sending a message, the message is decomposed into bits, where every character takes 1 byte (the size of a `char`). These bytes are sent to the server using `SIGUSR1` and `SIGUSR2`, each standing for a 0 and 1 respectively. Upon receiving eight 0 bits in a row (a NULL-terination character in ASCII), the server will display the message and get ready for the next one.

Since the client and server communicate in plain old bits, they both support unicode (as long as the terminal used does). This means one bonus is working in the regular version!

In case the message appears all screwed up, increase the value of `WAIT_TIME_MS` in *client/client.h*.


## Grade

[![115/100](https://badge42.herokuapp.com/api/project/fbes/minitalk)](https://github.com/JaeSeoKim/badge42)
