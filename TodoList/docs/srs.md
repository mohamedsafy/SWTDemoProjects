**System Requirements Specifications: To-Do List Console System**
*(Version 1.5)*

------------------------------------------------------------------------

**1. Introduction**

**1.1 Purpose**

This document specifies the functional and non-functional requirements
for a **C++ Console-based To-Do List Management System**. The system
provides a standalone interface for users to manage personal tasks (add,
edit, complete, delete) using a local file-based database.

------------------------------------------------------------------------

**1.2 System Scope**

The system is a simplified standalone utility focusing on **single-user
task management**. It allows users to create and manage tasks through a
console interface.

The system:

- Does not include authentication or multi-user support

- Uses a local JSON file for persistence

- Focuses on simplicity and maintainability

------------------------------------------------------------------------

**2. Functional Requirements**

**2.1 System Initialization**

**FR-IN-01:** The system shall load all tasks from the local JSON file
at startup.

**FR-IN-02:** If the file does not exist, the system shall initialize an
empty task list.

------------------------------------------------------------------------

**2.2 Main Menu**

**FR-MM-01:** Upon startup, the system shall present the following
options:

- Add Task

- View Tasks

- Complete Task

- Edit Task

- Delete Task

- Exit

------------------------------------------------------------------------

**2.3 Add Task**

**FR-AT-01:** The user shall enter a task description.

**FR-AT-02:** The system shall create a new task with a unique ID.

**FR-AT-03:** The system shall set the task status to "Not Completed".

**FR-AT-04:** The system shall store the task in memory and persist it
to the JSON file.

------------------------------------------------------------------------

**2.4 View Tasks**

**FR-VT-01:** The system shall display all tasks.

**FR-VT-02:** Each task shall include:

- ID

- Description

- Completion status

------------------------------------------------------------------------

**2.5 Complete Task**

**FR-CT-01:** The user shall select a task by ID.

**FR-CT-02:** The system shall mark the task as "Completed".

**FR-CT-03:** The system shall update the JSON file accordingly.

------------------------------------------------------------------------

**2.6 Edit Task**

**FR-ET-01:** The user shall select a task by ID.

**FR-ET-02:** The user shall enter a new description.

**FR-ET-03:** The system shall update the task description.

**FR-ET-04:** The system shall persist changes to the JSON file.

------------------------------------------------------------------------

**2.7 Delete Task**

**FR-DT-01:** The user shall select a task by ID.

**FR-DT-02:** The system shall remove the task from the list.

**FR-DT-03:** The system shall update the JSON file.

------------------------------------------------------------------------

**3. Non-Functional Requirements**

**3.1 Persistence & Reliability**

**NFR-REL-01:** All task data must be stored in a local tasks.json file
using *nlohmann/json*.

**NFR-REL-02:** The system must ensure consistency between in-memory
data and file data after every operation.

------------------------------------------------------------------------

**3.2 Usability**

**NFR-USA-01:** The system shall provide a clear and simple console
interface.

**NFR-USA-02:** All user inputs must be validated (e.g., invalid IDs).

------------------------------------------------------------------------

**3.3 Design Constraints**

**NFR-CON-01:** The codebase must be implemented in C++ and remain under
approximately **500 lines of code**.

**NFR-CON-02:** The project shall be divided into a maximum of **5
logical modules**.

**NFR-CON-03:** The system shall be console-based only.

------------------------------------------------------------------------

**3.4 Technical Constraints**

**NFR-TECH-01:** The system shall use C++11 or later.

**NFR-TECH-02:** The system shall use *nlohmann/json* for file
persistence.

**NFR-TECH-03:** The system shall avoid advanced C++ features such as:

- Template-heavy designs

- Metaprogramming

- Complex inheritance

------------------------------------------------------------------------

**3.5 Testability**

**NFR-TST-01:** The business logic shall be independent of the user
interface.

**NFR-TST-02:** The logic layer shall be unit-testable without file or
console dependencies.

------------------------------------------------------------------------

**4. System Specifications**

**4.1 Module Structure**

<table style="width:84%;">
<colgroup>
<col style="width: 18%" />
<col style="width: 65%" />
</colgroup>
<thead>
<tr>
<th><strong>Module Name</strong></th>
<th><strong>Responsibility</strong></th>
</tr>
</thead>
<tbody>
<tr>
<td><strong>TodoConsole</strong></td>
<td>Handles UI loop, menu display, and user interaction</td>
</tr>
<tr>
<td><strong>TaskService</strong></td>
<td>Manages business logic (add, edit, delete, complete tasks)</td>
</tr>
<tr>
<td><strong>TaskRepository</strong></td>
<td>Handles JSON read/write operations</td>
</tr>
<tr>
<td><strong>Task</strong></td>
<td>Data model representing a task</td>
</tr>
<tr>
<td><strong>Utils (Optional)</strong></td>
<td>Input validation and helper functions</td>
</tr>
</tbody>
</table>

------------------------------------------------------------------------

**4.2 Data Model (JSON Schema)**

{\
"tasks": \[\
{\
"id": 1,\
"description": "Finish SRS document",\
"completed": false\
}\
\]\
}

------------------------------------------------------------------------

**4.3 Technical Standards**

- **Language:** C++11 or later

- **Libraries:**

  - *nlohmann/json* for persistence

- **Data Structures:**

  - std::vector for task storage

  - std::string for text handling

------------------------------------------------------------------------

**4.4 Development Constraints for Code Minimalism and Simplicity**

- Maximize code reuse

- Favor simple structures over complex ones

- Maintain clear separation of layers:

  - Presentation

  - Logic

  - Data

- Limit total LOC to ~500

- Avoid advanced features such as:

  - Custom namespaces

  - Complex templates

  - Over-engineered abstractions

The resulting system should remain:

- Readable

- Maintainable

- Easy to test
