import tkinter as tk
from tkinter import ttk

# Label 
janela = tk.Tk()
janela.title("Aplicação GUI com o Windgets Label")
ttk.Label(janela, text="Componente Label").grid(column=0, row=0)
janela.mainloop()