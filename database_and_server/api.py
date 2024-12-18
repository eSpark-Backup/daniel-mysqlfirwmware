


# # curl -X INSERT -H "Content-Type: application/json" -d "{\"value\": 25.5}" http://localhost:5000/add_data

from flask import Flask, request, jsonify  # pip install flask

import mysql.connector

app = Flask(__name__)

# Database connection function
def get_db_connection():
    try:
        connection = mysql.connector.connect(
            host="localhost",
            user="root",  # Replace with your MySQL username
            password="mysql123456",  # Replace with your MySQL password
            database="esp32_data"
        )
        return connection
    except mysql.connector.Error as err:
        print(f"Error connecting to the database: {err}")
        raise

# Route to add data to the database
@app.route('/add_data', methods=['POST'])
def add_data():
    data = request.json
    required_fields = ["number1", "number2", "number3", "number4", "number5"]

    if not data or not all(field in data for field in required_fields):
        return jsonify({"error": "Invalid input, all numbers are required"}), 400

    try:
        connection = get_db_connection()
        cursor = connection.cursor()

        # Insert data into the table
        query = "INSERT INTO numbers (number1, number2, number3, number4, number5) VALUES (%s, %s, %s, %s, %s)"
        values = (data['number1'], data['number2'], data['number3'], data['number4'], data['number5'])
        cursor.execute(query, values)
        connection.commit()

        return jsonify({"message": "Data added successfully"}), 201
    except mysql.connector.Error as err:
        return jsonify({"error": str(err)}), 500
    finally:
        if connection.is_connected():
            cursor.close()
            connection.close()

@app.route('/get_last_data', methods=['GET'])
def get_last_data():
    try:
        connection = get_db_connection()
        cursor = connection.cursor(dictionary=True)
        # Fetch the last entered integer value from number5 column
        query = "SELECT number5 FROM Numbers ORDER BY id DESC LIMIT 1"
        cursor.execute(query)
        row = cursor.fetchone()

        if row:
            last_integer = row['number5']
            return jsonify({"last_integer": last_integer}), 200
        else:
            return jsonify({"message": "No data found"}), 404

    except mysql.connector.Error as err:
        return jsonify({"error": f"MySQL Error: {str(err)}"}), 500
    except Exception as e:
        return jsonify({"error": f"Server Error: {str(e)}"}), 500
    finally:
        if connection.is_connected():
            cursor.close()
            connection.close()


# Main entry point
if __name__ == "__main__":
    # app.run(host='localhost', port=5000, debug=True)
    app.run(host='0.0.0.0', port=5000, debug=True)
