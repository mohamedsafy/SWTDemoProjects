**System Requirements Specifications: Quiz System Console Application**

------------------------------------------------------------------------

**1. Introduction**

**1.1 Purpose**

This document specifies the functional and non-functional requirements
for a **C++ Console-based Quiz System**. The system provides a
standalone interface for users to attempt quizzes and view their results
using a local file-based database.

------------------------------------------------------------------------

**1.2 System Scope**

The system is a simplified standalone utility focusing on **single-user
quiz interaction**. It allows users to answer questions, submit quizzes,
and view scores.

The system:

- Does not include authentication or multi-user roles

- Uses a local JSON file for storing questions

- Focuses on simplicity, clarity, and maintainability

------------------------------------------------------------------------

**2. Functional Requirements**

**Actor: Player**

------------------------------------------------------------------------

**2.1 System Initialization**

**FR-IN-01:** The system shall load all quiz questions from the local
JSON file at startup.

**FR-IN-02:** If the file does not exist, the system shall initialize an
empty question set.

------------------------------------------------------------------------

**2.2 Main Menu**

**FR-MM-01:** Upon startup, the system shall present the following
options:

- Start Quiz

- View Last Score

- Exit

------------------------------------------------------------------------

**2.3 Start Quiz**

**FR-SQ-01:** The system shall present questions one by one.

**FR-SQ-02:** Each question shall include:

- Question text

- Multiple-choice options

**FR-SQ-03:** The user shall select an answer for each question.

**FR-SQ-04:** The system shall record user responses.

------------------------------------------------------------------------

**2.4 Submit Quiz**

**FR-SB-01:** After answering all questions, the system shall evaluate
responses.

**FR-SB-02:** The system shall calculate the final score.

**FR-SB-03:** The system shall display the score to the user.

**FR-SB-04:** The system may store the last score in memory or file.

------------------------------------------------------------------------

**2.5 View Score**

**FR-VS-01:** The system shall display the last recorded score.

------------------------------------------------------------------------

**2.6 Review Answers**

**FR-RA-01:** The system shall display correct answers alongside user
answers.

------------------------------------------------------------------------

**3. Non-Functional Requirements**

**3.1 Persistence & Reliability**

**NFR-REL-01:** All quiz questions must be stored in a local quiz.json
file using *nlohmann/json*.

**NFR-REL-02:** The system must ensure consistent loading of questions
before quiz start.

------------------------------------------------------------------------

**3.2 Usability**

**NFR-USA-01:** The system shall provide a simple and clear console
interface.

**NFR-USA-02:** The system shall validate user inputs (invalid choices,
empty answers).

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

<table style="width:78%;">
<colgroup>
<col style="width: 20%" />
<col style="width: 57%" />
</colgroup>
<thead>
<tr>
<th><strong>Module Name</strong></th>
<th><strong>Responsibility</strong></th>
</tr>
</thead>
<tbody>
<tr>
<td><strong>QuizConsole</strong></td>
<td>Handles UI loop, menu display, and user interaction</td>
</tr>
<tr>
<td><strong>QuizService</strong></td>
<td>Manages quiz logic (flow, scoring, validation)</td>
</tr>
<tr>
<td><strong>QuizRepository</strong></td>
<td>Handles JSON file operations for questions</td>
</tr>
<tr>
<td><strong>Question</strong></td>
<td>Data model representing a quiz question</td>
</tr>
<tr>
<td><strong>Result (Optional)</strong></td>
<td>Data model for storing score and answers</td>
</tr>
</tbody>
</table>

------------------------------------------------------------------------

**4.2 Data Model (JSON Schema)**

{\
"questions": \[\
{\
"id": 1,\
"text": "What is 2 + 2?",\
"options": \["1", "2", "3", "4"\],\
"correctIndex": 3\
}\
\]\
}

------------------------------------------------------------------------

**4.3 Technical Standards**

- **Language:** C++11 or later

- **Libraries:**

  - *nlohmann/json* for persistence

- **Data Structures:**

  - std::vector for storing questions

  - std::string for question text

  - integer for answer indices

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
