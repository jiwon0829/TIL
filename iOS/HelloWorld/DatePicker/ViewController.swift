//
//  ViewController.swift
//  DatePicker
//
//  Created by 한지원 on 2021/01/18.
//

import UIKit

class ViewController: UIViewController {
    let timeSelector: Selector = #selector(ViewController.updateTime)   //타이머가 구동되면 실행 될 함수
    let interval = 1.0 //타이머의 간격. 1.0은 1초를 의미
    var count = 0  //타이머가 설정한 간격대로 실행되는지 확인
    
    @IBOutlet var lblCurrentTime: UILabel!
    @IBOutlet var lblPickerTime: UILabel!
    
    override func viewDidLoad() {
        super.viewDidLoad()
        // Do any additional setup after loading the view.
        
        
        //타이머 설정
        Timer.scheduledTimer(timeInterval: interval, target: self, selector: timeSelector, userInfo: nil, repeats: true)   //타이머 간격, 동작될 view, 타이머가 구동될 때 실행할 함수, 사용자 정보, 반복 여부
    }

    @IBAction func changeDatePicker(_ sender: UIDatePicker) {
        let datePickerView = sender
        
        let formatter = DateFormatter()
        formatter.dateFormat = "yyyy-MM-dd HH:mm EEE"
        lblPickerTime.text = "선택시간 : " + formatter.string(from: datePickerView.date)
    }

    @objc func updateTime(){
        //타이머 구현
        /*lblCurrentTime.text = String(count)
        count = count + 1*/
        
        //현재 시간 출력
        let date = NSDate()

        let formatter = DateFormatter()
        formatter.dateFormat = "yyyy-MM-dd HH:mm:ss EEE"
        lblCurrentTime.text = "현재시간 : " + formatter.string(from: date as Date)
    }
}

