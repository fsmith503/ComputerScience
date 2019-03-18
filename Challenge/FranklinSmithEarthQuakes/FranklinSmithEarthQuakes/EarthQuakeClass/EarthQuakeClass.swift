//
//  EarthQuakeClass.swift
//  FranklinSmithEarthQuakes
//
//  Created by  Franklin Smith on 3/14/19.
//  Copyright © 2019  Franklin Smith. All rights reserved.
//

import Foundation
final class EarthQuake: NSObject {
// MARK: - Class Variables
    var size: String
    var date: String
    var webaddress: String
    var location: String
    
    
// MARK: - Class Initializer
init(size: String, date: String, webaddress: String, location: String) {
        self.size = size
        self.date = date
        self.webaddress = webaddress
        self.location = location
        super.init()
    }
}
