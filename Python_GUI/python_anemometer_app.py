#= -------------------------------------------------------------------------
# @file python_anemometer_app.py
#
# @date 09/05/16 21:38:26
# @author Martin Noblia
# @email martin.noblia@openmailbox.org
#
# @brief
# App for the Anemometer
# @detail
#
#  Licence:
# This program is free software: you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation, either version 3 of the License, or (at
# your option) any later version.
# 
# This program is distributed in the hope that it will be useful, but
# WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
# General Public License for more details.
# 
# You should have received a copy of the GNU General Public License

#---------------------------------------------------------------------------=#
from kivy.app import App
from kivy.uix.widget import Widget
from kivy.graphics import Color, Line
from kivy.uix.floatlayout import FloatLayout
#from math import cos, sin, pi
from numpy import cos, sin, pi
from kivy.clock import Clock
from kivy.lang import Builder
from kivy.properties import NumericProperty
import serial
import time
from threading import Thread
from kivy.app import App
from kivy.uix.boxlayout import BoxLayout
from kivy.uix.label import Label
from kivy.properties import ObjectProperty, StringProperty
import datetime
import re

kv = '''
#:import math math

[AnemometerNumber@Label]:
    text: ctx.d
    pos_hint: {"center_x": 0.5+0.42*math.sin(math.pi/8*(ctx.i-16)), "center_y": 0.5+0.42*math.cos(math.pi/8*(ctx.i-16))}
    font_size: self.height/16

<Box_a>:
    Label:
        id: mylabel
        text: "hello, world"

<MyAnemometerWidget>:
    face: face
    ticks: ticks
    FloatLayout:
        id: face
        size_hint: None, None
        pos_hint: {"center_x":0.5, "center_y":0.5}
        size: 0.9*min(root.size), 0.9*min(root.size)
        canvas:
            Color:
                rgba: 1, 1, 1, .8
            Ellipse:
                size: self.size
                pos: self.pos
                source:'/home/elsuizo/images/Reinel_wind_rose_round.png'
        AnemometerNumber:
            i: 0
            d: "N"
        AnemometerNumber:
            i: 1
            d: "NNO"
        AnemometerNumber:
            i: 2
            d: "NO"
        AnemometerNumber:
            i: 3
            d: "NOO"
        AnemometerNumber:
            i: 4
            d: "O" 
        AnemometerNumber:
            i: 5
            d: "SOO"
        AnemometerNumber:
            i: 6
            d: "SO"
        AnemometerNumber:
            i: 7
            d: "SSO"
        AnemometerNumber:
            i: 8
            d: "S"
        AnemometerNumber:
            i: 9
            d: "SSE"
        AnemometerNumber:
            i: 10
            d: "SE"
        AnemometerNumber:
            i: 11
            d: "SEE"
        AnemometerNumber:
            i: 12
            d: "E"
        AnemometerNumber:
            i: 13
            d: "NEE"
        AnemometerNumber:
            i: 14
            d: "NE"
        AnemometerNumber:
            i: 15
            d: "NNE"
    Ticks:
        id: ticks
        r: min(root.size)*0.9/2
'''
Builder.load_string(kv)

class MyAnemometerWidget(FloatLayout):
    pass

class Ticks(Widget):
    def __init__(self, **kwargs):
        super(Ticks, self).__init__(**kwargs)
        self.bind(pos=self.update_anemometer)
        self.bind(size=self.update_anemometer)

    def read_serial(self, *args):

        '''Serial communications: get a response'''

        # open serial port
        try:
            serial_port = serial.Serial('/dev/ttyUSB1',115200)
            #serial_port = serial.Serial(com_port, baudrate=115200, timeout=1)
        except serial.SerialException as e:
            print("could not open serial port '{}': {}".format(com_port, e))

        # read response from serial port
        lines = []
        while True:
            line = serial_port.readline()
            lines.append(line.decode('utf-8').rstrip())

            # wait for new data after each line
            timeout = time.time() + 0.05
            while not serial_port.inWaiting() and timeout > time.time():
                pass
            if not serial_port.inWaiting():
                break 

        #close the serial port
        serial_port.close()   
        return lines
    def update_anemometer(self, *args):
        self.canvas.clear()
        with self.canvas:
            Color(1, 1, 0)
            #th = time.hour*60 + time.minute
            #lines = self.read_serial()
            state = 0 
            # for num in lines:
            #     if num[0] == 'S':
            #         state = re.findall(r'\d+', num)
            #         state = int(state[-1])
            #         print 'The state is ', state
            #     if num[0] == 'F':
            #         freq = re.findall(r'\d+', num)
            #         freq = int(freq[-1])
            #         print 'The freq is ', freq

            Line(points=[self.center_x, self.center_y, self.center_x+1*self.r*cos(2*pi/state), self.center_y+1*self.r*sin(2*pi/state)], width=4)

class MyAnemometerApp(App):
    def build(self):
        clock = MyAnemometerWidget()
        Clock.schedule_interval(clock.ticks.update_anemometer, 1)
        return clock

if __name__ == '__main__':
    MyAnemometerApp().run()


