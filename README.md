# Software Testing Demo Projects Repository

This repository is a collection of small demo systems that can be used to practice software testing activities in line with the ISTQB test process. It is intended for learning, classroom exercises, assignments, walkthroughs, and hands-on test design using realistic but manageable application domains.

The projects cover a range of common business-style systems such as library management, inventory management, scheduling, banking, parking, grading, and tracking applications. Most projects include both implementation files and supporting analysis/design artifacts so the repository can be used for static testing as well as dynamic testing.

## Purpose

This repository supports the main ISTQB-aligned testing activities, including:

- Test planning
- Test analysis
- Test design
- Test implementation
- Test execution
- Test completion and reporting
- Static review of requirements, design, and code artifacts

It is especially useful for practicing:

- Deriving test conditions from SRS documents
- Reviewing class and sequence diagrams
- Writing test cases from functional requirements
- Identifying positive, negative, and edge test scenarios
- Preparing test plans and review reports
- Exploring traceability between requirements, design, code, and tests

## Repository Overview

The repository contains multiple independent demo projects:

| Project | Main Domain | Typical Artifacts Present |
| --- | --- | --- |
| `ATMSystem-ExampleProject` | ATM / banking | Source code, Visual Studio project, SRS/design files, test plan, test conditions, static review reports |
| `Appointment Scheduler` | Appointment booking | Source code, CMake, SRS, class diagram, sequence diagrams |
| `Command History Manager` | Command tracking | Source code, CMake, SRS, class diagram, sequence diagrams |
| `Contact Manager` | Contact management | Source code scaffold, SRS, class diagram, sequence diagrams |
| `Employee Management` | Employee records | Source code scaffold, SRS, class diagram, sequence diagrams |
| `Expense Tracker` | Personal finance tracking | Source code scaffold, SRS, class diagram, sequence diagrams |
| `Hospital Management System` | Hospital operations | Source code scaffold, SRS, class diagram, sequence diagrams |
| `Hotel Management System` | Hotel operations | Source code scaffold, SRS, class diagram, sequence diagrams |
| `Inventory Management System` | Inventory control | Source code scaffold, SRS, class diagram, sequence diagrams |
| `LibraryManagementSystem` | Library operations | Source code, CMake, SRS, class and sequence diagrams |
| `Parking Lot System` | Parking operations | Source code scaffold, SRS, class diagram, sequence diagrams |
| `Quiz System` | Quiz management | Source code scaffold, SRS, class diagram, sequence diagrams |
| `Student Grade Manager` | Grade management | Source code scaffold, SRS, class diagram, sequence diagrams |
| `TodoList` | Task management | Source code scaffold, SRS, class diagram, sequence diagrams |

## Common Structure

Most project folders follow a structure similar to:

```text
ProjectName/
|-- src/      # C++ source files and supporting headers
|-- docs/     # SRS, diagrams, review/testing artifacts
`-- CMakeLists.txt or IDE project files
```

Common artifact types in this repository include:

- `docs/srs.md` or `docs/SRS.docx`: software requirements specification
- `*.mmd`: Mermaid class or sequence diagrams
- `*.drawio` / `*.png`: exported design diagrams
- `CMakeLists.txt`: build configuration for selected projects
- `*.vcxproj` / `*.sln`: Visual Studio project files
- `*.json`: simple data storage for demo applications

## How This Maps to the ISTQB Test Process

### 1. Test Planning

Use each project to define:

- Scope of testing
- Test objectives
- Test items
- Risks and priorities
- Entry and exit criteria
- Deliverables such as test plans and reports

The ATM example already includes test planning-oriented artifacts under [`ATMSystem-ExampleProject/docs`](./ATMSystem-ExampleProject/docs).

### 2. Test Analysis

Review the SRS documents and identify:

- Test Conditions.
- Early on defects found through static testing methods.


Recommended source artifacts:

- `docs/srs.md`
- `docs/SRS.docx`

### 3. Test Design

Design test conditions and test cases using techniques such as:

- Equivalence partitioning
- Boundary value analysis
- Decision table testing
- State transition testing
- Use-case-based testing
- Error guessing

The included class and sequence diagrams can help derive structural and interaction-based scenarios.

### 4. Test Implementation

Prepare:

- Test cases
- Test data
- Test suites
- Traceability mappings
- Review checklists

Students or teams can implement these in spreadsheets, test management tools, or unit/integration test frameworks.

### 5. Test Execution

Build and run selected projects, then:

- Execute manual test cases
- Record actual results
- Compare expected vs. actual behavior
- Log defects
- Retest after fixes

### 6. Test Completion

Summarize:

- Coverage achieved
- Passed and failed tests
- Open defects
- Risks remaining
- Lessons learned

## Suggested Learning Workflow

For each project, a practical exercise flow is:

1. Read the SRS.
2. Review the class and sequence diagrams.
3. Identify test conditions.
4. Create a test plan.
5. Design test cases and test data.
6. Execute the application manually or through automated checks.
7. Log defects and produce a short test summary report.

## Building and Running Projects

Not every project currently has the same build setup, but several projects can be built directly with CMake, and the ATM example includes Visual Studio solution files.


### Visual Studio project

The ATM demo includes:

- `ATMSystem-ExampleProject/ATMSystem.sln`
- `ATMSystem-ExampleProject/ATMSystem.vcxproj`

Open the solution in Visual Studio and build/run it from there.

## Notes

- The projects are intentionally small and educational in nature.
- Some projects are more complete in implementation than others.
- Several folders are especially valuable for documentation-based testing even if their runtime implementation is minimal.
- Generated binaries, build outputs, and local data files may appear in some folders as part of prior development activity.

## Contribution Guidance

If you extend this repository, try to keep each project self-contained and include:

- A clear SRS
- Design diagrams
- Source code
- Sample data if needed
- Optional test artifacts such as test plans, test cases, review reports, or defect logs

## License

No license file is currently included in this repository. Add one if the repository is intended for broader distribution or reuse.
