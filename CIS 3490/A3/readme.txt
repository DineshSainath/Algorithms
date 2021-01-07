Name: Dinesh Sainath Koti Reddy
ID # 1025287
CIS 3490 Assignment 3

The programs can be compiled by using the command - "make Pxx"
where xx stands for the question number of file name.
For instance, to compile P11 use "make P11", to compile P22 use "make P22"

To execute the programs use " ./Pxx "
where xx stands for the question number of file name.
For instance, to execute P21 use "./P21"

#1
The time taken to find the anagrams in the text file using Brute Force is 0.08
seconds approximately.
The time taken to find the anagrams in the text file using Presort method is
0.05 seconds approximately.

#2
10 input strings have been taken into account to evaluate the average
performance of the programs.
Some of them are mentioned below

When the string "university" is searched, 177 occurrences are found.
Time taken for Brute Force:  0.100000 seconds Approximately; Shifts = 2984933
Time taken for Horspool method: 0.124000 seconds approximantely; Shifts = 404197
Time taken for Boyer Moore method: 0.163000 seconds approximately; Shifts = 3088063

When the string "credit" is searched, 177 occurrences are found.
Time taken for Brute Force:  0.178000 seconds Approximately; Shifts = 3164215
Time taken for Horspool method: 0.140000 seconds approximantely; Shifts = 615016
Time taken for Boyer Moore method: 0.186000 seconds approximately; Shifts = 3179336
And so on..

The time taken ratio for the three programs are as follows:
P21:P22:P23  =  0.1 : 0.12 : 0.16 seconds

It is evident that Brute Force method takes the least time to do the search
while Boyer Moore takes the most.
But, the brute force method takes more number of shifts than Horspool method,
which has the least number of shifts.
Therefore, Horspool method is more efficient.
