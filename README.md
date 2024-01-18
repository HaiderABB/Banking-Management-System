# Banking Management System in C++

## Overview

This Banking Management System is a console-based application developed in C++ utilizing Object-Oriented Programming (OOP) concepts. The project incorporates file handling to store and retrieve data, and it introduces three main classes: User, Company, and BankManager.

## Features

1. **User Class:**
   - Creation of user accounts.
   - Deposit and withdraw funds.
   - View account balance and transaction history.

2. **Company Class:**
   - Establishment of company profiles.
   - Deposit and withdraw company funds.
   - Monitor company account details.

3. **BankManager Class:**
   - Access to administrative functions.
   - Manage user and company accounts.
   - View overall financial status.

4. **File Handling:**
   - Data persistence using file handling techniques.
   - User and company account information stored in files for long-term usage.


## Class Structure

1. **User Class:**
   - Attributes: User ID, name, balance, transaction history.
   - Functions: CreateAccount, Deposit, Withdraw, DisplayBalance, DisplayTransactionHistory.

2. **Company Class:**
   - Attributes: Company ID, name, balance, transaction history.
   - Functions: CreateCompany, Deposit, Withdraw, DisplayBalance, DisplayTransactionHistory.

3. **BankManager Class:**
   - Functions: ManageUserAccounts, ManageCompanyAccounts, ViewFinancialStatus.

## File Structure

1. **user_data.txt:**
   - Stores user account information.

2. **company_data.txt:**
   - Stores company account information.

3. **manager_data.txt:**
   - Stores administrative data.
