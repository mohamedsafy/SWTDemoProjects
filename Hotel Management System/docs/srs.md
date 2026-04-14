**System Requirements Specifications: Hotel Management Console System**

------------------------------------------------------------------------

**1. Introduction**

**1.1 Purpose**

This document specifies the functional and non-functional requirements
for a **C++ Console-based Hotel Management System**. The system provides
a standalone interface for managing room bookings, guest check-ins, and
check-outs using a local file-based database.

------------------------------------------------------------------------

**1.2 System Scope**

The system is a simplified standalone utility focusing on
**receptionist-side hotel operations** such as room booking and guest
management.

The system:

- Does not include authentication or multiple user roles

- Uses a local JSON file for persistence

- Focuses on simplicity, clarity, and maintainability

------------------------------------------------------------------------

**2. Functional Requirements**

**Actor: Receptionist**

------------------------------------------------------------------------

**2.1 System Initialization**

**FR-IN-01:** The system shall load all rooms and reservations from the
local JSON file at startup.

**FR-IN-02:** If the file does not exist, the system shall initialize
empty room and reservation lists.

------------------------------------------------------------------------

**2.2 Main Menu**

**FR-MM-01:** Upon startup, the system shall present the following
options:

- Book Room

- Check-in Guest

- Check-out Guest

- Cancel Reservation

- View Room Availability

- Exit

------------------------------------------------------------------------

**2.3 Book Room**

**FR-BR-01:** The user shall enter booking details (guest name, room
number, date).

**FR-BR-02:** The system shall verify that the selected room is
available.

**FR-BR-03:** The system shall create a reservation with a unique ID.

**FR-BR-04:** The system shall store the reservation and persist it to
the JSON file.

------------------------------------------------------------------------

**2.4 Check-in Guest**

**FR-CI-01:** The user shall select a reservation by ID.

**FR-CI-02:** The system shall mark the room as occupied.

**FR-CI-03:** The system shall update the reservation status and persist
changes.

------------------------------------------------------------------------

**2.5 Check-out Guest**

**FR-CO-01:** The user shall select a reservation by ID.

**FR-CO-02:** The system shall mark the room as available.

**FR-CO-03:** The system shall finalize the reservation and persist
changes.

------------------------------------------------------------------------

**2.6 Cancel Reservation**

**FR-CR-01:** The user shall select a reservation by ID.

**FR-CR-02:** The system shall remove or mark the reservation as
canceled.

**FR-CR-03:** The system shall update the JSON file.

------------------------------------------------------------------------

**2.7 View Room Availability**

**FR-VA-01:** The system shall display all rooms and their availability
status.

**FR-VA-02:** Each room shall include:

- Room number

- Availability status

------------------------------------------------------------------------

**3. Non-Functional Requirements**

**3.1 Persistence & Reliability**

**NFR-REL-01:** All hotel data must be stored in a local hotel.json file
using *nlohmann/json*.

**NFR-REL-02:** The system must ensure:

- A room cannot be both available and occupied at the same time

- No double booking for the same room

------------------------------------------------------------------------

**3.2 Usability**

**NFR-USA-01:** The system shall provide a simple and clear console
interface.

**NFR-USA-02:** The system shall validate all user inputs (invalid IDs,
unavailable rooms).

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

<table style="width:85%;">
<colgroup>
<col style="width: 19%" />
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
<td><strong>HotelConsole</strong></td>
<td>Handles UI loop, menu display, and user interaction</td>
</tr>
<tr>
<td><strong>HotelService</strong></td>
<td>Manages business logic (booking, check-in/out, validation)</td>
</tr>
<tr>
<td><strong>HotelRepository</strong></td>
<td>Handles JSON file operations</td>
</tr>
<tr>
<td><strong>Room</strong></td>
<td>Data model representing a room</td>
</tr>
<tr>
<td><strong>Reservation</strong></td>
<td>Data model representing a reservation</td>
</tr>
</tbody>
</table>

------------------------------------------------------------------------

**4.2 Data Model (JSON Schema)**

{\
"rooms": \[\
{\
"roomNumber": 101,\
"isAvailable": true\
}\
\],\
"reservations": \[\
{\
"id": 1,\
"guestName": "John Doe",\
"roomNumber": 101,\
"date": "2026-04-10",\
"status": "Booked"\
}\
\]\
}

------------------------------------------------------------------------

**4.3 Technical Standards**

- **Language:** C++11 or later

- **Libraries:**

  - *nlohmann/json* for persistence

- **Data Structures:**

  - std::vector for storing rooms and reservations

  - std::string for guest name and date

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
