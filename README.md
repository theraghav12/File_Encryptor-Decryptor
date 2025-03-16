# File_Encryptor-Decryptor

## **Overview**  
**File_Encryptor-Decryptor** is a C++ application designed for **secure file encryption and decryption** using a lightweight modular shift-based encryption method. It leverages **task queue processing**, **environment-based key retrieval**, and **process management** for efficient execution. The system ensures **data confidentiality** by encrypting file contents using a key stored in an environment file.

This project is useful for **basic file protection**, preventing unauthorized access to sensitive data in local storage. It also serves as a foundation for building more **advanced cryptographic applications**.

---

## **Features**  
✅ **File Encryption & Decryption**: Uses a shift cipher to modify file contents based on a key.  
✅ **Process Queue Management**: Handles multiple encryption/decryption tasks sequentially.  
✅ **File Handling System**: Reads and writes encrypted data securely without data corruption.  
✅ **Environment-Based Key Storage**: Retrieves encryption keys from an `.env` file.  

---

## **Project Structure**  
```
.vscode/                  # VS Code configurations
encryptDecrypt/           # Core encryption logic
  ├── Cryption.cpp        # Implements encryption and decryption logic
  ├── Cryption.hpp        # Header file for encryption functionality
  ├── CryptionMain.cpp    # Main executable for encryption operations
fileHandling/             # File handling utilities
  ├── IO.cpp              # Handles file input/output streams
  ├── IO.hpp              # Header file for IO operations
  ├── ReadEnv.cpp         # Reads environment variables from .env file
processes/                # Process and task management
  ├── ProcessManagement.cpp  # Manages encryption tasks in a queue
  ├── ProcessManagement.hpp  # Header file for process management
  ├── Task.hpp               # Defines encryption/decryption task structure
test/                     # Test files
  ├── test1.txt           # Sample test file for encryption
.env                      # Stores encryption key
.gitignore                # Ignore unnecessary files
Makefile                  # Compilation script for building the project
README.md                 # Documentation
main.cpp                  # Application entry point
```

---

## **How It Works**  

### **1. Key Retrieval from Environment File**  
- The application reads the encryption key from an **`.env`** file.
- This prevents hardcoding encryption keys inside the source code, adding an extra layer of security.

### **2. Task Creation and Queueing**  
- Users specify a file and action (`ENCRYPT` or `DECRYPT`).
- The **`Task`** class encapsulates file operations and encryption mode.
- Tasks are added to a **queue** inside the `ProcessManagement` system.

### **3. File Encryption & Decryption**  
- The **`Cryption`** module modifies file contents using a **modular arithmetic shift cipher**.
- The **shift value is derived from the encryption key** stored in `.env`.
- Encrypted files are modified **in-place**, making them unreadable without decryption.

### **4. Multi-Process Execution**  
- **Child processes are created** using `fork()`, and `execv()` runs the encryption program separately.
- This design ensures that encryption tasks do not block the main process.

---

## **Installation & Compilation**  

### **Prerequisites**  
🔹 **C++ Compiler** (GCC or Clang)  
🔹 **Make** (for build automation)  

### **Build the Project**  
```sh
make
```

### **Run the Application**  
```sh
./encrypty <file_path> <ENCRYPT|DECRYPT>
```
Example:  
```sh
./encrypty test/test1.txt ENCRYPT
./encrypty test/test1.txt DECRYPT
```

---

## **Code Implementation Breakdown**  

### **1. File Handling (`IO.cpp`)**  
- Opens files in **binary mode** (`std::ios::in | std::ios::out | std::ios::binary`).
- Provides a `getFileStream()` method to return file streams for reading and writing.

### **2. Reading Environment Variables (`ReadEnv.cpp`)**  
- Reads the `.env` file and retrieves the encryption key.
- The encryption key is **converted into an integer** for modular arithmetic.

### **3. Task Management (`Task.hpp`)**  
- Defines a **task structure** for handling encryption/decryption requests.
- Uses **string serialization** (`toString()`, `fromString()`) to facilitate process communication.

### **4. Process Management (`ProcessManagement.cpp`)**  
- Implements a **queue system** for handling multiple encryption tasks.
- Uses **`fork()` and `execv()`** to spawn child processes for each encryption job.

### **5. Encryption Logic (`Cryption.cpp`)**  
- **Reads characters from the file**, applies a **shift cipher**, and writes them back.
- Uses the formula:  
  - **Encryption:** `ch = (ch + key) % 256`  
  - **Decryption:** `ch = (ch - key + 256) % 256`  
- Works at the **byte level**, making it suitable for both **text and binary files**.

---

## **Security Considerations**  

⚠️ **Limitations of Shift Cipher**  
- The current encryption technique is **not secure for real-world applications**.  
- It is vulnerable to **frequency analysis attacks** and **brute-force decryption**.  

🛡️ **Future Improvements**  
- Upgrade to **AES-256 or RSA encryption** for stronger security.  
- Store encryption keys **securely using key vaults** instead of `.env` files.  

---

## **Future Enhancements**  

🚀 **Planned Features:**  
- 🔹 **Implement AES or RSA encryption** for stronger security.  
- 🔹 **Support multi-threading for parallel processing**.  
- 🔹 **Add logging & error handling** to track encryption failures.  
- 🔹 **Implement a CLI interface** for better user experience.  
- 🔹 **Create a GUI version** with file selection and encryption settings.  

---

## **Conclusion**  
Encrypty is a **lightweight encryption tool** that provides basic file protection using a simple shift cipher. While not suitable for high-security needs, it serves as an **educational project** for understanding file encryption, process management, and C++ system programming.

For future iterations, **stronger cryptographic algorithms** and **secure key storage** will be integrated to make Encrypty a **robust encryption tool**.

---

