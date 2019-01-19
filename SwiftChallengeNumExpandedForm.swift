/*

Write Number in Expanded Form
You will be given a number and you will need to return it as a string in Expanded Form. For example:

expandedForm 12    -- Should return '10 + 2'
expandedForm 42    -- Should return '40 + 2'
expandedForm 70304 -- Should return '70000 + 300 + 4'

NOTE: All numbers will be whole numbers greater than 0.
expandedForm 12    -- Should return '10 + 2'
expandedForm 42    -- Should return '40 + 2'
expandedForm 70304 -- Should return '70000 + 300 + 4'
*/


func expandedForm(_ num: Int) -> String {
    var result = ""
    var input = String(num)
    var basecount = input.count-1
    
    for digit in input {
        if(digit == "0"){
         // do nothing skip it
        }
        if(digit != "0"){
            result += String(digit)
            for count in 0..<basecount{
                result += "0"
                if(count == basecount-1){
                result += " + "
                }
            }
        }
    basecount -= 1
    }
    print(result)
    return result
}

expandedForm(12)
expandedForm (42)
expandedForm(70304)
