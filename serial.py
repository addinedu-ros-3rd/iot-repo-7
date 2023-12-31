import time
from serial import Serial
import sys
from PyQt5.QtWidgets import *
from PyQt5.QtGui import *
from PyQt5.QtCore import *
from PyQt5 import uic

from_class = uic.loadUiType("serial.ui")[0]

class WindowClass(QMainWindow, from_class):
    def __init__(self):
        super().__init__()
        self.setupUi(self)

        self.conn = Serial(port='/dev/ttyACM0', baudrate=9600,timeout=0.1)
        self.serial = SerialManager(self.conn)
        self.serial.start()
        
        
        # 버튼 클릭시 이펙트
        self.setNextTime.setStyleSheet(""" QPushButton { border: 1px outset black; border-radius: 15px;}
            QPushButton:pressed {border-color : rgb(255, 255, 255); background-color: rgb(28, 113, 216); color: rgb(255, 255, 255);} """)
        self.giveInstantly.setStyleSheet(""" QPushButton { border: 1px outset black; border-radius: 15px;}
            QPushButton:pressed {border-color : rgb(255, 255, 255); background-color: rgb(28, 113, 216); color: rgb(255, 255, 255);} """)
        self.reset.setStyleSheet(""" QPushButton { border: 1px outset black; border-radius: 15px;}
            QPushButton:pressed {border-color : rgb(255, 255, 255); background-color: rgb(28, 113, 216); color: rgb(255, 255, 255);} """)
        self.btn_rec.setStyleSheet(""" QPushButton { border: 1px outset red; border-radius: 15px; font-weight: bold; color : rgb(224, 27, 36);}
            QPushButton:pressed {border-color : rgb(255, 255, 255); background-color: rgb(224, 27, 36); color: rgb(255, 255, 255);} """)
        self.btn_play.setStyleSheet(""" QPushButton { border: 1px outset black; border-radius: 15px; font-weight: bold;}
            QPushButton:pressed {border-color : rgb(255, 255, 255); background-color:rgb(28, 113, 216); color: rgb(255, 255, 255);} """)
        
        
        '------------ voice -------------'
        self.btn_rec.clicked.connect(self.RecVoice)
        self.btn_play.clicked.connect(self.PlayVoice)
        '------------button -------------'
        self.giveInstantly.clicked.connect(self.GiveRightnow)
        self.setNextTime.clicked.connect(self.SetNextTime)
        self.reset.clicked.connect(self.Reset)
        self.btn_amount.clicked.connect(self.setAmount)
        '-------------response---------------'
        self.serial.receive.connect(self.Recv)
        
    
    def RecVoice(self):
        retval = QMessageBox.question(self, 'VOICE', '녹음할꺼임??',
                                        QMessageBox.Yes | QMessageBox.No, QMessageBox.No)
        if retval == QMessageBox.Yes:
            text = "rec"
            text += "\n"
            self.conn.write(text.encode())
        else:
            pass
        
    def PlayVoice(self):
        retval = QMessageBox.question(self, 'VOICE', '초밥아 밥먹자~',
                                        QMessageBox.Yes | QMessageBox.No, QMessageBox.No)
        if retval == QMessageBox.Yes:
            text = "play"
            text += "\n"
            self.conn.write(text.encode())
        else:
            pass
        
    
    def GiveRightnow(self):
        
        retval = QMessageBox.question(self, 'question', 'Are you sure give right now?',
                                        QMessageBox.Yes | QMessageBox.No, QMessageBox.No)
        if retval == QMessageBox.Yes:
            text = "right now"
            text += "\n"
            self.conn.write(text.encode())
        else:
            pass
        
    
    def SetNextTime(self):

        print(self.hour.value(), ', ', self.minute.value(), ', ', self.second.value())

        if not((self.hour.value() == 0)and (self.minute.value() == 0) and (self.second.value() == 0)):
            retval = QMessageBox.question(self, 'question', 'Are you sure set Next Time?',
                                            QMessageBox.Yes | QMessageBox.No, QMessageBox.No)
            
            if retval == QMessageBox.Yes:
                text = "{0}H{1}M{2}S".format(self.hour.value(), self.minute.value(), self.second.value())
                text += "\n"
                
                self.conn.write(text.encode())

        elif (self.hour.value() == 0)and (self.minute.value() == 0) and (self.second.value() == 0):
            QMessageBox.warning(self,'warning','Please set Next Time and do press again')
        
        else:
            QMessageBox.warning(self,'warning','Please press reset button and do again')

    
    def Reset(self):

        text = "reset"
        text += "\n"
        self.conn.write(text.encode())


    def setAmount(self):
        retval = QMessageBox.question(self, 'question', 'Are you sure give {0}g?'.format(self.amount.value()),
                                        QMessageBox.Yes | QMessageBox.No, QMessageBox.No)
        if retval == QMessageBox.Yes:
            text = "{0}".format(self.amount.value())
            text += "\n"
            self.conn.write(text.encode())
        else:
            pass   
        

    def Recv(self, message):
        print(message)
        hms = message.split(",") 

        print(hms)
        if (hms[0] == '0') and (hms[1] == '0') and (hms[2] == '0') and (not"reset" in hms):
            QMessageBox.information(self,'notice','meals is given to your pet successfully')

            self.hourlabel.setText(hms[0])
            self.minutelabel.setText(hms[1])
            self.secondlabel.setText(hms[2])
        
        elif (hms[0] == '99') and (hms[1] == '99') and (hms[2] == '99'):
            QMessageBox.warning(self,'warning','Please press reset button and do again')
        
        elif (hms[1] == '88') and (hms[2] == '88'):
            self.amount.setValue(int(hms[0]))
        
        else:
            self.hourlabel.setText(hms[0])
            self.minutelabel.setText(hms[1])
            self.secondlabel.setText(hms[2])


class SerialManager(QThread):
    receive = pyqtSignal(str)

    def __init__(self, serial=None):
        super().__init__()
        self.serial = serial
        self.running = True

    def run(self):
        while self.running == True:
            if self.serial.readable():
                res = self.serial.readline().decode()
                if len(res) > 0:
                    self.receive.emit(str(res))
            time.sleep(0.1)

    def stop(self):
        self.running = False


if __name__ == "__main__":
    app = QApplication(sys.argv)
    myWindows = WindowClass()
    myWindows.show()

    sys.exit(app.exec())