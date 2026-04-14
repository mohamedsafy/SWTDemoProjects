**System Requirements Specifications: Inventory Management Console
System**

------------------------------------------------------------------------

**1. Introduction**

**1.1 Purpose**

This document specifies the functional and non-functional requirements
for a **C++ Console-based Inventory Management System**. The system
provides a standalone interface for managing products and stock levels
using a local file-based database.

------------------------------------------------------------------------

**1.2 System Scope**

The system is a simplified standalone utility focusing on **basic
inventory tracking**. It allows a store manager to manage products,
update stock, and monitor inventory levels.

The system:

- Does not include authentication or multi-user roles

- Uses a local JSON file for persistence

- Focuses on simplicity, clarity, and maintainability

------------------------------------------------------------------------

**2. Functional Requirements**

**Actor: Store Manager**

------------------------------------------------------------------------

**2.1 System Initialization**

**FR-IN-01:** The system shall load all product records from the local
JSON file at startup.

**FR-IN-02:** If the file does not exist, the system shall initialize an
empty inventory list.

------------------------------------------------------------------------

**2.2 Main Menu**

**FR-MM-01:** Upon startup, the system shall present the following
options:

- Add Product

- View Inventory

- Update Product Quantity

- Search Product

- Remove Product

- Exit

------------------------------------------------------------------------

**2.3 Add Product**

**FR-AP-01:** The user shall enter product details (name, quantity).

**FR-AP-02:** The system shall assign a unique ID to the product.

**FR-AP-03:** The system shall store the product and persist it to the
JSON file.

------------------------------------------------------------------------

**2.4 View Inventory**

**FR-VI-01:** The system shall display all products in the inventory.

**FR-VI-02:** Each product shall include:

- ID

- Name

- Quantity

------------------------------------------------------------------------

**2.5 Update Product Quantity**

**FR-UP-01:** The user shall select a product by ID.

**FR-UP-02:** The user shall enter the new quantity.

**FR-UP-03:** The system shall update the product quantity and persist
changes.

------------------------------------------------------------------------

**2.6 Search Product**

**FR-SP-01:** The user shall input a product name or part of a name.

**FR-SP-02:** The system shall return all matching products.

------------------------------------------------------------------------

**2.7 Remove Product**

**FR-RP-01:** The user shall select a product by ID.

**FR-RP-02:** The system shall remove the product from the inventory.

**FR-RP-03:** The system shall update the JSON file.

------------------------------------------------------------------------

**3. Non-Functional Requirements**

**3.1 Persistence & Reliability**

**NFR-REL-01:** All inventory data must be stored in a local
inventory.json file using *nlohmann/json*.

**NFR-REL-02:** The system must ensure that product quantities remain
valid (e.g., no negative values).

------------------------------------------------------------------------

**3.2 Usability**

**NFR-USA-01:** The system shall provide a simple and clear console
interface.

**NFR-USA-02:** The system shall validate all user inputs (invalid IDs,
negative quantities).

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

<table style="width:94%;">
<colgroup>
<col style="width: 24%" />
<col style="width: 69%" />
</colgroup>
<thead>
<tr>
<th><strong>Module Name</strong></th>
<th><strong>Responsibility</strong></th>
</tr>
</thead>
<tbody>
<tr>
<td><strong>InventoryConsole</strong></td>
<td>Handles UI loop, menu display, and user interaction</td>
</tr>
<tr>
<td><strong>InventoryService</strong></td>
<td>Manages business logic (add, update, search, delete products)</td>
</tr>
<tr>
<td><strong>InventoryRepository</strong></td>
<td>Handles JSON file operations</td>
</tr>
<tr>
<td><strong>Product</strong></td>
<td>Data model representing a product</td>
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
"products": \[\
{\
"id": 1,\
"name": "Laptop",\
"quantity": 10\
}\
\]\
}

------------------------------------------------------------------------

**4.3 Technical Standards**

- **Language:** C++11 or later

- **Libraries:**

  - *nlohmann/json* for persistence

- **Data Structures:**

  - std::vector for storing products

  - std::string for product name

  - integer type for quantity

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
