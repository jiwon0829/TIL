//
//  ViewController.swift
//  Mission_DatePicker
//
//  Created by 한지원 on 2021/01/18.
//

import UIKit

class ViewController: UIViewController {
    let timeSelector: Selector = #selector(ViewController.updateTime)   //타이머가 구동되면 실행 될 함수
    let interval = 1.0  //타이머 간격 1초
    var count = 0   //타이머가 설정한 간격대로 실행되는지 확인
    
    var alarmTime: String?
    
    @IBOutlet var lblCurrentTime: UILabel!
    @IBOutlet var lblPickerTime: UILabel!
    
    override func viewDidLoad() {
        super.viewDidLoad()
        // Do any additional setup after loading the view.
        
        //타이머 설정
        Timer.scheduledTimer(timeInterval: interval, target: self, selector: timeSelector, userInfo: nil, repeats: true)
    }

    @IBAction func changeDatePicker(_ sender: UIDatePicker) {
        let datePickerView = sender
        
        let formatter = DateFormatter()
        formatter.dateFormat = "yyyy-MM-dd HH:mm EEE"
        lblPickerTime.text = "선택 시간 : " + formatter.string(from: datePickerView.date)
        
        //알람 시간 설정
        formatter.dateFormat = "hh:mm aaa"
        alarmTime = formatter.string(from: datePickerView.date)
    }
    
    @objc func updateTime(){
        let date = NSDate()
        
        let formatter = DateFormatter()
        formatter.dateFormat = "yyyy-MM-dd HH:mm EEE"
        lblCurrentTime.text = "현재 시간 : " + formatter.string(from: date as Date)
        
        
        //알람 선택한 시간과 현재 시간이 동일하면 배경화면 붉은색
        formatter.dateFormat = "hh:mm aaa"
        let currentTime = formatter.string(from: date as Date)
        if(alarmTime == currentTime){
            view.backgroundColor = UIColor.red   //배경색 변경
        }
        else{
            view.backgroundColor = UIColor.white
        }
    }
    
}

