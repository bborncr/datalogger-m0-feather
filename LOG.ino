void logData() {
  // read raw accel/gyro measurements from device
  timestamp = getTimestamp();
  accelgyro.getMotion6(&ax, &ay, &az, &gx, &gy, &gz);
  Serial.println(timestamp);
  logfile.print(timestamp); logfile.print(",");
  logfile.print(ax); logfile.print(",");
  logfile.print(ay); logfile.print(",");
  logfile.println(az);

  if (count % 5 == 0) { //write to SD Card every 5 samples (saves energy)
    logfile.flush();
    if (logfile.size() > 10000000) { // if filesize is more than 10M then create a new file
      logfile.close();
      stage = NEW;
    }
  }
  if (count == 25) {
    count = 0;
    digitalWrite(SD_LED, HIGH);
  } else {
    digitalWrite(SD_LED, LOW);
  }
  count ++;
}
