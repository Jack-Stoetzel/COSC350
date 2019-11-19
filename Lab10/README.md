# Lab 10

## Task 1

Write two complete C programs "msgQsnd.c" and "msgQrcv.c" to communicate through the message queue.

### msgQsnd.c:

    * Create a message quese with rw-r--r--.
    To create a message queue, use existing file name "msgQsnd.c" for creating a key value.
    * Ask a message "two integer values" and send to the message queue.
    * Keep asking a message until EOF (Ctrl-D).
    * Remove the message queue with termination.

### msgQrcv.c

    * Receive a message (two integers) from the message queue created by msgQsnd.c.
    * Calculate sum of two integers and display result on standard output.
    * Keep reading a message until EOF.
