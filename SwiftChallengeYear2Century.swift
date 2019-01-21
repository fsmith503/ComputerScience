/*
 
 Return the inputted numerical year in century format. For example 2014, would return 21st.
 
 The input will always be a 4 digit string. So there is no need for year string validation
 
 Examples:
 Input: 1999 Output: 20th
 Input: 2011 Output: 21st
 Input: 2154 Output: 22nd
 Input: 2259 Output: 23rd
 Input: 1124 Output: 12th
 Input: 2000 Output: 20th
 */

func whatCentury(_ year: String) -> String {
    let startIndex = year.startIndex
    var result = ""
    let endIndex = year.endIndex
    result += String(year[year.startIndex])
    result += String(year[year.index(startIndex, offsetBy: +1)])
    
    let number = Int(result)
    var final = String(number! + 1)
    //print(final)
    var finalStartIndex = final.startIndex
    var finalEndIndex = final.endIndex
    var secondDigit = final[final.index(finalStartIndex, offsetBy: 1)]
    if (secondDigit == "0" || secondDigit == "4" || secondDigit == "5" || secondDigit == "6" || secondDigit == "7" || secondDigit == "8" || secondDigit == "9"){
        final += "th"
    }
    if (secondDigit == "1" ){
        final += "st"
    }
    if (secondDigit == "2" ){
        final += "nd"
    }
    if (secondDigit == "3" ){
        final += "rd"
    }
    return final
}
whatCentury("1234")
whatCentury("1999")
whatCentury("636")
whatCentury("2011")
whatCentury("2154")
whatCentury("2259")
whatCentury("1124")
whatCentury("2000")
whatCentury("542")
whatCentury("909")
whatCentury("236")
