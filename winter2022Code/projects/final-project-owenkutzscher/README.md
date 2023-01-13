<img src="https://www.colorado.edu/cs/profiles/express/themes/ucb/images/cu-boulder-logo-text-black.svg" alt="CU Boulder Logo" width="500">



# Questions

## Does one hashing collision work better than the other? Consider the data sets we used, and a much larger data set with 1 million records. Explain.
For the data we used, chaining appears to work better than open addressing. There are less steps the computer must run in order to insert items into chaining. We can see this from the output for test files A and B. Where  open addressing has more collisions and search opperations than chaining. I'm not going to include the specific numbers because that is on Asa's PDF. On a 1 million record data set, this would not be the case. This is because although collisions may occur with quadratic probing, we would (reletively) quickley be able to locate the value we are looking for. Vs with chaining, we could have several chains build up to extremily large sizes. So then searching for an element could aprach O(n).
So, for a very large set, use quadratic probing. For a smaller set, use chaining. One is only better than the other depending on the size of the data entered in.

## We used the same BST for both hashing mechanisms. What alternative data set would you advise? Why?
I would advide a red black tree. That way the time complexity stays at O(logn). With our current, potentially very unballanced, BST the time complexity could approach O(n), which defeate the purpouse of using a BST.

## Explain a few ways you could improve the application
One way is use a RBT instead of unbalanced BST. This would make it so the time complexity does not approach O(n) when many elements are added. Another way to improve this is to have a data size detector. This would assign the data set to eb stored with open addressing or chaining depending on how large it is. One way to improve this in the code would be to make the hash function return the index the item should be hashed at (or exists at). Currently the hash function is just one line. So we might as well have just put that one line in our code.








# CSCI 2270: Data Structures <br/> University Courses Database Project

## Introduction
The objective of this project is to write an application that reads a list of University courses from a data file and then inserts them into two separate hash tables. The first hash table will use the Open Addressing collision resolution scheme and the second hash table will use the Chaining collision resolution scheme. Users should be able to search the hash tables for a specific course number or display all of the courses. It’s your objective to compare and contrast the hashing collision resolution methods. Additionally, the application should maintain a list of courses taught by each professor by using a binary search tree data structure. Users should be able to search for a professor and view all of the courses taught by the Professor.

## Getting Started
1. Download the project pdf writeup located within this starter repo.<br/>
2. Download the PowerPoint slide deck [Getting Started With GitHub Classroom Workflow](https://docs.google.com/presentation/d/1B0yZb6twQ_NVL8PripCL7AkeIKSrR8_M/edit?usp=sharing&ouid=115561230768383364768&rtpof=true&sd=true).<br/>
3. Download the [GitHub presentation slide deck](https://drive.google.com/file/d/12mMxMGRrpnkSuz08FUlvkhC-9WJ4JHns/view?usp=sharing) created by Asa Ashraf.<br/>
4. View the GitHub lecture videos [Part I](https://drive.google.com/file/d/1P4iqEbt9Nx68-Nq0FxxpdBZCrbkx5cN3/view?usp=sharing) and [Part II](https://drive.google.com/file/d/1EFYq_qJsV3QNcx_W86nz2KFpQUhSn9jF/view?usp=sharing) given by Asa Ashraf.

## Disclaimer
Students are not allowed to share this code or make it public at any time, even after the course has completed.
