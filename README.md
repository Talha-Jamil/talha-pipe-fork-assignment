# talha-pipe-fork-assignment
Creating a pipe between two processes that have been forked and measuring the average time for 1 million messages to make a roundtrip as well as request per time

The parent process sends **1 million integer messages** to the child process through a pipe, and the child echoes them back. The program then calculates:
- **Requests per second**
- **Round-trip delay**

---

## Requirements

- A Linux environment (tested on **Ubuntu WSL** on Windows)
- GCC compiler

---

## How to Run (on WSL/Linux)

1. Clone the repository:
   ```bash
   git clone <your-repo-link>
   cd <your-repo-folder>
   
2. Compile
   ```bash
    gcc -o pipe_test pipe_test.c

3. Run
   ```bash
   ./pipe_test

## Notes 
- The project was developed and tested on WSL and can run on pure linux environments directly
