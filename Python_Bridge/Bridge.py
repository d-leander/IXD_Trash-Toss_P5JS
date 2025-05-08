from flask import Flask
from flask_cors import CORS

import serial

app = Flask(__name__)
CORS(app)

ser = serial.Serial('COM18', 9600, timeout=1)

@app.route('/')
def read_sensor():
    if ser.in_waiting:
        data = ser.readline().decode('utf-8').strip()
        return data
    return "No data available"

if __name__ == '__main__':
    print("Server running at http://localhost:5000")
    app.run(host='0.0.0.0', port=5000)
