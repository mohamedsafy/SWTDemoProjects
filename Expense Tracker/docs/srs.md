**System Requirements Specifications: Expense Tracker Console System**

------------------------------------------------------------------------

**1. Introduction**

**1.1 Purpose**

This document specifies the functional and non-functional requirements
for a **C++ Console-based Expense Tracker System**. The system provides
a standalone interface for users to record, manage, and analyze personal
expenses using a local file-based database.

------------------------------------------------------------------------

**1.2 System Scope**

The system is a simplified standalone utility focusing on **single-user
expense management**. It allows users to track expenses, categorize
them, and view summaries.

The system:

- Does not include authentication or multi-user support

- Uses a local JSON file for persistence

- Focuses on simplicity, clarity, and maintainability

------------------------------------------------------------------------

**2. Functional Requirements**

**Actor: User**

------------------------------------------------------------------------

**2.1 System Initialization**

**FR-IN-01:** The system shall load all expenses from the local JSON
file at startup.

**FR-IN-02:** If the file does not exist, the system shall initialize an
empty expense list.

------------------------------------------------------------------------

**2.2 Main Menu**

**FR-MM-01:** Upon startup, the system shall present the following
options:

- Add Expense

- View Expenses

- Filter Expenses by Category

- Edit Expense

- Delete Expense

- Exit

------------------------------------------------------------------------

**2.3 Add Expense**

**FR-AE-01:** The user shall enter expense details (description, amount,
category).

**FR-AE-02:** The system shall assign a unique ID to the expense.

**FR-AE-03:** The system shall store the expense and persist it to the
JSON file.

------------------------------------------------------------------------

**2.4 View Expenses**

**FR-VE-01:** The system shall display all recorded expenses.

**FR-VE-02:** Each expense shall include:

- ID

- Description

- Amount

- Category

------------------------------------------------------------------------

**2.5 Filter Expenses by Category**

**FR-FE-01:** The user shall input a category.

**FR-FE-02:** The system shall display all expenses matching the
category.

------------------------------------------------------------------------

**2.6 Edit Expense**

**FR-EE-01:** The user shall select an expense by ID.

**FR-EE-02:** The user shall enter updated expense details.

**FR-EE-03:** The system shall update the expense and persist changes.

**2.7 Delete Expense**

**FR-DE-01:** The user shall select an expense by ID.

**FR-DE-02:** The system shall remove the expense from the list.

**FR-DE-03:** The system shall update the JSON file.

------------------------------------------------------------------------

**3. Non-Functional Requirements**

**3.1 Persistence & Reliability**

**NFR-REL-01:** All expense data must be stored in a local expenses.json
file using *nlohmann/json*.

**NFR-REL-02:** The system must ensure consistency between in-memory
data and file data after each operation.

------------------------------------------------------------------------

**3.2 Usability**

**NFR-USA-01:** The system shall provide a simple and clear console
interface.

**NFR-USA-02:** The system shall validate all user inputs (e.g., invalid
IDs, negative amounts, empty fields).

------------------------------------------------------------------------

**3.3 Design Constraints**

**NFR-CON-01:** The codebase must be implemented in C++ and remain under
approximately **500 lines of code**.

**NFR-CON-02:** The system shall be divided into a maximum of **5
logical modules**.

**NFR-CON-03:** The system shall be console-based only.

------------------------------------------------------------------------

**3.4 Technical Constraints**

**NFR-TECH-01:** The system shall use C++11 or later.

**NFR-TECH-02:** The system shall use *nlohmann/json* for persistence.

**NFR-TECH-03:** The system shall avoid advanced C++ features such as:

- Complex templates

- Metaprogramming

- Advanced inheritance

------------------------------------------------------------------------

**3.5 Testability**

**NFR-TST-01:** The business logic shall be independent of the console
interface.

**NFR-TST-02:** The logic layer shall be unit-testable without file or
UI dependencies.

------------------------------------------------------------------------

**4. System Specifications**

**4.1 Module Structure**

<table style="width:87%;">
<colgroup>
<col style="width: 23%" />
<col style="width: 64%" />
</colgroup>
<thead>
<tr>
<th><strong>Module Name</strong></th>
<th><strong>Responsibility</strong></th>
</tr>
</thead>
<tbody>
<tr>
<td><strong>ExpenseConsole</strong></td>
<td>Handles UI loop, menu display, and user interaction</td>
</tr>
<tr>
<td><strong>ExpenseService</strong></td>
<td>Manages business logic (add, filter, edit, delete expenses)</td>
</tr>
<tr>
<td><strong>ExpenseRepository</strong></td>
<td>Handles JSON file operations</td>
</tr>
<tr>
<td><strong>Expense</strong></td>
<td>Data model representing an expense</td>
</tr>
<tr>
<td><strong>Utils (Optional)</strong></td>
<td>Validation and helper functions</td>
</tr>
</tbody>
</table>

------------------------------------------------------------------------

**4.2 Data Model (JSON Schema)**

{\
"expenses": \[\
{\
"id": 1,\
"description": "Groceries",\
"amount": 150.5,\
"category": "Food"\
}\
\]\
}

------------------------------------------------------------------------

**4.3 Technical Standards**

- **Language:** C++11 or later

- **Libraries:**

  - *nlohmann/json* for persistence

- **Data Structures:**

  - std::vector for storing expenses

  - std::string for description and category

  - numeric type (double) for amount

------------------------------------------------------------------------

**4.4 Development Constraints for Code Minimalism and Simplicity**

- Favor simple and direct implementations

- Avoid unnecessary abstractions

- Maintain strict separation between:

  - Presentation layer

  - Logic layer

  - Data layer

- Keep total LOC within ~500 lines

- Avoid advanced features such as:

  - Complex design patterns

  - Heavy template usage

  - Over-engineering

The resulting system should be:

- Easy to understand

- Easy to maintain

- Highly testable
