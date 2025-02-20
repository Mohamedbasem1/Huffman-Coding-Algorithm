# Huffman Coding Algorithm

## 📌 Introduction

This project implements **Huffman Coding**, a lossless data compression algorithm. Huffman Coding assigns variable-length codes to input characters, with shorter codes assigned to more frequent characters, optimizing data storage and transmission.

## 🚀 Features

- Compresses text using Huffman Encoding.
- Decompresses Huffman encoded text.
- Displays the Huffman Tree with character-to-code mapping.
- Simple and efficient implementation in C++.

## 🛠 How It Works

1. **Frequency Calculation**: Determines the frequency of each character in the input text.
2. **Building the Huffman Tree**: Constructs a binary tree based on character frequency.
3. **Generating Huffman Codes**: Assigns shorter binary codes to more frequent characters.
4. **Encoding the Input**: Replaces characters with their respective Huffman codes.
5. **Decoding the Compressed Data**: Recovers the original text using the Huffman tree.

## 🔧 Setup & Usage

### 🖥️ Compilation

To compile the program, use a C++ compiler (e.g., g++):

```sh
g++ huffman.cpp -o huffman
```

### ▶️ Running the Program

Run the compiled program:

```sh
./huffman
```

### 📜 Example Input & Output

#### **Input:**

```
Please Write a string to Compress
My name is Mohamed
```

#### **Huffman Tree Output:**

```
Character  ,    Code
   a             000
   M             001
   m             010
   e             011
   o             1000
   n             1001
   y             1010
   s             1011
   d             1100
   i             11010
   h             11011
                 111
```

#### **Compressed Message:**

```
5õ'§|ã┬
```

#### **Decompressed Message:**

```
My name is Mohamed
```

## 📌 Example Use Cases

- Text compression for reducing storage space.
- Efficient data transmission in networking.
- Implementing custom file compression utilities.

## 🏆 Why Use Huffman Coding?

✅ **Lossless Compression**: No loss of original data.  
✅ **Optimized Storage**: Reduces text size efficiently.  
✅ **Widely Used**: Used in ZIP, GZIP, JPEG, MP3, etc.

## 🤝 Contributing

Contributions are welcome! Feel free to **fork** this repository, submit **issues**, or create **pull requests**.

## 📞 Contact

For any inquiries, reach out via:  
📧 Email: Mohamed.basemm1@gmail.com

