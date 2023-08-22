# ***``Philosophers``***
## ***introduction***
  This project is about learning the basics of threading a process, learning how to make threads and discover the mutex.

### What you should understand to succeed this project:
  * Once or more philosophers are sitting at a round table either eating, either thinking, either sleeping, While they are eating, they do not think or sleep; while thinking they don't eat or sleep; and, of course, while sleeping, they do not eat or think.
  
  * The philosophers sit at a circular table with a large bowl of spaghetti in the center.
  
  * There are some forks on the table. Serving and eating spaghetti with a simple fork is very inconvenient, so the philosophers will eat with two forks, one for each hand.
  
  * Each time a philosopher finishes eating, they will drop their forks and start sleeping. Once they have finished sleeping, they will start thinking. The simulation stops when a philosopher dies.
  
  * Every philosopher needs to eat and they should never starve.
  
  * Philosophers don't speak with each other.
  
  * Philosophers don't know when another philosopher is about to die.
  * No need to say the philosophers should avoid dying!

## ***General Instructions*** :
You have to write a program for the mandatory part will have this the basic rules:
 * Global variables are forbidden!
 * The program should take the following arguments: `number_of_philosophers` `time_to_die` `time_to_eat` `time_to_sleep` `[number_of_times_each_philosopher_must_eat]`
    * `number_of_philosophers` : is the number of philosophers and also the number of forks.
    * `time_to_die`: is in milliseconds, if a philosopher doesn't start eating `time_to_die` milliseconds after starting their last meal or the beginning of the simulation, it dies.
    * `time_to_eat`: is in milliseconds and is the time it takes for a philosopher to eat. During that time they will need to keep the two forks.
    * `number_of_times_each_philosopher_must_eat`: argument is optional, if all philosophers eat at least `number_of_times_each_philosopher_must_eat` the simulation will stop. If not specified, the simulation will stop only at the death of a philosopher.
    * Each philosopher should be given a number from 1 to `number_of_philosophers`.
    * Philosopher number `1` is next to philosopher number `number_of_philosophers` . Any other philosopher with the number `N` is seated between philosopher `N - 1` and philosopher `N + 1`.
1. **About the logs of your program**:
    * Any change of status of a philosopher must be written as follows (with X replaced with the philosopher number and timestamp_in_ms the current timestamp in milliseconds):
        ```c
            => timestamp_in_ms X has taken a fork
            => timestamp_in_ms X is eating
            => timestamp_in_ms X is sleeping
            => timestamp_in_ms X is thinking
            => timestamp_in_ms X died   
        ```
    * The status printed should not be scrambled or intertwined with another philosopher's status.
    * You can't have more than 10ms between the death of a philosopher and when it will print its death.
    * Again, philosophers should avoid dying!
 
***``Your program must not have any data races.``***

## ***Mandatory Part***
The specific rules for the mandatory part are:
 * Each philosopher should be a thread.
 * One fork between each philosopher, therefore if they are multiple philosophers, there will be a fork at the right and the left of each philosopher.
 * To avoid philosophers duplicating forks, you should protect the forks state with a mutex for each of them.

## ***``Thread``***

### What is a Thread?
1. A thread is a single sequence stream within a process.
2. threads have some of the properties of processes,sometimes called lightweight processes ``(LWPs)``.
3. Threads reduce overhead by sharing fundamental parts.

### Why Do We Need Thread?
 - Threads allow a program to perform multiple tasks or operations simultaneously, improving the overall efficiency, responsiveness, and resource utilization of a program or system.
 - Here are several reasons why threads are important:
    1. **Concurrency** : Threads enable concurrent execution of code. This means that multiple parts of a program can execute in parallel, which is particularly useful for tasks that can be performed independently.
    2. **Utilizing Multi-Core Processors** : Modern CPUs often have multiple cores that can execute instructions independently. Threads allow you to take advantage of these cores by running multiple threads in parallel, effectively utilizing the available processing power more efficiently.
    3. **Responsiveness**: Threads can help maintain program responsiveness by allowing certain tasks to run in the background without blocking the main execution thread.
    4. **Parallelism**: Threads enable parallelism, which is crucial for performance-intensive tasks such as scientific simulations, data processing, and graphics rendering. By dividing a complex task into smaller subtasks and running them concurrently, threads can significantly reduce the time required to complete the overall task.
    5. **Improved Throughput**: Threads can improve the throughput of a system by overlapping the execution of multiple tasks. This is especially useful in scenarios where tasks involve waiting for I/O operations (such as reading from or writing to files or network sockets). While one thread is waiting, others can continue executing.
    6. **Resource Sharing and Isolation**: Threads within the same process share the same memory space, making it easier to share data between them compared to separate processes. However, this also requires careful management to avoid issues like race conditions and data corruption.
    7. **Efficient Use of Resources**: Threads can be more lightweight than creating separate processes, as they share resources like memory and file handles. This can lead to lower overhead and more efficient resource utilization.

### What Are Threads In A Processor?
 - Threads are virtual components that divide the CPU’s physical core into multiple virtual cores.
 - All CPUs have threads which allow the CPU to perform the multiple tasks simultaneously.
 - Each CPU core can have up to 2 threads. If a CPU has 2 cores, then it has 4 threads, CPU with 4 cores will have 8 threads, and so on.

### How do CPU Threads work?
CPU threads can be implemented in different ways depending on the architecture of the processor. Let's explore how CPU threads work in both single-core and multi-core processors:
 1. **Single-Core Processor:**
    - In a single-core processor, the concept of "simultaneous multithreading" (SMT) is often used to implement multiple threads.
    - Here's a simplified overview of how SMT works in a single-core processor:
        - The processor maintains multiple sets of registers and resources for each thread. These include program counters, general-purpose registers, and execution units.
        - As instructions are fetched and executed, the processor switches between different threads at specific intervals.
        - The active thread's instructions are executed until a resource conflict or a predefined switching point is reached.
        - The processor then switches to another thread, allowing it to execute its instructions in a similar manner.
2. **Multi-Core Processor:**
    - Multi-core processors have multiple independent processing cores, each capable of executing its own instructions. Each core can handle one or more threads, depending on the architecture and design.
    - Here's how threads work in a multi-core processor:
        - Each core in a multi-core processor can handle its own set of threads independently. This means that multiple threads can be executed in parallel, each on a different core.
        - Threads can be scheduled on different cores based on factors like load balancing, thread priorities, and the available resources on each core.
        - Threads running on different cores can communicate with each other through shared memory or other inter-core communication mechanisms.
Overall, whether in a single-core processor with SMT or a multi-core processor, the goal of CPU threads is to improve the overall throughput, responsiveness, and resource utilization of a system by enabling concurrent execution of tasks.

### How Do Computer Processor and Threads Work Together?
 - Computer processors and threads work together to enable efficient and concurrent execution of tasks, allowing modern computers to handle complex workloads and improve performance.
 - Let's dive into how processors and threads collaborate to execute programs:
    1. **Processor Architecture:** Modern processors are designed with multiple cores, each capable of executing its own set of instructions independently. Each core contains execution units, cache memory, registers, and other resources needed to perform computations. The number of cores in a processor can range from a few cores to many cores, depending on the architecture.
    2. **Threads and Thread Management:** A thread is a sequence of instructions that can be executed independently. Multiple threads can run concurrently within a single process. Threads can be created and managed by the operating system or the programming environment.
    3. **Task Parallelism:** 3. When a program is executed, it can be divided into smaller tasks that can run concurrently. Each task can be associated with a thread. For example, in a web server, different threads can handle incoming client requests simultaneously, improving the server's responsiveness.
    4. **Thread Creation and Scheduling:** When a program is executed, the operating system or the programming environment can create threads to perform different tasks.
    5. **Context Switching:** Threads are managed using a technique called context switching. When a thread's turn to execute arrives, the processor saves the current state of the executing thread (registers, program counter, etc.) and loads the saved state of the next thread to be executed. This process is known as context switching and enables seamless switching between threads.
    6. **Inter-Thread Communication:** Threads within the same process can communicate and share data using shared memory or inter-thread communication mechanisms like locks, mutexes, semaphores, and condition variables. These mechanisms help threads synchronize their actions and avoid race conditions.
    7. **Multicore Collaboration:** In multi-core processors, each core can execute its own threads independently. Threads can run in parallel across multiple cores, enabling higher throughput and improved performance for multi-threaded applications.

### Types of Threads 
Threads are of two types. These are described below.
1. **User Level Threads** :
    - User Level Thread is a type of thread that is not created using system calls. 
    - The kernel has no work in the management of user-level threads.
    - User-level threads can be easily implemented by the user.
    - In case when user-level threads are single-handed processes, kernel-level thread manages them.
    * *``Advantages of User-Level Threads``*:
        - Implementation of the `User-Level` Thread is easier than `Kernel-Level` Thread.
        - Context Switch Time is less in User Level Thread.
        - `User-Level` Thread is more efficient than `Kernel-Level` Thread.
    * *``Disadvantages of User-Level Threads``*:
        - There is a lack of coordination between Thread and Kernel.
        - In case of a page fault, the whole process can be blocked.

2. **Kernel Level Threads**:
    - A kernel Level Thread is a type of thread that can recognize the Operating system easily.
    - Kernel Level Threads has its own thread table where it keeps track of the system. 
    - The operating System Kernel helps in managing threads.
    - Kernel threads have a longer context switching time in some way.
    - Kernel helps in the management of threads
    * *``Advantages of Kernel-Level Threads``*:
        - It has up-to-date information on all threads.
        - Whenever any process requires more time to process, `Kernel-Level` Thread provides more time to it.
    * *``Disadvantages of Kernel-Level threads``*:
        - Kernel-Level Thread is slower than User-Level Thread.
        - Implementation of this type of thread is a little more complex than a user-level thread.

### What are the differences between process and thread? 

* Threads are not independent from each other unlike processes.

* Threads operate faster than processes.

  + Thread creation is much faster.

  + Threads can be terminated easily.

  + Communication between threads is faster.

  + Context switching between threads is much faster.

    + Shared memory: Threads within a process share the same memory space, processes have separate memory spaces.

    + Reduced resource allocation.
### Multithreading in C :
1. In a multi-threaded program, multiple threads run within the same process and share the same memory space. This means that they can access the same variables, data structures, and resources without the need for explicit interprocess communication mechanisms.
2. This is in contrast to separate processes, which have their own separate memory spaces and require interprocess communication (IPC) mechanisms to exchange data.

### Advantages Of Thread :
  1. Responsiveness: If the process is divided into multiple threads, if one thread completes its execution, then its output can be immediately returned.
  2. Faster context switch: Context switch time between threads is lower compared to the process context switch. 
  3. Effective utilization of multiprocessor system: If we have multiple threads in a single process, then we can schedule multiple threads on multiple processors. This will make process execution faster. 
  4. Resource sharing: Resources like code, data, and files can be shared among all threads within a process.
  5. Communication: Communication between multiple threads is easier, as the threads share a common address space. while in the process we have to follow some specific communication techniques for communication between the two processes. 
  6. Enhanced throughput of the system: If a process is divided into multiple threads, and each thread function is considered as one job, then the number of jobs completed per unit of time is increased, thus increasing the throughput of the system. 



### Disadvantages :
  * User-space threads have a problem that a single thread can monopolize the timeslice thus starving the other threads within the task. 
### Components of Threads:
These are the basic components of the Operating System.
 * ***Stack Space*** :
 * ***Register Set*** :
 * ***Program Counter*** : 

## ***``Mutex``***

### What is a mutex?
1. A mutex is a synchronization mechanism used in computer programming to protect shared resources, such as data or code, from being accessed simultaneously by multiple threads or processes.
2. A mutex is a programming concept that is frequently used to solve multi-threading problems.
3. A mutex ensures that only one thread or process can access the protected resource at a time, preventing potential issues like race conditions and data corruption.
4. In a multi-threaded or multi-process environment, multiple threads or processes can execute concurrently. When multiple threads/processes try to access and modify shared resources simultaneously, problems can arise, such as:

    - **Race Conditions**: A race condition occurs when two or more threads can access shared data and they try to change it at the same time.
    - **Data Corruption**: If multiple threads/processes simultaneously write to the same memory location without proper synchronization, the data can become corrupted.
    - **Deadlocks**: Deadlocks can occur when two or more threads/processes are stuck in a state where they're each waiting for a resource held by another, causing the program to come to a halt.
*-* A mutex helps address these issues by providing a way for threads or processes to lock and unlock a shared resource before and after using it, ensuring that only one thread/process can access it at any given time.
*-* When one thread/process locks a mutex, any other thread/process that tries to lock the same mutex will be blocked until the mutex is released.

<!-- //////////////////////////////////-------------/////// -->
# Functions Using In This Project:

## ***``gettimeofday()``*** 
 * What Is And How To Use ``gettimeofday`` function in C language?
    * The `gettimeofday()` function is used to retrieve the current time of day and timezone information.

***Syntax***
```c
#include <sys/time.h>

int gettimeofday(struct timeval *tv, struct timezone *tz);
```

***Arguments***
* This function takes two arguments:
    - `tv` : A pointer to a `struct timeval` where the current time will be stored.
    - `tz` : A pointer to a `struct timezone` where timezone information will be stored. This parameter can be set to `NULL` if you're not interested in the timezone information.
    The struct timeval looks like this:
    ```c
    struct timeval {
    time_t tv_sec;  // seconds
    suseconds_t tv_usec;  // microseconds
    };
    ```
    - `tv_sec` represents the number of seconds since the Epoch (usually January 1, 1970).
    - `tv_usec` represents the number of microseconds within the current second.
* Return values:
    - On success, the `gettimeofday()` return `0`, for failure the function returns `-1`.

---------
## ***```usleep()```***
* What Is And How To Use ``usleep`` function in C language?
    - The usleep function is a legacy function that is used to introduce a delay or pause in a C program for a specified number of microseconds.
    -  The `usleep()` function returns `0` on success.  On error, `-1` is returned, with errno set to indicate the error.

***Syntax***

```c
#include <unistd.h>

int usleep(useconds_t microseconds);
```

* We use this function in that project because shall cause the calling thread to be suspended from execution until either the number of realtime microseconds specified by the argument useconds has elapsed or a signal is delivered to the calling thread and its action is to invoke a signal-catching function or to terminate the process. The suspension time may be longer than requested due to the scheduling of other activity by the system.

---------
## ***```pthread_create()```***
 * What Is And How To Use ``pthread_creat`` function in C language?
    * The pthread_create function is used to create a new thread in a C program using the POSIX threads (pthreads) library. 
    * The pthread_create function takes care of creating the new thread and associating it with a specific function that the thread will execute.
***Syntax***

```c
#include <pthread.h>

int pthread_create(pthread_t *thread, const pthread_attr_t *attr, void *(*start_routine) (void *), void *arg);

```
***Arguments***
* This function takes four arguments:
    - `thread` : A pointer to a `pthread_t` variable that will hold the identifier of the newly created thread.
    - `attr` : A pointer to a `pthread_attr_t` variable that specifies the attributes of the new thread. You can generally pass `NULL` to use default attributes.
    - `start_routine` : A function pointer to the function that the new thread will execute. This function should take a single `void*` parameter and return a `void*`.
    - `arg` : An argument that will be passed to the `start_routine` when the new thread is created.

## ***```pthread_detach()```***
 * What Is And How To Use ``pthread_detach`` function in C language?
    * The `pthread_detach` function in the C programming language is used to detach a thread, allowing it to be automatically cleaned up and released when it finishes its execution. 

***Syntax***

```c
#include <pthread.h>

int pthread_detach(pthread_t thread);
```
***Arguments***
* This function takes one argument:
    - `thread` : The `pthread_t` identifier of the thread to be detached.

## ***```pthread_mutex_init()```***
 * What Is And How To Use ``pthread_mutex_init`` function in C language?
    * The `pthread_mutex_init` function in the C programming language is used to initialize a pthread mutex, which is a synchronization primitive used to protect shared resources from concurrent access by multiple threads. Mutexes help ensure that only one thread at a time can access a critical section of code or a shared resource, preventing data corruption and race conditions.

***Syntax***

```c
#include <pthread.h>

int pthread_mutex_init(pthread_mutex_t *mutex, const pthread_mutexattr_t *attr);
```
***Arguments***
* This function takes two argument:
    - `mutex` : A pointer to a `pthread_mutex_t` variable that will hold the initialized mutex.
    - `attr` : A pointer to a `pthread_mutexattr_t` variable that specifies the mutex attributes. You can generally pass `NULL` to use default attributes.

## ***```pthread_mutex_destroy()```***
 * What Is And How To Use ``pthread_mutex_destroy`` function in C language?
    - The `pthread_mutex_destroy` function in the C programming language is used to destroy a pthread mutex that was previously initialized using the `pthread_mutex_init` function.
    - Once a mutex is no longer needed, you should destroy it to release any associated resources.

***Syntax***

```c
#include <pthread.h>

int pthread_mutex_destroy(pthread_mutex_t *mutex);
```

***Arguments***
* This function takes one argument:
    - `mutex` : A pointer to a `pthread_mutex_t` variable that represents the mutex to be destroyed.

## ***```pthread_mutex_lock()```***
 * What Is And How To Use ``pthread_mutex_lock`` function in C language?
    - The pthread_mutex_lock function in the C programming language is used to acquire a pthread mutex, which is a synchronization primitive used to protect shared resources from concurrent access by multiple threads. 
    - Mutexes help ensure that only one thread at a time can access a critical section of code or a shared resource, preventing data corruption and race conditions.

***Syntax***

```c
#include <pthread.h>

int pthread_mutex_lock(pthread_mutex_t *mutex);
```


***Arguments***
* This function takes one argument:
    - `mutex`: A pointer to a `pthread_mutex_t` variable representing the mutex to be locked.


## ***```pthread_mutex_unlock()```***
 * What Is And How To Use ``pthread_mutex_unlock`` function in C language?
    - The `pthread_mutex_unlock` function in the C programming language is used to release a pthread mutex that was previously locked using the `pthread_mutex_lock` function. 
    - Mutexes are synchronization primitives used to ensure exclusive access to shared resources by multiple threads.
    - Once a thread is done using a shared resource or a critical section of code protected by a mutex, it should unlock the mutex to allow other threads to access it.

***Syntax***

```c
#include <pthread.h>

int pthread_mutex_unlock(pthread_mutex_t *mutex);
```


***Arguments***
* This function takes one argument:
    - `mutex`: A pointer to a `pthread_mutex_t` variable representing the mutex to be unlocked.