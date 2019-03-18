//
//  EarthQuakeDataViewController.swift
//  FranklinSmithEarthQuakes
//
//  Created by  Franklin Smith on 3/13/19.
//  Copyright © 2019  Franklin Smith. All rights reserved.
//

import UIKit

class EarthQuakeDataViewController: UIViewController {

// MARK: - Variables
    var quakeArray: Array<EarthQuake> = []
    var selectionDays = 15
    @IBOutlet var backButton: UIButton!
    @IBOutlet weak var EarthQuaketableView: UITableView!
    @IBOutlet var displayLabel: UILabel!
    @IBOutlet var DateLabel: UILabel!
    @IBOutlet var DateSelector: UISlider!
    
// MARK: - Lifecycle Methods
    override func viewDidLoad() {
        super.viewDidLoad()
        EarthQuaketableView.rowHeight = 90
        EarthQuaketableView.dataSource = self
        EarthQuaketableView.delegate = self
        displayLabel.numberOfLines = 2
        self.EarthQuaketableView.separatorStyle = UITableViewCell.SeparatorStyle.singleLine
        self.EarthQuaketableView.layoutMargins = UIEdgeInsets.zero;
        let nib = UINib(nibName: "EarthQuakeDataTableViewCell", bundle: nil)
        EarthQuaketableView.register(nib, forCellReuseIdentifier: "cellId")
        resetInformation()
    }
    
// MARK: - Logic Methods
    
    func resetInformation(){
        
        let today = Date()
        let maxValue = Calendar.current.date(byAdding: .day, value: -(selectionDays), to: today)!
        let filter = DateFormatter()
        filter.dateFormat = "MM-dd-yyyy"
        let displayString = "Recorded Earthquakes from the last" + String(self.selectionDays) + "Days."
        filter.dateFormat = "yyyy-MM-dd"
        let webAddress = "https://earthquake.usgs.gov/fdsnws/event/1/query?format=geojson&starttime="
        let firstDate = String(filter.string(from: maxValue))
        let secondDate = String(filter.string(from: today))
        let endParameter = "&endtime="
        let magnitugeparameter = "&minmagnitude=5"
        let webRequestAddress = URL(string: webAddress + firstDate + endParameter + secondDate + magnitugeparameter)
        
        self.quakeArray = []
        
        URLSession.shared.dataTask(with: webRequestAddress!, completionHandler: { (data, response, error) in
            
            if error != nil {
                let alertController = UIAlertController(title: "Your internet connection has been disabled.", message: nil, preferredStyle: .alert)
                self.present(alertController, animated: true, completion: nil)
                return
            }
            
            filter.dateFormat = "MM/dd/yyyy HH:mm"
            
            if let jsonObj = try? JSONSerialization.jsonObject(with: data!, options: .allowFragments) as? NSDictionary {
                
                if let earthquakeArray = jsonObj!.value(forKey: "features") as? NSArray {
                    
                    for quake in earthquakeArray {
                        
                        let feature = quake as! NSDictionary
                        
                        let properties = feature.value(forKey: "properties") as! NSDictionary
                        
                        let featurePlace = properties.value(forKey: "place") as! String
                        
                        let featureMag = properties.value(forKey: "mag") as! NSNumber
                        
                        let featureTime = NSDate(timeIntervalSince1970: TimeInterval(properties.value(forKey: "time") as! Int) / 1000)
                        
                        let featureURL = properties.value(forKey: "url") as! String
                        
                        let featureStatus = properties.value(forKey: "status") as! String
                        
                        let earthquake = EarthQuake(size: String(String(format: "%f", featureMag.doubleValue).prefix(3)), date: featurePlace, webaddress: filter.string(from: featureTime as Date), location: featureURL)
                        
                        if featureStatus == "reviewed" {
                            self.quakeArray.append(earthquake)
                        }
                    }
                }
            }
            
            DispatchQueue.main.async {
                self.EarthQuaketableView.reloadData()
            }
        }).resume()
    }


// MARK: - Button Action Methods
    @IBAction func backButtonPressed(_ sender: Any) {
        self.dismiss(animated: true)
    }

    @IBAction func slider(_ sender: UISlider){
    self.DateLabel.text = String(Int(sender.value))
    //self.EarthQuaketableView.removeAll()
    selectionDays = Int(sender.value)
    //print(self.selectionDays)
    resetInformation()
    self.EarthQuaketableView.reloadData()
}
    
} // End of EarthQuakeDataViewControllerClass

// MARK: - TableView

extension EarthQuakeDataViewController: UITableViewDelegate, UITableViewDataSource{
    
    func tableView(_ tableView: UITableView, didSelectRowAt indexPath: IndexPath){
        let url = URL(string: self.quakeArray[indexPath.row].location)
        print(url)
        if url == nil {
            return
        }
        UIApplication.shared.open(url!)
    }
    
    
    func tableView(_ tableView: UITableView, cellForRowAt indexPath: IndexPath) -> UITableViewCell {
        var cell: EarthQuakeDataTableViewCell? = EarthQuaketableView.dequeueReusableCell(withIdentifier: "cellId") as? EarthQuakeDataTableViewCell
        
        if cell == nil {
            cell = EarthQuakeDataTableViewCell()
        }
        cell!.sizeDisplay?.text = self.quakeArray[indexPath.row].size
        cell!.locationDisplay?.text = self.quakeArray[indexPath.row].date
        cell!.dateDisplay?.text = self.quakeArray[indexPath.row].webaddress
        
        
        return cell!
    }
    
    func numberOfSections(in tableView: UITableView) -> Int {
        return 1
    }
    
    func tableView(_ tableView: UITableView, heightForRowAt indexPath: IndexPath) -> CGFloat{
        return 90
    }
    
    func tableView(_ tableView: UITableView, numberOfRowsInSection section: Int) -> Int {
        return self.quakeArray.count
        
    }
    
} // end of tableview
    

