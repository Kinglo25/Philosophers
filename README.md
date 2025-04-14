# Philosopher

_Philosopher_ is a School 42 project that challenges you to solve the classic Dining Philosophers problem. The project focuses on handling concurrency, synchronization, and resource sharing using threads and synchronization primitives (e.g., mutexes, semaphores). Through this project, you will gain a deeper understanding of multi-threaded programming and the challenges of concurrent resource management.

---

## Table of Contents

- [Introduction](#introduction)
- [Project Description](#project-description)
- [Features](#features)
- [Prerequisites](#prerequisites)
- [Installation](#installation)
- [Configuration](#configuration)
- [Usage](#usage)
- [Troubleshooting](#troubleshooting)
- [Contributing](#contributing)
- [Author](#author)
- [License](#license)

---

## Introduction

The _Philosopher_ project involves simulating the Dining Philosophers problem, a classical synchronization problem used to teach the complexities of concurrent programming. The goal is to develop a solution where multiple philosopher threads share limited resources (forks) without causing deadlocks or starvation. This project highlights efficient use of system resources and safe handling of thread interactions.

---

## Project Description

In this project, you will implement a simulation featuring a number of philosopher threads that alternate between thinking, eating, and sleeping. Each philosopher must pick up two forks (one from their left and one from their right) to eat. The simulation should abide by the following principles:

- **Deadlock Avoidance:** Ensure that philosophers do not end up in a state where each one is waiting for a fork indefinitely.
- **Resource Management:** Efficiently manage access to shared resources using synchronization primitives.
- **Timing and State Management:** Keep track of the philosophers' states (thinking, eating, sleeping) and enforce timing constraints to simulate real-life behavior.
- **Graceful Termination:** Provide a mechanism to end the simulation cleanly after a set duration or upon meeting specific criteria.

The solution should modularize components such as thread creation, synchronization handling, and output formatting.

---

## Features

- **Concurrent Simulation:** Implements multithreading to simulate philosophers eating, sleeping, and thinking concurrently.
- **Synchronization:** Uses mutexes or semaphores to manage access to shared resources, ensuring no deadlocks occur.
- **Configurable Parameters:** Allows setting parameters such as the number of philosophers, time to die, time to eat, time to sleep, and the number of times each philosopher must eat.
- **Status Output:** Provides real-time logs or status messages to monitor the simulation's progress.
- **Clean Termination:** Ensures that all threads and resources are cleaned up properly when the simulation ends.

---

## Prerequisites

Before building and running _Philosopher_, ensure you have the following installed on your system:
- A C compiler (such as `gcc` or `clang`)
- [Make](https://www.gnu.org/software/make/) for build automation
- A Unix/Linux development environment (macOS or Linux is preferred)
- Basic knowledge of multithreading, synchronization, and system programming in C

---

## Installation

Follow these steps to clone, build, and run the project on your machine:

1. **Clone the Repository:**

   ```bash
   git clone https://github.com/Kinglo25/Philosopher.git
   cd Philosopher
   ```

2. **Build the Project:**

   Use the provided Makefile to clean and compile the project:

   ```bash
   make fclean
   make
   ```

3. **Verify the Build:**

   Run the compiled executable to ensure it starts correctly:

   ```bash
   ./philosopher [parameters]
   ```

   Replace `[parameters]` with the desired simulation parameters (e.g., number of philosophers, time values, etc.).

---

## Configuration

_Philosopher_ can be configured by passing command-line arguments to specify the simulation parameters. Common parameters include:

- **Number of Philosophers:** How many philosopher threads to create.
- **Time to Die:** Maximum time (in milliseconds) a philosopher can go without eating before dying.
- **Time to Eat:** Time (in milliseconds) a philosopher spends eating.
- **Time to Sleep:** Time (in milliseconds) a philosopher spends sleeping.
- **Meals Required:** (Optional) Number of times each philosopher must eat before the simulation ends.

For example:

```bash
./philosopher 5 800 200 200 7
```

This command sets up a simulation with 5 philosophers, where the time to die is 800ms, time to eat is 200ms, time to sleep is 200ms, and each philosopher must eat 7 times.

---

## Usage

Run the executable with the required parameters. During the simulation, the program outputs the state of each philosopher along with timestamps. The simulation runs until all philosophers have met the required conditions or until a philosopher dies.

- **Example Command:**

  ```bash
  ./philosopher 5 800 200 200
  ```

- **Interpreting Output:**

  The output logs will indicate when a philosopher starts eating, thinking, or sleeping, along with any status messages regarding forks and state changes.

---

## Troubleshooting

- **Compilation Errors:**  
  Verify that your development environment meets all prerequisites and that you have a compatible compiler installed.

- **Deadlocks or Starvation:**  
  If the simulation hangs or a philosopher never eats, check your implementation of mutexes or semaphores to ensure proper locking and unlocking.

- **Unexpected Behavior:**  
  Use debug prints or a debugger to trace thread execution and verify that timing parameters are correctly implemented.

For additional assistance, consult the project guidelines, discuss with peers, or reach out to your instructors at School 42.

---

## Contributing

Contributions are welcome to improve the _Philosopher_ project. To contribute:

1. Fork the repository.
2. Create a new branch for your modifications:
   ```bash
   git checkout -b feature/my-new-feature
   ```
3. Make your changes following School 42 coding standards.
4. Commit your changes with clear, descriptive messages.
5. Push your branch:
   ```bash
   git push origin feature/my-new-feature
   ```
6. Create a pull request for review.

Your contributions help enhance the project and benefit the entire learning community.

---

## Author

- **Kinglo25**  
  [GitHub: Kinglo25](https://github.com/Kinglo25)

Developed as part of the School 42 curriculum.

---

## License

Distributed under the MIT License. See the `LICENSE` file for details.
```

---
