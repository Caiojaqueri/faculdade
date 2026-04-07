import tkinter as tk

# Radiobutton
janela = tk.Tk()
v = tk.IntVar()
tk.Label(janela, text="""Escolha uma linguagem de programação: """,justify = tk.LEFT, padx = 20). pack()

tk.Radiobutton(janela, text="python", padx=25, variable=v, value=1).pack(anchor=tk.W)

tk.Radiobutton(janela, text="C++", padx=25, variable=v, value=2).pack(anchor=tk.W)

tk.Radiobutton(janela, text="JavaScript", padx=25, variable=v, value=3).pack(anchor=tk.W)
janela.mainloop()