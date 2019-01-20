
/* Factorial of Any Integer */

func FirstFactorial(_ num: Int) -> Int {
    
    // code goes here
    // Note: feel free to modify the return type of this function
    var result = 1
    for number in 1...num{
        result *= number
    }
    return result
    
}

// keep this function call here
FirstFactorial(3)
FirstFactorial(4)

