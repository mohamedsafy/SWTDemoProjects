**System Requirements Specifications: Employee Management Console
System**

------------------------------------------------------------------------

**1. Introduction**

**1.1 Purpose**

This document specifies the functional and non-functional requirements
for a **C++ Console-based Employee Management System**. The system
provides a standalone interface for managing employee records (add,
update, delete, view) using a local file-based database.

------------------------------------------------------------------------

**1.2 System Scope**

The system is a simplified standalone utility focusing on **basic
employee record management**. It allows a single administrator (HR
Manager) to manage employee data through a console interface.

The system:

- Does not include authentication or multi-user roles

- Uses a local JSON file for persistence

- Focuses on simplicity, clarity, and maintainability

------------------------------------------------------------------------

**2. Functional Requirements**

**Actor: HR Manager**

------------------------------------------------------------------------

**2.1 System Initialization**

**FR-IN-01:** The system shall load all employee records from the local
JSON file at startup.

**FR-IN-02:** If the file does not exist, the system shall initialize an
empty employee list.

------------------------------------------------------------------------

**2.2 Main Menu**

**FR-MM-01:** Upon startup, the system shall present the following
options:

- Add Employee

- View Employees

- Search Employee

- Update Employee

- Delete Employee

- Exit

------------------------------------------------------------------------

**2.3 Add Employee**

**FR-AE-01:** The user shall enter employee details (name, role,
salary).

**FR-AE-02:** The system shall assign a unique ID to the employee.

**FR-AE-03:** The system shall store the employee and persist it to the
JSON file.

------------------------------------------------------------------------

**2.4 View Employees**

**FR-VE-01:** The system shall display all employee records.

**FR-VE-02:** Each employee shall include:

- ID

- Name

- Role

- Salary

------------------------------------------------------------------------

**2.5 Search Employee**

**FR-SE-01:** The user shall input an employee name or part of a name.

**FR-SE-02:** The system shall return all matching employees.

------------------------------------------------------------------------

**2.6 Update Employee**

**FR-UE-01:** The user shall select an employee by ID.

**FR-UE-02:** The user shall enter updated employee details.

**FR-UE-03:** The system shall modify the employee record and persist
changes.

------------------------------------------------------------------------

**2.7 Delete Employee**

**FR-DE-01:** The user shall select an employee by ID.

**FR-DE-02:** The system shall remove the employee from the list.

**FR-DE-03:** The system shall update the JSON file.

------------------------------------------------------------------------

**3. Non-Functional Requirements**

**3.1 Persistence & Reliability**

**NFR-REL-01:** All employee data must be stored in a local
employees.json file using *nlohmann/json*.

**NFR-REL-02:** The system must ensure consistency between in-memory
data and file data after each operation.

------------------------------------------------------------------------

**3.2 Usability**

**NFR-USA-01:** The system shall provide a simple and clear console
interface.

**NFR-USA-02:** The system shall validate all user inputs (e.g., invalid
IDs, empty fields, incorrect salary format).

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

<table style="width:97%;">
<colgroup>
<col style="width: 25%" />
<col style="width: 71%" />
</colgroup>
<thead>
<tr>
<th><strong>Module Name</strong></th>
<th><strong>Responsibility</strong></th>
</tr>
</thead>
<tbody>
<tr>
<td><strong>EmployeeConsole</strong></td>
<td>Handles UI loop, menu display, and user interaction</td>
</tr>
<tr>
<td><strong>EmployeeService</strong></td>
<td>Manages business logic (add, search, update, delete employees)</td>
</tr>
<tr>
<td><strong>EmployeeRepository</strong></td>
<td>Handles JSON file operations</td>
</tr>
<tr>
<td><strong>Employee</strong></td>
<td>Data model representing an employee</td>
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
"employees": \[\
{\
"id": 1,\
"name": "John Doe",\
"role": "Software Engineer",\
"salary": 10000\
}\
\]\
}

------------------------------------------------------------------------

**4.3 Technical Standards**

- **Language:** C++11 or later

- **Libraries:**

  - *nlohmann/json* for persistence

- **Data Structures:**

  - std::vector for storing employees

  - std::string for name and role

  - numeric type for salary (e.g., int or double)

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
