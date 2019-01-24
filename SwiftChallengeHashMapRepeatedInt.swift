// hash map problem finds the first repeated integer

func hashmap(){
var dictionary: [String: Int] = [:]

// add key-value pair
//dictionary["firstName"] = "Steve"

// retrieve value for a key
//dictionary["firstName"] // outputs "Steve"

var rand = [1,2,3,3,3,4,5,6,7]
for index in 0..<rand.count {

    if dictionary.keys.contains(String(rand[index])) {
        dictionary[String(rand[index])] = dictionary[String(rand[index])]! + 1
        print(String(rand[index]) + " is the first repeated number")
        //return
    }
    else {
        dictionary[String(rand[index])] = 1
    }

    //dictionary[String(rand[index])] = rand[index]
}
print(dictionary)
}

hashmap()
