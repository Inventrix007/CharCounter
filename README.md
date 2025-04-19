# 🔠 charCounter

`charCounter` is a lightweight C utility designed for basic text analysis. It reads a text file character-by-character and provides statistics on characters and words, including unique word detection and word frequencies.

---

## 📦 Features

- ✅ Character counting
- ✅ Word tokenization based on space and newline
- ✅ Hash table-based word frequency tracking
- ✅ Unique word listing
- ✅ Console and file output support
- ✅ Lightweight and modular code

---

## 🚀 How It Works

The program uses `fgetc()` to read characters from a file and builds words dynamically. These words are inserted into a hash table for tracking frequency. Once the file is parsed, it prints:

- Each character (if enabled)
- Words as they are formed
- A list of all unique words (words occurring only once)

---

## 🔧 Usage

The program is controlled using flags:

- `-c` – Enables character counting
- `-w` – Enables word parsing and frequency tracking

You can configure the behavior based on which flags are set in the code.

---

## 🛠️ Example Output

![image](https://github.com/user-attachments/assets/13488a73-5cf2-4007-8273-02e1af8eec5e)

---

## 🧱 Build Instructions

Compile Instructions:
```bash
make all
make install
```

---

## ⚙️ Command-Line Arguments

The `charCounter` utility supports the following command-line flags:

| Flag          | Long Option    | Description                         |
|---------------|----------------|-------------------------------------|
| `-h`          | `--help`       | Show the help message               |
| `-v`          | `--version`    | Show the program version            |
| `-f <file>`   | `--file`       | Specify the input file to read from |
| `-o <output>` | `--output`     | Specify the output file to write to |
| `-c`          |                | Analyse the Characters              |
| `-w`          |                | Analyse the Words                   |

### 📌 Example Usage

```bash
charCounter -f input.txt -o output.txt
```


