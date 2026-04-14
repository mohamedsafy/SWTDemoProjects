**Requirements Specifications: Student Grade Manager Console System**

**1\. Introduction**

**1.1 Purpose**

This document specifies the functional and non-functional requirements for a **C++ Console-based Student Grade Manager System**. The system provides a standalone interface for managing student records and grades using a local file-based database.

**1.2 System Scope**

The system is a simplified standalone utility focusing on **instructor-side grade management**. It allows an instructor to manage student records, assign grades, update grades, and view student performance through a console interface.

The system:

- Does not include authentication or multi-user roles
- Uses a local JSON file for persistence
- Focuses on simplicity, clarity, and maintainability

**2\. Functional Requirements**

**Actor: Instructor**

**2.1 System Initialization**

**FR-IN-01:** The system shall load all student records and grades from the local JSON file at startup.

**FR-IN-02:** If the file does not exist, the system shall initialize an empty student list.

**2.2 Main Menu**

**FR-MM-01:** Upon startup, the system shall present the following options:

- Add Student
- Assign Grade
- Update Grade
- View Student Grades
- Calculate Average Grade
- Exit

**2.3 Add Student**

**FR-AS-01:** The user shall enter student details (name).

**FR-AS-02:** The system shall assign a unique ID to the student.

**FR-AS-03:** The system shall create a student record with an initially empty or default grade.

**FR-AS-04:** The system shall store the student and persist it to the JSON file.

**2.4 Assign Grade**

**FR-AG-01:** The user shall select a student by ID.

**FR-AG-02:** The user shall enter a numeric grade.

**FR-AG-03:** The system shall validate that the grade is within the allowed range.

**FR-AG-04:** The system shall save the grade and persist changes to the JSON file.

**2.5 Update Grade**

**FR-UG-01:** The user shall select a student by ID.

**FR-UG-02:** The user shall enter a new numeric grade.

**FR-UG-03:** The system shall update the stored grade and persist changes.

**2.6 View Student Grades**

**FR-VG-01:** The system shall display all student records.

**FR-VG-02:** Each student record shall include:

- ID
- Name
- Grade

**2.7 Calculate Average Grade**

**FR-CA-01:** The system shall calculate the average of all assigned student grades.

**FR-CA-02:** The system shall display the calculated average to the user.

**3\. Non-Functional Requirements**

**3.1 Persistence & Reliability**

**NFR-REL-01:** All student data must be stored in a local grades.json file using *nlohmann/json*.

**NFR-REL-02:** The system must ensure consistency between in-memory data and file data after each operation.

**NFR-REL-03:** The system must ensure that invalid grades are not stored.

**3.2 Usability**

**NFR-USA-01:** The system shall provide a simple and clear console interface.

**NFR-USA-02:** The system shall validate all user inputs (invalid IDs, empty names, invalid grade values).

**3.3 Design Constraints**

**NFR-CON-01:** The codebase must be implemented in C++ and remain under approximately **500 lines of code**.

**NFR-CON-02:** The system shall be divided into a maximum of **5 logical modules**.

**NFR-CON-03:** The system shall be console-based only.

**3.4 Technical Constraints**

**NFR-TECH-01:** The system shall use C++11 or later.

**NFR-TECH-02:** The system shall use *nlohmann/json* for persistence.

**NFR-TECH-03:** The system shall avoid advanced C++ features such as:

- Complex templates
- Metaprogramming
- Advanced inheritance

**3.5 Testability**

**NFR-TST-01:** The business logic shall be independent of the console interface.

**NFR-TST-02:** The logic layer shall be unit-testable without file or UI dependencies.

**4\. System Specifications**

**4.1 Module Structure**

**Module Name**

**Responsibility**

**GradeConsole**

Handles UI loop, menu display, and user interaction

**GradeService**

Manages business logic (student records, grades, averages, validation)

**GradeRepository**

Handles JSON file operations

**Student**

Data model representing a student

**Utils (Optional)**

Validation and helper functions

**4.2 Data Model (JSON Schema)**

{
"students": \[
{
"id": 1,
"name": "John Doe",
"grade": 85
}
\]
}

**4.3 Technical Standards**

- **Language:** C++11 or later
- **Libraries:**
    -   *nlohmann/json* for persistence
- **Data Structures:**
    -   std::vector for storing students
    -   std::string for student names
    -   numeric type for grades (e.g., int or double)

**4.4 Development Constraints for Code Minimalism and Simplicity**

- Favor simple and direct implementations
- Avoid unnecessary abstractions
- Maintain strict separation between:
    -   Presentation layer
    -   Logic layer
    -   Data layer
- Keep total LOC within ~500 lines
- Avoid advanced features such as:
    -   Complex design patterns
    -   Heavy template usage
    -   Over-engineering

The resulting system should be:

- Easy to understand
- Easy to maintain
- Highly testable