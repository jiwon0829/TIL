//
//  ViewController.swift
//  HelloWorld
//
//  Created by 한지원 on 2021/01/14.
//

import UIKit

class ViewController: UIViewController {
    //출력 레이블용 아웃렛 변수
    @IBOutlet var lb1Hello: UILabel!
    // 이름 입력용 아웃렛 변수
    @IBOutlet var txtName: UITextField!
    
    override func viewDidLoad() {
        super.viewDidLoad()
        // Do any additional setup after loading the view.
    }

    //입력받은 이름 출력하는 기능을 가진 버튼
    @IBAction func btnSend(_ sender: UIButton) {
        lb1Hello.text = "Hello, "+txtName.text!
    }
    
}

