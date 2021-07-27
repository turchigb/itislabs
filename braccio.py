class Articolazione:
    #tipo può essere base, spalla, gomito, polso, ...
    #pin_motore1 è il n. di pin sul microcontrollore a cui è collegato il motore1. Se ci sono 2 motori per l'articolazione, allora
    #   avremo pin_motore2  e pos2, con un overriding
    #   del costruttore
    #pos1 è la posizione corrente in gradi (pos2 se ci sono 2 motori). Al momento dell'istanza deve valere 90°
    
    def __init__(self, tipo, pin_motore1, pos1, pin_motore2=None, pos2=None):
        self.tipo=tipo
        self.pin_motore1 = pin_motore1
        self.pos1 = 90
        self.duemotori = False
        if pin_motore2 is not None:
            self.pin_motore2 = pin_motore2
            duemotori=True
        if pos2 is not None:
            self.pos2 = 90
    
    def get_pos1():
        return self.pos1
    
    def get_pos2():
        if duemotori==true:
            return self.pos2
        return -1
        
    def ruota(self, gradi):
        self.pos1=gradi
        print("Motore ",self.tipo,", su pin ",self.pin_motore1," ruota fino a ",gradi," gradi")
        if self.duemotori==True:
            self.pos2=180-gradi
            print("Motore ",self.tipo," su pin ",self.pin_motore2," ruota fino a ",gradi," gradi")

#----------------------------------------------------------------     
base = Articolazione("base",7, 90)
base.ruota(23)

gomito = Articolazione("gomito",8, 90,8,120)
gomito.ruota(45)




"""
https://www.digikey.com/en/maker/blogs/2021/how-to-control-servo-motors-with-a-raspberry-pi
from gpiozero import Servo
from time import sleep

servo = Servo(25)

try:
	while True:
    	servo.min()
    	sleep(0.5)
    	servo.mid()
    	sleep(0.5)
    	servo.max()
    	sleep(0.5)
except KeyboardInterrupt:
	print("Program stopped")
	
	servo = Servo(25)
val = -1

try:
	while True:
    	servo.value = val
    	sleep(0.1)
    	val = val + 0.1
    	if val > 1:
        	val = -1
except KeyboardInterrupt:
	print("Program stopped")

"""
	