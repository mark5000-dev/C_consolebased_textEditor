# Mini File Editor (C)

A simple command-line text editor written in C that can **create**, **append**, and **read** text files.

## ✅ Features

- Create a new file and write multiple lines (end input with a single `.` on its own line).
- Append text to an existing file using the same `.` terminator.
- Read and display a file’s contents to `stdout`.
- Logs actions with timestamps.

## 🧩 Cross-Platform Notes

This project is designed to compile and run on both **Windows** and **Linux/macOS**.

### Windows (MSVC / MinGW / GCC)
- Windows does **not** provide the POSIX `getline()` function.
- To support Windows, the project includes a **custom `getline()` implementation** in `getline.c`.
- The custom `getline()` is only compiled/declared on Windows (`_WIN32`) via macros in `mainLib.h`.

### Linux / macOS (POSIX)
- Linux/macOS already provide `getline()` in `<stdio.h>`.
- On these platforms, the system `getline()` is used automatically; the custom version is not included.

---

## 🛠️ Build Instructions

### Windows (GCC / MinGW)

```powershell
cd "c:\study\tech\C_programmes\GfG\Text Editor"
gcc main.c newFile.c append.c read.c log.c getline.c -o editor.exe
.
\editor.exe
```

### Linux / macOS

```bash
cd "/path/to/Text Editor"
gcc main.c newFile.c append.c read.c log.c getline.c -o editor
./editor
```

> ✅ The same set of source files is compiled on both platforms.

---

## 📁 Project Structure

- `main.c` – Program entry point and menu.
- `newFile.c` – Creates a file and writes user input.
- `append.c` – Appends user input to an existing file.
- `read.c` – Reads and prints file contents.
- `log.c` – Simple timestamped action logger.
- `getline.c` – Windows-only `getline()` implementation.
- `mainLib.h` – Shared declarations and cross-platform macros.

---

## 🧠 How it works (high-level)

1. The program presents a menu of actions.
2. For create/append, it reads lines until a single dot (`.`) is entered.
3. For read, it prints the file contents line-by-line.
4. Each action is logged (timestamp + action) to `stdout`.

---

## ✅ How to extend

- Add a “delete file” option.
- Add support for editing existing files line-by-line.
- Store log entries in a separate file instead of `stdout`.

---

## 🧪 Notes / Gotchas

- The terminator line is **exactly** `.` (a period by itself), followed by Enter.
- Files are opened in text mode; line endings will follow the platform default.
- The size limit for the filename is defined by `BUF_SIZE` in `mainLib.h`.
