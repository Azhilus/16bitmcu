# BLE Spammer for ESP32

This Arduino sketch provides a simple Bluetooth Low Energy (BLE) spoofer for ESP32 devices. It allows you to simulate various BLE devices with customizable payloads. This code can be utilized for testing and experimentation with BLE-enabled devices and applications.

<img src="https://github.com/Azhilus/16bitmcu/assets/66466976/4aa77863-a1ad-445f-ade0-bd006493bee5" alt="BLESPAMMER" width="300">


## Device Simulation

The code includes predefined payloads for different types of BLE devices, such as Airpods, PowerBeats, Beats Studio, Apple TV, HomePod, and more. You can easily customize the payload data for each device type to suit your testing requirements.

## Board Compatibility

This code is designed to work with ESP32 boards. Ensure that you have the ESP32 board support installed in your Arduino IDE.

## Prerequisites

Before uploading the code to your ESP32 board, make sure you have the following:

- Arduino IDE installed on your computer.
- ESP32 board support installed in the Arduino IDE.
- BLE libraries (BLEDevice, BLEUtils, BLEServer) installed. You can install these libraries through the Library Manager in the Arduino IDE.

## Customization

### User-Selectable Variables

- `deviceType`: Initial device type to simulate.
- `delaySeconds`: Delay in seconds between BLE advertising intervals.
- `advType`: Type of BLE advertisement.

### Payload Data

Customize the payload data for different device types using arrays like `dataAirpods`, `dataPowerBeats`, etc. These arrays contain the specific BLE advertisement data for each device type.

## Hardware Setup

Connect your ESP32 device to your computer and ensure that it is recognized by the Arduino IDE. No additional hardware is required for this code as it focuses on BLE simulation.

## Uploading the Code

1. Open the `BLESpammer.ino` file in the Arduino IDE.

2. Select your ESP32 board and port from the Tools menu.

3. Click the upload button to upload the code to your ESP32 board.

## Code Overview:

1. **BLE Libraries Inclusion:**
   ```cpp
   #include <BLEDevice.h>
   #include <BLEUtils.h>
   #include <BLEServer.h>
   ```
   These lines include the necessary BLE libraries for ESP32.

2. **User-Selectable Variables:**
   ```cpp
   int deviceType = 1; // Initial device type
   int delaySeconds = 2; // Delay in seconds
   int advType = 2;
   ```
   These variables allow users to select the initial device type, set the delay between advertising intervals, and choose the advertisement type.

3. **Payload Data for Different Devices:**
   Payload data is predefined for various device types using arrays (e.g., `dataAirpods`, `dataPowerBeats`). Customize these arrays according to the desired BLE advertisement for each device type.

4. **Setup Function:**
   ```cpp
   void setup() {
     Serial.begin(115200);
     Serial.println("Starting ESP32 BLE");

     BLEDevice::init("");
     BLEServer *pServer = BLEDevice::createServer();
     pAdvertising = pServer->getAdvertising();
   }
   ```
   - Serial communication is initiated.
   - BLE device initialization and server creation are performed.

5. **Update Device Type Function:**
   ```cpp
   void updateDeviceType() {
     // Function to switch the device type every 2 seconds
   }
   ```
   This function switches the device type every 2 seconds.

6. **Loop Function:**
   ```cpp
   void loop() {
     updateDeviceType();
     // Code to select appropriate payload data based on deviceType
     // Code to set up advertisement type and data
     // Code to start and stop advertising
   }
   ```
   The `loop()` function calls `updateDeviceType()` and contains the main code for selecting payload data, setting up BLE advertising, and starting/stopping the advertising.

7. **Advertisement Type Setup:**
   ```cpp
   // Code to set the advertisement type based on advType
   ```

8. **Advertisement Data Setup:**
   ```cpp
   // Code to set up the advertisement data based on the selected deviceType
   ```

9. **Start and Stop Advertising:**
   ```cpp
   pAdvertising->start();
   delay(delaySeconds * 500); // Delay for delaySeconds seconds
   pAdvertising->stop();
   ```

## Troubleshooting

- If you encounter issues during compilation or upload, ensure that the required BLE libraries are installed in your Arduino IDE.

- Double-check the ESP32 board and port selection in the Arduino IDE.

## Contributing

If you have improvements or additional features to suggest, feel free to fork the repository, make your changes, and submit a pull request.

## License

This project is licensed under the MIT License.

Happy Hacking!
