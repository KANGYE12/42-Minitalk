# 📨 Minitalk  

Minitalk is a project from 42 that consists of creating a small communication program using UNIX signals. The project is divided into two programs: **a server** and **a client**, which will communicate by sending and receiving messages using only `SIGUSR1` and `SIGUSR2` signals.

## 📜 Subject Summary  

- The **server** must wait for messages and display them when received.  
- The **client** must send a string to the server character by character, using signals.  
- Communication must be reliable, ensuring that all characters are transmitted correctly.  

## ⚙️ Features  

✅ Communication using **only UNIX signals** (`SIGUSR1` & `SIGUSR2`).  
✅ Handles **message encoding** into signals.  
✅ Supports sending **multi-line messages**.  
✅ **100% manual bitwise transmission**, no external libraries allowed.  

## 🛠️ Installation  

1. Clone the repository:  
   ```bash
   git clone https://github.com/KANGYE12/42-Minitalk.git minitalk
2. Enter in the directory
    ```bash
   cd minitalk
3. Do make and excute the commands
    ```bash
   make
   ./sever
    ./client "pid of the server" "message you want to send" 
   
