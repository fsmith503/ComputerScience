/*
 Your task is to write function findSum.
 
 Upto and including n, this function will return the sum of all multiples of 3 and 5.
 
 For example:
 
 findSum(5) should return 8 (3 + 5)
 
 findSum(10) should return 33 (3 + 5 + 6 + 9 + 10)
 */


func findSum(_ n: Int) -> Int {
    
    var result = 0
    for item in 0...n{
        if(item % 5 == 0 && item % 3 == 0){
            result += item
        }
        else if(item % 5 == 0){
            result += item
        }
        else if(item % 3 == 0){
            result += item
        }
        if item == n{
            break
        }
    }
    return result
}
findSum(5)
findSum(10)




