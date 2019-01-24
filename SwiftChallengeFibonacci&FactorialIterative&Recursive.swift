// factorial and fibonacci recursive and iterative


func factorial_recursive(number: Int) -> Int{
    if number == 0 {
    return 1
    }
    else{
        return number * factorial_recursive(number: number - 1 )
    }
}

factorial_recursive(number: 3)


func factorial_iterative(value: Int) -> Int{
    var result = 1
    for item in 1...value{
        result *= item
    }
    return result
}
factorial_iterative(value: 3)


func fibonacci_recursive(number: Int) -> Int{
    if number <= 1{
        return 1
    }
    else {
        return fibonacci_recursive(number: number - 1) + fibonacci_recursive(number: number - 2)
    }
}

fibonacci_recursive(number: 5)

func fibonacci_iterative(number: Int) -> Int{
    var result = 0
    if number <= 0{
        return 0
    }
    else {
        for value in 0...number {
            //result +=
            if value == number{
                result = fibonacci_recursive(number: value)
            }
            
        }
    }
    return result
}

fibonacci_iterative(number: 6)
