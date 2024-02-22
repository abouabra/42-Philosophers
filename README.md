# Philosophers

## Description

Philosophers is a project that aims to create a simulation of the dining philosophers problem.

the dining philosophers problem is a classic synchronization problem that is used to illustrate the challenges of avoiding deadlock and starvation in a multi-threaded environment. The problem is described as follows:
- There are 5 philosophers sitting at a round table.
- Each philosopher has a plate of spaghetti.
- There are 5 forks on the table, one between each philosopher.
- To eat, a philosopher needs to use two forks, one from the left and one from the right.
- After eating, the philosopher needs to sleep for a random amount of time.
- After sleeping, the philosopher thinks for a random amount of time.
- The philosophers should not starve.
- The philosophers should not deadlock.

the mandtory part of the project is to implement the simulation of the dining philosophers problem with the following constraints:
- Each philosopher is a thread.
- Each fork is a mutex.
- Each philosopher should be able to eat, sleep, and think.
- The philosophers should not deadlock.
- The philosophers should not starve.

the bonus part solves the same problem but with the following constraints:
- Each philosopher is a process.
- Each fork is a semaphore.
- Each philosopher should be able to eat, sleep, and think.
- The philosophers should not deadlock.
- The philosophers should not starve.

The project is written in C and uses the pthread library for the mandatory part and the fork and semaphore system calls for the bonus part.

## Installation

1. Clone the repository:
```bash
git clone https://github.com/abouabra/42-Philosophers.git
```
2. Change the current working directory:
```bash
cd 42-Philosophers
```
3. cd into the mandatory or bonus directory:
```bash
cd mandatory
```
or
```bash
cd bonus
```
4. Run the make command:
```bash
make
```


## Usage

5. Run the program:
```bash
./philo [number_of_philosophers] [time_to_die] [time_to_eat] [time_to_sleep] [optional: number_of_times_each_philosopher_must_eat]
```
or
```bash
./philo_bonus [number_of_philosophers] [time_to_die] [time_to_eat] [time_to_sleep] [optional: number_of_times_each_philosopher_must_eat]
```

### Explanation of the arguments
- number_of_philosophers: the number of philosophers sitting at the table.
- time_to_die: the time in milliseconds it takes for a philosopher to die if they don't start eating.
- time_to_eat: the time in milliseconds it takes for a philosopher to eat.
- time_to_sleep: the time in milliseconds it takes for a philosopher to sleep.
- number_of_times_each_philosopher_must_eat: the number of times each philosopher must eat before the simulation stops. If this argument is not provided, the simulation will run indefinitely.

### Example
```bash
./philo 5 300 200 200
```

**output:**
```
0 1 has taken a fork
0 1 has taken a fork
0 1 is eating
0 3 has taken a fork
0 3 has taken a fork
0 3 is eating
0 5 has taken a fork
200 3 is sleeping
200 5 has taken a fork
200 5 is eating
200 1 is sleeping
200 2 has taken a fork
200 2 has taken a fork
200 2 is eating
200 4 has taken a fork
300 2 has died
```



## Final Note
If you have any suggestions or improvements, feel free to open an issue or submit a pull request.
