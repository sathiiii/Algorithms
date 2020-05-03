**Problem Statement**

Ex-Special Forces operator Frank Martin lives what seems to be a quiet life along the French Mediterranean, 
hiring himself out as a mercenary transporter who moves goods - human or otherwise - from one place to another.

Frank is precise with his calculations per each job and premeditates every possible scenario that may arise during a 
transport. Hence he always imagines how he reaches the destination for which he looks for all possible routes and 
"P" filling stations along with the distance "A" to them from the outset and unit price "F", since different states have 
different laws it resulted in different prices in USA. It is assumed that a unit of gasoline is needed for a unit distance 
and at the beginning he has have “K” units bounded by a maximum "U", ultimately to cover a transport of "M" units long.

Your job here is to assist Frank to do the precise calculation of the least amount of money he needs to reach the destination 
of each transport. If there is an instance that he is unable to make it, return -1.

**Input Format**

* First line contains the number of test cases T.
* Next line contains P, U, K, M four integers separated by spaces.
* Next P lines contains A and F of each filling station separated by spaces.

**Constraints**

* 0 < M < 1000000001
* 0 < U < 1000001
* 1 <= F <= 1000000
* 0 < P < 50001
* 0 <= K <= U
* 0 <= A <= M

**Output Format**

Output should contain T lines, each consisting of an integer.

**Sample Input 0**
'''
5
10 10 10 1000
731 467592
386 754369
215 837197
851 407143
9 401476
943 234795
779 839893
269 385425
199 58693
745 725521
10 10 10 1000
731 467592
851 407143
9 401476
386 754369
215 837197
943 234795
269 385425
779 839893
199 58693
745 725521
10 10 10 1000
851 407143
9 401476
943 234795
731 467592
269 385425
386 754369
215 837197
779 839893
199 58693
745 725521
10 10 10 1000
731 467592
386 80000
215 837197
851 407143
9 401476
943 204795
779 839893
269 380425
199 58093
745 725521
10 350 10 1000
731 467592
386 80000
215 837197
851 407143
9 401476
943 204795
779 839893
269 380425
199 58093
745 725521
'''
**Sample Output 0**
'''
-1
-1
-1
-1
214075065
'''
