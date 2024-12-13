
#include <WiFi.h>
#include <HTTPClient.h>
#include <ArduinoJson.h>

// Wi-Fi credentials
const char* ssid = "StormFiber-E290";           // Replace with your WiFi SSID
const char* password = "D23Uh34e";

// Flask server URL
const char* serverURL = "http://192.168.18.32:5000";
int count =0;
void setup() {
  Serial.begin(115200);

  // Connect to Wi-Fi
  WiFi.begin(ssid, password);
  Serial.print("Connecting to Wi-Fi");
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.print(".");
  }
  Serial.println("\nConnected to Wi-Fi");
  Serial.println("Enter command (0 to input data, 1 to get last data by ID):");

}

void loop() {
    
    if (Serial.available()) {
      String command = Serial.readStringUntil('\n');
      command.trim();
   
    if (command == "0") {
      Serial.println("Enter 5 integers separated by spaces:");
      while (!Serial.available());
      String input = Serial.readStringUntil('\n');
      input.trim();

      int values[5];

      int count = sscanf(input.c_str(), "%d %d %d %d %d", &values[0], &values[1], &values[2], &values[3], &values[4]);
      
      Serial.println("5 Interger has been enter:\n");

      if (count == 5) {
        sendData(values);
        Serial.println("Data sent to server. Enter next command:");
        Serial.println("Enter command (0 to input data, 1 to get last data by ID):");
        count = 0;
      } else {
        Serial.println("Invalid input. Please enter exactly 5 integers.");
      }
    } else if (command == "1") {
      while (!Serial.available());
      getData();
      Serial.println("Enter next command:");
    } else {
      Serial.println("Invalid command. Enter 0 to input data or 1 to get last data by ID:");
    }
  }
}

void sendData(int values[5]) {
  if (WiFi.status() == WL_CONNECTED) {
    HTTPClient http;

    String url = String(serverURL) + "/add_data";
    http.begin(url);
    http.addHeader("Content-Type", "application/json");

    // Create JSON payload
    StaticJsonDocument<200> doc;
    doc["number1"] = values[0];
    doc["number2"] = values[1];
    doc["number3"] = values[2];
    doc["number4"] = values[3];
    doc["number5"] = values[4];

    String jsonPayload;
    serializeJson(doc, jsonPayload);

    // Send POST request
    int httpResponseCode = http.POST(jsonPayload);

    if (httpResponseCode > 0) {
      String response = http.getString();
      Serial.println("Response: " + response);
    } else {
      Serial.println("Error sending data: " + String(httpResponseCode));
    }

    http.end();
  } else {
    Serial.println("Wi-Fi not connected");
  }
}

void getData() {
  if (WiFi.status() == WL_CONNECTED) {
    HTTPClient http;

    String url = String(serverURL) + "/get_last_data";
    http.begin(url);

    // Send GET request
    int httpResponseCode = http.GET();

    if (httpResponseCode > 0) {
      String response = http.getString();
      Serial.println("Response: " + response);

      // Parse JSON response
      StaticJsonDocument<200> doc;
      DeserializationError error = deserializeJson(doc, response);

      if (!error) {
        Serial.print("ID: ");
        Serial.print(doc["id"].as<int>());
        Serial.print(", Number1: ");
        Serial.print(doc["number1"].as<int>());
        Serial.print(", Number2: ");
        Serial.print(doc["number2"].as<int>());
        Serial.print(", Number3: ");
        Serial.print(doc["number3"].as<int>());
        Serial.print(", Number4: ");
        Serial.print(doc["number4"].as<int>());
        Serial.print(", Number5: ");
        Serial.println(doc["number5"].as<int>());
      } else {
        Serial.println("Error parsing JSON");
      }
    } else {
      Serial.println("Error getting data: " + String(httpResponseCode));
    }

    http.end();
  } else {
    Serial.println("Wi-Fi not connected");
  }
}
