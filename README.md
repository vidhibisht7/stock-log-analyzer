# 📊 Stock Log File Analyzer

This is a C++ project that reads, filters, analyzes, and visualizes historical stock data using a CSV file (`all_stocks_5yr.csv`). It also includes a simple frontend built using HTML, CSS, and JavaScript to showcase the analysis.

---

## ✨ Features

- Read large stock datasets from CSV  
- Analyze individual companies by stock name (like `AAPL`, `GOOGL`, etc.)  
- Calculate key statistics: average open/close price, min/max, and trends  
- Output results to `output.txt`  
- Frontend displays the output file contents in a clean layout  

---

## 📁 Project Structure
# 📊 Stock Log File Analyzer

This is a C++ project that reads, filters, analyzes, and visualizes historical stock data using a CSV file (`all_stocks_5yr.csv`). It also includes a simple frontend built using HTML, CSS, and JavaScript to showcase the analysis.

---

## ✨ Features

- Read large stock datasets from CSV  
- Analyze individual companies by stock name (like `AAPL`, `GOOGL`, etc.)  
- Calculate key statistics: average open/close price, min/max, and trends  
- Output results to `output.txt`  
- Frontend displays the output file contents in a clean layout  

---

## 📁 Project Structure
# 📊 Stock Log File Analyzer

This is a C++ project that reads, filters, analyzes, and visualizes historical stock data using a CSV file (`all_stocks_5yr.csv`). It also includes a simple frontend built using HTML, CSS, and JavaScript to showcase the analysis.

---

## ✨ Features

- Read large stock datasets from CSV  
- Analyze individual companies by stock name (like `AAPL`, `GOOGL`, etc.)  
- Calculate key statistics: average open/close price, min/max, and trends  
- Output results to `output.txt`  
- Frontend displays the output file contents in a clean layout  


## Project Structure
stockProject/
├── all_stocks_5yr.csv # Not included in GitHub due to size limit
├── test.cpp # C++ code for analyzing stock data
├── input.txt # Stores company name input
├── output.txt # Output generated by C++ program
├── index.html # Frontend HTML
├── style.css # Frontend styling
├── script.js # JavaScript to load results into frontend
└── README.md # Project description


> `all_stocks_5yr.csv` is over 25MB and cannot be uploaded to GitHub.  
>  [Download it from Kaggle here](https://www.kaggle.com/datasets/borismarjanovic/price-volume-data-for-all-us-stocks-etfs)

---

##  How to Run

###  Backend (C++)
1. Place `all_stocks_5yr.csv` in the project folder.
2. Compile the code:
   ```bash
   g++ test.cpp -o test
3. Run the program
.\test < input.txt > output.txt
