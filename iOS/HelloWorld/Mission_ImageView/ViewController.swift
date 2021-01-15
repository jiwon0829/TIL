//
//  ViewController.swift
//  Mission_ImageView
//
//  Created by 한지원 on 2021/01/15.
//

import UIKit

class ViewController: UIViewController {
    var maxImage = 6
    var numImage = 1
    
    @IBOutlet var imgGallery: UIImageView!
    
    override func viewDidLoad() {
        super.viewDidLoad()
        // Do any additional setup after loading the view.
        imgGallery.image = UIImage(named: "1.png")
    }

    @IBAction func btnBefore(_ sender: UIButton) {
        numImage = numImage - 1
        if (numImage < 1) {
            numImage = maxImage
        }
        
        let imageName = String(numImage) + ".png"
        imgGallery.image = UIImage(named:imageName)
    }
    
    @IBAction func btnAfter(_ sender: UIButton) {
        numImage = numImage + 1
        if (numImage > maxImage) {
            numImage = 1
        }
        
        let imageName = String(numImage) + ".png"
        imgGallery.image = UIImage(named:imageName)
    }
}

