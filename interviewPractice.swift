import UIKit

var str = "Hello, playground"


//. Write a Swift program to compute the sum of the two integers. If the values are equal return the triple their sum
func sum(a: Int, b: Int) -> Int {
    var sum = a + b
    if(a == b){
        sum = sum * 3
    }
    return sum
}
//sum(a: 2, b: 2)

//Write a Swift program to compute and return the absolute difference of n and 51, if n is over 51 return double the absolute difference
func diff(n: Int) -> Int{
    var difference = 51 - n
    if (difference < 0){
    difference = difference * -1 * 2
    }
    return difference
}
//diff(n: 53)


// Write a Swift program that accept two integer values and return true if one of them is 20 or if their sum is 20
func third(a: Int, b: Int) -> Bool{
    var result = true
    if (a == 20 || b == 20 || (a+b) == 20){
        result = true
    }
    else{
        result = false
    }
    return result
}
//third(a: 6, b: 14)


//Write a Swift program to accept two integer values and return true if one is negative and one is positive. Return true only if both are negative
func stringPrac(a: Int, b: Int) -> Bool{
    var result:Bool
    if(a < 0 && b > 0){
        result = true
    }
    if(a > 0 && b < 0){
        result = true
    }
    if(a < 0 && b < 0){
        result = true
    }
    else {
        result = false
    }
    return result
}
//stringPrac(a: -4, b: -5)


//Write a Swift program to change the first and last character of a given string
func swap(a: String) -> String{
    var chars = Array(a.characters)
    chars[chars.startIndex] = "A"
    chars[chars.endIndex-1] = "B"
    var result = ""
    for thing in chars{
        result += String(thing)
    }
    return result
    
}
//swap(a: "franklin Smith")


//Write a Swift program to add the last character (given string) at the front and back of a given string. The length of the given string must be 1 or more.
func stringSwap(a: String) -> String{
    if(a.count < 1){
        return "String size smaller than 1, Program will exit."
    }
    var chars = Array(a.characters)
    let firstItem = chars[chars.startIndex]
    let lastItem = chars[chars.endIndex-1]
    var result = ""
    for item in 0...chars.endIndex-1 {
        //var result: String
        if(item == 0){
            result += String(lastItem)
        }
        else if(item == chars.endIndex-1){
            result += String(firstItem)
        }
        else{
            result += String(chars[item])
        }
    }
    return result
}

//stringSwap(a: "aaabbb")
//stringSwap(a: "")

//Write a Swift program that return true if either of two given integers is in the range 10..30 inclusive.
func checker(a: Int, b: Int) -> Bool{
    var result: Bool
    var r1 = (10 <= a && a <= 30)
    var r2 = (10 <= b && b <= 30)
    if(r1 && r2){
        result = true
    }
    else{
        result = false
    }
    return result
}
//checker(a: 9, b: 30)

//Write a Swift program to find the largest number among three given integers
func largest(a: Int, b: Int, c:Int) -> Int{
    var result = 0
    var array = [a,b,c]
    for item in array{
        if(item > result){
            result = item
        }
    }
    return result
}
//largest(a: 4, b: 0, c: -30303)

//Write a Swift program to test whether the last digit of the two given non-negative integer values are same or not
func test3(a: Int ) -> Bool {
    var value = false
    var chars = Array(String(a))
    //print(chars[chars.endIndex-1])
    //print(chars[chars.endIndex-2])
    if(chars[chars.endIndex-1] == chars[chars.endIndex-2] && a > 0){
        value = true
    }
    if(chars[chars.endIndex-1] != chars[chars.endIndex-2] && a < 0){
        value = false
    }
    print(value)
    return value
}

//test3(a: 44544)
//test3(a: 44534)


//Write a Swift program to check if the first instance of "a" in a given string is immediately followed by another "a"
func instanceCheck(a: String) -> Bool {
    var array = Array(a)
    var first = (array[array.startIndex] == array[array.startIndex+1])
    var returnValue: Bool
    if first {
        returnValue = true
    }
    else{
        returnValue = false
    }
    return returnValue
}

//instanceCheck(a: "aagg")
//instanceCheck(a: "abab")

//Write a Swift program to create a string made of every other char starting with the first from a given string. So "Python" will return "Pto"
func everyOther(input: String) -> String {
    var inputArray = Array(input)
    var result = ""
    for i in 0...inputArray.count-1{
        if(i%2 == 0){
            result = result + String(inputArray[i])
        }
    }
    return result
}

//everyOther(input: "python")
//everyOther(input: "ababab")

//Write a Swift program to count the number of 7's in a given array of integers.
func count7s(arrayInts: [Int]) -> Int {
    var sum = 0
    for i in 0...arrayInts.count-1{
        if arrayInts[i] == 7 {
            sum += 1
        }
        
    }
    return sum
}

//count7s(arrayInts: [7,3,4,5,3,7])


//Write a Swift program to check if one of the first 4 elements in a given array of integers is a 7. The length of the array may be less than 4.
func first4(inputInt: [Int]) -> Bool {
    var booleanValue = false
    for i in 0...inputInt.count-1{
        if(inputInt[i] == 7 && i < 5){
            booleanValue = true
        }
    }
    return booleanValue
}

//first4(inputInt: [1,2,3,4,5,7])
//first4(inputInt: [1,2,3,7])

//Write a Swift program to test if the sequence of numbers 0, 1, 2 appears in a given array of integers somewhere.

func sequenceCheck(sequence: [Int]) -> Bool {
    var output = false
    for i in 0...sequence.count-1 {
        if i > 0 || i == sequence.count-2{
            if(sequence[i-1] == 0 && sequence[i] == 1 && sequence[i+1] == 2){
                output = true
            }
        }
    }
    return output
}

//sequenceCheck(sequence: [0,0,0,0,0,0])
//sequenceCheck(sequence: [0,0,0,1,2,0])


//Write a Swift program to create a new string where all the character "a" have been removed except the first and last positions
func removalAlg(inputStr: String) -> String {
//    var measurements: [Double] = [1.1, 1.5, 2.9, 1.2, 1.5, 1.3, 1.2]
//    let removed = measurements.remove(at: 2)
//    print(measurements)
    //var inputArray = Array(input)
    //var result = ""
    var strArray = Array(inputStr)
    var removalArray:[Int] = []
    for i in 0...strArray.count-1{
        //print(i)
        if strArray[i] == "a"{
           //strArray.remove(at: i)
            removalArray.append(i)
            //print(i)
        }
    }
    print(removalArray)
    for item in removalArray{
        print(item)
        strArray.remove(at: item)
    }
    return String(strArray)
}
//removalAlg(inputStr: "franklin baaapp")




