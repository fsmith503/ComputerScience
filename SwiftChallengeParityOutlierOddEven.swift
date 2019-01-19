/*
You are given an array (which will have a length of at least 3, but could be very large) containing integers. 
The array is either entirely comprised of odd integers or entirely comprised of even integers except for a single integer N. 
Write a method that takes the array as an argument and returns this "outlier" N.

Examples
[2, 4, 0, 100, 4, 11, 2602, 36]
Should return: 11 (the only odd number)

[160, 3, 1719, 19, 11, 13, -21]
Should return: 160 (the only even number)
*/

func findOutlier(_ array: [Int]) -> Int {
var oddCount = 0
var evenCount = 0
var evenArray:  [Int] = []
//var emptyArray: [Int] = []
var oddArray: [Int] = []
var result = 0
    for item in array{
        if (item % 2 == 0){
            evenCount += 1
            evenArray.append(item)
            
        }
        if (item % 2 != 0)
        {
            oddCount += 1
            oddArray.append(item)
        }
    }
    if (evenArray.count > oddArray.count){
    result = oddArray[oddArray.startIndex]
    }
    if (oddArray.count > evenArray.count){
    result = evenArray[evenArray.startIndex]
    }
    
    return result
    
}
    

/*
[2, 4, 0, 100, 4, 11, 2602, 36]
Should return: 11 (the only odd number)

[160, 3, 1719, 19, 11, 13, -21]
Should return: 160 (the only even number)
 */
findOutlier([2, 4, 0, 100, 4, 11, 2602, 36])

findOutlier([160, 3, 1719, 19, 11, 13, -21])
