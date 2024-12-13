# MySQL Interactive Firmware Development

## Step 1: Create a Database on MySQL

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

[Watch the Demo Video](https://www.loom.com/share/528119e048e3420cb9b495e7fc252071?sid=429f4312-00d7-4192-bc60-79b06f0897c9)
