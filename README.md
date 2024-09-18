# Project 02: Sorting List-Based Strings and Numbers
# Date: 09/17/2024
# Group Members: Dylan Woods, Anthony Toms, Jakob Brown
# Net ID: dwoods24, atoms, jbrow327
# Project Description:
This project creates a C++ sorting tool called volsort which uses a linked
list to store the data. It sorts either numbers or strings and supports different sorting methods: STL, Qsort, Merge, and Quick

## Benchmark Results:

| Mode    | Size       | Elapsed Time (seconds)  |
|---------|------------|-------------------------|
| STL     | 10         | 0.001                   | 
| STL     | 100        | 0.001                   | 
| STL     | 1000       | 0.001                   | 
| STL     | 10000      | 0.008                   | 
| STL     | 100000     | 0.083                   | 
| STL     | 1000000    | 1.219                   | 
| STL     | 10000000   | 15.406                  |
| QSORT   | 10         | 0.001                   | 
| QSORT   | 100        | 0.001                   | 
| QSORT   | 1000       | 0.001                   | 
| QSORT   | 10000      | 0.006                   | 
| QSORT   | 100000     | 0.058                   | 
| QSORT   | 1000000    | 0.813                   | 
| QSORT   | 10000000   | 9.917                   |
| MERGE   | 10         | 0.001                   | 
| MERGE   | 100        | 0.001                   | 
| MERGE   | 1000       | 0.001                   | 
| MERGE   | 10000      | 0.006                   | 
| MERGE   | 100000     | 0.066                   | 
| MERGE   | 1000000    | 0.948                   | 
| MERGE   | 10000000   | 12.217                  |
| QUICK   | 10         | 0.001                   | 
| QUICK   | 100        | 0.001                   | 
| QUICK   | 1000       | 0.001                   | 
| QUICK   | 10000      | 0.008                   | 
| QUICK   | 100000     | 0.071                   | 
| QUICK   | 1000000    | 1.301                   | 
| QUICK   | 10000000   | 18.425                  |

## Analysis of Performance:

### Relative Performance of Sorting Methods:
From our benchmark results, we saw that qsort was the fastest sorting method, especially with larger datasets. This may be because it's a highly optimized function in the C library, designed to handle sorting efficiently. STL sort was also fast, but it was a bit slower than qsort. Merge sort worked well too but was slower for larger datasets because it requires more memory to merge the lists. Our custom quicksort was the slowest with big datasets, probably because it’s not as well optimized as qsort, and our method for choosing the pivot might not have been the best.

### Complexity vs. Performance:
Even though all the sorting methods have a time complexity of O(n log n), the actual performance can vary based on how they are implemented. qsort and STL sort are made to be very efficient, while merge sort has the extra memory overhead that slows it down. Our custom quicksort could be improved. This shows that theoretical complexity doesn't always reflect real-world performance, which depends a lot on how the algorithm is implemented.

### Best Sorting Mode:
Overall, qsort seems to be the best sorting method. While STL and custom sorts might be useful in certain situations, qsort is the best choice for general-purpose sorting because of its speed and simplicity. It strikes a good balance between performance and ease of implementation, making it a great option for large datasets.

## Group Dynamics and Contributions:
- **Dylan Woods**: I contributed to the implementation of the qsort and stl sort algorithms. Additionally, I implemented the benchmarking script and worked on the debugging process.
- **Jakob Brown**: I wrote and implemented Merge Sort, helped with structure and formatting, and helped with STL sort, and Qsort
- **Anthony Toms**: was responsible for integrating the STL and qsort sorting modes 


