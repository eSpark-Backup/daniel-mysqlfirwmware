# MySQL Interactive Firmware Development

## Step# 1: Create a Database on MySQL.
Make sure MySQL workbench should be installed.
Change  `user` and `password` according to MySQL workbench.
``` bash
            host="localhost",
            user="root",              # Replace with your MySQL username
            password="mysql123456",  # Replace with your MySQL password
            database="esp32_data"
```
### Database Script:
  - Run the `pip install mysql-connector-python` on terminal. 
  - Run the database script on python `mysql_database.py`.
    
    ![image](https://github.com/user-attachments/assets/8cc9cc8d-fb89-4051-9887-194d9becc55e)
    
  - Database created on MySQL workbench.
  
   ![image](https://github.com/user-attachments/assets/2bd55a4b-2c16-44db-a06d-2a8d76292b6a)

## Step# 2: Create a Server.
Change  `user` and `password` according to MySQL workbench. 
``` bash
            host="localhost",
            user="root",              # Replace with your MySQL username
            password="mysql123456",   # Replace with your MySQL password
            database="esp32_data"
```
### Server Script:
  - Run the `pip install flask` on terminal.
  - Run the server script on python `api.py`.
  - Server start running.

  ![image](https://github.com/user-attachments/assets/e425cc07-f02a-4f8a-a1ff-cbe736d8cc0f)


## Step# 3: Update Firmware.
- Make sure the server and ESP32 network are the same. 

  ![image](https://github.com/user-attachments/assets/7c4d3240-ed5b-4f54-9533-48014a53249f) ![image](https://github.com/user-attachments/assets/095af066-88db-407c-89a9-e4c545e2df84)

- Compile and upload the firmware in ESP32.
  


