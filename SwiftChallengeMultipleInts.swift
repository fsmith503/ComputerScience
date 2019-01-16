/* If we list all the natural numbers below 10 that are multiples of 3 or 5, we get 3, 5, 6 and 9. The sum of these multiples is 23.

Finish the solution so that it returns the sum of all the multiples of 3 or 5 below the number passed in.

Note: If the number is a multiple of both 3 and 5, only count it once.

*/


import XCTest
class SolutionTest: XCTestCase {
    static var allTests = [
        ("Test Solution", testSolution),
    ]

    func testSolution() {
        XCTAssertEqual(solution(10), 23)
        XCTAssertEqual(solution(20), 78)
        XCTAssertEqual(solution(200), 9168)
    }
}

XCTMain([
    testCase(SolutionTest.allTests)
])



func solution(_ num: Int) -> Int {
  var result = 0
    for item in 0...num{
        if item == num{
            break
        }
        if(item % 5 == 0 && item % 3 == 0){
            result += item
        }
        else if(item % 5 == 0){
            result += item
        }
        else if(item % 3 == 0){
            result += item
        }
    }
    return result
}





