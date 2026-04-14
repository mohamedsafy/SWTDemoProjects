**Requirements Specifications: Library Console System**

**1. Introduction**

**1.1 Purpose**

This document specifies the functional and non-functional requirements
for a C++ Console-based Library Management System. The system provides a
standalone interface for members to manage book borrowings and returns
using a local file-based database.

**1.2 System Scope**

The system is a simplified standalone utility focusing on member-side
interactions (Search, Borrow, Return, View History). It bypasses complex
librarian/admin roles. It uses a Member ID for login and relies on an
nlohmann/json file for persistent storage of the catalog and user
records.

------------------------------------------------------------------------

**2. Functional Requirements**

**2.1 User Authentication**

- **FR-AU-01:** The system shall prompt the user to enter a **Member
  ID** (unique numeric identifier) to access the system.

- **FR-AU-02:** The system shall validate the Member ID against the
  local database. If the ID is invalid, an error message is displayed.

- **FR-AU-03:** On successful login, the system loads the member's
  profile and active borrowings.

**2.2 Main Menu**

- **FR-MM-01:** Upon login, the system shall present the following
  options:

  - Search/View Catalog

  - Borrow a Book

  - Return a Book

  - View My Borrowing History

  - Exit

**2.3 Search & View Catalog**

- **FR-VC-01:** The system shall list all available books in the
  library, including Title, Author, ISBN, and current availability
  status.

- **FR-VC-02:** Users can search for a book by its Title or ISBN.

**2.4 Borrow Book**

- **FR-BB-01:** The user shall enter the ISBN of the book they wish to
  borrow.

- **FR-BB-02:** The system shall verify if the book is currently
  "Available."

- **FR-BB-03:** If available, the system updates the book status to
  "Borrowed," assigns it to the Member ID, creates a transaction log,
  and saves changes to the JSON file.

**2.5 Return Book**

- **FR-RB-01:** The system shall display a list of books currently held
  by the logged-in member.

- **FR-RB-02:** The user selects a book to return. The system updates
  the status to "Available" and records the return date in the
  transaction logs.

**2.6 Borrowing History**

- **FR-BH-01:** The system shall retrieve and display all past and
  present transaction logs associated with the Member ID.

------------------------------------------------------------------------

**3. Non-Functional Requirements**

**3.1 Persistence & Reliability**

- **NFR-REL-01:** All library data (books, members, logs) must be stored
  in a local library_db.json file.

- **NFR-REL-02:** The system must ensure that a book cannot be marked
  "Available" and "Borrowed" simultaneously (Atomic-style updates to the
  JSON).

**3.2 Security**

- **NFR-SEC-01:** Access is restricted to valid Member IDs.

- **NFR-SEC-02:** Data is local; no network security is required, but
  the JSON must maintain structural integrity during writes.

**3.3 Design Constraints**

- **NFR-CON-01:** The codebase must be implemented in C++ and stay under
  **500 lines**.

- **NFR-CON-02:** The project should be divided into 5-6 logical modules
  for high maintainability.

------------------------------------------------------------------------

**4. System Specifications**

**4.1 Module Structure**

<table style="width:100%;">
<colgroup>
<col style="width: 20%" />
<col style="width: 79%" />
</colgroup>
<thead>
<tr>
<th><strong>Module Name</strong></th>
<th><strong>Responsibility</strong></th>
</tr>
</thead>
<tbody>
<tr>
<td><strong>LibraryConsole</strong></td>
<td>Handles the UI loop, menu rendering, and user input/output.</td>
</tr>
<tr>
<td><strong>LibraryEngine</strong></td>
<td>Manages business logic (borrowing rules, search logic, session
state).</td>
</tr>
<tr>
<td><strong>LibraryDatabase</strong></td>
<td>Wrapper for nlohmann/json to handle CRUD operations on the local
file.</td>
</tr>
<tr>
<td><strong>Book</strong></td>
<td>Class representing a book (ISBN, Title, Author, Status).</td>
</tr>
<tr>
<td><strong>Member</strong></td>
<td>Class representing the user (ID, Name, List of active
Borrowings).</td>
</tr>
<tr>
<td><strong>Transaction</strong></td>
<td>Data model for logging borrow/return events.</td>
</tr>
</tbody>
</table>

**4.2 Data Model (JSON Schema)**

JSON

{

"books": \[

{

"isbn": "978-0131103627",

"title": "The C Programming Language",

"author": "Kernighan & Ritchie",

"isAvailable": true

}

\],

"members": \[

{

"memberId": 5001,

"name": "Alice Smith",

"history": \[

{ "isbn": "978-0131103627", "action": "borrow", "date": "2026-03-31" }

\]

}

\]

}

**4.3 Technical Standards**

- **Language:** C++17 or later.

- **Libraries:**

  - nlohmann/json for all data handling.

  - Chrono for date handling.

**4.4 Development Constraints for Code Minimalism
<span dir="rtl"></span>and Simplicity**

- Maximize code reuse.

- Favor simpler structures over complex, unnecessary ones.

- Use appropriate C++ standard features (C++11 or later is recommended).

- Ensure separation of layers (Presentation layer, logic layer, data
  layer)

- Limit the total source code lines (across all files) to approximately
  500 lines. This requires concise implementations and careful planning.

- Avoid using advanced C++ features such as:

  - Optional\<item\>

  - Auto variables

  - Custom namespaces.

  - Advanced for loops.\
    Stick to simple C++ features.

- The resulting codebase should promote testability.
