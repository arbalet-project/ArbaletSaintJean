from .model import Model
from .simulator import Simulator
from threading import Thread
from struct import pack
from time import sleep
from artnet import dmx
from os import path
from serial import Serial
import struct
import sys
import json


class Wall(Thread):
    PROTOCOL_VERSION = 2
    PROTOCOL_RECEIVE_FRAME = b'F'
    PROTOCOL_SEND_DISCOVERY = b'H'
    NUM_PIXELS_PER_DGRAM = 15

    def __init__(self, hardware_ip, hardware_port, hardware=True, simulator=True):
        Thread.__init__(self)
        self.header = bytes(list(map(ord, ['A', 'R', 'B', 'A'])) + [self.PROTOCOL_VERSION]) + self.PROTOCOL_RECEIVE_FRAME
        self.model = Model(15, 20)
        self.ip = hardware_ip
        self.port = hardware_port
        self.num_pixels = self.model.height * self.model.width

        # row, column -> (DMX universe, DMX address)
        config_path = path.join(path.dirname(__file__), 'config', 'config.json')
        with open(config_path) as f:
            self.config = json.load(f)

        self.serial = None
        self.simulator = None
        self.rate = int(self.config['refresh_rate'])

        if simulator:
            self.simulator = Simulator(self.model)

        if hardware:
            self.serial = Serial("/dev/ttyACM0", self.config["baudrate"], timeout=1)

    def __getitem__(self, row):
        return self.model.__getitem__(row)

    def __setitem__(self, key, value):
        with self.model:
            self.model.__setitem__(key, value)

    def set_all(self, r, g, b):
        for row in range(self.model.height):
            for col in range(self.model.width):
                self.model[row, col] = r, g, b

    def update(self):
        from random import randint
        if self.serial is not None:
            with self.model:
                num_subframes = round(self.num_pixels / self.NUM_PIXELS_PER_DGRAM)
                frame = [[0]*3*self.NUM_PIXELS_PER_DGRAM for subframe in range(num_subframes)]
                for row in range(self.model.height):
                    for col in range(self.model.width):
                        num_pixel = self.config['mapping'][row][col]
                        subframe_id = int(num_pixel / self.NUM_PIXELS_PER_DGRAM)
                        num_pixel_in_subframe = int(num_pixel % self.NUM_PIXELS_PER_DGRAM)
                        r, g, b = map(lambda x: min(255, max(0, int(x))), self.model[row][col])
                        frame[subframe_id][num_pixel_in_subframe*3] = r
                        frame[subframe_id][num_pixel_in_subframe*3+1] = g
                        frame[subframe_id][num_pixel_in_subframe*3+2] = randint(0, 255)

                for subframe_id, subframe in enumerate(frame):
                    packet = bytes([subframe_id]) + bytes(subframe)
                    self.serial.write(self.header + packet)
            print("Frame update")
            self.update_serial_input()

        if self.simulator is not None:
            self.simulator.update() 

    def update_serial_input(self):
        if self.serial:
            while self.serial.in_waiting > 0:
                print(self.serial.in_waiting, "Bytes response available:")
                print(self.serial.readline())

    def run(self):
        for i in range(5, 0, -1):
            self.update_serial_input()
            print("Waiting {} sec... ".format(i))
            sleep(1)
        self.running = True
        try:
            while self.running:
                self.update()
                sleep(1./self.rate)
        finally:
            self.close()

    def close(self):
        self.running = None
        if self.serial is not None:
            self.serial.close()
        if self.simulator is not None:
            self.simulator.close()


