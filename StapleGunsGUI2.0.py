import tkinter
import customtkinter

customtkinter.set_appearance_mode("light")  # Modes: system (default), light, dark
customtkinter.set_default_color_theme("dark-blue")  # Themes: blue (default), dark-blue, green

app = customtkinter.CTk()  # create CTk window like you do with the Tk window
app.geometry("1280x800")

def button_function():
    print("button pressed")
    
def frontUp_function():
    print("front up")
    
def frontDown_function():
    print("button pressed")
    
def backUp_function():
    print("front up")
    
def backDown_function():
    print("button pressed")
    
def teachFrontUp_function():
    print("front up")
    
def teachFrontDown_function():
    print("button pressed")
    
def teachBackUp_function():
    print("front up")
    
def teachBackDown_function():
    print("front up")

#TITLE
label = customtkinter.CTkLabel(master=app,
                               textvariable=tkinter.StringVar(value="STAPLE GUNS AUTOMATION"),
                               width=300,
                               height=100,
                               text_font=("Roboto", "30"),
                               corner_radius=8)
label.place(relx=0.5, rely=0.07, anchor=tkinter.CENTER)

########################FRONT ACTUATOR GUI######################################

#TEACH BUTTON
button = customtkinter.CTkButton(master=app,
                                 width=250,
                                 height=75,
                                 border_width=0,
                                 corner_radius=8,
                                 text="SET TOPPOINT 1",
                                 text_font=("Roboto", "14"),
                                 command=button_function)
button.place(relx=0.1, rely=0.17, anchor=tkinter.CENTER)

#TEACH ENTRY
entry = customtkinter.CTkEntry(master=app,
                               placeholder_text=0,
                               width=120,
                               height=75,
                               border_width=2,
                               text_font=("Roboto", "18"),
                               corner_radius=10)
entry.place(relx=0.25, rely=0.17, anchor=tkinter.CENTER)

#FRONT UP BUTTON
button = customtkinter.CTkButton(master=app,
                                 width=375,
                                 height=75,
                                 border_width=0,
                                 corner_radius=8,
                                 text="RAISE FRONT",
                                 text_font=("Roboto", "14"),
                                 command=frontUp_function)
button.place(relx=0.1485, rely=0.3, anchor=tkinter.CENTER)

#DISTANCE LABEL
label = customtkinter.CTkLabel(master=app,
                               textvariable=tkinter.StringVar(value="LENGTH"),
                               width=100,
                               height=25,
                               text_font=("Roboto", "14"),
                               corner_radius=8)
label.place(relx=0.1485, rely=0.38, anchor=tkinter.CENTER)

#DISTANCE VALUE LABEL
label = customtkinter.CTkLabel(master=app,
                               textvariable=tkinter.StringVar(value="0"),
                               width=40,
                               height=40,
                               #fg_color("white", "gray75"),
                               text_font=("Roboto", "50"),
                               corner_radius=8)
label.place(relx=0.1485, rely=0.45, anchor=tkinter.CENTER)

#FRONT DOWN BUTTON
button = customtkinter.CTkButton(master=app,
                                 width=375,
                                 height=75,
                                 border_width=0,
                                 corner_radius=8,
                                 text="LOWER FRONT",
                                 text_font=("Roboto", "14"),
                                 command=frontUp_function)
button.place(relx=0.1485, rely=0.57, anchor=tkinter.CENTER)

#TEACH BUTTON
button = customtkinter.CTkButton(master=app,
                                 width=250,
                                 height=75,
                                 border_width=0,
                                 corner_radius=8,
                                 text="SET ENDPOINT 1",
                                 text_font=("Roboto", "14"),
                                 command=button_function)
button.place(relx=0.1, rely=0.7, anchor=tkinter.CENTER)

#TEACH ENTRY
entry = customtkinter.CTkEntry(master=app,
                               placeholder_text=0,
                               width=120,
                               height=75,
                               border_width=2,
                               text_font=("Roboto", "18"),
                               corner_radius=10)
entry.place(relx=0.25, rely=0.7, anchor=tkinter.CENTER)


########################BACK ACTUATOR GUI######################################

#TEACH BUTTON
button = customtkinter.CTkButton(master=app,
                                 width=250,
                                 height=75,
                                 border_width=0,
                                 corner_radius=8,
                                 text="SET TOPPOINT 2",
                                 text_font=("Roboto", "14"),
                                 command=button_function)
button.place(relx=0.41, rely=0.17, anchor=tkinter.CENTER)

#TEACH ENTRY
entry = customtkinter.CTkEntry(master=app,
                               placeholder_text=0,
                               width=120,
                               height=75,
                               border_width=2,
                               text_font=("Roboto", "18"),
                               corner_radius=10)
entry.place(relx=0.56, rely=0.17, anchor=tkinter.CENTER)

#BACK UP BUTTON
button = customtkinter.CTkButton(master=app,
                                 width=375,
                                 height=75,
                                 border_width=0,
                                 corner_radius=8,
                                 text="RAISE BACK",
                                 text_font=("Roboto", "14"),
                                 command=frontUp_function)
button.place(relx=0.4585, rely=0.3, anchor=tkinter.CENTER)

#DISTANCE LABEL
label = customtkinter.CTkLabel(master=app,
                               textvariable=tkinter.StringVar(value="DISTANCE"),
                               width=100,
                               height=25,
                               text_font=("Roboto", "14"),
                               corner_radius=8)
label.place(relx=0.4585, rely=0.38, anchor=tkinter.CENTER)

#DISTANCE VALUE LABEL
label = customtkinter.CTkLabel(master=app,
                               textvariable=tkinter.StringVar(value="0"),
                               width=40,
                               height=40,
                               text_font=("Roboto", "50"),
                               corner_radius=8)
label.place(relx=0.4585, rely=0.45, anchor=tkinter.CENTER)

#BACK DOWN BUTTON
button = customtkinter.CTkButton(master=app,
                                 width=375,
                                 height=75,
                                 border_width=0,
                                 corner_radius=8,
                                 text="LOWER BACK",
                                 text_font=("Roboto", "14"),
                                 command=frontUp_function)
button.place(relx=0.4585, rely=0.57, anchor=tkinter.CENTER)

#TEACH BUTTON
button = customtkinter.CTkButton(master=app,
                                 width=250,
                                 height=75,
                                 border_width=0,
                                 corner_radius=8,
                                 text="SET ENDPOINT 2",
                                 text_font=("Roboto", "14"),
                                 command=button_function)
button.place(relx=0.41, rely=0.7, anchor=tkinter.CENTER)

#TEACH ENTRY
entry = customtkinter.CTkEntry(master=app,
                               placeholder_text=0,
                               width=120,
                               height=75,
                               border_width=2,
                               text_font=("Roboto", "18"),
                               corner_radius=10)
entry.place(relx=0.56, rely=0.7, anchor=tkinter.CENTER)

#############################AUTOMATION SECTION#############################





app.mainloop()
