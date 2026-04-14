**System Requirements Specifications: Appointment Scheduler Console
System**

------------------------------------------------------------------------

**1. Introduction**

**1.1 Purpose**

This document specifies the functional and non-functional requirements
for a **C++ Console-based Appointment Scheduler System**. The system
provides a standalone interface for users to manage appointments
(booking, viewing, rescheduling, and cancellation) using a local
file-based database.

------------------------------------------------------------------------

**1.2 System Scope**

The system is a simplified standalone utility focusing on **single-user
appointment management**. It allows users to organize appointments with
basic time validation.

The system:

- Does not include multi-user or authentication features

- Uses a local JSON file for persistence

- Focuses on simplicity, clarity, and testability

------------------------------------------------------------------------

**2. Functional Requirements**

**2.1 System Initialization**

**FR-IN-01:** The system shall load all appointments from the local JSON
file at startup.

**FR-IN-02:** If the file does not exist, the system shall initialize an
empty appointment list.

------------------------------------------------------------------------

**2.2 Main Menu**

**FR-MM-01:** Upon startup, the system shall present the following
options:

- Book Appointment

- View Appointments

- Reschedule Appointment

- Cancel Appointment

- Check Availability

- Exit

------------------------------------------------------------------------

**2.3 Book Appointment**

**FR-BA-01:** The user shall enter appointment details (title, date,
time).

**FR-BA-02:** The system shall validate that the selected time slot is
available.

**FR-BA-03:** The system shall create a new appointment with a unique
ID.

**FR-BA-04:** The system shall store the appointment and persist it to
the JSON file.

------------------------------------------------------------------------

**2.4 View Appointments**

**FR-VA-01:** The system shall display all scheduled appointments.

**FR-VA-02:** Each appointment shall include:

- ID

- Title

- Date

- Time

------------------------------------------------------------------------

**2.5 Reschedule Appointment**

**FR-RA-01:** The user shall select an appointment by ID.

**FR-RA-02:** The user shall enter a new date and time.

**FR-RA-03:** The system shall validate availability of the new slot.

**FR-RA-04:** The system shall update the appointment and persist
changes.

------------------------------------------------------------------------

**2.6 Cancel Appointment**

**FR-CA-01:** The user shall select an appointment by ID.

**FR-CA-02:** The system shall remove the appointment from the list.

**FR-CA-03:** The system shall update the JSON file.

------------------------------------------------------------------------

**2.7 Check Availability**

**FR-AV-01:** The user shall input a date and time.

**FR-AV-02:** The system shall check whether the slot is free.

**FR-AV-03:** The system shall display availability status.

------------------------------------------------------------------------

**3. Non-Functional Requirements**

**3.1 Persistence & Reliability**

**NFR-REL-01:** All appointment data must be stored in a local
appointments.json file using *nlohmann/json*.

**NFR-REL-02:** The system must ensure no two appointments share the
same date and time (no double booking).

------------------------------------------------------------------------

**3.2 Usability**

**NFR-USA-01:** The system shall provide a simple and clear console
interface.

**NFR-USA-02:** The system shall validate all user inputs (invalid IDs,
incorrect formats).

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

- Advanced inheritance structures

------------------------------------------------------------------------

**3.5 Testability**

**NFR-TST-01:** The business logic shall be independent of the console
interface.

**NFR-TST-02:** The logic layer shall be unit-testable without file
dependencies.

------------------------------------------------------------------------

**4. System Specifications**

**4.1 Module Structure**

<table style="width:94%;">
<colgroup>
<col style="width: 28%" />
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
<td><strong>SchedulerConsole</strong></td>
<td>Handles UI loop, menu display, and user interaction</td>
</tr>
<tr>
<td><strong>SchedulerService</strong></td>
<td>Manages business logic (booking, validation, rescheduling)</td>
</tr>
<tr>
<td><strong>AppointmentRepository</strong></td>
<td>Handles JSON file operations</td>
</tr>
<tr>
<td><strong>Appointment</strong></td>
<td>Data model representing an appointment</td>
</tr>
<tr>
<td><strong>Utils (Optional)</strong></td>
<td>Time validation and helper functions</td>
</tr>
</tbody>
</table>

------------------------------------------------------------------------

**4.2 Data Model (JSON Schema)**

{\
"appointments": \[\
{\
"id": 1,\
"title": "Doctor Visit",\
"date": "2026-04-10",\
"time": "14:00"\
}\
\]\
}

------------------------------------------------------------------------

**4.3 Technical Standards**

- **Language:** C++11 or later

- **Libraries:**

  - *nlohmann/json* for persistence

- **Data Structures:**

  - std::vector for storing appointments

  - std::string for date/time

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

  - Custom frameworks

  - Heavy template usage

  - Complex design patterns

The resulting system should be:

- Easy to understand

- Easy to extend

- Highly testable
