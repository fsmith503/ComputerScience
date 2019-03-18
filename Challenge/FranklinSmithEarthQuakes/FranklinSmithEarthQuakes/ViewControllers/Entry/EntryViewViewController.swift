//
//  EntryViewViewController.swift
//  FranklinSmithEarthQuakes
//
//  Created by  Franklin Smith on 3/13/19.
//  Copyright © 2019  Franklin Smith. All rights reserved.
//

import UIKit

class EntryViewViewController: UIViewController {
    
// MARK: - Class Variables
    
    @IBOutlet var infoLabel: UILabel!
    @IBOutlet var enterButton: UIButton!
    
    
// MARK: - Lifecycle Methods
    override func viewDidLoad() {
        super.viewDidLoad()
        infoLabel.numberOfLines = 2
        self.enterButton.layer.borderWidth = 1
        self.enterButton.layer.cornerRadius = 4
        self.enterButton.layer.borderColor = UIColor.black.cgColor        // Do any additional setup after loading the view.
        self.enterButton.titleLabel?.textColor = UIColor.black
    }

// MARK: - Button Action Methods
    
    @IBAction func enterButtonPressed(_ sender: Any) {
        let vc = EarthQuakeDataViewController(nibName: "EarthQuakeDataViewController", bundle: nil)
        self.present(vc, animated: true, completion: nil)
    }
    

}
