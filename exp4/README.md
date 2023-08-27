#I/O System Calls<br>

2.1 open<br>
2.1.1 Description<br>

- A call to it creates a new open file descriptor, and is used to open a file.<br>
- The open() function returns a new file descriptor. Unsuccessful attempt returns -1.<br>

  2.2 close<br>
  2.2.1 Description<br>

- It is used to close the corresponding file descriptor.<br>
- Successful operation returns O and error returns -1.<br>

  2.3 read<br>
  2.3.1 Description<br>

- Used to retrieve data from a file stored in a file system.<br>
- The value returned is the number of bytes read (or -1 for error) and the file position is moved forward by this number.<br>

  2.4 write<br>
  2.4.1 Description<br>

- It writes data from a buffer to a file/device.<br>
- The value returned is the number of bytes written (or -1 for error)successfully.<br>
