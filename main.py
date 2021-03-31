from layout import Ui_Form
from PySide2.QtWidgets import *


app = QApplication([]) # Start an application.

window = QMainWindow()

win = Ui_Form() # Create a window.

win.setupUi(window)

window.show() # Show window

app.exec_() # Execute the App
