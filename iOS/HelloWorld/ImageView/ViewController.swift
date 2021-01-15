//
//  ViewController.swift
//  ImageView
//
//  Created by 한지원 on 2021/01/15.
//

import UIKit

class ViewController: UIViewController {
    
    var isZoom = false  //확대 여부를 나타내는 변수
    var imgOn : UIImage?   //켜진 전구 이미지가 있는 UIImage 타입의 변수
    var imgOff : UIImage?   //꺼진 전구 이미지가 있는 UIImage 타입의 변수
    
    @IBOutlet var imgView: UIImageView!
    @IBOutlet var btnResize: UIButton!
    
    override func viewDidLoad() {
        super.viewDidLoad()
        // Do any additional setup after loading the view.
        
        imgOn = UIImage(named: "lamp_on.png")
        imgOff = UIImage(named: "lamp_off.png")
        
        imgView.image = imgOn
    }

    @IBAction func btnResizeImage(_ sender: UIButton) {
        let scale: CGFloat = 2.0   //scale 상수는 이미지를 확대할 배율값을 의미
        var newWidth:CGFloat, newHeight:CGFloat   //newWidth, newHeight 변수는 확대 또는 축소하였을 때 이미지의 가로.세로 길이를 저장할 변수
        
        if(isZoom){
            newWidth = imgView.frame.width/scale
            newHeight = imgView.frame.height/scale
            btnResize.setTitle("확대", for: .normal)
        }
        else{
            newWidth = imgView.frame.width*scale
            newHeight = imgView.frame.height*scale
            btnResize.setTitle("축소", for: .normal)
        }
        imgView.frame.size = CGSize(width: newWidth, height: newHeight)
        isZoom = !isZoom
    }
    
    @IBAction func switchImageOnOff(_ sender: UISwitch) {
        if sender.isOn{
            imgView.image = imgOn
        }
        else{
            imgView.image = imgOff
        }
    }
}

