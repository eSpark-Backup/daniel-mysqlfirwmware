# MySQL Interactive Firmware Development

# ESP32 Setup and Binary Build Guide

## 1. Setup ESP32 on Arduino IDE

### Step 1: Install the ESP32 Board Manager URL
1. Open Arduino IDE(2.3.4).
2. Go to **File → Preferences** (on Windows/Linux).
3. In the **Additional Board Manager URLs** field, paste the following URL:
   ```bash
   http://arduino.esp8266.com/stable/package_esp8266com_index.json,https://dl.espressif.com/dl/package_esp32_index.json,https://raw.githubusercontent.com/espressif/arduino-esp32/gh-pages/package_esp32_index.json
   ```
4. Click **OK** to save.

### Step 2: Install the ESP32 Boards
1. Go to **Tools → Board → Boards Manager**.
2. In the search bar, type `esp32`.
3. Find and select the **esp32 by Espressif Systems** package.
4. Click **Install** and wait for the installation to complete.

### Step 3: Select the ESP32 Board
1. Go to **Tools → Board**.
2. Scroll down and select the appropriate ESP32 board (e.g., `ESP32 Dev Module`).

### Step 4: Select the COM Port
1. Go to **Tools → Port**.
2. Select the port corresponding to your ESP32 board (e.g., `COM3`).

---

## 2. Install Required Libraries
1. Open Arduino IDE(2.3.4).
2. Go to **Tools → Manage Libraries**.
3. Search and install the following libraries:
- `ArduinoJSON (v7.2.1)`
- `HttpClient (v2.2.0)`

---

## 3. Build Binaries

### Step 1: Download the Flash Download Tool
1. Download the tool from the following link:  
[Flash Download Tool](https://github.com/Makerfabs/esp_tool)

### Step 2: Install the Flash Download Tool
1. After downloading, install the tool on your system.

### Step 3: Configure and Flash the Board
1. Open the **Flash Download Tool** after installation.
2. Configure the tool with your ESP32 board and project binary files.
3. Follow the instructions in the tool to flash the binaries onto the ESP32.
   
![image](https://github.com/user-attachments/assets/4a7db585-1fa2-4346-931f-f9ca2b60a109)

5. Click on the three dots to open file browser.

 ![image](https://github.com/user-attachments/assets/873c5b6d-ebec-428c-9f8d-fa7dcf7531a8)

6. Select the binary file from the directory and open.

![image](https://github.com/user-attachments/assets/d6e74d36-e572-4e3c-b348-5bb74fc7489f)

7. Make sure the address should 0x00.
8. Select the port and Baudrate the click on start.

![image](https://github.com/user-attachments/assets/7f662f95-fa11-4b4d-b888-1b72e7f4420d)

9. Binary file has been upload on ESP32.

![image](https://github.com/user-attachments/assets/739c5ab6-a147-4798-9890-b8c47f3dd5e2)

⦁	NOTE: Make sure same COM port shouldn't be open (like Serial Monitor in Arduino IDE) other wise COM FAIL error occured.


## 4. Create a Database on MySQL

Make sure MySQL Workbench is installed. Update the `user` and `password` fields in `mysql_database.py` according to your MySQL Workbench configuration.

```python
host="localhost",
user="root",              # Replace with your MySQL username
password="mysql123456",   # Replace with your MySQL password
database="esp32_data"
```

### Database Setup:
1. Install the MySQL connector for Python by running:
   ```bash
   pip install mysql-connector-python
   ```
2. Execute the database script using Python:
   ```bash
   python mysql_database.py
   ```

### Verification:
- The database should now be created in MySQL Workbench.

![Database Created](https://github.com/user-attachments/assets/2bd55a4b-2c16-44db-a06d-2a8d76292b6a)

---

## Step 2: Create a Server

Update the `user` and `password` fields in the server script to match your MySQL Workbench credentials.

```python
host="localhost",
user="root",              # Replace with your MySQL username
password="mysql123456",   # Replace with your MySQL password
database="esp32_data"
```

### Server Setup:
1. Install Flask by running:
   ```bash
   pip install flask
   ```
2. Execute the server script:
   ```bash
   python api.py
   ```

### Verification:
- The server should start running as shown in the terminal output.

![Server Running](https://github.com/user-attachments/assets/e425cc07-f02a-4f8a-a1ff-cbe736d8cc0f)

---

## Step 3: Update Firmware

Ensure that both the server and ESP32 are on the same network.

![ESP32 Network](https://github.com/user-attachments/assets/7c4d3240-ed5b-4f54-9533-48014a53249f)
![Firmware Compilation](https://github.com/user-attachments/assets/095af066-88db-407c-89a9-e4c545e2df84)

1. Compile the firmware.
2. Upload the firmware to your ESP32 device.

---

## Demo Video

[Watch the Demo Video] (https://www.loom.com/share/41fb0520eaf24f73900536a465b07a0f?sid=ff07c38c-4034-4e3b-81e7-210350594474)
