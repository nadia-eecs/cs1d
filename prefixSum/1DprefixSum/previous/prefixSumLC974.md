## LC974: 1D Prefix Sum Subarrays Divisible by K
### Variable Declarations
- [X] Input datatype: `vector <int> nums` , `int k`
- [X] Output datatype: int (a count)
- [X] create a `prefixSum`: vector of ints of nums.size() + 1
- [X] create `remCount`: vector of ints of size k
- [x] create an int variable `prefixSumMod` to 
- [x] store current index of prefixSum's remainder
### Variable Initializations
- [x] calculate compounding sum in prefixSum vector
- [x] per `prefixSum` index, calculate % k and increment remCount for specified remainder

### prefixSum initialization

- [ ] every length of subarrays beginning at index zero
- [ ] create a for loop from 0 to nums.size() - 1
- [ ] add nums at the current index to the prefix sum at the previous index
- [ ] Mod the sumArray to k and add k, mod k
- [ ] add modded sum array to prefixSum variable then add value to remCount vector
- [ ] 

### remCount initialization/calculation/whatever

- [ ] check the amount of times a remainder shows up by looping through remCount
- [ ] after that answer -> return
- [ ] include if statement to see if i
