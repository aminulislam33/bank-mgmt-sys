# 🏦 Bank Management System in C

A simple terminal-based Bank Management System written in C. This project helps demonstrate the use of structures, file handling, string manipulation, and control structures in the C programming language.

---

## ✨ Features

- ✅ Create a new bank account
- 🔐 Login with account number and password
- 💰 Check account balance
- 💸 Transfer money to another account
- 💾 Save and load account data using binary file storage

---

## 📁 Files

- `main.c` — Contains the core implementation of the system.
- `accounts.dat` — Binary file used to store account information persistently.

---

## 🧠 Technologies Used

- C Language
- File I/O (binary file handling using `fread` / `fwrite`)
- Structs, arrays, strings
- Console I/O (terminal interface)

---

## 🛠️ How It Works

1. On program start, account data is loaded from `accounts.dat` (if exists).
2. Users can:
   - Create accounts (assigned a unique number)
   - Login using account number and password
   - Check balance and transfer money (post-login)
3. All account data is saved back to file after operations.

---

## 📌 Account Data

Each account includes:

- Account Number (auto-generated)
- Name
- Password
- Balance

Data is saved in binary format in `accounts.dat` to maintain persistence across sessions.

---

## 🚀 How to Compile & Run

Using GCC:

```bash
gcc main.c -o bank
./bank
