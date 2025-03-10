Project Philosophers - 42 School
The Philosophers project is a classic exercise in concurrent programming, part of 42 School's curriculum, designed to teach synchronization, thread/process management, and resource allocation. Inspired by Edsger Dijkstra's "Dining Philosophers Problem", it challenges students to solve a scenario where multiple philosophers (threads/processes) share limited resources (forks) while avoiding deadlocks, data races, and starvation.
Core Objective

Simulate philosophers sitting around a circular table, alternating between eating, thinking, and sleeping. Each philosopher needs two forks (mutexes) to eat, placed between adjacent philosophers. The goal is to ensure all philosophers survive as long as possible, with no philosopher starving due to improper resource allocation.
Key Requirements

    Input Parameters:
    The program accepts the following arguments:

        number_of_philosophers (e.g., 5 philosophers)

        time_to_die (ms a philosopher can survive without eating)

        time_to_eat (ms spent eating)

        time_to_sleep (ms spent sleeping)

        [number_of_meals] (optional: stops simulation after all philosophers eat this many times).

    Rules:

        Each philosopher must pick up two forks to eat.

        Forks are shared with neighbors; no two philosophers can hold the same fork simultaneously.

        Prevent deadlocks (e.g., all philosophers grabbing one fork and waiting indefinitely).

        Avoid starvation (philosophers must get fair access to forks).

        Log state changes (e.g., [timestamp] X has taken a fork, ...is eating, ...died).

Technical Implementation

    Threads & Mutexes:
    Each philosopher is a thread, and forks are represented by mutexes. Students use POSIX thread functions (pthread_create, pthread_detach, pthread_mutex_init, etc.) to manage concurrency.

    Synchronization:

        Timestamp precision with gettimeofday or clock_gettime.

        Delays between actions (e.g., a philosopher starts dying if they don’t eat within time_to_die).

        Careful mutex locking/unlocking to prevent data races on shared resources (forks and output logs).

    Deadlock Prevention:
    Solutions include:

        Allowing only N-1 philosophers to eat simultaneously.

        Asymmetric fork pickup (even-numbered philosophers pick left first, odd-numbered pick right).

Bonus Extensions

Optional enhancements demonstrate deeper understanding:

    Processes & Semaphores: Replace threads with processes (fork) and use semaphores (sem_open, sem_wait).

    Visualization: Display real-time status (e.g., terminal animations).

    Starvation-Free Guarantee: Ensure no philosopher waits indefinitely.

Learning Outcomes

    Concurrency: Managing threads/processes and shared resources.

    Synchronization: Using mutexes/semaphores to avoid race conditions.

    Algorithm Design: Balancing efficiency and fairness in resource allocation.

    Debugging: Identifying issues like deadlocks with tools like valgrind or tsan.

Philosophers is a foundational project for understanding parallel computing, emphasizing precision, efficiency, and problem-solving under strict constraints. It prepares students for advanced topics in operating systems and real-time systems.