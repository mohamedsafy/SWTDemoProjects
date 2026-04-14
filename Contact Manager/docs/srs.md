**System Requirements Specifications: Contact Manager Console System**

------------------------------------------------------------------------

**1. Introduction**

**1.1 Purpose**

This document specifies the functional and non-functional requirements
for a **C++ Console-based Contact Manager System**. The system provides
a standalone interface for users to manage personal contacts (add,
search, update, delete) using a local file-based database.

------------------------------------------------------------------------

**1.2 System Scope**

The system is a simplified standalone utility focusing on **single-user
contact management**. It allows users to store and manage contact
information through a console interface.

The system:

- Does not include authentication or multi-user support

- Uses a local JSON file for persistence

- Focuses on simplicity, clarity, and maintainability

------------------------------------------------------------------------

**2. Functional Requirements**

**2.1 System Initialization**

**FR-IN-01:** The system shall load all contacts from the local JSON
file at startup.

**FR-IN-02:** If the file does not exist, the system shall initialize an
empty contact list.

------------------------------------------------------------------------

**2.2 Main Menu**

**FR-MM-01:** Upon startup, the system shall present the following
options:

- Add Contact

- View Contacts

- Search Contact

- Update Contact

- Delete Contact

- Exit

------------------------------------------------------------------------

**2.3 Add Contact**

**FR-AC-01:** The user shall enter contact details (name, phone number).

**FR-AC-02:** The system shall assign a unique ID to the contact.

**FR-AC-03:** The system shall store the contact and persist it to the
JSON file.

------------------------------------------------------------------------

**2.4 View Contacts**

**FR-VC-01:** The system shall display all stored contacts.

**FR-VC-02:** Each contact shall include:

- ID

- Name

- Phone number

------------------------------------------------------------------------

**2.5 Search Contact**

**FR-SC-01:** The user shall input a name or part of a name.

**FR-SC-02:** The system shall return all matching contacts.

------------------------------------------------------------------------

**2.6 Update Contact**

**FR-UC-01:** The user shall select a contact by ID.

**FR-UC-02:** The user shall enter updated contact information.

**FR-UC-03:** The system shall modify the contact and persist changes.

------------------------------------------------------------------------

**2.7 Delete Contact**

**FR-DC-01:** The user shall select a contact by ID.

**FR-DC-02:** The system shall remove the contact from the list.

**FR-DC-03:** The system shall update the JSON file.

------------------------------------------------------------------------

**3. Non-Functional Requirements**

**3.1 Persistence & Reliability**

**NFR-REL-01:** All contact data must be stored in a local contacts.json
file using *nlohmann/json*.

**NFR-REL-02:** The system must ensure consistency between in-memory
data and file data after each operation.

------------------------------------------------------------------------

**3.2 Usability**

**NFR-USA-01:** The system shall provide a simple and clear console
interface.

**NFR-USA-02:** The system shall validate all user inputs (e.g., invalid
IDs, empty fields).

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

<table style="width:82%;">
<colgroup>
<col style="width: 22%" />
<col style="width: 59%" />
</colgroup>
<thead>
<tr>
<th><strong>Module Name</strong></th>
<th><strong>Responsibility</strong></th>
</tr>
</thead>
<tbody>
<tr>
<td><strong>ContactConsole</strong></td>
<td>Handles UI loop, menu display, and user interaction</td>
</tr>
<tr>
<td><strong>ContactService</strong></td>
<td>Manages business logic (add, search, update, delete)</td>
</tr>
<tr>
<td><strong>ContactRepository</strong></td>
<td>Handles JSON file operations</td>
</tr>
<tr>
<td><strong>Contact</strong></td>
<td>Data model representing a contact</td>
</tr>
<tr>
<td><strong>Utils (Optional)</strong></td>
<td>Validation and search helpers</td>
</tr>
</tbody>
</table>

------------------------------------------------------------------------

**4.2 Data Model (JSON Schema)**

{\
"contacts": \[\
{\
"id": 1,\
"name": "John Doe",\
"phone": "0123456789"\
}\
\]\
}

------------------------------------------------------------------------

**4.3 Technical Standards**

- **Language:** C++11 or later

- **Libraries:**

  - *nlohmann/json* for persistence

- **Data Structures:**

  - std::vector for storing contacts

  - std::string for name and phone

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
