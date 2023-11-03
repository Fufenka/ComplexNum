import tkinter as tk
from socket import *


class PopcatClient:
    def __init__(self):
        self.win = tk.Tk()
        self.win.title('rock')
        self.win.geometry("300x300")
        self.win.config(bg='red')

        self.btn = tk.Button(self.win, text='ROCK', font="Arial 40", width=5, height=2, command=self.click)
        self.btn.place(relx=0.5, rely=0.5, anchor='center')

        self.client = socket(AF_INET, SOCK_STREAM)
        self.client.connect(("127.0.0.1", 8000))

    def click(self):
        self.client.send(bytes("\00", 'ascii'))


    def finish(self):
        self.client.close()
        self.win.destroy()

    def run(self):
        self.win.mainloop()


popcat_client = PopcatClient()
popcat_client.run()