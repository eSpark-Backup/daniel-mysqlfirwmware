
import mysql.connector   # pip install mysql-connector-python

def create_database():
    connection = None
    try:
        # Connect to MySQL server
        connection = mysql.connector.connect(
            host="localhost",               
            user="root",  # Replace with your MySQL username
            password="mysql123456"  # Replace with your MySQL password
        )
        cursor = connection.cursor()

        # Create database
        cursor.execute("CREATE DATABASE IF NOT EXISTS esp32_data")

        # Select the database
        cursor.execute("USE esp32_data")

        # Create a table
        cursor.execute("""
        CREATE TABLE IF NOT EXISTS Numbers (
            id INT AUTO_INCREMENT PRIMARY KEY,
            number1 FLOAT,
            number2 FLOAT,
            number3 FLOAT,
            number4 FLOAT,
            number5 FLOAT
        )
        """)

        print("Database and table created successfully!")
    except mysql.connector.Error as err:
        print(f"Error: {err}")
    finally:
        if connection is not None and connection.is_connected():
            connection.close()
            print("MySQL connection closed.")

if __name__ == "__main__":
    create_database()
