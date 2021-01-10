import webbrowser
import speech_recognition as sr
import pyttsx3
import datetime
import wikipedia
import os
import smtplib

engine = pyttsx3.init('sapi5')
voices = engine.getProperty('voices')
engine.setProperty('voice',voices[0].id)
engine.setProperty('rate',150)

def speak(audio):
    '''
    this function is for creating a computer defult voice
    '''
    engine.say(audio)
    engine.runAndWait()

def wishme():
    '''
    this function is for starting and wish to programmer
    '''
    hour = int(datetime.datetime.now().hour)
    if hour >=0 and hour <12:
        speak("Good Morning Vaibhav!")
    elif hour>=12 and hour <17:
        speak("Good Afternoon Vaibhav!")
    else:
        speak("Good evening Vaibhav!")
    speak("I am jarvis.\nPlease tell me how may i help you.")

def Getcommond():
    '''
    it takes micro phone input from the usre and give a string output
    '''
    r = sr.Recognizer()
    with sr.Microphone() as source:
        print("Listening....")
        r.pause_threshold = 1

        audio = r.listen(source)

    try:
        print("Recognizing.....")
        query = r.recognize_google(audio, language='en-in')
        print(f"user said: {query}")
    except Exception as e:
        print(e)  #if you don't want to show eroor while running the program
        print("Say that again please...")
        return "None"
    return query
def sendEmail(to, content):
    server = smtplib.SMTP('smtp.gmail.com', 587)
    server.ehlo()
    server.starttls()
    server.login('vadadoriyavaibhav0000@gmail.com', 'vaibhav4545')
    server.sendmail('vadadoriyavaibhav0000@gmail.com', to, content)
    server.close()



if __name__ == '__main__':
    wishme()
    while True:
        query =  Getcommond().lower()
        #logic for exicuting program
        if 'wikipedia' in query:
            speak("speaking Wikipedia....")
            query = query.replace("wikipeadia","")
            results = wikipedia.summary(query,sentences=2)
            speak("Acrroding to wikipedia...")
            print(results)
            speak(results)
        elif 'youtube' in query:
            webbrowser.open("https://www.youtube.com/")

        elif 'google' in query:
            webbrowser.open("https://www.google.com/")

        elif 'dbms' in query:
            webbrowser.open("https://meet.google.com/jmn-ztpa-zrr?pli=1&authuser=2")

        elif 'whatsapp' in query:
            webbrowser.open("https://web.whatsapp.com/")


        elif 'play music' in query:
         music_dir = "E:\\vaibhav\\music"
         songs = os.listdir(music_dir)
         print(f"\n{songs}")
         os.startfile(os.path.join(music_dir,songs[0]))

        elif 'time' in query:
            strtime = datetime.datetime.now().strftime("%H:%H:%S")
            speak(f"sir, the time is {strtime}")

        elif 'opne code' in query:
            codePath = "C:\\Users\\user\\AppData\\Roaming\\Microsoft\\Windows\\Start Menu\\Programs\\Visual Studio Code"
            os.startfile(codePath)

        elif 'stop' in query:
            speak("Thank you sir , see you later")
            exit(0)

        elif 'email to krishna' in query:
            try:
                speak("what should i say?")
                content = Getcommond()
                to = "Chaudharikrishna3676@gmail.com"
                sendEmail(to, content)
                speak("Email has been sent")
            except Exception as e:
                print(e)
                speak("sorry vaibhav  bhai i can't be able to send this emain")

