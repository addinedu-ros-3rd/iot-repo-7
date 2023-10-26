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

        self.count = 0
        
        '------------ voice -------------'
        self.btn_rec.clicked.connect(self.RecVoice)
        self.btn_play.clicked.connect(self.PlayVoice)

        # self.send.clicked.connect(self.Send)
        '------------button -------------'
        self.giveInstantly.clicked.connect(self.GiveInstantly)
        self.setNextTime.clicked.connect(self.SetNextTime)
        self.reset.clicked.connect(self.Reset)
        '---------------next Time----------------------'
        self.hour.setRange(0, 8)
        self.hour.setSingleStep(1)
        # self.hour.valueChanged.connect(self.setNextHour)
        
        self.minute.setRange(0, 59)
        self.minute.setSingleStep(1)
        # self.minute.valueChanged.connect(self.setNextMinute)

        self.second.setRange(0, 59)
        self.second.setSingleStep(1)
        # self.second.valueChanged.connect(self.setNextSecond)
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
        
        
    
    def GiveInstantly(self):
        
        retval = QMessageBox.question(self, 'question', 'Are you sure give instantly?',
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